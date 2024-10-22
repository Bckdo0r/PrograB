/*
Desarrollar una función que obtenga el grado de un vértice (dato) de un grafo almacenado en:
a) una matriz de adyacencia
b) una lista de adyacencia
c) media matriz (triángulo superior)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"

int grado(TMat, char);

int main()
{
    TMat mat = {
        {0, 0, 1, 1, 0, 1, 0},
        {0, 0, 1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0, 1, 0},
        {1, 1, 0, 1, 1, 1, 1},
        {0, 0, 0, 1, 0, 0, 1},
        {1, 0, 1, 1, 0, 0, 1},
        {0, 0, 0, 1, 1, 1, 0}};

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }

    printf("\nEl grado de D es: %d\n", grado(mat, 'D'));

    return 0;
}

int grado(TMat mat, char V)
{
    int gr = 0, j = 0, i = V - 'A';

    while (j < i)
        gr += mat[i][j++];

    while (i < N)
        gr += mat[i++][j];

    return gr;
}