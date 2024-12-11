#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../Practica7/TDA/N-ario.h"
#include "../Practica7/TDA/arboles.h"
#include "../Practica8/grafo.h"
#define ZONAS 10

// pilas.h
#define MAX 100

typedef struct
{
    st10 FechaHora;
    st7 Patente;
} TElementoP;

typedef struct
{
    TElementoP datos[MAX];
    int tope;
} TPila;

// main.c
typedef char st4[5];
typedef char st7[8];
typedef char st10[11];

typedef struct nodoD
{
    unsigned short int Zona;
    st4 Cod;
    TPila Infracciones;
    struct nodo *ant, *sig;
} nodoD, *PnodoD;

typedef struct
{
    PnodoD pri, ult;
} ListaD;

typedef struct nodoC
{
    unsigned short int Zona;
    unsigned int Radares, Camaras;
    struct nodoC *sig;
} nodoC, *ListaC;

typedef struct
{
    unsigned short int Zona;
    PnodoD nodoRadar, nodoCamara;
} REG;

// Ej.2
int esRadar(PnodoD act)
{
    return act->Cod[0] == 'R';
}

void cantInfracciones(TPila *P, int *cant, int validar)
{
    TElementoP X;
    st10 f;

    if (!vaciaP(*P))
    {
        sacaP(P, &X);
        cantInfracciones(P, *cant, validar);
        poneP(P, X);
        strcpy(f, X.FechaHora);
        if (!validar || f[0] == 1 && f[1] == 2 && f[2] == 1 && f[3] == 9)
            (*cant)++;
    }
}

void cantRadares(ListaD LD, int *cant)
{
    PnodoD act = LD.pri;

    while (act != NULL)
    {
        if (esRadar(act) && act->Zona % 2 == 0)
            cantInfracciones(&act->Infracciones, cant, 1);

        act = act->sig;
    }
}

void agregaLC(ListaC *LC, int Zona, int Radares, int Camaras)
{
    ListaC act, ant, nuevo = (ListaC)malloc(sizeof(nodoC));
    nuevo->Zona = Zona;
    nuevo->Radares = Radares;
    nuevo->Camaras = Camaras;

    if (*LC == NULL)
    {
        *LC = nuevo;
        nuevo->sig = nuevo;
    }
    else if (Zona > (*LC)->Zona)
    {
        nuevo->sig = (*LC)->sig;
        (*LC)->sig = nuevo;
        *LC = nuevo;
    }
    else
    {
        act = (*LC)->sig;
        ant = *LC;

        while (act->Zona < Zona)
        {
            ant = act;
            act = act->sig;
        }

        nuevo->sig = act;
        ant->sig = nuevo;
    }
}

void generaLC(ListaD LD, ListaC *LC)
{
    PnodoD act = LD.pri;
    REG V[ZONAS];
    int camaras, radares;

    while (act != NULL)
    {
        V[act->Zona].Zona = act->Zona;

        if (esRadar(act))
            V[act->Zona].nodoRadar = act;
        else
            V[act->Zona].nodoCamara = act;

        act = act->sig;
    }

    for (int i = 0; i < ZONAS; i++)
    {
        REG R = V[i];
        radares = camaras = 0;
        if (R.nodoRadar != NULL && R.nodoCamara != NULL)
        {
            cantInfracciones(&R.nodoRadar->Infracciones, &radares, 0);
            cantInfracciones(&R.nodoCamara->Infracciones, &camaras, 0);
            agregaLC(LC, R.Zona, radares, camaras);
        }
    }
}

// Ej.3
int esVocal(char c)
{
    c = toupper(c);
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

int cantCumplen(Arbol A, Posicion p, int nivel)
{
    Posicion c;
    int cant = 0, len;
    char *cad;

    if (Nulo(p))
        return 0;

    c = HijoMasIzq(p, A);
    while (!Nulo(c))
    {
        cant += cantCumplen(A, c, nivel + 1);
        c = HermanoDer(c, A);
    }

    strcpy(cad, Info(p, A));
    len = strlen(cad);
    return cant + (nivel % 2 == 1 && len % 2 == 1 && esVocal(cad[0]) && esVocal(cad[len - 1]));
}

// Ej.4
int esta(arbol0 A, int X)
{
    if (A == NULL)
        return 0;

    if (X == A->dato)
        return 1;

    if (X < A->dato)
        return esta(A->izq, X);

    return esta(A->der, X);
}

int verticesCumplen(TMat M, int i, int j, int grE, arbol0 A)
{
    if (j >= N) // Si me pasé, retorno 1 para no arruinar el resultado acumulado.
        return 1;

    if (M[j][j] == 0) // No chequeo vértices sin bucle
        return verticesCumplen(M, 0, j + 1, 0, A);

    if (i < N) // Acumulo el grado de entrada
        return verticesCumplen(M, i + 1, j, grE + M[i][j], A);

    return esta(A, grE) && verticesCumplen(M, 0, j + 1, 0, A); // Chequeo si todos los vértices cumplen
}

int main()
{
    ListaD LD;
    ListaC LC;
    Arbol A;
    int cant = 0;

    cargaLD(&LD);
    cantRadares(LD, &cant);
    printf("\nLa cantidad de radares que cumplen lo pedido es: %d", cant);

    generaLC(LD, &LC);

    printf("\nLa cantidad de nodos del árbol que cumplen lo pedido es: %d", cantCumplen(A, Raiz(A), 0));

    return 0;
}