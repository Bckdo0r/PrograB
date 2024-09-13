#define MAX 100

typedef int TElemento;

typedef struct{
    TElemento datos[MAX];
    int tope;
} TPila;

void iniciaP(TPila *P);
int vaciaP(TPila P);
void poneP(TPila *P,TElemento x);
TElemento consultaP(TPila P);
void sacaP(TPila *P, TElemento *x);