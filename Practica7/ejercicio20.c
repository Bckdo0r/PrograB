/*
 Dado un árbol binario proveniente de la conversión de un árbol general, hallar la cantidad de
 nodos que había en niveles impares.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDA/arboles.h"

int getOddLvl(arbol, int);
int getAll(arbol);

int main()
{
    arbol a;
    addNodo(&a, 1);                                          // A
    addNodo(&a->der, 2);                                     // B
    addNodo(&a->der->izq, 3);                                // C
    addNodo(&a->der->izq->der, 4);                           // D
    addNodo(&a->der->izq->der->izq, 5);                      // E
    addNodo(&a->der->izq->der->izq->der, 6);                 // F
    addNodo(&a->der->izq->der->izq->der->izq, 9);            // I
    addNodo(&a->der->izq->der->izq->der->izq->der, 10);      // J
    addNodo(&a->der->izq->der->izq->der->izq->der->der, 11); // K
    addNodo(&a->der->der, 12);                               // L
    addNodo(&a->der->der->izq, 13);                          // M
    addNodo(&a->der->der->izq->der, 14);                     // N
    addNodo(&a->der->der->izq->der->izq, 15);                // O
    addNodo(&a->der->der->der, 7);                           // G
    addNodo(&a->der->der->der->der, 8);                      // H

    printf("Cantidad de nodos en niveles impares del bosque: %d \n", getAll(a));

    return 0;
}

int getAll(arbol a)
{
    int cant = 0;
    while (a != NULL)
    {
        cant += getOddLvl(a->izq, 1);
        a = a->der;
    }

    return cant;
}

int getOddLvl(arbol a, int nivel)
{
    if (a == NULL)
        return 0;

    return nivel % 2 + getOddLvl(a->izq, nivel + 1) + getOddLvl(a->der, nivel);
}