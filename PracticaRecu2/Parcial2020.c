#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Practica7/TDA/arboles.h"

/* Dado un arbol binario proveniente de la transformacion de bosque, de claves enteras verficar que todos los arboles del bosque
tenian al menos un nodo de grado 2 o 3 que verifica ademas que su clave era igual a la suma de las claves de sus hijos */

int gradoYClaves(arbol0 a,int dato){
    int suma = 0,gr = 0;

    while(a != NULL && suma <= dato){
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
        verif = gradoYClaves(a->izq,a->dato);
        if (!verif)
            verif = verifica(a->izq);

        a = a->der;    
    }

    return verif;
}

int verifica2(arbol0 a) {
    int suma = 0, gr = 0, verif = 1;
    arbol0 aux;

    if (a == NULL)
        return 1;

    aux = a->izq;

    while (aux != NULL && verif) {
        gr++;
        suma += aux->dato;
        verif = verifica2(aux->izq);
        aux = aux->der;
    }

    if ((gr == 2 || gr == 3) && suma == a->dato)
        return 1;

    return verifica2(a->der);
}

int recorreBosque2(arbol0 a) {
    int verif = 1;

    while (a != NULL && verif) {
        verif = verifica2(a);
        a = a->der;
    }

    return verif;
}

int main() {
    arbol0 a = NULL;

    cargaArbolEnteros(&a);

    printf("El bosque %s verifica la condicion solicitada.\n",recorreBosque(a) ? "SI" : "NO");
    printf("El bosque %s verifica la condicion solicitada.\n",recorreBosque2(a) ? "SI" : "NO");

    return 0;
}