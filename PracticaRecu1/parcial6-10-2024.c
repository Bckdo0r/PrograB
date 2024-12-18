#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Practica5/TDAs/colas.h"

typedef char ST30[31];

typedef struct {
    unsigned int hs,min;
} Thora;

typedef struct{
    ST7 Pat;
    unsigned int fecha;
    ST5 hora;
    Thora Tabon,Tocup;
} reg;

typedef struct nodito{
    reg dato;
    struct nodito *sig;
} nodoSL;

typedef nodoSL *SLista;

typedef struct nodo{
    ST5 codA;
    ST30 nomb;
    char Est;
    SLista sub;
    struct nodo *ant,*sig;
} nodoLD;

typedef struct{
    nodoLD *pri,*ult;
} ListaD;

void cargaLista(ListaD *);
void cargaCola(TCola *);
void actualizaLD(ListaD, TCola *);
void agregaNodoSL(SLista *,TElementoC);
nodoLD* buscaAgente(ListaD,ST5);
int verifMesYHora(unsigned int,ST5);
reg copiaMulta(SLista);
void creaArch(ListaD,ST5,int);
void elimContinuo(SLista *);
void eliminaSL(SLista *);
void eliminaLD(ListaD *,ST5);

int main() {
    ListaD L;
    TCola C;
    ST5 X,AG;
    int K;

    L.pri = NULL;
    L.ult = NULL;
    iniciaC(&C);
    cargaLista(&L);
    cargaCola(&C);

    actualizaLD(L,&C);
    creaArch(L,AG,K);
    eliminaLD(&L,X);

    return 0;
}

void agregaNodoSL(SLista *S,TElementoC X){
    SLista ant, act, new = (SLista) malloc(sizeof(nodoSL));
    
    strcpy(new->dato.Pat,X.pat);
    strcpy(new->dato.hora,X.horaM);
    new->dato.Tabon.hs = X.Tabon / 60;
    new->dato.Tabon.min = X.Tabon % 60;
    new->dato.Tocup.hs = X.Tocup / 60;
    new->dato.Tocup.min = X.Tocup % 60;
    new->dato.fecha = X.fecha;

   if (*S == NULL || strcmp((*S)->dato.Pat,new->dato.Pat) > 0){
        new->sig = *S;
        *S = new;
    }
    else {
        act = *S;

        while (act != NULL && strcmp(act->dato.Pat,new->dato.Pat) <= 0){
            ant = act;
            act = act->sig;
        }

        ant->sig = new;
        new->sig = act;
    }
}

nodoLD* buscaAgente(ListaD L,ST5 cod){
    nodoLD *aux;
    aux = L.pri;

    while (aux != NULL && strcmp(aux->codA,cod) > 0)
        aux = aux->sig;

    return aux != NULL && strcmp(aux->codA,cod) == 0 ? aux : NULL;    
}

void actualizaLD(ListaD L,TCola *C){ //! A)
    TCola auxC;
    TElementoC x;
    nodoLD *auxL;

    iniciaC(&auxC);
    while (!vaciaC(*C)){
        sacaC(C,&x);

        if (x.fecha >= 243 && x.fecha <= 273 && x.Tabon < x.Tocup){
            auxL = buscaAgente(L,x.codA);
            if (auxL != NULL)
                agregaNodoSL(&auxL->sub,x);
            else
                printf("El agente %s no esta registrado",x.codA);    
        }

        else
            poneC(&auxC,x);
    }

    while (!vaciaC(auxC)){
        sacaC(&auxC,&x);
        poneC(C,x);
    }
}

int verifMesYHora(unsigned int fecha,ST5 hora){
    int i = 0, meses[12] = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

    while (i < 12 && fecha <= meses[i])
        i++;

    return (i+1 % 2 == 0) && strcmp(hora,"00:00") >= 0 && strcmp(hora,"12:00") < 0 || strcmp(hora,"18:00") > 0;;     
}

void creaArch(ListaD L,ST5 AG,int k){ //! B)
    int cont = 0;
    FILE *arch;
    nodoLD *aux;
    SLista auxS;
    
    aux = buscaAgente(L,AG); //Verificar que exista primero el agente antes de abrir archivo

    if (aux != NULL){
        arch = fopen("MULTAS.DAT","wb");
        auxS = aux->sub;
        
        while (auxS != NULL){
            cont++;
            if (verifMesYHora(auxS->dato.fecha,auxS->dato.hora))     
                fwrite(&auxS->dato,sizeof(reg),1,arch);

            auxS = auxS->sig; 
        }
        printf("Al agente %s, %s le corresponde el 15 de descuento ",AG, aux->Est == 'S' && cont > k ? "SI" : "NO");
        
        fclose(arch);
    }
    else
        printf("El agente %s no esta registrado",AG);    
    
}

void elimContinuo(SLista *S){
    SLista elim;
    while (*S != NULL && strncmp((*S)->dato.Pat,"AF",2) == 0){
        elim = *S;
        *S = (*S)->sig;
        free(elim);
    }
}

void eliminaSL(SLista *S){
    SLista ant,act;

    if (*S != NULL && strncmp((*S)->dato.Pat,"AF",2) == 0)
        elimContinuo(S);
    
    else{
        act = *S;
        
        while (act != NULL && strncmp(act->dato.Pat,"AF",2) < 0)
            ant = act;
            act = act->sig;

        elimContinuo(&act);
    }
}

void eliminaLD(ListaD *L,ST5 X){ //! C)
    nodoLD *aux;
    
    aux = buscaAgente(*L,X);

    if (aux != NULL){
        eliminaSL(&aux->sub);

        if (aux->sub == NULL){
            
            if (L->pri == L->ult){
                L->pri = NULL;
                L->ult = NULL;
            }

            else if (aux == L->pri){
                L->pri = aux->sig;
                aux->sig->ant = NULL;
            }
            
            else if (aux == L->ult){
                L->ult = aux->ant;
                aux->ant->sig = NULL;
            }
            
            else{
                aux->ant->sig = aux->sig;
                aux->sig->ant = aux->ant;
            }

            free(aux);
        }
    }
    else
        printf("El agente %s no esta registrado",X);
}