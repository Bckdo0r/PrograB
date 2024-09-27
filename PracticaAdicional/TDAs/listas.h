typedef int ElementoL;

typedef struct nodo{
   ElementoL dato;
   struct nodo *sig;
} nodoLs;

typedef struct nodoD
{
   ElementoL dato;
   struct nodoD *ant, *sig;
} nodoD;
typedef nodoD *pnodoD;

typedef nodoLs *ListaS;
typedef nodoLs *ListaC;
typedef struct {
   pnodoD pri, ult;
} ListaD;

void agregaNodoLs(ListaS *,ElementoL);
void agregaNodoLsOrd(ListaS *,ElementoL);
void agregaNodoLc(ListaC *,ElementoL);
void agregaNodoLcOrd(ListaC *,ElementoL);
void agregaNodoLd(ListaD *,ElementoL);
void agregaNodoLdOrd(ListaD *,ElementoL);
void muestraLD(ListaD);