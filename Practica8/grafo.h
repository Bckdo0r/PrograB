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
} reg;

typedef reg TVec[N];
typedef int TMat[N][N];

void insertarEnLista(Lista *, char, int);
void cargaLista(TVec);
void cargaMatriz(TMat);