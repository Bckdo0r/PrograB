typedef int TElementoA;
typedef int posicion;

typedef struct nodo
{
   TElementoA dato;
   struct nodo *izq;
   struct nodo *der;
} NODO, *arbol;

//typedef NODO *arbol;

void addNodo(arbol *, TElementoA);