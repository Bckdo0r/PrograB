#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Practica5/TDAs/pilas1.h"

typedef char ST25[26];

typedef struct nodito{
    ST5 cod;
    struct nodito *sig;
} nodoSL;

typedef nodoSL *pSub;

typedef struct nodo{
    ST5 cod;
    ST25 nom;
    unsigned int cuatri,creditos;
    pSub sub;
    struct nodo *sig;
} nodoLs;

typedef nodoLs *pLista;

typedef struct nodold{
    unsigned int cuatri;
    TPila P;
    struct nodold *sig,*ant;
} nodoLd;

typedef nodoLd *pNodoLd;

typedef struct {
    pNodoLd pri,ult;
} pListaD;

void cargaListaS(pLista *);
void generaArchivo(pLista,ST5);
pLista buscaAsig(pLista,ST5);
void nombreYCreditos(pLista,pSub,ST25,int *);
void generaListaD(pLista,pListaD *);
void iniciaListaD(pListaD *);
void agregaAListaD(pListaD,pLista);
void eliminaAsig(pLista *,pListaD,ST5);
void eliminaDeSubs(pLista,ST5);
void eliminaDePila(TPila *,ST5);

int main() {
    pLista Ls = NULL;
    pListaD Ld;
    ST5 A,B;
    
    Ld.pri = NULL;
    Ld.ult = NULL;

    cargaListaS(&Ls);

    printf("Ingrese un codigo A: ");
    scanf("%s",A);
    printf("\nIndese un codigo B: ");
    scanf("%s",B);

    generaArchivo(Ls,A);
    generaListaD(Ls,&Ld);
    eliminaAsig(&Ls,Ld,B);

    return 0;
}

void generaArchivo(pLista L,ST5 A){ //! A)
    FILE *arch;
    pLista aux;
    char nomArch[10];
    ST25 nombre;
    int sumaCred = 0,cont = 0;

    strcpy(nomArch,A);
    strcat(nomArch,".TXT");

    arch = fopen(nomArch,'w');

    if (arch != NULL){
        aux = buscaAsig(L,A);

        fprintf(arch,"Nombre de asignatura: %s | Cuatrimestre: %d\n",aux->nom,aux->cuatri);
        fprintf(arch,"Asignaturas correlativas anteriores: ");
        if (aux->sub == NULL){
            fprintf(arch,"NO TIENE");
        }
        else{
            while (aux->sub != NULL){
                cont++;
                nombreYCreditos(L,aux->sub->cod,nombre,&sumaCred); //? aporta claridad
                fprintf(arch,"%s ",nombre);
                aux->sub = aux->sub->sig;    
            }

            fprintf(arch,"\nPromedio de creditos de dichas asignaturas: %.2f",(float)sumaCred / cont);
        }
        fclose(arch); 
    }
}

pLista buscaAsig(pLista L,ST5 cod){
    while (L != NULL && strcmp(L->cod,cod) < 0)
        L = L->sig;
    return L != NULL && strcmp(L->cod,cod) == 0 ? L : NULL;    
}

void nombreYCreditos(pLista L,pSub S,ST25 nombre,int *sumaCred){
    pLista aux;

    aux = buscaAsig(L,S->cod);
    strcpy(nombre,aux->nom);
    (*sumaCred) += aux->creditos;
}

void generaListaD(pLista Ls,pListaD *Ld){ //! B)
    
    iniciaListaD(Ld);

    while (Ls != NULL){
        if (Ls->cod[0] != 'O')
            agregaAListaD(*Ld,Ls);
        Ls = Ls->sig;    
    }

}

void iniciaListaD(pListaD *L){ //? es correcto o hay otra forma mejor
    int i;
    pNodoLd *vecP;

    vecP = (pNodoLd*) malloc(10 * sizeof(nodoLd));
    for (i = 0; i < 10 ;i++){
        vecP[i] = (pNodoLd) malloc(sizeof(nodoLd));
        iniciaP(&vecP[i]->P);
        vecP[i]->cuatri = i+1;
        vecP[i]->ant = NULL;
        vecP[i]->sig = NULL;
    }

    for (i = 0; i < 10 - 1 ;i++)
        vecP[i]->sig = vecP[i+1];

    for (i = 9; i > 0 ;i--)
        vecP[i]->ant = vecP[i-1];

    L->pri = vecP[0];
    L->ult = vecP[9];
    free(vecP);
}

void agregaAListaD(pListaD Ld,pLista Ls){
    pNodoLd aux = Ld.pri;
    TElementoP x;
    
    strcpy(x.cod,Ls->cod);
    x.creditos = Ls->creditos;

    while (aux->cuatri != Ls->cuatri)
        aux = aux->sig;

    poneP(&aux->P,x);
}

void eliminaAsig(pLista *Ls,pListaD Ld,ST5 B){ //! C)
    pLista ant,act;
    pSub elim;
    pNodoLd aux = Ld.pri;
    
    act = *Ls;
    while (act != NULL && strcmp(act->cod,B) < 0){
        ant = act;
        act = act->sig;
    }

    if (act != NULL && strcmp(act->cod,B) == 0){
        eliminaDeSubs(*Ls,B);
        
        while (aux->cuatri != act->cuatri)
            aux = aux->sig;

        eliminaDePila(&aux->P,B);

        while (act->sub != NULL){
            elim = act->sub;
            act->sub = act->sub->sig;
            free(elim);
        }

        if (act == *Ls)
            *Ls = (*Ls)->sig;
        
        else
            ant->sig = act->sig;

        free(act);
    }
    else
        printf("La asignatura seleccionada no se encuentra en la lista.\n");  
}

void eliminaDeSubs(pLista L,ST5 cod){
    pSub act,ant;
    
    while (L != NULL){
        act = L->sub;
        while (act != NULL && strcmp(act->cod,cod) != 0){
            ant = act;
            act = act->sig;    
        }

        if (act != NULL){
            if (act == L->sub)
                L->sub = L->sub->sig;
            else
                ant->sig = act->sig;
            free(act);        
        }
        L = L->sig;
    }
}

void eliminaDePila(TPila *P,ST5 cod){
    TElementoP x;

    if (!vaciaP(*P)){
        sacaP(P,&x);
        eliminaDePila(P,cod);

        if (x.cod != cod)
            poneP(P,x);    
    }
}