/* 
Para un grafo almacenado en una matriz de adyacencia, desarrollar funciones para:
    a) mostrar todos sus vértices mediante recorrido en profundidad
    b) mostrar todos sus vértices mediante recorrido en amplitud
    c) devolver la cantidad de componentes conexas
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Practica5/TDAs/colas.h"
#include "../Practica5/TDAs/pilasD.h"
#include "grafo.h"

void recorreDFS(TMat);
void recorreBFS(TMat);

int main() {

    TMat mat = {
        {0, 0, 1, 1, 0, 1, 0},
        {0, 0, 1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0, 1, 0},
        {1, 1, 0, 0, 1, 1, 1},
        {0, 0, 0, 1, 0, 0, 1},
        {1, 0, 1, 1, 0, 0, 1},
        {0, 0, 0, 1, 1, 1, 0}};

    printf("Recorrido BFS (en amplitud)\n");
    recorreBFS(mat);
    printf("\n");
    printf("Recorrido BFS (en profundidad)\n");
    recorreDFS(mat);
    return 0;
}

void recorreBFS(TMat M){
    TCola C;
    int j;
    int vec[N] = {0,0,0,0,0,0,0};
    TElementoC x,aux;
    x.V = 0;

    iniciaC(&C);
    poneC(&C,x);
    while (!vaciaC(C)){
        sacaC(&C,&x);
        if (vec[x.V] == 0){
            vec[x.V] = 1;
            printf("%c ",x.V + 'A');
            for (j = 0; j<N ;j++)
                if (M[x.V][j] != 0 && vec[j] == 0){
                    aux.V = j;
                    poneC(&C,aux);
                }
        }
        
    }

}

void recorreDFS(TMat M){
    TPila P;
    int j;
    int vec[N] = {0,0,0,0,0,0,0};
    TElementoP x=0,aux;

    iniciaP(&P);
    poneP(&P,x);
    while(!vaciaP(P)){

        j = 0;
        while(j<N && M[x][j] == 0 && vec[j] == 0)
            j++;

        if (j<N){
            printf("%c ",x + 'A');
            vec[j] = 1;
            poneP(&P,x);
            x = j;    
        }
        else
            sacaP(&P,&x);

    }
}