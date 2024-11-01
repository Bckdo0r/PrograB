#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Practica7/TDA/arboles.h"
#include "../Practica8/grafo.h"

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

/* Dada la matriz de adyacencia de un digrafo de N vertices y la matriz final de floyd para el mismo digrafo, hallar
de forma recursive el vertice Vi que no tiene bucle y alcanza la mayor cantidad de vertices con costo mayor a X
En el caso de que existan más que uno, devolver el ultimo. */

int calculaPeso(TMat M,TMat F,int V,int j){
    int peso = 0,indice;

    if (j>N)
        return peso;
        
    indice = F[V][j];

    peso += indice ? calculaPeso(M, F, V, indice) : M[V][indice];

    return peso + calculaPeso(M,F,V,j+1); 
}

int verticeCumple(TMat M,TMat F,int i,int X,int maxV,int maxPeso){
    
    if (i>N)
        return maxV;
    
    if (M[i][i])
        return verticeCumple(M,F,i+1,X,maxV,maxPeso);

    int peso = calculaPeso(M,F,i,0);

    if (peso >= maxPeso && peso > X){
        maxPeso = peso;
        maxV = i;
    }

    return verticeCumple(M,F,i+1,X,maxV,maxPeso);

}