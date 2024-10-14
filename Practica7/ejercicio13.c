/*
Generar un arreglo de caracteres con el contenido de las claves de un ABB. Los elementos del
arreglo deben quedar ordenados descendentemente.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDA/arboles.h"

void generaVec(arbol, int[], int);

int main()
{
    arbol a;
    int vec[100];

    addNodo(&a, 15);
    addNodo(&a->izq, 10);
    addNodo(&a->izq->izq, 7);
    addNodo(&a->der, 20);
    addNodo(&a->der->izq, 16);
    addNodo(&a->der->izq->der, 17);
    addNodo(&a->der->der, 25);

    generaVec(a, vec, 0);

    for (int i = 0; i < 7; i++)
    {
        /* code */
        printf("%d ", vec[i]);
    }

    return 0;
}

void generaVec(arbol a, int vec[], int i)
{
    if (a != NULL)
    {
        generaVec(a->der, vec, i);
        vec[i++] = a->dato;
        if (a->izq != NULL)
            generaVec(a->izq, vec, i);
    }
}