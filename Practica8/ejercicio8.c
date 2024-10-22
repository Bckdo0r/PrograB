/*
Desarrollar funciones recursivas para:
a) Generar un arreglo con el grado de cada vértice de un grafo almacenado en una matriz de adyacencia.
b) Hallar el vértice con el mayor grado de entrada, en un digrafo representado por una matriz de adyacencia.
c) Determinar si todos los vértices de un grafo almacenado en media matriz de adyacencia (triángulo superior) tienen al menos un vértice adyacente con costo mayor a X (dato).
d) Generar un vector de registros con grado y vértice para aquellos vértices, de un grafo almacenado en una matriz de adyacencia, cuyo grado sea mayor a 3.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"

typedef int Vec[N];

// a)
int grado();
void crearVec(TMat, Vec, int, int);

// b)
int _verticeConMayorGradoEntrada(TMat, int, int, int, int, int);
char verticeConMayorGradoEntrada(TMat);

// c)
int cumple(TMat, int, int, int);

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

    Vec vec;

    crearVec(mat, vec, 0, 0);

    for (int i = 0; i < N; i++)
        printf("%c: %d\n", 'A' + i, vec[i]);

    printf("El vértice con mayor grado de entrada es: %c\n", verticeConMayorGradoEntrada(mat));

    return 0;
}

// a)
void crearVec(TMat mat, Vec vec, int i, int j)
{

    if (i < N)
    {
        if (j < N)
        {
            vec[i] += mat[i][j];
            crearVec(mat, vec, i, j + 1);
        }
        else
            crearVec(mat, vec, i + 1, 0);
    }
}

// b)
char verticeConMayorGradoEntrada(TMat mat)
{
    return _verticeConMayorGradoEntrada(mat, 0, 0, 0, 0, 0) + 'A';
}

int _verticeConMayorGradoEntrada(TMat mat, int i, int j, int grado, int maxVertice, int max)
{
    if (i >= N)
        return maxVertice;

    if (j >= N)
        return _verticeConMayorGradoEntrada(mat, i + 1, 0, 0, grado > max ? i : maxVertice, grado > max ? grado : max);

    return _verticeConMayorGradoEntrada(mat, i, j + 1, grado + mat[i][j], maxVertice, max);
}

// c)
