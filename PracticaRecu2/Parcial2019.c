#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../Practica7/TDA/arboles.h"

/* Dado un arbo binario proveniente de la transformacion de un arbol general, obtener mediante una funcion int la suma de las claves
que en el arbol general su clave coincida con su altura y con su grado */

int gradoAlt(arbol0 a,int altura){
    int gr = 0;

    while (a != NULL && gr < altura){
        gr++;
        a = a->der;
    }

    return gr == altura && a == NULL;
}

int sumaClaves(arbol0 a,int alt){
    int der;
    int suma = 0;
    
    if (a == NULL)
        return 0;

    if (gradoAlt(a->izq,alt))
        suma += a->dato;  
        
    return suma + sumaClaves(a->izq,alt+1) + sumaClaves(a->der,alt);
}

/* Dado un arbol N-Arios de enteros, desarrollar una funcion entera que obtenga la cantidad de nodos de grado mayor a 1, 
ubicadoes entro los niveles k1  y k2, que verifican que las claves del primer y del ultimo hijo son mayores al nivel del nodo. */
/*
int cuentaNodos(arbol0 a,posicion p,int K1,int K2,int lvl){
    int gr = 0,pri,ult,cont = 0;
    posicion c,b;
    
    if (nulo(p))
        return 0;
    
    if (lvl >= K1 && lvl <= K2){
        b = hijoMasIzq(p,a);
        if (!nulo(b) && !nulo(hrnoDer(b,a)) && info(b,a) > lvl){
            while (!nulo(hrnoDer(b,a)))
                b = hrnoDer(b,a);

            cont += info(b,a) > lvl;    
        }
    }
        
    c = hijoMasIzq(p,a);
    while(!nulo(c)){
        cont += cuentaNodos(a,c,K1,K2,lvl+1);

        c = hrnoDer(c,a);
    }

    return cont;       
}
*/
int cuentaNodos1(arbol0 a,int k1,int k2,int lvl){
    arbol0 c;
    int cont = 0,h1 = 0,h2;

    if (a != NULL && lvl <= k2){
        if (a->izq != NULL && a->izq->der != NULL)
            h1 = a->izq->dato > lvl;
        
        c = a->izq;
        while (c != NULL){
            cont += cuentaNodos1(c,k1,k2,lvl+1);
            h2 = c->dato > lvl;
            c = c->der;
        }

        cont += lvl >= k1 && h1 && h2;    
    }

    return cont;
}

int cantNodos(arbol0 a, int k1, int k2, int nivelAct){
    arbol0 c,aux;
    int cont = 0;

    if (a == NULL)
        return 0;

    if (nivelAct >= k1 && nivelAct <= k2){
        if (a->izq != NULL)
            if (a->izq->dato > nivelAct){
                aux = a->izq;
                
                while (aux->der != NULL)
                    aux = aux->der;
                
                if (aux->dato > nivelAct)
                    cont ++;        
            }   
    }

    c = a->izq;
    while (c != NULL){
        cont += cantNodos(c,k1,k2,nivelAct+1);
        c = c->der; 
    }

    return cont;        
}

int main() {
    arbol0 a = NULL;
    clock_t inicio, fin;
    double tiempo_ejecucion;

    cargaArbolEnteros(&a);
    printf ("La suma de las claves es %d.\n",sumaClaves(a,0));
    inicio = clock();
    printf ("La cantidad de nodos que cumplen son %d.\n",cantNodos(a,2,4,1));
    fin = clock();
    tiempo_ejecucion = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecucion: %.6f segundos\n", tiempo_ejecucion);
    inicio = clock();
    printf ("La cantidad de nodos que cumplen son %d.\n",cuentaNodos1(a,2,4,1));
    fin = clock();
    tiempo_ejecucion = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecucion: %f segundos\n", tiempo_ejecucion);
    
    return 0;
}