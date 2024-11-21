#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../Practica7/TDA/arboles.h"
#define MAX 20

typedef char string[MAX];
typedef int posicion;

int esConsonante(char c){
    c = toupper(c);

    return c >= 'A' && c <= 'Z'  && c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U';
}

int cuentaGr(arbol2 a){
    int gr = 0;

    while (a != NULL){
        gr++;
        a = a->der;
    }

    return gr;
}

int verifica(arbol2 a){
    int verif = 0,consonante;
    int gr;

    if (a == NULL)
        return 0;
    
    else{

        consonante = esConsonante(a->dato[0]);

        if (consonante){
            gr = cuentaGr(a->izq);

            verif = gr > 0 && gr % 2 == 0;
        }

        if (verif)
            return 1;

        else
            return verifica (a->izq) || verifica (a->der);
    }

}

int recorreBosque(arbol2 r){
    int verif = 1,gr;

    while(r != NULL && verif){
        verif = 0;
        if (esConsonante(r->dato[0])){
            gr = cuentaGr(r->izq);
            
            verif = gr > 0 && gr % 2 == 0;

        }
        if (!verif)
            verif = verifica(r->izq);
        printf("\n");
        r = r->der;        
    }

    return verif;
}

// Prueba del recorrido preorden
int main() {
    // Crear el árbol de prueba
    arbol2 raiz;
    cargaArbolCadenas(&raiz);
    printf("El bosque %s cumple.\n",recorreBosque(raiz) ? "SI" : "NO");

    return 0;
}