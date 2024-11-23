#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Practica7/TDA/arboles.h"

/* Dado un arbo binario proveniente de la transformacion de un arbol general, obtener mediante una funcion int la suma de las claves
que en el arbol general su clave coincida con su altura y con su grado */

int gradoAlt(arbol0 a,int altura){
    int gr = 0;

    while (a != NULL && gr < altura){
        gr++;
        a = a->der;
    }

    return gr == altura && a == NULL;
}

int sumaClaves(arbol0 a,int alt,int suma){
    if (a == NULL)
        return suma;

    if (gradoAlt(a->izq,alt))
        suma += a->dato;  
        
    suma = sumaClaves(a->izq,alt+1,suma);
    return sumaClaves(a->der,alt,suma);
}

int main() {
    arbol0 a = NULL;

    cargaArbolEnteros(&a);
    printf ("La suma de las claves es %d.",sumaClaves(a,0,0));

    return 0;
}