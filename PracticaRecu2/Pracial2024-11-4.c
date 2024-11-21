#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../Practica5/TDAs/pilas0.h"
#define MAX 20

typedef char string[MAX];
typedef int posicion;

typedef struct nodo{
    string dato;
    struct nodo *izq,*der;
} nodoA, *Arbol;

int esConsonante(char c){
    c = toupper(c);

    return c >= 'A' && c <= 'Z'  && c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U';
}

int cuentaGr(Arbol a){
    int gr = 0;

    while (a != NULL){
        gr++;
        a = a->der;
    }

    return gr;
}

int verifica(Arbol a){
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

int recorreBosque(Arbol r){
    int verif = 1;

    while(r != NULL && verif){
        verif = 0;
        
        if (esConsonante(r->dato[0]) && cuentaGr(r->izq))
            verif = 1;
        else
            verif = verifica(r->izq);
        
        if (verif)
            r = r->der;        
    }

    return verif;
}

// Prueba del recorrido preorden
int main() {
    // Crear el árbol de prueba
    Arbol raiz = crearNodo(10);
    raiz->izq = crearNodo(5);
    raiz->der = crearNodo(15);
    raiz->izq->izq = crearNodo(2);
    raiz->izq->der = crearNodo(7);

    printf("El bosque %s cumple.\n",recorreBosque(raiz) ? "SI" : "NO");

    return 0;
}

//Cantidad de nodos en niveles menores a K que verifican que su primer hijo y el resto de los hijos son multiplos del primero

int cuentaNodos(Arbol a, posicion p, int K, int lvl, int cont){
    if (!nulo(p,a)){
        if (lvl < K){
            a = hijoMasIzq(p,a);
            
        }
    }
}