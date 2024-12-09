#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "../Practica5/TDAs/colas1.h"
// #include "../Practica7/TDA/N-ario.h"
#define N 7
#define MAX 100

// colas.h
typedef int TElementoC;

// Static
typedef struct
{
    TElementoC datos[MAX];
    int pri, ult;
} TCola;

void iniciaC(TCola *C);
int vaciaC(TCola C);
void poneC(TCola *C, TElementoC x);
TElementoC consultaC(TCola C);
void sacaC(TCola *C, TElementoC *x);

// n-ario.h
#include <stdlib.h>

typedef int TElementoA;
typedef struct nodo
{
    TElementoA dato;
    struct nodo *hijoIzq;
    struct nodo *hermanoDer;
} Nodo, *Arbol;

typedef Nodo *Arbol;
typedef Nodo Posicion; // Definimos Posicion como un puntero a nodo

// Funciones básicas
int Vacio(Arbol A);
int Nulo(Posicion p);
Posicion HijoMasIzq(Posicion p, Arbol A);
Posicion HermanoDer(Posicion p, Arbol A);
TElementoA Info(Posicion p, Arbol A);
Posicion Raiz(Arbol A);
Posicion Padre(Posicion p, Arbol A);

// main.c
typedef int TMat[N][N];

typedef struct nodoD
{
    int num, nivel;
    struct nodoD *ant, *sig;
} nodoD, *PnodoD;

typedef struct
{
    PnodoD pri, ult;
} ListaD;

// Ej.2
void eliminar(TCola *C, int *V)
{
    TElementoC X;
    TCola aux;
    int i, verif;

    iniciaC(&aux);

    while (!vaciaC(*C))
    {
        sacaC(C, &X);
        i = 0;
        verif = 0;

        while (i < N && !verif)
        {
            if (X == V[i])
                verif = 1;

            i++;
        }

        if (verif)
            poneP(&aux, X);
    }

    while (!vaciaC(aux))
    {
        sacaC(&aux, &X);
        poneC(C, X);
    }
}

void procesaDigrafo(TMat M, int i, int j, int *V)
{
    if (j < N)
    {

        if (i < N)
        {
            V[j] += M[i][j] > 0;
            procesaDigrafo(M, i + 1, j, V);
        }
        else
            procesaDigrafo(M, 0, j + 1, V);
    }
}

// Ej. 3
void agregaLD(ListaD *LD, int num, int nivel)
{
    PnodoD act, nuevo = (PnodoD)malloc(sizeof(nodoD));
    nuevo->num = num;
    nuevo->nivel = nivel;
    nuevo->ant = NULL;
    nuevo->sig = NULL;

    if (LD->pri == NULL)
        LD->pri = LD->ult = nuevo;
    else if (nivel < LD->pri->num)
    {
        nuevo->sig = LD->pri;
        LD->pri->ant = nuevo;
        LD->pri = nuevo;
    }
    else if (nivel > LD->ult->num)
    {
        nuevo->ant = LD->ult;
        LD->ult->sig = nuevo;
        LD->ult = nuevo;
    }
    else
    {
        act = LD->pri;

        while (act->nivel < nivel)
            act = act->sig;

        nuevo->sig = act;
        nuevo->ant = act->ant;
        nuevo->ant->sig = nuevo;
        nuevo->sig->ant = nuevo;
    }
}

void generaLD(Arbol A, Posicion p, ListaD *LD, int nivel)
{
    Posicion c;

    if (!Nulo(p))
    {
        c = HijoMasIzq(p, A);

        if (Nulo(c) && nivel % 2 == 1)
            agregaLD(LD, Info(p, A), nivel);
        else
            while (!Nulo(c))
            {
                generaLD(A, c, LD, nivel + 1);
                c = HermanoDer(c, A);
            }
    }
}

// Eliminar de la lista, las claves que se encuentren en el nivel K (dato de entrada), informar la cantidad
// de claves eliminadas de la lista. (la lista esta ordenada por nivel ascendente)
void eliminaLD(ListaD *LD, int K, int *cantElim)
{
    PnodoD act = LD->pri, elim;

    while (act != NULL && act->nivel != K)
        act = act->nivel;

    if (act != NULL)
    {
        while (act != NULL && act->nivel == K)
        {
            elim = act;
            act = act->sig;

            if (elim == LD->pri)
            {
                LD->pri = act;
                if (LD->pri != NULL)
                    LD->pri->ant = NULL;
            }
            else if (elim == LD->ult)
            {
                LD->ult = elim->ant;
                if (LD->ult != NULL)
                    LD->ult->sig = NULL;
            }
            else
            {
                elim->ant->sig = act;
                if (act != NULL)
                    act->ant = elim->ant;
            }

            elim->ant = NULL;
            elim->sig = NULL;

            free(elim);

            (*cantElim)++;
        }
    }
}

int main()
{
    TCola C;
    TMat M;
    ListaD LD;
    Arbol A;
    int V[N];
    int cantElim = 0, K;

    cargaC(&C);
    cargaM(M);

    procesaDigrafo(M, 0, 0, V);
    eliminar(&C, V);

    cargaA(&A);
    generaLD(A, Raiz(A), &LD, 0);

    printf("Ingrese K: ");
    scanf("%d", &K);
    eliminaLD(&LD, K, &cantElim);
    printf("\nSe han eliminado %d nodos\n", cantElim);

    return 0;
}