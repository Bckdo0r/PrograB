#include <stdlib.h>

typedef int TElementoA;
typedef struct nodo
{
    TElementoA dato;
    struct nodo *hijoIzq;
    struct nodo *hermanoDer;
} Nodo;

typedef Nodo *Arbol;
typedef Nodo *Posicion; // Definimos Posicion como un puntero a nodo

// Funciones básicas
int Vacio(Arbol A);
int Nulo(Posicion p);
Posicion HijoMasIzq(Posicion p, Arbol A);
Posicion HermanoDer(Posicion p, Arbol A);
TElementoA Info(Posicion p, Arbol A);
Posicion Raiz(Arbol A);
Posicion Padre(Posicion p, Arbol A);