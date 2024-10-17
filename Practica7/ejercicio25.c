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
    addNodo(&a->der, 2);                                     
    addNodo(&a->der->izq, 3);                                
    addNodo(&a->der->izq->der, 4);                           
    addNodo(&a->der->izq->der->izq, 5);                      
    addNodo(&a->der->izq->der->izq->der, 6);                 
    addNodo(&a->der->izq->der->izq->der->izq, 9);            
    addNodo(&a->der->izq->der->izq->der->izq->der, 10);      
    addNodo(&a->der->izq->der->izq->der->izq->der->der, 11); 
    addNodo(&a->der->der, 12);                               
    addNodo(&a->der->der->izq, 13);                          
    addNodo(&a->der->der->izq->der, 14);                     
    addNodo(&a->der->der->izq->der->izq, 15);                
    addNodo(&a->der->der->der, 7);                           
    addNodo(&a->der->der->der->der, 8);                      

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
