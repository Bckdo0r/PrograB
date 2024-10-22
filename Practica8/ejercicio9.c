/*
Hallar el vértice con el mayor grado de entrada, en un digrafo representado por una lista de
adyacencia. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 7

typedef struct nodo{
    char nodo;
    struct nodo *sig;
}nodoL;

typedef nodoL *Lista;

typedef struct{
    char nodo;
    Lista L;
}reg;

typedef struct{
    char nodo;
    int grE;
}grados;

typedef grados VecGrE[N];
typedef reg TVec[N];

void insertarEnLista(Lista *L, char nodo) {
    Lista nuevoNodo = (Lista)malloc(sizeof(nodoL));
    
    nuevoNodo->nodo = nodo;
    nuevoNodo->sig = *L;
    *L = nuevoNodo;
}

void carga(TVec V, VecGrE VGr) {
    int i;

    // Inicializar los nodos del grafo
    V[0].nodo = 'A'; V[0].L = NULL;
    V[1].nodo = 'B'; V[1].L = NULL;
    V[2].nodo = 'C'; V[2].L = NULL;
    V[3].nodo = 'D'; V[3].L = NULL;
    V[4].nodo = 'E'; V[4].L = NULL;
    V[5].nodo = 'F'; V[5].L = NULL;
    V[6].nodo = 'G'; V[6].L = NULL;

    // Cargar adyacencias
    // A -> [D, F]
    insertarEnLista(&V[0].L, 'F');
    insertarEnLista(&V[0].L, 'D');

    // B -> [C]
    insertarEnLista(&V[1].L, 'C');

    // C -> [A, F]
    insertarEnLista(&V[2].L, 'F');
    insertarEnLista(&V[2].L, 'A');

    // D -> [B, F]
    insertarEnLista(&V[3].L, 'F');
    insertarEnLista(&V[3].L, 'B');

    // E -> [D]
    insertarEnLista(&V[4].L, 'D');

    // F -> [D, G]
    insertarEnLista(&V[5].L, 'G');
    insertarEnLista(&V[5].L, 'D');

    // G -> [D, E]
    insertarEnLista(&V[6].L, 'E');
    insertarEnLista(&V[6].L, 'D');

    for (i=0; i<N ;i++)
        VGr[i].grE = 0;

    VGr[0].nodo = 'A';
    VGr[1].nodo = 'B';
    VGr[2].nodo = 'C';
    VGr[3].nodo = 'D';
    VGr[4].nodo = 'E';
    VGr[5].nodo = 'F';
    VGr[6].nodo = 'G';    
}

char verticeMayorGrE(TVec vec,);

int main() {


    return 0;
}