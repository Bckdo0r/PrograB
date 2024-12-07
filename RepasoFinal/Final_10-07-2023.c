#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Practica5/TDAs/pilas0.h"
#define M 20
#define N 31

typedef char st8[9];
typedef unsigned short int usi;
typedef int TMat[M][N];

typedef struct nodito
{
    st8 idClienteResp;
    usi ocupantes, diaEntrada, diaSalida;
    struct nodito *sig;
} nodito, *SubLista;

typedef struct nodo
{
    usi habitacion, capacidad;
    float precioXPersona;
    SubLista sub;
    struct nodo *sig;
} nodo, *Lista;

int main()
{
    Lista L;
    TPila P;
    TMat Mat;
    int desde = 17, hasta = 28;

    cargaL(&L);
    generarMatriz(L, Mat);
    printf("%d", informe(Mat, 0, desde, desde, hasta));

    cargaP(&P);
    filtraciones(L, &P);

    return 0;
}

void iniciarM(TMat Mat)
{
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            Mat[i][j] = 0;
}

void generarMatriz(Lista L, TMat Mat)
{
    SubLista sub;
    int i = 0;

    iniciarM(Mat);

    while (L != NULL)
    {
        sub = L->sub;
        while (sub != NULL)
        {
            Mat[i][sub->diaEntrada] = sub->ocupantes;
            sub = sub->sig;
        }
        i++;
        L = L->sig;
    }
}

int informe(TMat Mat, int i, int j, int desde, int hasta)
{
    int cant = 0;

    if (desde < 0)
        desde = 0;

    if (hasta >= N)
        hasta = N - 1;

    if (j <= hasta)
        cant += Mat[i][j] && informe(Mat, i, j + 1, desde, hasta);

    if (i <= M)
        cant += informe(Mat, i + 1, desde, desde, hasta);

    return cant;
}

int afectado(SubLista act, TElementoP x)
{
    int diaEntrada = act->diaEntrada;
    int diaSalida = act->diaSalida;
    int filtracionEntrada = x.D;
    int filtracionSalida = x.D + x.C;

    return filtracionEntrada < diaSalida && filtracionSalida > diaEntrada;
}

void filtraciones(Lista L, TPila *P)
{
    Lista aux;
    SubLista act, ant, elim;
    TElementoP x;
    float dineroPerdido = 0;

    while (!vaciaP(*P))
    {
        sacaP(P, &x);

        aux = L;
        while (aux->habitacion != x.H)
            aux = aux->sig;

        act = aux->sub;

        while (act != NULL)
        {
            if (afectado(act, x))
            {
                elim = act;
                act = act->sig;

                if (elim == aux->sub)
                    aux->sub = act;
                else
                    ant->sig = act;

                dineroPerdido += elim->ocupantes * aux->precioXPersona;

                free(elim);
            }
            else
            {
                ant = act;
                act = act->sig;
            }
        }
    }

    printf("Perdida por filtraciones: $%.2f\n", dineroPerdido);
}