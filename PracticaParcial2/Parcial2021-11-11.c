#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Practica7/TDA/arboles.h"

typedef struct{
    unsigned int clave,nivel;
} Tclave;

void cargaArbol(arbol);
void clavesMinMax(arbol,Tclave *,Tclave *);

int main() {


    return 0;
}

/* Dado un ABB de enteros sin repetir, obtener las calves mayor y menor considerando solamente los nodos
de grado 2. Ademas retornar el nivel donde se encuentra cada una de las claves */

void clavesMinMax(arbol a,Tclave *min,Tclave *max){
    int verif = 0,nivel = 0;
    arbol aux = a;
    
    while (aux->izq != NULL){
        nivel++;
        if (aux->der != NULL){
            min->clave = aux->dato;
            min->nivel = nivel;
            if (!verif){
                max->clave = min->clave;
                max->nivel = min->nivel;
                verif = 1;
            }
        }
        aux = aux->izq;
    }

    nivel = 0;
    aux = a;
    do { 
        if (aux->der != NULL){
            max->clave = aux->dato;
            max->nivel = nivel;
        }   
        nivel++;
        aux = aux->der;
    } while (aux != NULL);
    
}