#include <stdio.h>
#include <stdlib.h>
#include "../Practica7/TDA/arboles.h"

/* Dado un arbol binario que proviene de la transformacion de un bosque, determinar cunatos arboles del bosque
tienen exactamente un nodo de grado K (funciones NO VOID)*/

int gradoK(arbol a, int k){
    int gr = 0;

    while (a != NULL && gr < k){
        gr++;
        a = a->der;
    }

    return gr == k && a == NULL;
}

int verifica(arbol a, int K, int cuenta){
    arbol aux;
    if (a == NULL || cuenta > 1)
        return cuenta;
    
    else {
        aux = a->izq;
        
        cuenta += gradoK(aux, K);

        return verifica(aux,K,cuenta) + verifica(aux->der,K,cuenta);     
    }    
} 

int cuentaArboles(arbol r, int K){
    int cont = 0, cuenta;

    while (r != NULL){

        cuenta = verifica(r,K,0);

        if (cuenta == 1)
            cont++;

        r = r->der;
    }

    return cont;
}

int main() {

    arbol a = NULL;
    int K = 4;

    addNodo(&a, 1);                                          
    addNodo(&a->izq, 4);                           
    addNodo(&a->izq->der, 5);
    addNodo(&a->izq->der->izq, 6);        
    addNodo(&a->izq->der->izq->der, 8);        
    addNodo(&a->izq->der->der, 15);
    addNodo(&a->izq->der->der->izq, 11);
    addNodo(&a->izq->der->der->izq->der, 12);
    addNodo(&a->izq->der->der->izq->der->der, 13);
    addNodo(&a->izq->der->der->izq->der->der->izq, 14);
    addNodo(&a->izq->der->der->izq->der->der->izq->der, 16);
    addNodo(&a->izq->der->der->izq->der->der->izq->der->der, 17);
    addNodo(&a->izq->der->der->izq->der->der->izq->der->der->der, 18);
    addNodo(&a->izq->der->der->izq->der->der->izq->izq, 6);
    addNodo(&a->izq->der->der->izq->der->der->izq->izq->der, 12);
    addNodo(&a->izq->der->der->izq->der->der->izq->izq->der->der, 9);
    addNodo(&a->izq->izq, 5);                           
    addNodo(&a->izq->izq->der, 7);                           
    addNodo(&a->izq->izq->der->izq, 8);                           
    addNodo(&a->izq->izq->der->izq->der, 10);                           
    addNodo(&a->izq->izq->der->der, 12);
    addNodo(&a->izq->izq->izq, 21);
    addNodo(&a->izq->izq->izq->der, 11);
    addNodo(&a->izq->izq->izq->der->der, 17);

    addNodo(&a->der, 4);                                          
    addNodo(&a->der->izq, 15);                                          
    addNodo(&a->der->izq->der, 11);                                          
    addNodo(&a->der->izq->der->izq, 10);                                          
    addNodo(&a->der->izq->der->izq->der, 20);                                          
    addNodo(&a->der->izq->der->izq->der->der, 20);                                          
    addNodo(&a->der->izq->der->izq->der->der->der, 2);                                          
    addNodo(&a->der->izq->izq, 1);                                          
    addNodo(&a->der->izq->izq->der, 21);
                                              
    addNodo(&a->der->der, 19);                                          
    addNodo(&a->der->der->izq, 28);                                          
    addNodo(&a->der->der->izq->izq, 24);                                          
    addNodo(&a->der->der->izq->izq->der, 13);                                          
    addNodo(&a->der->der->izq->izq->der->der, 21);

    printf ("\n%d arboles del bosque tiene 1 nodo de grado K\n",cuentaArboles(a,K));

    return 0;
}


