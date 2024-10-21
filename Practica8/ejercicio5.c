/*
Dado un vértice determinado de un digrafo representado en una matriz de adyacencia,
implementar funciones que devuelvan:
a) su grado de entrada
b) su grado de salida
c) el grado de dicho vértice
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 7

int retornaGrE(int [N][N],int);
int retornaGrS(int [N][N],int);
int retornaGrVer(int [N][N],int);

int main() {
    //vertice D
    int V=3,mat[N][N] = {
        {0, 0, 0, 1, 0, 1, 0},
        {0, 0, 1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0, 1, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 1},
        {0, 0, 0, 1, 1, 0, 0}
    };

    printf("%d\n",retornaGrE(mat,V));
    printf("%d\n",retornaGrS(mat,V));
    printf("%d\n",retornaGrVer(mat,V));

    return 0;
}

int retornaGrE(int mat[N][N],int V){
    int j,cont=0;

        for (j=0; j<N ;j++)
            cont += mat[j][V];
    return cont;        
}

int retornaGrS(int mat[N][N],int V){
    int i,cont=0;

        for (i=0; i<N ;i++)
            cont += mat[V][i];
    return cont;        
}

int retornaGrVer(int mat[N][N],int V){
    return retornaGrE(mat,V) + retornaGrS(mat,V) - mat[V][V];
}
