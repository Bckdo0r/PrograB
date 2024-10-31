/* Dado un árbol binario de enteros y un nivel K, verifica que todos los nodos en el nivel K estén en orden 
ascendente de izquierda a derecha. Si cumplen esta condición. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Practica7/TDA/arboles.h"

void verifica(arbol a,int K,int nivelAct, TElementoA *ant,int *verif){
    if (verif && a != NULL){

        if (nivelAct < K){
            verifica(a->izq,K,nivelAct+1,ant,verif);
            verifica(a->der,K,nivelAct+1,ant,verif);
        }
        
        else{
            if (a->dato >= (*ant))
                (*ant) = a->dato;
            else
                (*verif) = 0;    
        }
                 
    }
}

int main() {


    return 0;
}