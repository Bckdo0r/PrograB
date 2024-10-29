/*
Dada la matriz de alcance correspondiente a un digrafo, realizar una función recursiva para
hallar el vértice alcanzado por la mayor cantidad de vértices. En el caso de que existan más de
uno, devolver el primero encontrado.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5

typedef int TMat[N][N];

int _mayorAlcanzado(TMat, int, int, int, int);
char mayorAlcanzado(TMat);

int main()
{
    TMat R = {
        {0, 1, 1, 1, 1},
        {0, 0, 1, 1, 1},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
    };

    printf("El nodo más alcanzado es: %c\n", mayorAlcanzado(R));

    return 0;
}

int _mayorAlcanzado(TMat R, int i, int j, int actual, int mayor)
{

    if (j < N)
    {
        if (i < N)
            return _mayorAlcanzado(R, i + 1, j, actual + R[i][j], mayor);

        return _mayorAlcanzado(R, 0, j + 1, 0, actual > mayor ? actual : mayor);
    }

    return mayor;
}

char mayorAlcanzado(TMat R)
{
    return _mayorAlcanzado(R, 0, 0, 0, 0) + 'A';
}