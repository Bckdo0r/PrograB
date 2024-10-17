/* Desarrollar funciones para:
a) devolver la suma de los elementos múltiplos de 3 de un árbol binario.
b) retornar la cantidad de hojas de un árbol binario.
c) informar si un valor recibido como parámetro se encuentra en un árbol binario.  */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TDA/arboles.h"


int sumaMult3(arbol);
int cantHojas(arbol, int);
int seEncuentra(arbol, TElementoA);

int main() {
   arbol a;
   TElementoA x=7;

   addNodo(&a, 5);
   addNodo(&a->izq, 8);
   addNodo(&a->izq->izq, 3);
   addNodo(&a->izq->der, 6);
   addNodo(&a->der, 4);
   addNodo(&a->der->izq, 1);
   addNodo(&a->der->izq->der, 2);

   printf("Suma de los elementos multiplos de 3: %d\n",sumaMult3(a));
   printf("Cantidad de hojas: %d\n",cantHojas(a,0));
   printf("El numero %d %s se encuentra en el arbol.\n",x,seEncuentra(a,x)? "SI":"NO");
   return 0;
}

int sumaMult3(arbol A){
   int suma = 0;
   
   if (A == NULL)
      return 0; //caso base

   if (A->dato % 3 == 0)
      suma += (A->dato);
    
   return suma + sumaMult3(A->izq) + sumaMult3(A->der); //lleva el valor de suma a lo largo de la recursividad      
}

int cantHojas(arbol A, int cont){
   if (A == NULL)
      return cont;

   if (A->izq == NULL && A->der == NULL)
      ++cont;

   cont = cantHojas(A->izq,cont);
   cont = cantHojas(A->der,cont);

   return cont;   
}

int seEncuentra(arbol A,TElementoA x){
   if (A == NULL)
      return 0;

   if (A->dato == x)
      return 1;

   return seEncuentra(A->izq,x) || seEncuentra (A->der,x);
}