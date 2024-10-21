#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDA/arboles.h"

int main()
{
    return 0;
}

// a)
int cantNodos(arbol A, posicion p)
{
    posicion c;
    int cant = 0;

    if (A == NULL)
        return 0;

    c = HijoMasIzq(A, p);
    while (!Nulo(c))
    {
        cant += 1 + cantNodos(A, c);
        c = HermanoDer(A, c);
    }

    return cant;
}

// b)
float porcentajePares(arbol A, posicion p)
{
    posicion c;
    int pares, totales = 0;

    if (A == NULL)
        return 0;

    pares = Info(p) % 2 == 0;
    totales++;

    c = HijoMasIzq(A, p);

    while (!Nulo(c))
    {
        pares += Info(c) % 2 == 0;
        totales += 1 + porcentajePares(A, c);
        c = HermanoDer(A, c);
    }

    return (pares * 100) / (float)totales;
}

// c)
int grado(arbol A, posicion p)
{
    posicion c;
    int gradoActual = 0, gradoMax = 0, gradoHijo;

    if (A == NULL || Nulo(p))
        return 0;

    c = HijoMasIzq(A, p);

    while (!Nulo(c))
    {
        gradoActual++;
        gradoHijo = grado(A, c);
        if (gradoHijo > gradoMax)
            gradoMax = gradoHijo;

        c = HermanoDer(A, c);
    }

    return gradoActual > gradoMax ? gradoActual : gradoMax;
}

// d)
int cantImparEnNivelImpar(arbol A, posicion p, int nivel)
{
    posicion c;
    int gradoActual = 0, impares = 0;

    if (Nulo(p))
        return 0;

    c = HijoMazIzq(A, p);

    while (!Nulo(c))
    {
        gradoActual++;
        impares += cantImparEnNivelImpar(A, c, nivel + 1);
        c = HermanoDer(A, c);
    }

    return impares + (gradoActual % 2 && nivel % 2);
}

// e)
int verifica(arbol A, posicion p)
{
    posicion c;
    int grado = 0, verif = 1;

    if (Nulo(p))
        return verif;

    c = HijoMasIzq(A, p);

    if (Nulo(c))
        return verif;

    while (!Nulo(c) && verif)
    {
        grado++;
        verif = verifica(A, c);
        c = HermanoDer(A, c);
    }

    return verif && Info(p) == grado;
}

void verificaVoid(arbol A, posicion p, int *verif)
{
    posicion c;
    int grado = 0;

    if (!Nulo(p))
    {
        c = HijoMasIzq(A, p);
        if (!Nulo(c))
        {
            while (!Nulo(c) && *verif)
            {
                grado++;
                verificaVoid(A, c, verif);
                c = HermanoDer(A, c);
            }
            *verif = Info(p) == grado;
        }
    }
}

// f)
float promedio(arbol A, int K)
{
    int hijos = 0, suma = 0;

    calcHijosYSuma(A, Raiz(A), K, 0, &hijos, &suma);

    return hijos ? ((float)suma) / hijos : 0;
}

void calcHijosYSuma(arbol A, posicion p, int K, int nivel, int *hijos, int *suma)
{
    posicion c;

    if (!Nulo(p))
    {
        if (nivel == K)
        {
            (*hijos)++;
            *suma += Info(p);
        }

        c = HijoMasIzq(A, p);

        while (!Nulo(c))
        {
            calcHijosYSuma(A, c, K, nivel + 1, hijos, suma);
            c = HermanoDer(A, c);
        }
    }
}
