#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../Practica5/TDAs/pilasE.h"
#include "../Practica8/grafo.h"
#include "../Practica7/TDA/arboles.h"
#include "../Practica7/TDA/N-ario.h"

typedef char string[100];

typedef struct nodoD
{
    string cadena;
    struct nodoD *ant, *sig;
} nodoD, *PnodoD;

typedef struct
{
    PnodoD pri, ult;
} ListaD;

typedef struct
{
    int consonantes, vocales;
    string cadena;
} Reg;

int main()
{

    return 0;
}

// Ej 2
int cantidadEnL(ListaD L, char c)
{
    PnodoD act = L.pri;
    int cant = 0;

    while (act != NULL && act->cadena[0] <= c)
    {
        if (act->cadena[0] == c)
            cant++;

        act = act->sig;
    }

    return cant;
}

void actualiza(TPila *P, ListaD L)
{
    TElemento x;

    if (!vaciaP(*P))
    {
        sacaP(P, &x);
        actualiza(P, L);
        x.E = cantidadEnL(L, x.C);
        poneP(P, x);
    }
}

void cantidadEnP(TPila *P, char c, int *cant)
{
    TElemento x;
    if (!vaciaP(*P))
    {
        sacaP(P, &x);
        if (x.C == c)
            (*cant)++;
        cantidadEnP(P, c, cant);
        poneP(P, x);
    }
}

int esVocal(char c)
{
    c = toupper(c);
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

int cantVocales(string cadena)
{
    int cant = 0;
    for (int i = 0; i < strlen(cadena); i++)
        cant += esVocal(cadena[i]);

    return cant;
}

void elimina(ListaD *L, TPila *P)
{
    int cant;
    Reg reg;
    PnodoD act = L->pri, elim;
    FILE *arch = fopen("RESUMEN.DAT", "wb");

    while (act != NULL)
    {
        cant = 0;
        cantidadEnP(P, act->cadena[0], &cant);

        if (cant == 0)
        {
            elim = act;
            act = act->sig;

            if (elim == L->pri)
            {
                L->pri = act;
                act->ant = NULL;
            }
            else if (elim == L->ult)
            {
                L->ult = elim->ant;
                elim->ant->sig = NULL;
            }
            else
            {
                act->ant = elim->ant;
                elim->ant->sig = act;
            }

            elim->ant = NULL;
            elim->sig = NULL;

            reg.vocales = cantVocales(elim->cadena);
            reg.consonantes = strlen(elim->cadena) - reg.vocales;
            strcpy(reg.cadena, elim->cadena);

            fwrite(&reg, sizeof(Reg), 1, arch);

            free(elim);
        }
        else
            act = act->sig;
    }

    fclose(arch);
}

// pilas.h
#define MAX 100
typedef struct
{
    int E, C;
} TElementoP;

typedef struct
{
    TElementoP datos[MAX];
    int tope;
} TPila2;

void SacaP(TPila2 *P, TElementoP *x)
{
    if (P->tope > -1)
        *x = P->datos[P->tope--];
}

void PoneP(TPila2 *P, TElementoP x)
{
    if (P->tope < MAX - 1)
        P->datos[++(P->tope)] = x;
}

// Ej 3
int esta(arbol0 A, int x)
{
    if (A == NULL)
        return 0;

    if (A->dato == x)
        return 1;

    if (A->dato > x)
        return esta(A->izq, x);

    return esta(A->der, x);
}

int cantVertices(TVec V, arbol0 A)
{
    int cant = 0, esBucle, costoMin;
    AdyReg reg;
    Lista L;

    for (int i = 0; i < N; i++)
    {
        reg = V[i];
        L = reg.L;
        esBucle = 0;
        costoMin = INT64_MAX;

        while (L != NULL && !esBucle)
        {
            esBucle = L->nodo == reg.nodo;
            if (L->peso < costoMin)
                costoMin = L->peso;
            L = L->sig;
        }

        if (!esBucle && !esta(A, costoMin))
            cant++;
    }

    return cant;
}

// Ej 4
int cantNodosGradoK(Arbol A, posicion p, int K)
{
    int cant = 0, gr = 0;
    posicion c;

    if (Nulo(p))
        return 0;

    c = HijoMasIzq(p, A);

    while (!Nulo(c) && cant <= 1)
    {
        gr++;
        cant += cantNodosGradoK(A, c, K);
        c = HermanoDer(c, A);
    }

    return cant + (gr == K);
}

int main()
{
    Arbol A;
    int cant, K = 2;

    cant = cantNodosGradoK(A, Raiz(A), K);
    printf("%s", cant == 1 ? "Si" : "No");

    return 0;
}