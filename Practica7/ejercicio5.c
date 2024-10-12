/* Desarrollar funciones para:
a) calcular la profundidad de un árbol binario.
b) retornar la longitud de la cadena más larga de un árbol binario de cadenas.
c) devolver la cantidad de hijos derechos que contiene un árbol binario */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDA/arboles.h"

int calculaProf(arbol,int);
int cadMasLarga(arbol,int);
int cantHijosDer(arbol,int);

int main() {
    arbol A;
    int contA=0, contB = 0, longitud;

    addNodo(&A, "INSANO");
    addNodo(&A->izq, "BUENOS");
    addNodo(&A->izq->izq, "DIAS");
    addNodo(&A->izq->der, "HOLA");
    addNodo(&A->der, "MUNDO");
    addNodo(&A->der->izq, "TRAPICHE");
    addNodo(&A->der->izq->der, "GOD");

    printf("La profundidad del arbol es %d\n",calculaProf(A,contA));
    longitud = cadMasLarga(A,contB);
    printf("La longitud de la cadena mas larga es %d\n",(longitud == 0)? 0:longitud+1);
    printf("La cantidad de hijos derechos que contiene el arbol %d",cantHijosDer(A,0));

    return 0;
}

int calculaProf(arbol A, int cont) {
    int profIzq,profDer;
    if (A == NULL)
        return cont;
    ++cont;

    //* La profundidad máxima entre los subárboles izquierdo y derecho
    profIzq = calculaProf(A->izq, cont);
    profDer = calculaProf(A->der, cont);

    return (profIzq > profDer) ? profIzq : profDer;
}

int cadMasLarga(arbol A,int cad){
    if (A == NULL)
        return cad;

    if (strlen(A->dato) > cad)
        cad = strlen(A->dato);

    cad = cadMasLarga(A->izq,cad);
    cad = cadMasLarga(A->der,cad);

    return cad;        
}

int cantHijosDer(arbol A,int cont){
    if (A == NULL)
        return cont;
    
    if (A->der != NULL)
        ++cont;
    
    cont = cantHijosDer(A->izq,cont);
    cont = cantHijosDer(A->der,cont);
    
    return cont;
}