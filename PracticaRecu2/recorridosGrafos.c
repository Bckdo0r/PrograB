#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Practica8/grafo.h"
#include "../Practica5/TDAs/colas1.h"

typedef int VecV[MAX];

typedef struct nodo{
    int v;
    struct nodo *sig;
} nodoL;

typedef nodoL *pLista;

typedef struct{
    int Vertice;
    pLista L;
} reg;

typedef reg VecAdy[MAX];

void BFSMatriz(TMat M,int V,VecV Vec){
    TCola C;
    int i;
    TElementoC x;

    iniciaC(&C);
    poneC(&C,V);

    while(!vaciaC(C)){
        sacaC(&C,&x);
        i = 0;

        if (Vec[x] == 0)
            Vec[x] = 1;

        while(i<N){
            if (M[x][i] && !Vec[i])
                poneC(&C,i);
            
            i++;
        }
    }
}

void BFSListaAdy(VecAdy VAdy,int V,VecV Vec){
    TCola C;
    TElementoC x;
    pLista L;

    iniciaC(&C);
    poneC(&C,V);

    while(!vaciaC(C)){
        sacaC(&C,&x);

        if(Vec[x] == 0)
            Vec[x] = 1;

        L = VAdy[x].L;
        while (L != NULL){
            if (!Vec[L->v])
                poneC(&C,L->v);
            L = L->sig;    
        }    
    }
}

int main() {


    return 0;
}