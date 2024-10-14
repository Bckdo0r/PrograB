/* El draw de un torneo de tenis se representa mediante un árbol binario invertido. Desarrollar
subprogramas que muestren:
a) el nombre del ganador.
b) los nombres de los 2 finalistas.
c) los nombres de los 4 semifinalistas.
d) los nombres de todos los competidores y la cantidad. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDA/arboles.h"

void muestraNodo(arbol a);
void muestraFinal(arbol a);
void muestraSemi(arbol a);
void muestraParticipantes(arbol a, int *);

int main()
{
    arbol A;
    int cant = 0;

    addNodo(&A, "Djokovic");
    addNodo(&A->der, "Sinner");
    addNodo(&A->izq, "Djokovic");
    addNodo(&A->der->der, "Sinner");
    addNodo(&A->izq->izq, "Rune");
    addNodo(&A->izq->der, "Djokovic");
    addNodo(&A->der->izq, "Alcaraz");
    addNodo(&A->izq->der->izq, "Djokovic");
    addNodo(&A->izq->der->der, "Fritz");
    addNodo(&A->der->izq->izq, "Paul");
    addNodo(&A->der->izq->der, "Alcaraz");
    addNodo(&A->der->der->izq, "Sinner");
    addNodo(&A->der->der->der, "Rublev");
    addNodo(&A->izq->izq->der, "Dimitrov");
    addNodo(&A->izq->izq->izq, "Rune");
    muestraNodo(A);
    printf("====================\n");
    // muestraFinal(A);
    // muestraSemi(A);
    muestraParticipantes(A, &cant);
    printf("Cantidad de jugadores: %d\n", cant);

    return 0;
}

void muestraNodo(arbol A)
{
    printf("%s\n", A->dato);
}

void muestraParticipantes(arbol A, int *cant)
{
    if (A != NULL)
    {
        if (A->izq == NULL && A->der == NULL)
        {
            muestraNodo(A);
            (*cant)++;
        }
        muestraParticipantes(A->izq, cant);
        muestraParticipantes(A->der, cant);
    }
}