// . Retornar el valor mínimo de un ABB.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDA/arboles.h"

int min(arbol, int);
int min2(arbol);

int main(int argc, char const *argv[])
{
    arbol a;
    addNodo(&a, 15);
    addNodo(&a->der, 20);
    addNodo(&a->izq, 10);
    addNodo(&a->izq->izq, 7);

    printf("%d\n", min(a, a->dato));
    printf("%d\n", min2(a));

    return 0;
}

int min(arbol a, int mini)
{
    if (a != NULL)
        return mini < a->dato ? min(a->izq, mini) : min(a->izq, a->dato);

    return mini;
}

int min2(arbol a)
{
    if (a == NULL)
        return 0;

    while (a->izq != NULL)
        a = a->izq;

    return a->dato;
}
