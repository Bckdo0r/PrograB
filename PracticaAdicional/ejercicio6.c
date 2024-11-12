/* Resolver mediante subprogramas las siguientes operaciones sobre una lista circular:
a) insertar un elemento conociendo la posición (puntero) del anterior. Tomar el último como
anterior del primero, y nulo para insertar en una lista vacía.
b) insertar un elemento conociendo la posición (puntero) del siguiente. Tomar el primero
como siguiente del último, nulo para insertar en una lista vacía.
c) eliminar todas las ocurrencias del elemento X (recibido como parámetro) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo{
    int dato;
    struct nodo *sig;
}nodoLc;

typedef nodoLc *pListaC;

int main() {


    return 0;
}

void insertaA(pListaC *L,pListaC ant){
    
}
