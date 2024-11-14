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
void procesaPasajerosIda(pSub *,TPila *,int *,int *,int *,char,int,int);
void procesaPasajerosVuelta(pSub *,TPila *,int *,int *,int *,char,int,int);


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
    pSub *vecP,ult,nuevo;
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
            //hay que agregar a la sublista los elementos que voy leyendo, pero en orden
            
            nuevo = (pSub) malloc(sizeof(nodoSL));
            fscanf(arch,"%c",&dest);
            
            nuevo->dest = dest;
            nuevo->sig = NULL;
            aux->sub = nuevo;
            ult = nuevo;

            for (i = 0; i < cant - 1 ; i++){
                nuevo = (pSub) malloc(sizeof(nodoSL));
                fscanf(arch,"%c",&dest);
                
                nuevo->dest = dest;
                nuevo->sig = NULL;
                ult->sig = nuevo;
                ult = nuevo;
            }
            
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
    while (aux != NULL){ //? esta bien modularizado
        bajanPasajeros(&tren,aux->est,&contPas);
        procesaPasajerosIda(&aux->sub,&tren,&contPas,&contPasTot,&SumaKm,aux->est,D,CAPA);
        aux = aux->sig;
    }

    aux = L.ult;
    while (aux != NULL){  
        bajanPasajeros(&tren,aux->est,&contPas);        
        procesaPasajerosVuelta(&aux->sub,&tren,CAPA,&contPas,&contPasTot,&SumaKm,aux->est,D);
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

void procesaPasajerosIda(pSub *S,TPila *P,int *contPas,int *contPasTot,int *SumaKm,char est,int D,int CAPA){
    pSub elim,ant,act = *S;
    while (act != NULL && (*contPas) <= CAPA){
        if (act->dest > est){
            poneP(P,act->dest);
            (*SumaKm) += (act->dest - est)*D;
            (*contPas)++;
            (*contPasTot)++;
            
            if (*S == act)
                *S = act->sig;
            else
                ant->sig = act->sig;

            elim = act;
            act = act->sig;
            free(elim);
        }
        else{
            ant = act;
            act = act->sig;
        }
    }
}

void procesaPasajerosVuelta(pSub *S,TPila *P,int *contPas,int *contPasTot,int *SumaKm,char est,int D,int CAPA){
    pSub elim,ant,act = *S;
    while (act != NULL && (*contPas) <= CAPA){
        if (act->dest < est){
            poneP(P,act->dest);
            (*SumaKm) += (act->dest - est)*D;
            (*contPas)++;
            (*contPasTot)++;
            
            if (*S == act)
                *S = act->sig;
            else
                ant->sig = act->sig;    
            
            act = elim;
            act = act->sig;
            free(elim);
        }
        else{
            ant = act;
            act = act->sig;
        }
    }
}

void eliminaDeSub(pSub *S,pSub act){
    if (*S == act)
        *S = act->sig;
    else
            
}

//! C)
/* En caso de tener pasajeros con prioridad, en la funcion procesaPasajers, que es la encargada de subir gente al tren,
agregaria un ciclo while (previo al desarrollado), donde me muevo con un actual y un anterior. A medida que me muevo en la sublista,
si encuentro un pasajero con priorida, lo pongo en la pila e incremento los contadores correspondientes (contPas,contPasTot,SumaKm),
luego guardo ese nodo en una variable elim. Si el nodo es la cabeza de la lista, muevo el puntero al siguiente de la lista.
En otro caso, el ant->sig me apuntaria a mi actual->sig (para aislar a actual, ahora tambien llamado elim). Luego de estas 2 opciones
elimino el nodo con free(elim). Luego de este ciclo, solo me quedarian en la lista los pasajeros sin prioridad, por lo que seguiria
el ciclo ya desarrollado en la funcion mencionada. */