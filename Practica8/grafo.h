#define N 7

typedef struct Vertice
{
    char nodo;
    unsigned short int peso;
    struct Vertice *sig;
} Vertice;

typedef Vertice *Lista;

typedef struct
{
    char nodo;
    Lista L;
} AdyReg;

typedef AdyReg TVec[N];
typedef int TMat[N][N];

void insertarEnLista(Lista *, char, int);
void cargaListaA(TVec);
void cargaMatriz(TMat);