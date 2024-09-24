#include <stdio.h>
#include <stdlib.h>

// \

typedef struct nodoD
{
    char car;
    struct nodoD *ant, *sig;
} nodoD;

typedef nodoD *PnodoD;

typedef struct
{
    PnodoD pri, ult;
} ListaD;

typedef struct nodo
{
    char car;
    struct nodo *sig;
} nodo;

typedef nodo *ListaC;

void agregaNodoLD(ListaD *, char);
void agregaNodoLC(ListaC *, char);
void cargaListas(ListaD *, ListaC *);
void mostrarListas(ListaD, ListaC);
void elimina(ListaD *, ListaC *, int);

int main()
{
    ListaD LD;
    ListaC LC = NULL;

    LD.pri = NULL;
    LD.ult = NULL;

    cargaListas(&LD, &LC);
    mostrarListas(LD, LC);
    elimina(&LD, &LC, 2);
    mostrarListas(LD, LC);

    return 0;
}

void agregaNodoLD(ListaD *LD, char car)
{
    PnodoD act;
    PnodoD nuevo = (PnodoD)malloc(sizeof(nodoD));
    nuevo->car = car;
    nuevo->ant = NULL;
    nuevo->sig = NULL;

    if (LD->pri == NULL)
    {
        LD->pri = nuevo;
        LD->ult = nuevo;
    }
    else if (car < LD->pri->car)
    {
        nuevo->sig = LD->pri;
        LD->pri->ant = nuevo;
        LD->pri = nuevo;
    }
    else if (car > LD->ult->car)
    {
        nuevo->ant = LD->ult;
        LD->ult->sig = nuevo;
        LD->ult = nuevo;
    }
    else
    {
        act = LD->pri;

        while (car > act->car)
            act = act->sig;

        nuevo->sig = act;
        nuevo->ant = act->ant;
        act->ant->sig = nuevo;
        act->ant = nuevo;
    }
}

void agregaNodoLC(ListaC *LC, char car)
{
    ListaC ant, act, nuevo = (ListaC)malloc(sizeof(nodo));
    nuevo->car = car;

    if (*LC == NULL)
    {
        nuevo->sig = nuevo;
        *LC = nuevo;
    }
    else if (car > (*LC)->car)
    {
        nuevo->sig = (*LC)->sig;
        (*LC)->sig = nuevo;
        *LC = nuevo;
    }
    else
    {
        act = *LC;

        do
        {
            ant = act;
            act = act->sig;
        } while (act != *LC && car > act->car);

        nuevo->sig = act;
        ant->sig = nuevo;
    }
}

void cargaListas(ListaD *LD, ListaC *LC)
{
    FILE *arch;
    char car;

    arch = fopen("datosEJ8.txt", "r");

    if (arch == NULL)
        printf("Error lens");
    else
    {

        while (fscanf(arch, "%c", &car) == 1)
        {
            agregaNodoLD(LD, car);
            agregaNodoLC(LC, car);
        }

        fclose(arch);
    }
}

void mostrarListas(ListaD LD, ListaC LC)

{
    ListaC aux = LC;

    printf("\n\nLista Doble: \n");
    while (LD.pri != NULL)
    {
        printf("%c", LD.pri->car);
        LD.pri = LD.pri->sig;
    }

    printf("\n\nLista Circular: \n");
    if (LC != NULL)
        do
        {
            aux = aux->sig;
            printf("%c", aux->car);
        } while (aux != LC);

    printf("\n");
}

void elimina(ListaD *LD, ListaC *LC, int pos)
{
    int i;
    PnodoD actD;
    ListaC antC, actC;

    if (LD->pri != NULL)
    {
        actD = LD->pri;
        i = 1;

        while (actD != NULL && i++ < pos)
            actD = actD->sig;

        if (actD != NULL)
        {

            if (actD == LD->pri)
            {
                LD->pri = actD->sig;
                actD->sig->ant = NULL;
            }
            else if (actD == LD->ult)
            {
                LD->ult = actD->ant;
                actD->ant->sig = NULL;
            }
            else
            {
                actD->ant->sig = actD->sig;
                actD->sig->ant = actD->ant;
            }
            free(actD);
        }
    }

    if (*LC != NULL)
    {
        actC = *LC;
        i = 1;

        do
        {
            antC = actC;
            actC = actC->sig;
        } while (i++ < pos);

        antC->sig = actC->sig;

        if (actC == *LC)
            *LC = antC;

        free(actC);
    }
}
