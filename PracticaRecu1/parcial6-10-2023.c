#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Practica5/TDAs/pilas0.h"

typedef char ST30[31];

typedef struct nodito{
    char dest;
    struct nodito *sig;
} nodoSL;

typedef nodoSL *pSub;

typedef struct nodo{
    char est;
    ST30 nom;
    pSub sub;
    struct nodo *ant,*sig;
} nodoLd;

typedef struct{
    nodoLd *pri,*ult;
} pListaD;

void cargaLista(pListaD *);
void actulizaLd(pListaD *);
void agregaALd(pListaD *,nodoLd *);
nodoLd* buscaEstacion(pListaD,char);
void simulaViaje(pListaD,int,int);
void bajanPasajeros(TPila *,char,int *);
void procesaPasajeros(pSub *,TPila *,int *,int *,int *,char,int,int);

int main() {
    pListaD L;
    int D,CAPA;
    L.pri = NULL;
    L.ult = NULL;

    cargaLista(&L);
    printf("Ingrese la distancia D: ");
    scanf("%d",&D);
    printf("\nIngrese la capacidad del tren: ");
    scanf("%d",&CAPA);

    actulizaLd(&L);
    simulaViaje(L,CAPA,D);

    return 0;
}

void actulizaLd(pListaD *L){ //! A)
    FILE *arch;
    char est,dest;
    int cant,i;
    ST30 nom;
    pSub *vecP;
    nodoLd *aux;

    arch = fopen("INICIAL.txt","r");

    if (arch != NULL){
        while (fscanf(arch,"%c %s %d",&est,nom,&cant) == 3){

            aux = buscaEstacion(*L,est);

            if (aux == NULL){
                aux = (nodoLd*) malloc(sizeof(nodoLd));
                aux->est = est;
                strcpy(aux->nom,nom);
                aux->sub = NULL;

                agregaALd(L,aux);
            }

            vecP = (pSub*) malloc(cant * sizeof(pSub));
            for (i = 0; i < cant ; i++){
                fscanf(arch,"%c",&dest);
                vecP[i] = (pSub) malloc(sizeof(nodoSL)); 
                vecP[i]->dest = dest;
                vecP[i]->sig = NULL;
            }

            for (i = 0; i < cant-1 ; i++)
                vecP[i]->sig = vecP[i+1];
            
            aux->sub = vecP[0];
            free(vecP);
        }
        fclose(arch);
    }
}

void agregaALd(pListaD *L,nodoLd *aux){
    nodoLd *act;

    if (L->pri == NULL){
        L->pri = aux;
        L->ult = aux;
        aux->ant = NULL;
        aux->sig = NULL;
    }
    else if (aux->est < L->pri->est){
        aux->sig = L->pri;
        aux->ant = NULL;
        L->pri = aux;
    }
    else if (aux->est > L->ult->est){
        aux->sig = NULL;
        aux->ant = L->ult;
        L->ult = aux;
    }
    else{
        act = L->pri;
        while (act->est < aux->est)
            act = act->sig;
        aux->sig = act;
        aux->ant = act->ant;
        act->ant->sig = aux;
        act->ant = aux;
    }
}

nodoLd* buscaEstacion(pListaD L,char est){
    nodoLd *aux = L.pri;
    while (aux != NULL && aux->est < est)
        aux = aux->sig;

    return aux != NULL && aux->est == est ? aux : NULL;    
}

void simulaViaje(pListaD L,int CAPA,int D){ //! B)
    TPila tren;
    int contPas = 0,SumaKm = 0,contPasTot = 0;
    nodoLd *aux;
    iniciaP(&tren);

    aux = L.pri;
    while (aux != NULL){
        bajanPasajeros(&tren,aux->est,&contPas);
        procesaPasajeros(&aux->sub,&tren,&contPas,&contPasTot,&SumaKm,aux->est,D,CAPA);
        aux = aux->sig;
    }

    aux = L.ult;
    while (aux != NULL){  
        bajanPasajeros(&tren,aux->est,&contPas);        
        procesaPasajeros(&aux->sub,&tren,CAPA,&contPas,&contPasTot,&SumaKm,aux->est,D);
        aux = aux->ant;
    }

    printf("La distancia promedio que recorrio cada pasajero fue: %.2f\n",(float)SumaKm / contPasTot);
}

void bajanPasajeros(TPila *P,char est,int *contPas){
    TElementoP x;
    if (!vaciaP(*P)){
        sacaP(P,&x);
        bajanPasajeros(P,est,contPas);
        if (x == est)
            (*contPas)--; 
        else    
            poneP(P,x);
    }
}

void procesaPasajeros(pSub *S,TPila *P,int *contPas,int *contPasTot,int *SumaKm,char est,int D,int CAPA){
    pSub elim;
    while (*S != NULL && (*contPas) <= CAPA){
        poneP(P,(*S)->dest);
        (*SumaKm) += ((*S)->dest - est)*D;
        (*contPas)++;
        (*contPasTot)++;
        *S = elim;
        *S = (*S)->sig;
        free(elim);
    }
}

//! C)
/* En caso de tener pasajeros con prioridad, en la funcion procesaPasajers, que es la encargada de subir gente al tren,
agregaria un ciclo while (previo al desarrollado), donde me muevo con un actual y un anterior. A medida que me muevo en la sublista,
si encuentro un pasajero con priorida, lo pongo en la pila e incremento los contadores correspondientes (contPas,contPasTot,SumaKm),
luego guardo ese nodo en una variable elim. Si el nodo es la cabeza de la lista, muevo el puntero al siguiente de la lista.
En otro caso, el ant->sig me apuntaria a mi actual->sig (para aislar a actual, ahora tambien llamado elim). Luego de estas 2 opciones
elimino el nodo con free(elim). Luego de este ciclo, solo me quedarian en la lista los pasajeros sin prioridad, por lo que seguiria
el ciclo ya desarrollado en la funcion mencionada. */