typedef char TElementoA[15];

typedef struct nodo{
   TElementoA dato;
   struct nodo *izq;
   struct nodo *der;
} NODO;

typedef NODO * arbol;

void addNodo(arbol*, TElementoA);