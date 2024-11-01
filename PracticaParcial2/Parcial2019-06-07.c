#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Practica7/TDA/arboles.h"

void cargaArbol(arbol);

int main() {


    return 0;
}

/* Dado un ABB de caracteres, obtener la clave del nodo de grado 2 que se encuentre ubicado en el mayor nivel. Si no hubiere
nodo de grado 2 en el arbol, retornar el caracter vacio. */
void claveGr2MaxLvl(arbol a,int nivel,int nivelMax, char *clave){
    if (a != NULL) {
        if (a->izq != NULL && a->der != NULL && nivel > nivelMax){
            (*clave) = a->dato;
            nivelMax = nivel;
        }
        claveGr2MaxLvl(a->izq, nivel+1, nivelMax, clave);
        claveGr2MaxLvl(a->der, nivel+1, nivelMax, clave);
    }
}

/* Dado un arbol N-Arios de enteros, desarrollar una funcion entera que obtenga la cantidad de nodos de grado mayor a 1, 
ubicadoes entro los niveles k1  y k2, que verifican que las claves del primer y del ultimo hijo son mayores al nivel del nodo. */

int cantNodos(arbol a,posicion p, int k1,int k2,int nivelAct){
    posicion c,aux;
    int cont = 0;

    if (nulo(p))
        return 0;
    
    if (nivelAct >= k1 && nivelAct <= k2){
        if (!nulo(hijoMasIzq(p,a)))
            if (info(hijoMasIzq(p,a)) > nivelAct){
                aux = hijoMasIzq(p,a);
                
                while (!nulo(hrnoDer(p,aux)))
                    aux = hrnoDer(p,aux);
                
                if (info(aux) > nivelAct)
                    cont ++;        
            }   
    }

    c = hijoMasIzq(p,a);
    nivelAct ++;
    while (!nulo(c)){
        cont += cantNodos(a,p,k1,k2,nivelAct);
        c = hrnoDer(c,a); 
    }

    return cont;        
}