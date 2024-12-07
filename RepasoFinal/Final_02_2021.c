#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Practica8/grafo.h"
#include "../Practica5/TDAs/pilas0.h"

typedef struct nodito
{
    int num;
    struct nodito *sig;
} nodito, *SubLista;

typedef struct nodoD
{
    int num;
    SubLista sub;
    struct nodoD *ant, *sig;
} nodoD, *PnodoD;

typedef struct
{
    PnodoD pri, ult;
} ListaD;

int main()
{

    return 0;
}

/*
Ej 2.- Suponer una lista doblemente enlazada LDE en la que cada elemento contiene un
número N entero positivo (no se repiten) y una sublista con valores enteros que se supone son
divisores de N. Se pide, definir tipos e implementar:
i) Dado K, verificar si todos los elementos de la sublista del nodo que contiene K son sus
divisores. Eliminar los que no lo sean. Informar la situación.
ii) Dado X, generar un archivo de texto DIVI.TXT con los valores de la lista que sean pares y
tienen exactamente X divisores. Colocar un valor por línea.
*/

PnodoD busca(ListaD LDE, int K)
{
    PnodoD act = LDE.pri;

    while (act != NULL && act->num != K)
        act = act->sig;

    return act != NULL ? act : NULL;
}

void verifica(ListaD LDE, int K)
{
    PnodoD act;
    SubLista actS, antS = NULL, elimS;
    int cumple = 1;

    act = busca(LDE, K);

    if (act != NULL)
    {
        actS = act->sub;

        while (actS != NULL)
        {
            if (act->num % actS->num != 0)
            {
                cumple = 0;
                elimS = actS;
                actS = actS->sig;

                if (elimS == act->sub)
                    act->sub = actS;
                else
                    antS->sig = actS;

                free(elimS);

                printf("Se eliminó el número %d de la SubLista", actS->num);
            }
            else
            {
                antS = actS;
                actS = actS->sig;
            }
        }

        if (cumple)
            printf("Todos los numeros de la sublista de son divisores");
        else
            printf("No todos los numeros de la sublista eran divisores");
    }
    else
        printf("No se encontró el nodo %d", K);
}

/*
Dado X, generar un archivo de texto DIVI.TXT con los valores de la lista que sean pares y
tienen exactamente X divisores. Colocar un valor por línea.
*/
void generaArch(ListaD LDE, int X)
{
    PnodoD act = LDE.pri;
    SubLista sub;
    FILE *arch = fopen("DIVI.TXT", "w");

    if (arch == NULL)
        printf("Error");
    else
    {

        while (act != NULL)
        {
            if (act->num % 2 == 0 && tieneXDivisores(act->sub, X))
                fscanf(arch, "%d\n", act->num);

            act = act->sig;
        }

        fclose(arch);
    }
}

int tieneXDivisores(SubLista sub, int X)
{
    int divisores = 0;

    while (sub != NULL && divisores <= X)
    {
        divisores++;
        sub = sub->sig;
    }

    return sub == NULL && divisores == X;
}

/*
Ej.4 Dado un digrafo con aristas ponderadas implementado en una lista de
adyacencia, y una pila P en la que cada elemento contiene un peso y un vértice. Se pide definir
tipos y desarrollar una solución recursiva sobre la Pila que elimine de la misma
aquellos vértices cuyo peso sea menor que el costo total de las aristas que se vinculan con él que
no son bucles.
*/
void eliminaPila(TVec V, TPila *P)
{
    TElementoP X;
    int costo = 0, esBucle = 0;

    if (!vaciaP(*P))
    {
        sacaP(P, &X);
        eliminaPila(V, P);
        costoTotal(V[X.vertice], &costo, &esBucle);
        if (!esBucle && X.peso >= costo)
            poneP(P, X);
    }
}

void costoTotal(AdyReg reg, int *costo, int *esBucle)
{
    Lista L = reg.L;
    while (L != NULL && !(*esBucle))
    {
        if (!(*esBucle))
            *esBucle = L->nodo == reg.nodo;
        (*costo) += L->peso;
        L = L->sig;
    }
}