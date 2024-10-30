/* Dado un árbol binario de búsqueda (ABB) de enteros, encuentra la clave del nodo de grado 1 que se encuentre en el nivel más bajo 
(es decir, el nivel más cercano a la raíz). Si no existe un nodo de grado 1, retorna un valor especial (por ejemplo, -1).

Un nodo de grado 1 es aquel que tiene exactamente un hijo (solo un hijo izquierdo o solo un hijo derecho). */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Practica7/TDA/arboles.h"

int buscaClave(arbol a,int nivelMax,int nivelAct){
    int clave;

    if (a == NULL)
        return 1;

    if (nivelMax > nivelAct)
        return buscaClave(a->izq,nivelMax,nivelAct+1) && buscaClave(a->der,nivelMax,nivelAct+1);     

    if (a->izq != NULL && a->der == NULL && a->izq->izq == NULL){
        nivelMax = nivelAct;
        return a->dato;
    }


    
}

int main() {


    return 0;
}