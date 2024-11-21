#include <stdio.h>
#include <stdlib.h>
#include "../Practica7/TDA/arboles.h"

/* Dado un arbol binario que proviene de la transformacion de un bosque, determinar cunatos arboles del bosque
tienen exactamente un nodo de grado K (funciones NO VOID)*/

int cuentaGr(arbol a){
    int gr = 0;

    while (a != NULL){
        gr++;
        a = a->der;
    }

    return gr;
}

int verifica(arbol a, int K, int verif){
    int gr;

    if (a == NULL)
        return 1;
    
    else {
        gr = cuentaGr(a->izq);

        if (gr == K){
            if (verif)
                return 0;
        
            verif = 1;    
        }

        return verifica(a->izq,K,verif) && verifica(a->der,K,verif);    
    }    
} 

int cuentaArboles(arbol r, int K){
    int cont = 0, verif;

    while (r != NULL){
        verif = 0;
        verif = cuentaGr(r->izq) == K ? 1 : 0;
        cont += verifica(r->izq,K,verif);

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

    printf ("%d arboles del bosque tiene 1 nodo de grado K\n",cuentaArboles(a,K));

    return 0;
}


