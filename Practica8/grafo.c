#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"

void insertarEnLista(Lista *L, char nodo)
{
    Lista nuevoNodo = (Lista)malloc(sizeof(nodoL));

    nuevoNodo->nodo = nodo;
    nuevoNodo->sig = *L;
    *L = nuevoNodo;
}

void cargaLista(TVec V)
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