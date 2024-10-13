/* Desarrollar una función que retorne la suma del contenido de aquellos nodos de un árbol 
binario que tengan grado 1 y se encuentren en un nivel X que es dato. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDA/arboles.h"

int retornaSuma(arbol,int,int);

int main() {
    arbol A;
    int X=2;

    addNodo(&A, 5);
    addNodo(&A->izq, 8);
    addNodo(&A->izq->izq, 3);
    addNodo(&A->izq->izq->der, 9);
    addNodo(&A->izq->der, 6);
    addNodo(&A->izq->der->der, 7);
    addNodo(&A->der, 4);
    addNodo(&A->der->izq, 1);
    addNodo(&A->der->izq->der, 2);

    printf("La suma del contenido de aquellos nodos de grado 1 (nivel %d) son: %d",X,retornaSuma(A,X,0));

    return 0;
}

int retornaSuma(arbol A, int X, int lvlAct){
    int suma = 0;
    
    if (A == NULL)
        return suma;

    if (lvlAct == X)
        return (A->izq != NULL && A->der == NULL || A->izq == NULL && A->der != NULL)? suma + A->dato:suma;

    suma += retornaSuma(A->izq,X,lvlAct+1);
    suma += retornaSuma(A->der,X,lvlAct+1);

    return suma;        
}