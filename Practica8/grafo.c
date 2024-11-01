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
    insertarEnLista(&V[0].L, 'F', 1);
    insertarEnLista(&V[0].L, 'D', 2);

    // B -> [C]
    insertarEnLista(&V[1].L, 'C', 3);

    // C -> [A, F]
    insertarEnLista(&V[2].L, 'F', 4);
    insertarEnLista(&V[2].L, 'A', 5);

    // D -> [B, F]
    insertarEnLista(&V[3].L, 'F', 6);
    insertarEnLista(&V[3].L, 'B', 7);

    // E -> [D]
    insertarEnLista(&V[4].L, 'D', 8);

    // F -> [D, G]
    insertarEnLista(&V[5].L, 'G', 9);
    insertarEnLista(&V[5].L, 'D', 10);

    // G -> [D, E]
    insertarEnLista(&V[6].L, 'E', 11);
    insertarEnLista(&V[6].L, 'D', 12);
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