#include "tipos.h"

typedef char ST5[6];

typedef struct{
    ST5 cod;
    unsigned int creditos;
} TElementoP;

typedef struct nodoP{
    TElementoP dato;
    struct nodoP *sig;
} nodoP;

typedef nodoP *TPila;

void iniciaP(TPila *P);
int vaciaP(TPila P);
void poneP(TPila *P,TElementoP x);
TElementoP consultaP(TPila P);
void sacaP(TPila *P, TElementoP *x);