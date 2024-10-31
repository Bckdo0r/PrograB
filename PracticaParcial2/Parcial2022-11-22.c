#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Practica7/TDA/arboles.h"

void cargaArbol(arbol);
int verifica(arbol,int,int);

int main() {


    return 0;
}

/* Dado un AB de caracteres, verificar que todas las claves del nivel k (dato), son mayores a su padre
y menor a su hermano a derecha (si existe) */

int verifica(arbol a,int K,int nivelAct){

    int verif;

    if (a == NULL)
        return 1;

    if (nivelAct < K-1){
        verif = verifica(a->izq,K,nivelAct+1);
        verif = verifica(a->der,K,nivelAct+1);
    }

    verif = a->izq != NULL && a->der != NULL && a->izq->dato > a->dato && a->der->dato > a->izq->dato;

    return verif;

}#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Practica7/TDA/arboles.h"

void cargaArbol(arbol);
int verifica(arbol,int,int);

int main() {


    return 0;
}

/* Dado un AB de caracteres, verificar que todas las claves del nivel k (dato), son mayores a su padre
y menor a su hermano a derecha (si existe) */

int verifica(arbol a,int K,int nivelAct){

    int verif;

    if (a == NULL)
        return 1;

    if (nivelAct < K-1){
        verif = verifica(a->izq,K,nivelAct+1);
        verif = verifica(a->der,K,nivelAct+1);
    }

    verif = a->izq != NULL && a->der != NULL && a->izq->dato > a->dato && a->der->dato > a->izq->dato;

    return verif;

}

int verificaNivelK(arbol a, int K, int nivelAct, char padre, char hermanoDer) {
    if (a == NULL)
        return 1; // Si no hay nodo, no rompe la condición

    // Si aún no hemos llegado al nivel K, seguimos recorriendo
    if (nivelAct < K) {
        return verificaNivelK(a->izq, K, nivelAct + 1, a->dato, a->der ? a->der->dato : '\0') &&
               verificaNivelK(a->der, K, nivelAct + 1, a->dato, '\0');
    }


    // Condiciones del nivel K: el nodo debe ser mayor que el padre y menor que el hermano derecho (si existe)
    int cumplePadre = (padre == '\0' || a->dato > padre);
    int cumpleHermano = (hermanoDer == '\0' || a->dato < hermanoDer);

    return cumplePadre && cumpleHermano;
}

int verificaNivelK(arbol a, int K, int nivelAct, char padre, char hermanoDer) {
    if (a == NULL)
        return 1; // Si no hay nodo, no rompe la condición

    // Si aún no hemos llegado al nivel K, seguimos recorriendo
    if (nivelAct < K) {
        return verificaNivelK(a->izq, K, nivelAct + 1, a->dato, a->der ? a->der->dato : '\0') &&
               verificaNivelK(a->der, K, nivelAct + 1, a->dato, '\0');
    }


    // Condiciones del nivel K: el nodo debe ser mayor que el padre y menor que el hermano derecho (si existe)
    int cumplePadre = (padre == '\0' || a->dato > padre);
    int cumpleHermano = (hermanoDer == '\0' || a->dato < hermanoDer);

    return cumplePadre && cumpleHermano;
}