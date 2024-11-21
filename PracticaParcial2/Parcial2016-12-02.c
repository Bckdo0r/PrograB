#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Practica7/TDA/arboles.h"
#include "../Practica8/grafo.h"

/* Dado un arbol N-ario de caracteres, verificar si en todos los niveles hay al menos una vocal. */

int esVocal(char c){
    c = toupper(c);
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

void verifica(arbol a, posicion p, int *verif, int vecVoc[], int nivelAct){
    posicion c;

    if (!nulo(p) && (*verif)){
        
        if (vecVoc[nivelAct] == 0)
            vecVoc[nivelAct] = esVocal(info(p));

        c = hijoMasIzq(p,a);;
        while(!nulo(c) && *verif){
            verifica(a,c,verif,vecVoc,nivelAct+1);

            c = hrnoDer(c,a);
        }

        if (vecVoc[nivelAct] == 0)
            *verif = 0;        
    }
}

/* Dado un digrafo ponderado almacenado en una matriz de adyacencia, determinar cual vertice tiene el mayor costo de entrada promedio.
Una unica funcion recursiva */

void verticeMax(TMat A, int i, int j, int suma, int grE, float *promMax, int *vMax){
    float prom;
    if (j < N){
        
        if (i < N){
            if (A[i][j] > 0){
                grE ++;
                suma += A[i][j]; 
            }
            verticeMax(A,i+1,j,suma,grE,promMax,vMax);
        }
        
        prom = grE > 0 ? (float)suma / grE : 0;
        if (prom > *promMax){
            *promMax = prom;
            *vMax = j;
        }

        verticeMax(A,0,j+1,0,0,promMax,vMax);
    }
}

/* Dado un arbol binario que proviene de la transformacion de un bosque, determinar cunatos arboles del bosque
tienen exactamente un nodo de grado K (funciones NO VOID)*/

int verificaArbol(arbol a,int K){
    int cont = 0 ,gr = 0;

    if (a == NULL)
        return 0;

    while (a != NULL){
        gr++;
        cont += verificaArbol(a->izq,K) + verificaArbol(a->der,K);

        a = a->der;
    }
 
    return cont + (gr == K);
}

int cuentaArboles(arbol a, int K){
    int cont = 0;

    while (a != NULL){
        cont += verificaArbol(a->izq,K);
        
        a = a->der;
    }

    return cont;
}

int main() {


    return 0;
}