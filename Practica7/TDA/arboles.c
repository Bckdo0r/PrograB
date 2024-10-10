#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arboles.h"

void addNodo(arbol *A,TElementoA x){
   arbol new;

   if (*A == NULL) {
      new = (arbol) malloc(sizeof(NODO));
      new->izq = NULL;
      new->der = NULL;
   } else if (x < (*A)->dato) {
      addNodo(&((*A)->izq), x);
   } else {
      addNodo(&((*A)->der), x);
   }
}


