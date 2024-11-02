#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"

void insertarEnLista(Lista *L, char nodo, int peso)
{
    Lista nuevoNodo = (Lista)malloc(sizeof(Vertice));

    nuevoNodo->nodo = nodo;
    nuevoNodo->peso = peso;
    nuevoNodo->sig = *L;
    *L = nuevoNodo;
}

void cargaListaA(TVec V)
{
    int i;

    V[0].nodo = 'A';
    V[0].L = NULL;
    V[1].nodo = 'B';
    V[1].L = NULL;
    V[2].nodo = 'C';
    V[2].L = NULL;
    V[3].nodo = 'D';
    V[3].L = NULL;
    V[4].nodo = 'E';
    V[4].L = NULL;
    V[5].nodo = 'F';
    V[5].L = NULL;
    V[6].nodo = 'G';
    V[6].L = NULL;

    // A -> [D, F]
    insertarEnLista(&V[0].L, 'B', 10);
    insertarEnLista(&V[0].L, 'C', 200);

    // B -> [C]
    insertarEnLista(&V[1].L, 'B', 32);
    insertarEnLista(&V[1].L, 'C', 17);
    insertarEnLista(&V[1].L, 'D', 19);

    // C -> [A, F]
    insertarEnLista(&V[2].L, 'A', 43);
    insertarEnLista(&V[2].L, 'C', 50);
    insertarEnLista(&V[1].L, 'D', 10);


    // D -> [B, F]
    insertarEnLista(&V[3].L, 'A', 62);
    insertarEnLista(&V[3].L, 'B', 7);

    // E -> [D]
    insertarEnLista(&V[4].L, 'F', 18);
    insertarEnLista(&V[1].L, 'G', 10);


    // F -> [D, G]
    insertarEnLista(&V[5].L, 'B', 91);
    insertarEnLista(&V[5].L, 'C', 30);
    insertarEnLista(&V[1].L, 'G', 14);


    // G -> [D, E]
    insertarEnLista(&V[6].L, 'F', 13);
}

void cargaMatriz(TMat mat)
{
    TMat temp = {
        {0, 0, 0, 1, 0, 1, 0},
        {0, 0, 1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0, 1, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 1},
        {0, 0, 0, 1, 1, 0, 0}};

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            mat[i][j] = temp[i][j];
}