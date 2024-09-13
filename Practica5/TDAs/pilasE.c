#include <stdio.h>
#include "pilasE.h"

void iniciaP(TPila *P){
    P->tope = -1; 
}

int vaciaP(TPila P){
    return (P.tope == -1);    
}

void poneP(TPila *P,TElemento x){
    if (P->tope < MAX-1){
        P->tope ++;
        P->datos[P->tope] = x;  
    }
    else
        printf("Error. Pila llena \n");
}

void sacaP(TPila *P,TElemento *x){ //saca el ultimo elemento de la pila y lo almacena en x
    if (P->tope != MAX-1)
        *x = P->datos[P->tope --];
}

TElemento consultaP(TPila P){
    if (P.tope != -1)
        return P.datos[P.tope];    
}
