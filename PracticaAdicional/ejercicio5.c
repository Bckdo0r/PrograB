/* Resolver mediante subprogramas las siguientes operaciones sobre una lista doblemente 
enlazada:
a) insertar un elemento en la posición media. Si la cantidad de elementos de la lista es impar 
insertar en la posición media más uno. Considerar la inserción en una lista vacía (único 
nodo)
b) eliminar un elemento conociendo la posición (puntero) del anterior, nulo para eliminar el
primer elemento.
c) eliminar todas las ocurrencias del elemento X (recibido como parámetro) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDAs/listas.h"

void creaListaDoble(ListaD *);

int main() {

   ListaD L;
   L.pri = NULL;
   L.ult = NULL;
   creaListaDoble(&L);
   muestraLD(L);

   return 0;
}

void creaListaDoble(ListaD *L){
   ElementoL nums[] = {2,5,6,7,5,4,3};

   for (int i = 0; i < 7; i++)
      agregaNodoLdOrd(L, nums[i]);
}