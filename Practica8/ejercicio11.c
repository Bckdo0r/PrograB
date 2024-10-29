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

void recorreDFS(TMat,int[],TElementoP);
void recorreBFS(TMat,char[]);
void recorreDFS2(TMat);
void cuentaConexas(TMat);
int comparar(const void *, const void *);

int main() {
    int VecDNF[N]={0},VecBFS[N]={0};
    TMat mat = {
        {0, 0, 1, 1, 0, 1, 0},
        {0, 0, 1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0, 1, 0},
        {1, 1, 0, 0, 1, 1, 1},
        {0, 0, 0, 1, 0, 0, 1},
        {1, 0, 1, 1, 0, 0, 1},
        {0, 0, 0, 1, 1, 1, 0}};

    TMat M = {
        {0, 1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1, 0}
    };    

    //printf("Recorrido BFS (en amplitud)\n");
    //recorreBFS(mat,VecBFS);
    //printf("\n");
    printf("Recorrido DFS (en profundidad)\n");
    recorreDFS(mat,VecDNF,0);
    printf("\n");
    cuentaConexas(M);
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

void recorreDFS(TMat M,int vec[],TElementoP x){
    TPila P;
    int j,verif;

    iniciaP(&P);
    poneP(&P,x);
    vec[x] = 1;
    //printf("%c ",(char)x + 'A');
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
            //printf("%c ",(char)(j + 'A'));
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

int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void cuentaConexas(TMat M){
    int cont = 0 ,i,j;
    int sumaIdx[N] = {0};

    for (i=0; i<N ;i++){
        int vec[N] = {0};
        recorreDFS(M,vec,i);
        for (j=0; j<N ;j++)
            if (vec[j]==1)
                sumaIdx[i]+=j;        
    }
    qsort(sumaIdx,N,sizeof(int),comparar); //! ??
    
    // Siempre hay al menos un número único
    for (i=0; i<N-1 ; i++) {
        if (sumaIdx[i] != sumaIdx[i + 1]) {
            cont++;
        }
    }
    printf("La cantidad de componentes conexas son: %d\n",cont);
}