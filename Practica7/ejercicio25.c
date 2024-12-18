/* Dado un árbol binario de números naturales que proviene de la transformación de un bosque, 
devolver un arreglo con la clave mayor de cada uno de los árboles que conforman el bosque. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDA/arboles.h"

void maxArbol(arbol, int *);
void generaVec(arbol, int []);

int main() {
    arbol a;
    
    int vec[100];

    addNodo(&a, 1);                                          
    addNodo(&a->izq, 4);                           
    addNodo(&a->izq->der, 5);
    addNodo(&a->izq->der->izq, 6);        
    addNodo(&a->izq->der->izq->der, 8);        
    addNodo(&a->izq->der->der, 15);
    addNodo(&a->izq->der->der->izq, 11);
    addNodo(&a->izq->der->der->izq->der, 12);
    addNodo(&a->izq->der->der->izq->der->der, 13);
    addNodo(&a->izq->der->der->izq->der->der->izq, 14);
    addNodo(&a->izq->der->der->izq->der->der->izq->der, 16);
    addNodo(&a->izq->der->der->izq->der->der->izq->der->der, 17);
    addNodo(&a->izq->der->der->izq->der->der->izq->der->der->der, 18);
    addNodo(&a->izq->der->der->izq->der->der->izq->izq, 6);
    addNodo(&a->izq->der->der->izq->der->der->izq->izq->der, 12);
    addNodo(&a->izq->der->der->izq->der->der->izq->izq->der->der, 9);
    addNodo(&a->izq->izq, 5);                           
    addNodo(&a->izq->izq->der, 7);                           
    addNodo(&a->izq->izq->der->izq, 8);                           
    addNodo(&a->izq->izq->der->izq->der, 10);                           
    addNodo(&a->izq->izq->der->der, 12);
    addNodo(&a->izq->izq->izq, 21);
    addNodo(&a->izq->izq->izq->der, 11);
    addNodo(&a->izq->izq->izq->der->der, 17);

    addNodo(&a->der, 4);                                          
    addNodo(&a->der->izq, 15);                                          
    addNodo(&a->der->izq->der, 11);                                          
    addNodo(&a->der->izq->der->izq, 10);                                          
    addNodo(&a->der->izq->der->izq->der, 20);                                          
    addNodo(&a->der->izq->der->izq->der->der, 20);                                          
    addNodo(&a->der->izq->der->izq->der->der->der, 2);                                          
    addNodo(&a->der->izq->izq, 1);                                          
    addNodo(&a->der->izq->izq->der, 21);
                                              
    addNodo(&a->der->der, 19);                                          
    addNodo(&a->der->der->izq, 28);                                          
    addNodo(&a->der->der->izq->izq, 24);                                          
    addNodo(&a->der->der->izq->izq->der, 13);                                          
    addNodo(&a->der->der->izq->izq->der->der, 21);                      

    generaVec(a,vec);

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", vec[i]);
    }
    

    return 0;
}

void generaVec(arbol a, int vec[]){
    int max, i = 0;
    while (a != NULL) {
        max = 0;
        maxArbol(a->izq, &max);
        if (a->dato > max)
            max = a->dato;
        vec[i++] = max;
        a = a->der;
    }
}

void maxArbol(arbol a, int *max) {
    if (a != NULL) {

        if (a->dato > *max)
            *max = a->dato;

        maxArbol(a->izq, max);
        maxArbol(a->der, max);
    }
}
