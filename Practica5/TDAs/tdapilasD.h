typedef char TElementoP;

typedef struct nodoD
{
    TElementoP dato;
    struct nodoD *sig;
} nodoP;

typedef nodoP *TPila;

void iniciaP(TPila *P);
int vaciaP(TPila P);
void poneP(TPila *P, TElementoP x);
TElementoP consultaP(TPila P);
void sacaP(TPila *P, TElementoP *x);