#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Practica7/TDA/arboles.h"
#include "../Practica8/grafo.h"

/*
Dado un AB de enteros proviente de la transformacion de un arbol general, se pide obtener la suma de las claves de
grado impar ubicadas en niveles menores a K (dato). El grado y el nivel se refieren a los del arbol original.
*/

int Grado(arbol A)
{
    int gr = 0;

    if (A == NULL)
        return 0;

    A = A->izq;

    while (A != NULL)
    {
        gr++;
        A = A->der;
    }

    return gr;
}

int SumaArbol(arbol A, int K, int nivel)
{
    if (A == NULL)
        return 0;

    if (nivel < K)
        return (Grado(A) % 2 == 1 ? A->dato : 0) + SumaArbol(A->izq, K, nivel + 1) + SumaArbol(A->der, K, nivel);

    return 0;
}

int main()
{

    return 0;
}

// EJ 2)
/*
Dado un arbol N ario de caracteres verificar que exista alguna nodo no hoja, de grado par cuya clave sea vocal
y todos sus hijos tambien lo sean.
*/

int EsHoja(arbol A, posicion p)
{
    return Nulo(p) || Nulo(HijoMasIzq(A, p));
}

int GradoNArio(arbol A, posicion p)
{
    posicion c;
    int gr = 0;

    if (EsHoja(A, p))
        return 0;

    c = HijoMasIzq(A, p);
    while (!Nulo(c))
    {
        gr++;
        c = HermanoDer(A, c);
    }

    return gr;
}

int EsVocal(char c)
{
    c = toupper(c);
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

/*
Dado un arbol N ario de caracteres verificar que exista alguna nodo no hoja, de grado par cuya clave sea vocal
y todos sus hijos tambien lo sean.
*/
int Verifica(arbol A, posicion p)
{
    posicion c;
    int existe = 1;

    if (Nulo(p))
        return 0;

    if (!EsHoja(A, p) && EsVocal(Info(p)) && GradoNArio(A, p) % 2 == 0)
    {
        c = HijoMasIzq(A, p);
        while (!Nulo(c) && existe)
        {
            existe = EsVocal(Info(c));
            c = HermanoDer(A, c);
        }
        if (existe)
            return 1;
    }

    while (!Nulo(c) && existe)
    {
        existe = Verifica(A, c);
        c = HermanoDer(A, c);
    }

    return existe;
}

int Verifica2(arbol A, posicion p)
{
    if (Nulo(p))
        return 0;

    int grado = 0;
    int todosHijosSonVocales = 1;
    int cumpleCondiciones = 0;

    posicion c = HijoMasIzq(A, p);
    while (!Nulo(c))
    {
        if (!EsVocal(Info(c)))
            todosHijosSonVocales = 0;

        grado++;
        cumpleCondiciones = Verifica2(A, c);

        c = HermanoDer(A, c);
    }

    if (grado % 2 == 0 && EsVocal(Info(p)) && todosHijosSonVocales)
        cumpleCondiciones = 1;

    return cumpleCondiciones;
}

typedef struct
{
    int vertice, gradoS;
} Data;

/*
Dado un digrafo de orden N almacenado en una matriz de ady, los vertices numerados de 1 a N,
generar mediante una unica funcion recursive un arreglo con los vertices que tengan bucle, alamcenando ademas su grado de salida. Mostrar vec.
*/
void genera(TMat D, int i, int j, Data V[], int *c, int grS)
{
    if (i < N)
    {
        if (j < N)
            genera(D, i, j + 1, V, c, grS + D[i][j]);
        else
        {
            if (D[i][i] == 1)
            {

                V[(*c)].vertice = i + 1;
                V[(*c)].gradoS = grS;
                (*c)++;
                printf("Vertice: %d, con grado: %d\n", i + 1, grS);
            }

            genera(D, i + 1, 0, V, c, 0);
        }
    }
}
