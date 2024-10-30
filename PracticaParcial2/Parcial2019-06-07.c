#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Practica7/TDA/arboles.h"

void cargaArbol(arbol);
char claveGr2MaxLvl(arbol,int,int);

int main() {


    return 0;
}

/* Dado un ABB de caracteres, obtener la clave del nodo de grado 2 que se encuentre ubicado en el mayor nivel. Si no hubiere
nodo de grado 2 en el arbol, retornar el caracter vacio. */
char claveGr2MaxLvl(arbol a,int nivel,int nivelMax){
    char clave;

    if (a == NULL)
        return '\0';

    if (a->izq != NULL && a->der != NULL && nivelMax < nivel){
        clave = a->dato;
        nivelMax = nivel;
    }

    clave = claveGr2MaxLvl(a->izq,nivel+1,nivelMax);
    clave = claveGr2MaxLvl(a->der,nivel+1,nivelMax);

    return clave;    
}