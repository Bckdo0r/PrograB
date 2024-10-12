/*Dado un árbol binario de cadenas de caracteres retornar el nivel en el que se encuentra la 
cadena más larga que comienza con A */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDA/arboles.h"

int retornaLvl(arbol, char, int, int);

int main() {
    arbol A;
    int lvl;

    addNodo(&A, "INSANO");
    addNodo(&A->izq, "ARBOLES");
    addNodo(&A->izq->izq, "DIAS");
    addNodo(&A->izq->der, "HOLA");
    addNodo(&A->der, "MUNDO");
    addNodo(&A->der->izq, "AINOGASTA");
    addNodo(&A->der->izq->der, "GOD");

    lvl = retornaLvl(A,'A',-1,0);

    if (lvl == -1)
        printf("No hay palabras que empiecen con 'A'.");
    else
        printf("El nivel de la palabra mas larga que comienza con A: %d",lvl);

    return 0;
}

int retornaLvl(arbol A, char car, int aux, int length) {
    int lvl = -1, profIzq, profDer; 

    if (A == NULL)
        return lvl; 

    ++aux;

    if (A->dato[0] == car) {
        if (strlen(A->dato) > length) {
            length = strlen(A->dato); 
            lvl = aux;  
        }
    }

    profIzq = retornaLvl(A->izq, car, aux, length);
    profDer = retornaLvl(A->der, car, aux, length);

    // Devolver el mayor nivel encontrado en los subárboles
    if (profIzq != -1 && (profIzq > lvl)) 
        lvl = profIzq;
    if (profDer != -1 && (profDer > lvl)) 
        lvl = profDer;

    return lvl;            
}