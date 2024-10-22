#define N 7

typedef struct nodo
{
    char nodo;
    struct nodo *sig;
} nodoL;

typedef nodoL *Lista;

typedef struct
{
    char nodo;
    Lista L;
} reg;

typedef reg TVec[N];
typedef int TMat[N][N];

void insertarEnLista(Lista *, char);
void cargaLista(TVec);
void cargaMatriz(TMat);