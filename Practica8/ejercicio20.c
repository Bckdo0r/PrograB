/*
¿Cómo modificaría el algoritmo anterior si además quisiera saber por cuántos vértices debe
pasar para llegar de vi a vj?
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5

typedef int TMat[N][N];

void alcanza(TMat, int, int, int *, int *, int[N]);

int main()
{

    TMat A = {
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 1, 0},
    };

    int alc = 0, cont = 0;
    int VV[N] = {0};

    int i = 3, j = 2;

    alcanza(A, i, j, &alc, &cont, VV);

    if (alc)
        printf("%c alcanza a %c con un camino de longitud de %d\n", i + 'A', j + 'A', cont);
    else
        printf("%c no alcanza a %c\n", i + 'A', j + 'A');

    return 0;
}

void alcanza(TMat A, int i, int j, int *alc, int *cont, int VV[])
{
    int k = 0;

    if (A[i][j])
    {
        (*cont)++;
        *alc = 1;
    }
    else
        while (k < N && !(*alc))
        {
            if (A[i][k] && !VV[i])
            {
                VV[i] = 1;
                (*cont)++;
                alcanza(A, k, j, alc, cont, VV);
            }

            k++;
        }
}