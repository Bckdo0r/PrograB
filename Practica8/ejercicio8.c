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

typedef struct{
    int gr;
    char V;
} registro;

typedef registro VecReg[N];

typedef int Vec [N];

// a)
void crearVec(TMat, Vec, int, int);

void creaVecReg(TMat,VecReg,int *,int,int,int,int);
// b)
int _verticeConMayorGradoEntrada(TMat, int, int, int, int, int);
char verticeConMayorGradoEntrada(TMat);

// c)
int cumple(TMat, int,int,int,int);

int main()
{
    VecReg vec2;
    int k = 0,X = 2; 
    TMat mat = {
        {0, 0, 1, 1, 0, 1, 0},
        {0, 0, 1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0, 1, 0},
        {1, 1, 0, 0, 1, 1, 1},
        {0, 0, 0, 1, 0, 0, 1},
        {1, 0, 1, 1, 0, 0, 1},
        {0, 0, 0, 1, 1, 1, 0}};

    TMat matriz = {
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
    printf("Todos los vertices del grafo %s cumplen la condicion pedida.\n",cumple(matriz,0,0,0,X) ? "SI":"NO");
    creaVecReg(mat,vec2,&k,0,0,0,X);

    for (int i = 0; i < k; i++)
        printf("Vertice %c: %d\n",vec2[i].V,vec2[i].gr);

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

/*
    c)
    {0, 4, 0, 7, 3, 0, 5}, 
    {0, 0, 5, 0, 6, 1, 0}, 
    {0, 0, 0, 2, 8, 0, 3}, 
    {0, 0, 0, 0, 9, 4, 0}, 
    {0, 0, 0, 0, 0, 7, 2}, 
    {0, 0, 0, 0, 0, 0, 6}, 
    {0, 0, 0, 0, 0, 0, 0}

*/ 
int cumple(TMat M,int i,int j,int V,int X){
    if (V >= N ) //recorri toda la media matriz;
        return 1;
    else     
        if (i<V)
            if (M[i][j] > X)
                return cumple(M,0,V+1,V+1,X);    
            else
                return cumple(M,i+1,j,V,X);

        else if (j<N)
            if (M[i][j] > X)   
                return cumple(M,0,V+1,V+1,X);    
            else
                return cumple(M,i,j+1,V,X);
        else
            return 0;    
}

void creaVecReg(TMat M,VecReg vec,int *k,int i,int j,int grV,int x){
    if (i < N){
        if (j<N)
            if (M[i][j] > 0)
                creaVecReg(M,vec,k,i,j+1,grV+1,x);
            else
                creaVecReg(M,vec,k,i,j+1,grV,x);    
        else{
            if (grV > x){
                vec[*k].gr = grV;
                vec[*k].V = 'A' + i;
                (*k)++;
            }
            
            creaVecReg(M,vec,k,i+1,0,0,x);    
        }
    }
}