/*
Desarrollar un subprograma que reciba como parámetro una matriz de adyacencia que
representa un digrafo sin aristas ponderadas y retorne en la misma matriz el grafo subyacente. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void funcionInsana(int mat[7][7],int N){
    int i,j;

    for (i=0; i<N ;i++)
        for (j=0; j<N ;j++){
            if (mat[i][j] == 1 || mat[j][i] == 1) {     
                mat[i][j] = 1;
                mat[j][i] = 1;
            }
        }
}

int main() {
    
    int i,j,N=7,temp[7][7] = {
        {0, 0, 0, 1, 0, 1, 0},
        {0, 0, 1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0, 1, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 1},
        {0, 0, 0, 1, 1, 0, 0}
    };

    funcionInsana(temp,7);

    for (i=0; i<N ;i++){
        for (j=0; j<N ;j++)
            printf("%d ",temp[i][j]);
        printf("\n");
    }
            
    return 0;
}