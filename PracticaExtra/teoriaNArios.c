/* 

    RECORRIDOS 

    Preorden:   Visitar la raiz
                preorden Subarbol 1
                preorden Subarbol 2
                .
                .
                .
                preorden Subarbol n


    Inorden:    Inorden Subarbol 1
                Visitar la raiz
                Inorden Subarbol 2
                .
                .
                .
                Inorden Subarbol n

    !Preorden   30-10-1-17-5-2-22-8-40-3-7-24-25-16-15
                1-10-30-5-22-2-8-17-3-24-25-7-16-40-30            (P)



*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDA/arboles.h"

typedef unsigned short int posicion;

int main() {
    arbol a;

    preorden(a, Raiz(a));
    Inorden(a, Raiz(a));
    return 0;
}

void preorden(arbol A,posicion p){
    if (!Nulo(p)){

    }
}

void Inorden(arbol a, posicion p) {
    posicion c;
    if (!Nulo(p)) {
        c = HijoMasIzq(p, a);
        Inorden(a, c);
        printf("%d ", Info(p, a));
        while (!Nulo(c)) {
            c = HermanoDer(c, a);
            Inorden(a, c);
        }
    }
}

void cantGradoPar(arbol A, posicion p, int *cant) {
    posicion c;

    if (!Nulo(p)) {
        (*cant) += !(grado(A, p) % 2);

        c = HijoMasIzq(p, A);
        while (!Nulo(c)) {
            cantGradoPar(A, c, cant);
            c = HermandoDer(c, A);
        }
    }
}

int cantGradoPar2(arbol A, posicion p) {
    posicion c;
    int cont;

    if (Nulo(p)) return 0;

    cont = grado(A, c) % 2 == 0;
    c = HijoMasIzq(p, A);

    while (!Nulo(c)) {
        cont += cantGradoPar2(A, c);
        c = HermanoDer(c, A);
    }

    return cont;
}

int grado(arbol A, posicion p) {
    posicion c;
    int g = 0;

    if (Nulo(p)) return 0;

    c = HijoMasIzq(p, A);
    while (!Nulo(c)) {
        g++;
        c = HermanoDer(c, A);
    } 

    return g;
}

int esta(arbol A, posicion p, int x) {
    posicion c;
    int v = 0;

    if (Nulo(p)) return 0;
    if (Info(p) == x) return 1;

    c = HijoMasIzq(A, p);

    while (!Nulo(c) && !v) {
        v = esta(A, c, x);
        c = HermanoDer(A, c);
    }

    return v;
}