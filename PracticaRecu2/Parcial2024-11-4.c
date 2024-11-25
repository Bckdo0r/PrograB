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

int verifica2(arbol2 a){
    int verif = 0,consonante;
    arbol2 aux;
    int gr = 0;

    if (a == NULL)
        return 0;

    consonante = esConsonante(a->dato[0]);
    aux = a->izq;
    
    while (aux != NULL){
        gr++;
        verif = verifica2(aux);
        aux = aux->der;
    }

    if (consonante)
        verif = gr > 0 && gr % 2 == 0;

    if (verif)
        return 1;
    
    else
        return verifica (a->der);


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

int nodosVerif(arbol0 a,posicion p,int K,int lvl){
    int cant = 0,verif1 = 0,verif2 = 1,dato;
    posicion c,aux;

    if (nulo(p) || lvl >= K)
        return 0;

    c = aux = hijoMasIzq(p,a);

    if (!nulo(c)){
        verif1 = nulo(hijoMasIzq(c,a)) && !nulo(hrnoDer(c,a));
        dato = info(aux,a);
    }

    while (!nulo(c)){
        verif2 = verif1 && verif2 && info(c,a) % dato == 0;
        cant += nodosVerif(a,c,K,lvl+1);
        
        c = hrnoDer(c,a);
    }

    return cant + (verif1 && verif2);
}

int nodosVerif2(arbol0 a,int K,int lvl){
    int cant = 0,dato,verif1 = 0,verif2 = 1;
    arbol0 c;

    if (a == NULL || lvl >= K)
        return 0;

    c = a->izq;

    if (c != NULL){
        verif1 = c->izq == NULL && c->der != NULL;
        dato = c->dato;
    }    
        
    while (c != NULL){

        verif2 = verif1 && verif2 && c->dato % dato == 0;
        cant += nodosVerif2(c,K,lvl+1);
        
        c = c->der;
    }

    return cant + (verif1 && verif2);
}

// Prueba del recorrido preorden
int main() {
    // Crear el árbol de prueba
    arbol2 raiz;
    arbol0 a;
    cargaArbolCadenas(&raiz);
    cargaArbolEnteros(&a);
    printf("El bosque %s cumple.\n",recorreBosque(raiz) ? "SI" : "NO");
    printf("%d nodos cumplen.\n",nodosVerif2(a,5,1));

    return 0;
}