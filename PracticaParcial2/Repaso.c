#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Practica7/TDA/arboles.h"
#include "../Practica8/grafo.h"

void DFS(TVec Lista_Ady, int origen, int visitados[N])
{
    Lista aux;

    if (visitados[origen] == 0)
        visitados[origen] = 1;

    aux = Lista_Ady[origen].L;

    while (aux != NULL)
    {
        if (visitados[aux->nodo] == 0)
            DFS(Lista_Ady, aux->nodo, visitados);

        aux = aux->sig;
    }
}

void esConexa(TVec Lista_Ady)
{
    int visitados[N] = {0};
    int i = 0;

    DFS(Lista_Ady, 0, visitados);

    while (visitados[i] && i < N)
        i++;

    printf("El grafo %s es conexo", i == N ? "SI" : "NO");
}

// EJ 1) Dado un arbol binario de enteros, proveniente de la transformación de un bosque, calcular con funciones int, la cantidad de arboles que tenían
// alguna clave negativa entre los niveles K1 y K2 (datos). Los árboles no necesariamente tienen K1 o K2 niveles y K1 <= K2.

int HayNegativa(arbol A, int K1, int K2, int nivel)
{
    if (A == NULL || nivel > K2)
        return 0;

    if (nivel >= K1 && A->dato < 0)
        return 1;

    return HayNegativa(A->izq, K1, K2, nivel + 1) || HayNegativa(A->der, K1, K2, nivel);
}

int CantBosque(arbol A, int K1, int K2)
{
    int cant = 0;

    while (A != NULL)
    {
        cant += K1 == 1 && A->dato < 0 ? 1 : HayNegativa(A->izq, K1, K2, 1);
        A = A->der;
    }

    return cant;
}

// EJ 2) Dado un arbol N-ario de caracteres obtener el máximo y el mínimo grado de los nodos ubicados en el nivel K.

void MaxGrado(arbol A, posicion p, int K, int nivel, int *min, int *max, int *tieneKNiveles)
{
    posicion c;
    int gr = 0;

    if (!Nulo(p) && nivel <= K)
    {
        c = HijoMasIzq(A, p);

        while (!Nulo(c))
        {
            gr++;
            MaxGrado(A, c, K, nivel + 1, min, max, tieneKNiveles);
            c = HermanoDer(A, c);
        }

        if (nivel == K)
        {
            *tieneKNiveles = 1;

            if (gr > *max)
                *max = gr;

            if (gr < *min)
                *min = gr;
        }
    }
}

// EJ 3) Dados los grafos G = (V, E) con |V| = N y G' = (V', E') con |V'| = N, determinar si G es subgrafo de G' o viceversa o ninguna.
// G en triangulo inf y G' en triangulo sup. No hay bucles.

// -1 si G es subgrafo de G', 0 si no es nada, 1 si G' es subgrafo de G
int SubGrafo(TMat M, int NN)
{
    int R1 = 1, R2 = 1;
    int i = 1, j;

    while (i < NN && R1)
    {
        j = 0;
        while (j < i && R1)
        {
            if (M[i][j] && !M[j][i])
                R1 = 0;

            j++;
        }
        i++;
    }

    if (R1)
        return -1;

    i = 0;

    while (i < NN - 1 && R2)
    {
        j = i + 1;
        while (j < NN && R2)
        {
            if (M[j][i] && !M[i][j])
                R2 = 0;

            j++;
        }
        i++;
    }

    if (R2)
        return 1;

    return 0;
}

// EJ 4)
// Dado un ABB de numeros naturales sin elementos repetidos, obtener las claves menor y mayor considerando los nodos de grado 2,
// ademas retornar el nivel en que se encuentran. Sin recorrer mas de una vez.

void Cant(arbol A, int nivel, int *min, int *max, int *nivelMin, int *nivelMax)
{
    int clave;
    if (A != NULL)
    {
        if (A->izq != NULL)
            Cant(A->izq, nivel + 1, min, max, nivelMin, nivelMax);

        if (A->izq != NULL && A->der != NULL)
        {
            int clave = A->dato;

            if (clave < *min)
            {
                *min = clave;
                *nivelMin = nivel;
            }

            if (clave > *max)
            {
                *max = clave;
                *nivelMax = nivel;
            }
        }

        if (A->der != NULL)
            Cant(A->der, nivel + 1, min, max, nivelMin, nivelMax);
    }
}

int main()
{
    TVec Lista_Ady;

    esConexa(Lista_Ady);

    arbol A;
    int min = 9999999;
    int max = -1;
    int tieneKNiveles = 0;
    int K = 3;

    MaxGrado(A, Raiz(A), K, 1, &min, &max, &tieneKNiveles);

    if (tieneKNiveles)
        printf("El menor grado es: %d y el mayor grado es: %d", min, max);
    else
        printf("No tiene %d niveles", K);

    return 0;
}