#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FILA 21
#define MAX_COLUMNA 41

typedef char st6[7];
typedef char st8[9];
typedef char TMat[MAX_FILA][MAX_COLUMNA];

typedef struct nodito
{
    int numEmpresa;
    st6 fecha;
    struct nodito *sig;
} nodito, *SubLista;

typedef struct nodo
{
    int norma;
    st8 nombre;
    SubLista sub;
    struct nodo *sig;
} nodo, *Lista;

int main()
{

    return 0;
}

void generaMatriz(Lista L, TMat M)
{
    SubLista sub;
    int i = 0;

    iniciaM(M);

    while (L != NULL)
    {

        sub = L->sub;

        while (sub != NULL)
        {
            M[i][sub->numEmpresa] = 'S';
            sub = sub->sig;
        }

        L = L->sig;
    }
}