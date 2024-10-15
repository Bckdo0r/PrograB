#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDA/arboles.h"

/*Dado un árbol binario proveniente de la conversión de un árbol general, obtener el promedio
de las claves cuyo grado era K (dato de entrada).*/

float promedioBosque(arbol, int);
void promedioArbol(arbol, int, int *, int *);
int gradoNodo(arbol);

int main()
{
    arbol a;
    int K;

    addNodo(&a, 1);                                          // A
    addNodo(&a->der, 2);                                     // B
    addNodo(&a->der->izq, 3);                                // C
    addNodo(&a->der->izq->der, 4);                           // D
    addNodo(&a->der->izq->der->izq, 5);                      // E
    addNodo(&a->der->izq->der->izq->der, 6);                 // F
    addNodo(&a->der->izq->der->izq->der->izq, 9);            // I
    addNodo(&a->der->izq->der->izq->der->izq->der, 10);      // J
    addNodo(&a->der->izq->der->izq->der->izq->der->der, 11); // K
    addNodo(&a->der->der, 12);                               // L
    addNodo(&a->der->der->izq, 13);                          // M
    addNodo(&a->der->der->izq->der, 14);                     // N
    addNodo(&a->der->der->izq->der->izq, 15);                // O
    addNodo(&a->der->der->der, 7);                           // G
    addNodo(&a->der->der->der->der, 8);                      // H

    printf("Ingrese K: ");
    scanf("%d", &K);
    printf("Promedio de las claves cuyo grado era %d: %.2f\n", K, promedioBosque(a, K));

    return 0;
}

float promedioBosque(arbol a, int K)
{
    int suma, cont;
    suma = cont = 0;

    while (a != NULL)
    {
        promedioArbol(a->izq, K, &suma, &cont);
        a = a->der;
    }

    return cont == 0 ? 0 : ((float)suma) / cont;
}

void promedioArbol(arbol a, int K, int *suma, int *cont)
{
    if (a != NULL)
    {
        if (gradoNodo(a) == K)
        {
            (*cont)++;
            (*suma) += a->dato;
        }
        promedioArbol(a->izq, K, suma, cont);
        promedioArbol(a->der, K, suma, cont);
    }
}

int gradoNodo(arbol a)
{
    int g = 0;
    if (a == NULL)
        return 0;

    a = a->izq;
    while (a != NULL)
    {
        g++;
        a = a->der;
    }

    return g;
}
