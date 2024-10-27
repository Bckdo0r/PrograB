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

void recorreDFS(TMat,char[]);
void recorreBFS(TMat,char[]);
void recorreDFS2(TMat);
void cuentaConexas(TMat);

int main() {
    char VecDNF[N]={},VecBFS[N]={};
    TMat mat = {
        {0, 0, 1, 1, 0, 1, 0},
        {0, 0, 1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0, 1, 0},
        {1, 1, 0, 0, 1, 1, 1},
        {0, 0, 0, 1, 0, 0, 1},
        {1, 0, 1, 1, 0, 0, 1},
        {0, 0, 0, 1, 1, 1, 0}};

    printf("Recorrido BFS (en amplitud)\n");
    recorreBFS(mat,VecBFS);
    printf("\n");
    printf("Recorrido DFS (en profundidad)\n");
    recorreDFS(mat,VecDNF);
    printf("\n");
    return 0;
}

void recorreBFS(TMat M,char orden[]){
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

void recorreDFS(TMat M,char orden[]){
    TPila P;
    int j,verif;
    int vec[N] = {0,0,0,0,0,0,0};
    TElementoP x = 0,aux;

    iniciaP(&P);
    poneP(&P,x);
    vec[x] = 1;
    printf("%c ",(char)x + 'A');
    while(!vaciaP(P)){
        
        j = 0;
        verif = 0;
        while(!verif){
            
            if (M[x][j] != 0 && vec[j] == 0 || j == N)
                verif=1; 
            else
                j++;    
        }

        if (j<N && vec[j]==0){
            poneP(&P,x);
            printf("%c ",(char)(j + 'A'));
            poneP(&P,j);
            vec[j] = 1;
            x = j;    
        }
        else
            sacaP(&P,&x);

    }
}

void recorreDFS2(TMat M){
    TPila P;
    int j;
    int vec[N] = {0,0,0,0,0,0,0};
    TElementoP x = 0, aux;

    iniciaP(&P);
    poneP(&P, x);
    vec[x] = 1;
    printf("%c ", x + 'A');
    
    while (!vaciaP(P)) {
        int encontrado = 0;
        j = 0;
        
        // Busca el primer vecino no visitado
        while (j < N) {
            if (M[x][j] != 0 && vec[j] == 0) {  // Encuentra un vecino no visitado
                encontrado = 1;
                break;
            }
            j++;
        }
        
        if (encontrado) {
            poneP(&P, x);      // Guarda el vértice actual en la pila
            printf("%c ", j + 'A');  // Imprime el vecino encontrado
            vec[j] = 1;        // Marca el vecino como visitado
            x = j;             // Mueve el cursor al vecino
        } else {
            sacaP(&P, &x);     // Retrocede si no hay vecinos no visitados
        }
    }
}

void cuentaConexas(TMat M){
    int cont;

}