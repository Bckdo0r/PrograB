#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDA/arboles.h"

int busca(arbol a, int x)
{
    if (a == NULL)
        return 0;
    if (x == a->dato)
        return 1;
    if (x < a->dato)
        return busca(a->izq, x);

    return busca(a->der, x);
}