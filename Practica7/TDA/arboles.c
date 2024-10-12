#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arboles.h"

void addNodo(arbol* a, TElementoA e) {
    *a = (arbol)malloc(sizeof(NODO));
    strcpy((*a)->dato,e);
    (*a)->izq = NULL;
    (*a)->der = NULL;
}


