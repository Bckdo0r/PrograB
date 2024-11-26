#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Practica8/grafo.h"
#include "../Practica5/TDAs/colas1.h"
#include "../Practica5/TDAs/pilas0.h"

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

void BFS1(TMat M,int V,VecV Vec){
    TCola C;
    int i;
    TElementoC x;

    iniciaC(&C);
    poneC(&C,V);

    while(!vaciaC(C)){
        sacaC(&C,&x);

        if (Vec[x] == 0)
            Vec[x] = 1;

        for(i = 0; i < N ;i++)
            if (M[x][i] && !Vec[i])
                poneC(&C,i);
    }
}

void BFS2(VecAdy VAdy,int V,VecV Vec){
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

void DFS1(TMat M,int V,VecV Vec){
    TPila P;
    TElementoP x;
    int i;

    iniciaP(&P);
    poneP(&P,V);

    while(!vaciaP(P)){
        sacaP(&P,&x);

        if (!Vec[x])
            Vec[x] = 1;

        for(i = 0; i < N ;i++)
            if (M[x][i] && !Vec[i])
                poneP(&P,i);     
    }    
}

void DFS2(VecAdy VAdy,int V,VecV Vec){
    TPila P;
    TElementoP x;
    pLista L;

    iniciaP(&P);
    poneP(&P,V);

    while(!vaciaP(P)){
        sacaP(&P,&x);

        if(!Vec[x])
            Vec[x] = 1;

        L = VAdy[x].L;
        while(L != NULL){
            if(!Vec[L->v])
                poneP(&P,L->v);

            L = L->sig;    
        }
    }
}

void DFSRecu1(TMat M,int V,VecV Vec){
    int i;
    
    if (!Vec[V])
        Vec[V] = 1;

    for (i = 0; i < N ;i++)
        if (M[V][i] && !Vec[i])
            DFSRecu1(M,i,Vec);    
}

void DFSRecu2(VecAdy VAdy,int V,VecV Vec){
    pLista L;

    if (!Vec[V])
        Vec[V] = 1;

    L = VAdy[V].L;
    while(L != NULL){
        if (!Vec[L->v])
            DFSRecu2(VAdy,L->v,Vec);

        L = L->sig;    
    }    
}

void RecorreMediaMat(TMat M,int *Gr){
    int i,j,V = 0;

    while (V < N){ //! Triangulo Superior
        i = 0;
        while (i < V){
            M[i][V];
            i++;
        }

        j = i; //* en este caso se tiene en cuenta la diagonal. Si no fuera el caso, seria: j = i + 1;
        while (j < N){
            M[V][j];   
            j++;
        }
        
        V++;        
    }

    while (V > 0){ //! Triangulo Inferior
        i = N;
        while (i > V){
            M[i][V]; 
            i--;
        }

        j = i; //* en este caso se tiene en cuenta la diagonal. Si no fuera el caso, seria: j = i + 1;
        while (j > N){
            M[V][j];
            j--;
        }

        V--;        
    }

}

int main() {


    return 0;
}