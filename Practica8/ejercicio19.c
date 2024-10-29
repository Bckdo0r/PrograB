/*
Desarrollar un subprograma que determine si un vértice (vi) es alcanzable desde otro (vj) para
un digrafo almacenado en:
a) una matriz de adyacencia
b) una lista de adyacencia
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5

typedef int TMat[N][N];

void alcanza(TMat, int, int, int *, int[N]);

int main()
{

    TMat A = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 0, 0, 0, 0},
    };

    int alc = 0;
    int VV[N] = {0};

    alcanza(A, 1, 4, &alc, VV);
    printf("Alcanza? %s", alc ? "Si" : "No");

    return 0;
}

void alcanza(TMat A, int i, int j, int *alc, int VV[])
{
    int k = 0;

    if (A[i][j])
        *alc = 1;
    else
        while (k < N && !(*alc))
        {
            if (A[i][k] && !VV[i])
            {
                VV[i] = 1;
                alcanza(A, k, j, alc, VV);
            }

            k++;
        }
}