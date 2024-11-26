#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Practica7/TDA/arboles.h"

/* Dado un arbol binario proveniente de la transformacion de bosque, de claves enteras verficar que todos los arboles del bosque
tenian al menos un nodo de grado 2 o 3 que verifica ademas que su clave era igual a la suma de las claves de sus hijos */

int gradoYClaves(arbol0 a,int dato){
    int suma = 0,gr = 0;

    while(a != NULL){
        gr++;
        suma += a->dato;
        a = a->der;
    }

    return a == NULL && (gr == 2 || gr == 3) && suma == dato;
}

int verifica(arbol0 a){
    if (a == NULL)
        return 0;

    if (gradoYClaves(a->izq,a->dato))
        return 1;

    return verifica(a->izq) || verifica(a->der);        
}

int recorreBosque(arbol0 a){
    int verif = 1;

    while (a != NULL && verif){
        if (!gradoYClaves(a->izq,a->dato))
            verif = verifica(a->izq);

        a = a->der;    
    }

    return verif;
}

/* Dado un arbol N-Ario de enteros, determinar mediante una unica funcion cuantos nodos del arbol son hojas y
cuantos nodos del arbol tienen un hermano a izquierda que sea negativo. */

void cuentaNodos(arbol0 a,posicion p,int *contHojas,int *contIzqNeg){
    posicion c;
    if(!nulo(p)){
        (*contHojas) += nulo(hijoMasIzq(p,a));
        c = hijoMasIzq(p,a);

        while (!nulo(c)){
            (*contIzqNeg) += info(c,a) < 0 && !nulo(hrnoDer(c,a));
            cuentaNodos(a,c,contHojas,contIzqNeg);
            c = hrnoDer(c,a);
        }
    }
}

int main() {
    arbol0 a = NULL;

    cargaArbolEnteros(&a);

    printf("El bosque %s verifica la condicion solicitada.\n",recorreBosque(a) ? "SI" : "NO");

    return 0;
}