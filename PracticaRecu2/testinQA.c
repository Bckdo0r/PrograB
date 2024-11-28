#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Practica7/TDA/arboles.h"
#include <time.h>

int gradoYclave(arbol0 a,int dato){
    int gr = 0;
    while (a != NULL){
        gr++;
        a = a->der;
    }

    return dato == gr;
}

int cumpleInt1(arbol0 a){
    if (a == NULL)
        return 1;

    if (a->izq != NULL && !gradoYclave(a->izq,a->dato))
        return 0;

    return cumpleInt1(a->izq) && cumpleInt1(a->der);
}

int cumpleInt(arbol0 a){
    int dato,contH = 0,verif = 1;
    arbol0 c;

    if (a != NULL){
        dato = a->dato;
        c = a->izq;
        printf("%d\n",dato);

        while(c != NULL && verif){
            contH++;
            printf("%d\n",verif);
            verif = cumpleInt(c);
            c = c->der; 
        }

        if (contH > 0)
            verif = dato == contH;
    }

    return verif;
}

int main() {
    arbol0 a = NULL;
    clock_t inicio, fin;
    double tiempo_ejecucion;

    cargaArbolEnteros(&a);

    inicio = clock();
    printf("El arbol %s cumple.\n",cumpleInt1(a) ? "SI" : "NO");
    fin = clock();
    
    tiempo_ejecucion = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecucion: %f segundos\n", tiempo_ejecucion);

    return 0;
}