#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Practica7/TDA/arboles.h"

/* Dado un arbol binario de enteros proveniente de la transformacion de arbol general, se pide obtener la suma de las claves con grado impar
ubicadas en niveles menores a K (nivel y grado del arbol original), funciones NO VOID*/

int gradoImpar(arbol0 a){
    int gr = 0;

    while (a != NULL){
        gr++;
        a = a->der;
    }

    return gr % 2 != 0;
}

int sumaClaves(arbol0 a,int K,int lvl,int suma){
    if (a == NULL || lvl == K)
        return suma;

    if (gradoImpar(a->izq))
        suma += a->dato;

    suma = sumaClaves(a->izq,K,lvl+1,suma);
    return sumaClaves(a->der,K,lvl,suma);        
}

int sumaClaves2(arbol0 a,int K,int lvl){
    int suma = 0;
    int gr = 0;
    arbol0 aux;
    
    if (a == NULL || lvl >= K)
        return 0;

    aux = a->izq;
    while (aux != NULL){
        gr++;
        suma += sumaClaves2(aux,K,lvl+1);
        aux = aux->der;
    }

    if (gr % 2 != 0)
        suma += a->dato;
    
    return suma;
}

int bosque(arbol0 a, int K) {
    int suma = 0;

    while (a != NULL) {
        suma += sumaClaves2(a, K, 1);
        a = a->der;
    }

    return suma;
}

int main() {
    arbol0 a = NULL;
    int K = 3;

    cargaArbolEnteros(&a);

    printf("La suma de las claves (para K = %d): %d\n",K,bosque(a,K));
    printf("La suma de las claves (para K = %d): %d\n",K,sumaClaves(a,K,1,0));

    return 0;
}