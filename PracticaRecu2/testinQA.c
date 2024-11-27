#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Practica7/TDA/arboles.h"
#include <time.h>

int gradoMax(arbol0 a){
    int grM,gr = 0, Max = 0;
    arbol0 c;

    if (a != NULL){
        c = c->izq;
        while(c != NULL){
            gr++;
            grM = gradoMax(c);
            if (grM > Max)
                Max = grM;
            c = c->der;
        }
    }

    return gr > Max ? gr : Max;
}

int main() {
    arbol0 a = NULL;
    clock_t inicio, fin;
    double tiempo_ejecucion;

    cargaArbolEnteros(&a);

    inicio = clock();
    printf("Grado maximo: %d\n",gradoMax(a));
    fin = clock();
    
    tiempo_ejecucion = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecucion: %f segundos\n", tiempo_ejecucion);

    return 0;
}