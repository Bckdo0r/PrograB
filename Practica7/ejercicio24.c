/* Dado un árbol binario que proviene de la transformación de un bosque, hallar la cantidad de 
árboles del bosque que tenían altura al menos K (dato de entrada)  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDA/arboles.h"

int altArbol(arbol,int);
int recorreArbolBin(arbol,int);

int main(){

    arbol a;
    int K = 3;

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

    printf("Arboles del bosque con altura mayora a %d: %d\n",K,recorreArbolBin(a,K));

    return 0;
}

int recorreArbolBin(arbol a,int k){
    int cont = 0;

    while (a != NULL){
        if (altArbol(a->izq,1)>=k)
            cont++;  
        a = a->der;
    }

    return cont;
}

int altArbol(arbol a, int alt) {
    int altIzq,altDer;
    if (a == NULL)
        return alt;

    altIzq = altArbol(a->izq, alt + 1);
    altDer = altArbol(a->der, alt);

    return (altIzq > altDer) ? altIzq : altDer;
}