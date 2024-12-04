#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Practica5/TDAs/pilas1.h"
#include "../Practica7/TDA/N-ario.h"
#include "../Practica7/TDA/arboles.h"

int main()
{

    return 0;
}

typedef char st20[21];
typedef char st10[11];

typedef struct nodito
{
    int idCancion;
    st20 titulo;
    unsigned int duracion;
    struct nodito *sig;
} nodito, *SubLista;

typedef struct nodo
{
    st10 idInterprete;
    SubLista sub;
    struct nodo *sig;
} nodo, *Lista;

typedef struct nodoC
{
    int idCancion;
    st10 idInterprete;
    struct nodoC *sig;
} nodoC, *ListaC;

void listar(ListaC *LC, Lista L, st10 idInterprete)
{
    char eliminada;
    int cantElim = 0, duracionElim = 0;
    ListaC act = *LC, ant = NULL, elim;
    SubLista sub;

    printf("Interprete: %s\n", idInterprete);

    while (L != NULL && strcmp(L->idInterprete, idInterprete) < 0)
        L = L->sig;

    if (L != NULL && strcmp(L->idInterprete, idInterprete) == 0)
    {
        sub = L->sub;

        printf("Id cancion\t\tTitulo\t\tEliminada\n");
        while (sub != NULL)
        {
            eliminada = 'N';
            eliminaLC(LC, sub->idCancion, &eliminada);

            if (eliminada == 'S')
            {
                cantElim++;
                duracionElim += sub->duracion;
            }

            printf("%s\t\t%s\t\t%c\n", sub->idCancion, sub->titulo, eliminada);

            sub = sub->sig;
        }

        printf("%d Cancion eliminadas (%d minutos)", cantElim, (int)(duracionElim / 60));
    }
}

void eliminaLC(ListaC *LC, int idCancion, char *eliminada)
{
    ListaC act = *LC, ant = NULL, elim;

    do
    {
        ant = act;
        act = act->sig;

        if (strcmp(act->idCancion, idCancion) == 0)
        {
            *eliminada = 'S';
            elim = act;

            if (act->sig == act)
                *LC = NULL;
            else
            {
                act = act->sig;

                if (elim == *LC)
                    *LC = ant;

                ant->sig = act;
            }

            free(elim);
        }

    } while (act != *LC && *LC != NULL);
}

// Ej 3
void eliminaPila(TPila *P, Arbol A)
{
    TElementoP X;
    int len;

    if (!vaciaP(*P))
    {
        sacaP(P, &X);

        eliminaPila(P, A);

        len = strlen(X);
        if (len % 2 != 0 && mismoPadre(A, Raiz(A), X[0], X[len - 1]))
            poneP(P, X);
    }
}

int mismoPadre(Arbol A, Posicion p, char x1, char x2)
{
    Posicion c, h;
    int cumple = 0;

    if (Nulo(p))
        return 0;

    c = HijoMasIzq(p, A);

    while (!Nulo(c) && !cumple)
    {
        h = HermanoDer(c, A);

        while (!Nulo(h) && !cumple)
        {
            cumple = (Info(c, A) == x1 && Info(h, A) == x2) || (Info(c, A) == x2 && Info(h, A) == x1);

            if (!cumple)
                cumple = mismoPadre(A, h, x1, x2);

            h = HermanoDer(h, A);
        }

        if (!cumple)
            cumple = mismoPadre(A, c, x1, x2);

        c = HermanoDer(c, A);
    }

    return cumple;
}

// Ej 4 Dado un arbol binario de la transformacion de un bosque de enteros, hallar la cantidad de nodos del bosque
// que tenian grado par.
int cantArbol(arbol0 a)
{
    int gr = 0, cant = 0;

    if (a == NULL)
        return 0;

    a = a->izq;

    while (a != NULL)
    {
        gr++;
        cant += cantArbol(a);
        a = a->der;
    }

    return cant + (gr % 2 == 0);
}

int cantBosque(arbol0 a)
{
    int cant = 0;

    while (a != NULL)
    {
        cant += cantArbol(a);
        a = a->der;
    }

    return cant;
}