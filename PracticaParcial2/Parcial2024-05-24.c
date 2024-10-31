#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Practica7/TDA/arboles.h"
#define N 5

typedef int TMat[N][N];

// EJ 1)
int Grado(arbol A)
{
    int grado = 0;

    if (A == NULL)
        return 0;

    A = A->izq;

    while (A != NULL)
    {
        grado++;
        A = A->der;
    }

    return grado;
}

int VerificaArbol(arbol A, int gradoRaiz)
{
    return A == NULL || (A->izq == NULL) ? 1 :  // Es nulo o es Hoja
        Grado(A) == gradoRaiz && VerificaArbol(A->izq, gradoRaiz) && VerificaArbol(A->der, gradoRaiz);
}

int VerificaBosque(arbol A)
{
    int verif = 1;

    if (A == NULL)
        return 0;

    while (A != NULL && verif)
    {
        verif = VerificaArbol(A->izq, Grado(A));
        A = A->der;
    }

    return verif;
}

// EJ 2)
int GradoNodo(arbol A, posicion p)
{
    int grado = 0;
    posicion c;

    if (Nulo(p))
        return 0;

    c = HijoMasIzq(A, p);

    while (!Nulo(c))
    {
        grado++;
        c = HermanoDer(A, c);
    }

    return grado;
}

int EsHoja(arbol A, posicion p)
{
    return Nulo(p) || Nulo(HijoMasIzq(A, p));
}

int HijosGradoCreciente(arbol A, posicion p)
{
    int creciente = 1;

    if (EsHoja(A, p))
        return 0;

    posicion c = HijoMasIzq(A, p);
    int gradoAnterior = GradoNodo(A, c);

    c = HermanoDer(A, c);
    while (!Nulo(c) && creciente)
    {
        int gradoActual = GradoNodo(A, c);
        creciente = gradoActual >= gradoAnterior;
        gradoAnterior = gradoActual;
        c = HermanoDer(A, c);
    }

    return creciente;
}

int Existe(arbol A, posicion p)
{
    posicion c;
    int existe = 0;

    if (Nulo(p))
        return 0;

    if (HijosGradoCreciente(A, p))
        return 1;

    c = HijoMasIzq(A, p);

    while (!Nulo(c) && !existe)
    {
        existe += Existe(A, c);
        c = HijoMasIzq(A, c);
    }

    return existe;
}

// EJ 3)
int VerticesCumplen(TMat R, int i, int j, int grE, int grS, int V)
{

    if (V > N)
        return 0;

    if (R[V][V])
        return VerticesCumplen(R, 0, V + 1, 0, 0, V + 1);

    if (i < N)
        return VerticesCumplen(R, i + 1, j, grE, grS + R[i][j], V);

    if (j < N)
        return VerticesCumplen(R, i, j + 1, grE += R[V][j], grS, V);

    return grE == grS + VerticesCumplen(R, 0, V + 1, 0, 0, V + 1);
}

int main()
{
    arbol a = NULL;

    // Nodo raíz
    addNodo(&a, 1);

    // Subárbol izquierdo (Grado = 2)
    addNodo(&a->izq, 2);
    addNodo(&a->izq->izq, 3);
    addNodo(&a->izq->der, 4);
    addNodo(&a->izq->izq->der, 5);

    // Subárbol derecho (Grado = 3)
    addNodo(&a->der, 7);
    addNodo(&a->der->izq, 8);
    addNodo(&a->der->izq->der, 9);
    addNodo(&a->der->izq->izq, 10);
    addNodo(&a->der->izq->izq->der, 11);

    /* // Subárbol en el extremo derecho (Grado = 1)
    addNodo(&a->der->der->der->der, 14);
    addNodo(&a->der->der->der->der->izq, 15);  */

    printf("Resultado de VerificaBosque: %d\n", VerificaBosque(a));

    return 0;
}