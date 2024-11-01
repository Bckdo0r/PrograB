#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Practica7/TDA/arboles.h"


/* Dado un arbol N-Ario de enteros, determinar mediante una unica funcion cuantos nodos del arbol son hojas y
cuantos nodos del arbol tienen un hermano a izquierda que sea negativo. */

void cuentaNodos(arbol a, posicion p, int *cantHojas, int *izqNeg){
    posicion c;

    if (!nulo(p)){
        
        (*cantHojas) += nulo(hijoMasIzq(a,p));
        (*izqNeg) += info(p) < 0 && !nulo(hrnoDer(a,p));

        c = hijoMasIzq(a,p);
        while (!nulo(c)){
            cuentaNodos(a,c,cantHojas,izqNeg);

            c = hrnoDer(a,c);
        }
    }

}

void cuentaNodos2(arbol a, posicion p, int *cantHojas, int *izqNeg, int *verif){
    posicion c;

    if (!nulo(p)){
        
        (*cantHojas) += nulo(hijoMasIzq(a,p));
        
        if ((*verif) && info(p) < 0 && !nulo(hrnoDer(p,a))){
            (*izqNeg) ++; 
            (*verif) = 0;
        }

        c = hijoMasIzq(p,a);
        while (!nulo(c)){
            
            (*verif) ? cuentaNodos2(a,c,cantHojas,izqNeg,1) : cuentaNodos2(a,c,cantHojas,izqNeg,0);

            c = hrnoDer(c,a);
        }

        (*verif) = 1;
    }

}

int main() {
    arbol a;
    int cantHojas = 0,izqNeg = 0;

    cuentaNodos(a,raiz(a),&cantHojas,&izqNeg);

    return 0;
}