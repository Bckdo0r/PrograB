typedef long TElementoP;

typedef struct nodo{
    TElementoP dato;
    struct nodo *sig;
} nodoP;

typedef nodoP *TPila;

void iniciaP(TPila *P);
int vaciaP(TPila P);
void poneP(TPila *P,TElementoP x);
TElementoP consultaP(TPila P);
void sacaP(TPila *P, TElementoP *x);