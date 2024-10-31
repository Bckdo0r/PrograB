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

void clavesMinMax(arbol a,Tclave *min,Tclave *max,int nivel){

    if (a != NULL){
        
        if (a->dato < min->clave){
            min->clave = a->dato;
            min->nivel = nivel;
        }
        
        else if (a->dato > max->clave){
            max->clave = a->dato;
            max->nivel = nivel;
        }

        clavesMinMax(a->izq,min,max,nivel+1);
        clavesMinMax(a->der,min,max,nivel+1);
    }
        
    
}

// EJ 2)

/*
Dado un arbol N-Ario de Nros naturales retornar mediante una funcion recursiva int la mayor clave de entre los nodos 
de grado G (dato) o 2G. En caso de no existir retornar -1.
*/  

int Grado(arbol A, posicion p) {
    int grado = 0;
    posicion c;

    if (Nulo(p))
        return 0;

    c = HijoMasIzq(A, p);

    while (!Nulo(c)) {
        grado++;
        c = HermanoDer(A, c);
    }

    return grado;
}

TElementoA MayorClave(arbol A, posicion p, int G, TElementoA max) {
    posicion c;
    TElementoA clave;
    int grado;

    if (Nulo(p))
        return -1;

    grado = Grado(A,p); 
    
    if (grado >= G && grado <= 2 * G && Info(p) > max)
        max = Info(p);

    c = HijoMasIzq(A,p);
    while(!Nulo(c)){
        clave = MayorClave(A, c, max);

        if (clave > max) 
            clave = max;

        c = HermanoDer(A, c);
    }

    return clave;
}
