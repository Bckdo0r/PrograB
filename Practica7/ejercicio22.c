#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDA/arboles.h"

/*
. Dado un árbol binario que proviene de la transformación de un árbol general, obtener la altura
del árbol original
*/

int maxAltura(arbol);
int altura(arbol);

int main()
{

    arbol a;
    addNodo(&a, 1);
    addNodo(&a->der, 2);
    addNodo(&a->der->izq, 3);
    addNodo(&a->der->izq->der, 4);
    addNodo(&a->der->izq->der->izq, 5);
    addNodo(&a->der->izq->der->izq->der, 6);
    addNodo(&a->der->izq->der->izq->der->izq, 9);
    addNodo(&a->der->izq->der->izq->der->izq->der, 10);
    addNodo(&a->der->izq->der->izq->der->izq->der->der, 11);
    addNodo(&a->der->der, 12);
    addNodo(&a->der->der->izq, 13);
    addNodo(&a->der->der->izq->der, 14);
    addNodo(&a->der->der->izq->der->izq, 15);
    addNodo(&a->der->der->der, 7);
    addNodo(&a->der->der->der->der, 8);

    printf("Altura del arbol original: %d \n", maxAltura(a));

    return 0;
}

int maxAltura(arbol a)
{
    int max = 0, alt;

    while (a != NULL)
    {
        alt = altura(a->izq) + 1;
        if (alt > max)
            max = alt;
        a = a->der;
    }

    return max;
}

int altura(arbol a)
{
    if (a == NULL)
        return 0;

    return (a->izq != NULL ? 1 : 0) + altura(a->izq) + altura(a->der);
}