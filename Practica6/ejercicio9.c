#include <stdio.h>
#include <stdlib.h>

// \

typedef struct nodoD
{
    int num;
    struct nodoD *ant, *sig;
} nodoD;

typedef nodoD *PnodoD;

typedef struct
{
    PnodoD pri, ult;
} ListaD;

typedef struct nodo
{
    int num;
    struct nodo *sig;
} nodo;

typedef nodo *ListaC;
typedef nodo *Lista;

void agregaNodoLD(ListaD *, int);
void agregaNodoLC(ListaC *, int);
void agregaNodoL(Lista *, int);
void cargaLista(Lista *);
void trasvasaLista(Lista, ListaD *, ListaC *);
void muestraListas(ListaD, ListaC);

int main()
{
    Lista L = NULL;
    ListaC LC = NULL;
    ListaD LD;
    LD.pri = NULL;
    LD.ult = NULL;
    cargaLista(&L);
    trasvasaLista(L, &LD, &LC);
    muestraListas(LD, LC);
    return 0;
}

void agregaNodoL(Lista *L, int num)
{

    Lista new = (Lista)malloc(sizeof(nodo));
    new->num = num;

    new->sig = *L;
    *L = new;
}

void agregaNodoLD(ListaD *LD, int num)
{
    PnodoD act;
    PnodoD nuevo = (PnodoD)malloc(sizeof(nodoD));
    nuevo->num = num;
    nuevo->ant = NULL;
    nuevo->sig = NULL;

    if (LD->pri == NULL)
    {
        LD->pri = nuevo;
        LD->ult = nuevo;
    }
    else if (num < LD->pri->num)
    {
        nuevo->sig = LD->pri;
        LD->pri->ant = nuevo;
        LD->pri = nuevo;
    }
    else if (num > LD->ult->num)
    {
        nuevo->ant = LD->ult;
        LD->ult->sig = nuevo;
        LD->ult = nuevo;
    }
    else
    {
        act = LD->pri;

        while (num > act->num)
            act = act->sig;

        nuevo->sig = act;
        nuevo->ant = act->ant;
        act->ant->sig = nuevo;
        act->ant = nuevo;
    }
}

void agregaNodoLC(ListaC *LC, int num)
{
    ListaC ant, act, nuevo = (ListaC)malloc(sizeof(nodo));
    nuevo->num = num;

    if (*LC == NULL)
    {
        nuevo->sig = nuevo;
        *LC = nuevo;
    }
    else if (num > (*LC)->num)
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
        } while (act != *LC && num > act->num);

        nuevo->sig = act;
        ant->sig = nuevo;
    }
}

void cargaLista(Lista *L)
{
    FILE *arch;
    int num;

    arch = fopen("datosEJ9.txt", "r");

    if (arch == NULL)
        printf("FATAL CRASH");
    else
    {
        while (fscanf(arch, "%d", &num) == 1)
            agregaNodoL(L, num);

        fclose(arch);
    }
}

void trasvasaLista(Lista L, ListaD *LD, Lista *LC)
{

    while (L != NULL)
    {
        agregaNodoLD(LD, L->num);
        agregaNodoLC(LC, L->num);
        L = L->sig;
    }
}

void muestraListas(ListaD LD, ListaC LC)
{
    ListaC aux = LC;

    printf("\n\nLista Doble: \n");
    while (LD.pri != NULL)
    {
        printf("%d ", LD.pri->num);
        LD.pri = LD.pri->sig;
    }

    printf("\n\nLista Circular: \n");
    if (LC != NULL)
        do
        {
            aux = aux->sig;
            printf("%d ", aux->num);
        } while (aux != LC);

    printf("\n");
}