#include "tipos.h"

typedef struct
{
    int H, D, C;
} TElementoP;

typedef struct nodoP
{
    TElementoP dato;
    struct nodoP *sig;
} nodoP;

typedef nodoP *TPila;

void iniciaP(TPila *P);
int vaciaP(TPila P);
void poneP(TPila *P, TElementoP x);
TElementoP consultaP(TPila P);
void sacaP(TPila *P, TElementoP *x);