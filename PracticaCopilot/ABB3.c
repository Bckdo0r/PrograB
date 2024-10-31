/* Dado un ABB de enteros, encuentra el nivel más profundo (no hoja) en el árbol y cuenta la cantidad de nodos de grado 2 
que se encuentran en ese nivel. Devuelve esta cantidad. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Practica7/TDA/arboles.h"

void contNodods(arbol a,int *nivelMax,int nivelAct,int *cont){
    
    if (a != NULL){

        if (nivelAct > (*nivelMax) && (a->izq != NULL || a->der != NULL)){
            (*nivelMax) = nivelAct;
            (*cont) = a->izq && a->der;
        }
        
        else if (nivelAct == (*nivelMax))
            (*cont) += a->izq && a->der;
        
        else{
            contNodods(a->izq,nivelMax,nivelAct+1,cont);
            contNodods(a->der,nivelMax,nivelAct+1,cont);   
        }
    }
}

int main() {


    return 0;
}