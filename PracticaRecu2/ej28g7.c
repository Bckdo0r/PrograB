#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Practica7/TDA/arboles.h"

/* Dado un árbol N-ario de enteros, desarrollar funciones utilizando TDA N.ARIO para: 
 
e) verificar si cumple que para todas las claves salvo las de las hojas, su valor numérico es igual 
a la cantidad de hijos. (función int y función void) 
f) obtener el promedio de las claves del nivel K (dato)  */

//a) retornar la cantidad de nodos que posee.
int cantNodos(arbol0 a,posicion p){
    int cont = 0;
    posicion c;

    if (!nulo(p)){
        cont++;
        c = hijoMasIzq(p,a);
        while(!nulo(c)){
            cont += cantNodos(a,c);
            c = hrnoDer(c,a);
        }
    }

    return cont;
}

//b) hallar el porcentaje de claves pares 
float porcClavesP(arbol0 a,posicion p){
    int cont = 0,suma = 0,dato;
    posicion c;

    if (!nulo(p)){
        dato = info(p,a);
        if (dato % 2 == 0){
            cont++ ;
            suma += dato;
        }

        c = hijoMasIzq(p,a);
        while(!nulo(c)){
            cont += porcClavesP(a,c);
            c = hrnoDer(c,a);
        }
    }

    return cont > 0 ? (float)suma / cont : 0;
}

//c) retornar su grado 
int gradoMax(arbol0 a,posicion p){
    int grM = 0,gr = 0;
    posicion c;

    if (!nulo(c)){
        c = hijoMasIzq(p,a);
        while(!nulo(c)){
            gr++;
            grM = gradoMax(c,p);
            c = hrnoDer(c,a);
        }

        if (gr > grM)
            grM = gr;
    }

    return grM;
}

//d) hallar la cantidad de nodos de grado impar que hay en niveles impares. 
int nodosGrImp(arbol0 a,posicion p,int lvl){
    int cont = 0, gr = 0;
    posicion c;

    if (!nulo(c)){
        c = hijoMasIzq(p,a);
        while (!nulo(c)){
            gr++;
            cont += nodosGrImp(a,c,lvl+1);
            c = hrnoDer(c,a);
        }

        cont += gr % 2 != 0 && lvl % 2 != 0;
    }

    return cont;
}

//e) verificar si cumple que para todas las claves salvo las de las hojas, su valor numérico es igual 
//a la cantidad de hijos. (función int y función void) 
int cumpleInt(arbol0 a,posicion p){
    int dato,contH = 0,verif = 1;
    posicion c;

    if (!nulo(p) && verif){
        dato = info(p,a);
        c = hijoMasIzq(p,a);

        while(!nulo(c)){
            contH++;
            verif = cumpleInt(a,c);
            c = hrnoDer(c,a); 
        }

        verif = contH > 0 && dato == contH; //el nodo no es hoja y la cantidad de hijos == clave
    }

    return verif;
}

void cumpleVoid(arbol0 a,posicion p,int *verif){
    int dato,contH = 0;
    posicion c;

    if (!nulo(p) && (*verif)){
        dato = info(p,a);
        c = hijoMasIzq(p,a);

        while(!nulo(c)){
            contH++;
            verif = cumpleInt(a,c);
            c = hrnoDer(c,a); 
        }

        (*verif) = contH > 0 && dato == contH; 
    }
}


int main() {


    return 0;
}