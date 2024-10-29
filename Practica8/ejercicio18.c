/*
Para un digrafo dado, desarrollar un programa que genere la matriz de alcance R a partir de la
matriz A resultante del algoritmo de Floyd. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 9999
#define N 4

typedef int TMat[N][N]; 

void floydWarshall(TMat);
void matrizR(TMat,TMat);

int main() {
    
    TMat R;

    TMat A = {
        {0, 1, 4, INF},
        {INF, 0, 2, INF},
        {INF, INF, 0, 3},
        {INF, 5, INF, 0}
    };

    floydWarshall(A);
    matrizR(A,R);

    for (int i=0; i<N ;i++){
        for (int j=0; j<N ;j++)
            printf("%d ",R[i][j]);
        printf("\n");
    }

    return 0;
}

void matrizR(TMat A,TMat R){
    int i,j;

    for (i=0; i<N ;i++)
        for (j=0; j<N ;j++)
            R[i][j] = (A[i][j] == INF)? 0:1;
}

void floydWarshall(TMat A) {
    int k,j,i;
    for (k = 0; k < N; k++) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                if (A[i][k] != INF && A[k][j] != INF) {
                    if (A[i][j] > A[i][k] + A[k][j]) {
                        A[i][j] = A[i][k] + A[k][j];
                    }
                }
            }
        }
    }
}