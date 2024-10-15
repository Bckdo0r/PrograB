#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDA/arboles.h"

int esABB(arbol);

int main()
{
    arbol a;

    addNodo(&a, 15);
    addNodo(&a->izq, 10);
    addNodo(&a->izq->izq, 7);
    addNodo(&a->der, 20);
    addNodo(&a->der->izq, 16);
    addNodo(&a->der->izq->der, 17);
    addNodo(&a->der->der, 25);
    addNodo(&a->der->der->der, 30);

    /*
                 15
                /  \
              10    20
              /    /  \
             7    16  25
                   \
                    17
    */

    printf("Es ABB? %s", esABB(a) ? "Si" : "No");

    return 0;
}

int esABB(arbol a)
{
    if (a == NULL || (a->izq == NULL && a->der == NULL))
        return 1;

    return (a->izq != NULL && a->dato < a->izq->dato || a->der != NULL && a->dato > a->der->dato) ? 0 : esABB(a->izq) && esABB(a->der);
}