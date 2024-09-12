typedef char TElemento[9];

typedef struct nodo{
    TElemento dato;
    struct nodo *sig;
} nodoP;

typedef nodoP *TPila;

void iniciaP(TPila *P);
int vaciaP(TPila P);
void poneP(TPila *P,TElemento x);
TElemento consultaP(TPila P);
void sacaP(TPila *P, TElemento *x);