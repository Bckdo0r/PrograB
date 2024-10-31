#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Practica7/TDA/arboles.h"

/*
Dado un AB de enteros proviente de la transformacion de un arbol general, se pide obtener la suma de las claves de 
grado impar ubicadas en niveles menores a K (dato). El grado y el nivel se refieren a los del arbol original.
*/

int Grado(arbol A) {
    int gr = 0;

    if (A == NULL)
        return 0;

    A = A->izq;

    while (A != NULL)
    {
        gr++;
        A = A->der;
    }

    return gr;
}

int SumaArbol(arbol A, int K, int nivel) {
    if (A == NULL)
        return 0;

    if (nivel < K)
        return (Grado(A) % 2 == 1 ? A->dato : 0) + SumaArbol(A->izq, K, nivel + 1) + SumaArbol(A->der, K, nivel);

    return 0;
}

int main() {


    return 0;
}

// EJ 2)
/*
Dado un arbol N ario de caracteres verificar que exista alguna nodo no hoja, de grado par cuya clave sea vocal 
y todos sus hijos tambien lo sean.
*/

int EsHoja(arbol A, posicion p) {
    return Nulo(p) || Nulo(HijoMasIzq(A, p));
}

int Grado(arbol A, posicion p) {
    posicion c;
    int gr = 0;

    if (EsHoja(A, p))
        return 0;
    
    c = HijoMasIzq(A, p);
    while (!Nulo(c)) {
        gr++;
        c = HermanoDer(A, c);
    }

    return gr;
}

int EsVocal(char c) {
    c = toupper(c);
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}


/*
Dado un arbol N ario de caracteres verificar que exista alguna nodo no hoja, de grado par cuya clave sea vocal 
y todos sus hijos tambien lo sean.
*/
int Verifica(arbol A, posicion p) {
    posicion c;
    int existe = 1;

    if (Nulo(p))
        return 0;

    if (!EsHoja(A, p) && EsVocal(Info(p)) && Grado(A, p) % 2 == 0) {
        c = HijoMasIzq(A, p);
        while (!Nulo(c) && existe) {
            existe = EsVocal(Info(c));
            c = HermanoDer(A, c);
        }
        if (existe)
            return 1;
    } 

    while (!Nulo(c) && existe) {
        existe = Verifica(A, c);
        c = HermanoDer(A, c);
    }

    return existe;
}