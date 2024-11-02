#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Practica8/grafo.h"

// EJ 3)
/* Dado un digrafo con |V| = N con aristas ponderadas almacenado en una lista de ady, determinar cuál es el vértice que, conteniendo bucle, 
tiene el mayor costo promedio de las aristas que llegan a el desde otros vertices. */

typedef struct
{
    int peso, CantAr,bucle;
} HASH;

char Determina(TVec Vec)
{
    char V, VMax = 0;
    Lista sub;
    HASH hashMap[N];
    int i;
    float prom = 0, maxProm = 0;

    for (i = 0; i < N; i++)
    {
        hashMap[i].peso = 0;
        hashMap[i].CantAr = 0;
    }

    for (i = 0; i < N; i++)
    {
        sub = Vec[i].L;
        V = Vec[i].nodo;
        hashMap[V - 'A'].bucle = 0;

        while (sub != NULL)
        {
            if (V == sub->nodo)
                hashMap[V - 'A'].bucle = 1;

            hashMap[sub->nodo - 'A'].peso += sub->peso;
            hashMap[sub->nodo - 'A'].CantAr++;

            sub = sub->sig;
        }
    }

    for (i = 0; i < N; i++)
    {
        prom = hashMap[i].bucle ? ((float)hashMap[i].peso / hashMap[i].CantAr) : 0;
        if (prom > maxProm)
        {
            maxProm = prom;
            V = i + 'A';
        }
    }

    return maxProm ? V : '-';
}

int main()
{

    TVec V;

    cargaListaA(V);

    printf("%c\n", Determina(V));

    return 0;
}