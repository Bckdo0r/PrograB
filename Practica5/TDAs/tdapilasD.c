#include <stdio.h>
#include "tdapilasD.h"
#include <stdlib.h>

void poneP (TPila *P, TElemento x){
    TPila N;
    N = (TPila)malloc(sizeof(nodoP));
    N->dato = x;
    N->sig = *P;
    *P = N; 
}

void sacaP(TPila *P, TElemento *x){
    TPila N;
    if (*P != NULL){
        N = *P;
        *x = (*P)->dato;
        *P = (*P)->sig;
        free(N);
    }
}

TElemento consultaP(TPila P){
    if (P != NULL)
        return P->dato;
}

int vaciaP(TPila P){
    return (P == NULL);
}

void iniciaP(TPila *P){
    *P = NULL;
}