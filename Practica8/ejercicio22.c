/*
Desarrollar un subprograma para mostrar el camino del vértice origen al vértice v (dato) a partir
del vector P generado por el algoritmo de Dijkstra.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 6

typedef int TVec[N];

void muestraCamino(TVec, int);

int main()
{
    //        0  1  2  3  4  5
    //        A  B  C  D  E  F
    TVec P = {0, 3, 4, 5, 1, 0};

    muestraCamino(P, 4);
    printf("\n");

    return 0;
}

void muestraCamino(TVec P, int v)
{
    if (v > 0)
        muestraCamino(P, P[v]);

    printf("%c ", v + 'A');
}