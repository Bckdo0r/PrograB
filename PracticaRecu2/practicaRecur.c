#include <stdio.h>
#include <stdlib.h>
#include "../Practica7/TDA/arboles.h"

/* Dado un arbol binario que proviene de la transformacion de un bosque, determinar cunatos arboles del bosque
tienen exactamente un nodo de grado K (funciones NO VOID)*/

int gradoK(arbol0 a, int k){
    int gr = 0;

    while (a != NULL && gr < k){
        gr++;
        a = a->der;
    }

    return gr == k && a == NULL;
}

int verifica(arbol0 a, int K, int cuenta) {
    int x;
    if (a == NULL || cuenta > 1)
        return cuenta;
 
    cuenta += gradoK(a->izq, K);
    
    cuenta = verifica(a->izq, K, cuenta);
    return verifica(a->der, K, cuenta);    
}

int verifica2(arbol0 a, int K, int cuenta) {
    int x;
    if (a == NULL || cuenta == 2)
        return cuenta;

    if (gradoK(a->izq, K)){
        cuenta++;
        if (cuenta == 2)
            return cuenta;
    } 
        
    x = verifica(a->izq, K, cuenta);
    if (x == 2)
        return cuenta;

    return x + verifica(a->der, K, cuenta);     
}

int cuentaArboles(arbol0 r, int K){
    int cont = 0, cuenta;

    while (r != NULL){

        cuenta = gradoK(r->izq,K);
        cuenta += verifica(r->izq,K,cuenta);
        
        if (cuenta == 1)
            cont++;

        r = r->der;
    }

    return cont;
}

int main() {

    arbol0 a = NULL;
    int K = 4;

    cargaArbolEnteros(&a);
    printf ("\n%d arbol(es) del bosque tiene(n) SOLO UN nodo de grado %d\n",cuentaArboles(a,K),K);

    return 0;
}