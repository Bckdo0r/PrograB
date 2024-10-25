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
void crearVec(TMat, Vec, int, int);

// b)
int _verticeConMayorGradoEntrada(TMat, int, int, int, int, int);
char verticeConMayorGradoEntrada(TMat);

// c)
int cumple(TMat, int,int,int,int,int);

int main()
{
    int X = 2;
    TMat mat = {
        {0, 0, 1, 1, 0, 1, 0},
        {0, 0, 1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0, 1, 0},
        {1, 1, 0, 0, 1, 1, 1},
        {0, 0, 0, 1, 0, 0, 1},
        {1, 0, 1, 1, 0, 0, 1},
        {0, 0, 0, 1, 1, 1, 0}};

    int matriz[N][N] = {
        {0, 4, 0, 7, 3, 0, 5}, // A -> B, D, E, G
        {0, 0, 5, 0, 6, 1, 0}, // B -> C, E, F
        {0, 0, 0, 2, 8, 0, 3}, // C -> D, E, G
        {0, 0, 0, 0, 9, 4, 0}, // D -> E, F
        {0, 0, 0, 0, 0, 7, 2}, // E -> F, G
        {0, 0, 0, 0, 0, 0, 6}, // F -> G
        {0, 0, 0, 0, 0, 0, 0}  // G -> (Ninguno)
    };    

    Vec vec = {0,0,0,0,0,0,0};

    crearVec(mat, vec, 0, 0);

    for (int i = 0; i < N; i++)
        printf("%c: %d\n", 'A' + i, vec[i]);

    printf("El vértice con mayor grado de entrada es: %c\n", verticeConMayorGradoEntrada(mat));
    printf("Todos los vertices del grafo %s cumplen la condicion pedida.\n",cumple(matriz,0,0,N-1,N-1,X) ? "SI":"NO");

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
int cumple(TMat M,int i,int j,int f,int c,int X){
    if (i > N && c < 1) //recorri toda la media matriz;
        return 1;
    else{
        
        if (j>N)
            return M[i][j] > X ? cumple(M,i+1,i+1,f,c,X) : cumple(M,i,j+1,f,c,X);
        else if (f>0)
            return M[f][c] > X ? cumple(M,i,j,c-1,c-1,X) : cumple(M,i,j,f-1,c,X);
        else
            return 0; 
    }
}