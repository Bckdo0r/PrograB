#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Practica7/TDA/arboles.h"

/* Dado un arbol binario proveniente de un bosque, verificar si todos los arboles tenian algun nodo de grado K */

int gradoK(arbol0 a,int X){
    int gr = 0;

    while (a != NULL && gr < X){
        gr++;
        a = a->der;
    }

    return gr == X && a == NULL;
}

int verifica(arbol0 a,int X){
    if (a == NULL)
        return 0;

    if (gradoK(a->izq,X))
        return 1;

    return verifica(a->izq,X) || verifica(a->der,X);        
}

int recorreBosque(arbol0 r,int X){
    int verif = 1;

    while (r != NULL && verif){
        verif = gradoK(r->izq,X);

        if (!verif)
            verif = verifica(r->izq,X);
            
        r = r->der;
    }

    return verif;
}

int main() {
    arbol0 a = NULL;
    int X = 2;

    cargaArbolEnteros(&a);
    printf ("\nEl bosque %s tiene al menos un nodo de grado %d por arbol\n",recorreBosque(a,X) ? "SI" : "NO",X);

    return 0;
}