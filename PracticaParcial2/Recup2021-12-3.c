#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Practica7/TDA/arboles.h"

/* Dodo un arbol N-Arios de numeros enteros retornar la cantidad de nodos no hoja cuyo grado es menor 
al promedio de las claves de sus hijos */

int grado(arbol a,posicion p){
    int gr = 0;
    posicion c;
    c = hijoMasIzq(p,a);
    while (!nulo(c)){
        gr++;
        c = hrnoDer(c,a);
    }

    return gr;
}

float promClavesHijos(arbol a,posicion p){
    int suma = 0,cont = 0;
    posicion c;

    c = hijoMasIzq(p,a);
    while (!nulo(c)){
        suma += info(c);
        cont++;
        c = hrnoDer(c,a);
    }

    return cont > 0 ? (float)suma/cont : 0;
}

int contNodos(arbol a,posicion p){
    posicion c;
    int cont;

    if (nulo(p))
        return 0;

    cont += !nulo(hijoMasIzq(p,a)) ? grado(a,p) > promClavesHijos(a,p) : 0;
    
    c = hijoMasIzq(p,a);
    while (!nulo(c)){
        cont += contNodos(a,p);
        c = hrnoDer(c,a);
    }

    return cont;

}

int main() {


    return 0;
}