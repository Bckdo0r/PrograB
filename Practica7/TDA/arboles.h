typedef int posicion;

typedef struct nodo0
{
   int dato;
   struct nodo0 *izq,*der;
} NODO0, *arbol0;

typedef struct nodo1
{
   char dato;
   struct nodo1 *izq,*der;
} NODO1, *arbol1;

typedef struct nodo2
{
   char *dato;
   struct nodo2 *izq,*der;
} NODO2, *arbol2;

void addNodo0(arbol0 *, int);
void cargaArbolEnteros(arbol0 *a);

void addNodo1(arbol1 *, char);
void cargaArbolCaracteres(arbol1 *a);

void addNodo2(arbol2 *, const char *);
void cargaArbolCadenas(arbol2 *);