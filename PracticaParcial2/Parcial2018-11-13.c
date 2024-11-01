#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Practica8/grafo.h"

// EJ 3)
// Dado un digrafo con |V| = N con aristas ponderadas almacenado en una lista de ady, determinar cuál es el vértice que, conteniendo bucle, tiene el mayor costo promedio
// de las aristas que llegan a el desde otros vertices.

typedef struct
{
    int peso, aristas;
} HASH;

char Determina(TVec Vec)
{
    char V, VMax = 0;
    Lista sub;
    HASH hashMap[N];
    int bucle, i;
    float prom = 0, maxProm = 0;

    for (i = 0; i < N; i++)
    {
        hashMap[i].peso = 0;
        hashMap[i].aristas = 0;
    }

    for (i = 0; i < N; i++)
    {
        sub = Vec[i].L;
        V = Vec[i].nodo;
        bucle = 0;

        while (sub != NULL)
        {
            if (!bucle)
                bucle = V == sub->nodo;

            hashMap[sub->nodo - 'A'].peso += sub->peso;
            hashMap[sub->nodo - 'A'].aristas++;

            sub = sub->sig;
        }

        if (!bucle)
            hashMap[V - 'A'].peso = 0;
    }

    for (i = 0; i < N; i++)
    {
        printf("%c: %d %d\n", i + 'A', hashMap[i].peso, hashMap[i].aristas);
        prom = ((float)hashMap[i].peso / hashMap[i].aristas);
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

    cargaLista(V);

    printf("%c", Determina(V));

    return 0;
}