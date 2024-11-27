#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Practica7/TDA/arboles.h"

// Dado un árbol N-ario de enteros, desarrollar funciones utilizando TDA N.ARIO para:

//! god
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
void porcClavesP(arbol0 a,posicion p,float *porcen,int *contPares,int *contNodos){
    posicion c;

    if (!nulo(p)){
        (*contNodos)++;
        if (info(p,a) % 2 == 0)
            (*contPares)++;

        c = hijoMasIzq(p,a);
        while(!nulo(c)){
            porcClavesP(a,c,porcen,contPares,contNodos);
            c = hrnoDer(c,a);
        }
    }

    (*porcen) = (*contNodos) > 0 ? (float)(*contPares) * 100 / (*contNodos) : 0; 
}

//! Mepa que no va a funcionar porque tenés el grM como variable local. Creo que solo te va a tomar las dos últimas comparaciones. (CREO) 
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
    }

    return cont + (gr % 2 != 0 && lvl % 2 != 0);
}

//e) verificar si cumple que para todas las claves salvo las de las hojas, su valor numérico es igual 
//a la cantidad de hijos. (función int y función void) 
int cumpleInt(arbol0 a,posicion p){
    int dato,contH = 0,verif = 1;
    posicion c;

    if (!nulo(p) && verif){
        dato = info(p,a);
        c = hijoMasIzq(p,a);

        while(!nulo(c) && verif){ //! Acá tmb iría el verif, porque a la vuelta de la recursividad, si alguno de los hijos no cumple, ya no deberías seguir.
            contH++;
            verif = cumpleInt(a,c);
            c = hrnoDer(c,a); 
        }

        if (contH > 0) //*modif
            verif = dato == contH;
    }

    return verif;
}

void cumpleVoid(arbol0 a,posicion p,int *verif){
    int dato,contH = 0;
    posicion c;

    if (!nulo(p) && (*verif)){
        dato = info(p,a);
        c = hijoMasIzq(p,a);

        while(!nulo(c) && (*verif)){
            contH++;
            verif = cumpleInt(a,c);
            c = hrnoDer(c,a); 
        }

        if (contH > 0) //* modif
            (*verif) = dato == contH; 
    }
}

//f) obtener el promedio de las claves del nivel K (dato)


//! eee (-4 puntos)
int main() {


    return 0;
}