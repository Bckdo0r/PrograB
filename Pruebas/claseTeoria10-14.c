/*
Para transformar un arbol general a un arbol binario:

1) Unir hermanos
2) Cortar el enlace de un nodo con sus hijos excepto el hijo mas a izq
3) Rotar levemente el arbol en sentido horario


Para calcular el nivel/altura de un arbol de este estilo, hacer el recorrido
como un arbol binario normal, pero aumentar el contador cuando hay un hijo izq
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int TElem;

typedef struct nodo{
   TElem dato;
   struct nodo *izq,*der;
} nodo;

typedef nodo *arbol;

unsigned short int hojas(arbol a)
{
   if (a == NULL)
      return 0;
   else
      return (a->izq == NULL)? 1 + hojas(a->der): hojas(a->izq) + hojas(a->der);
}

unsigned short int raices(arbol a){
   int i = 1;
   printf("Arbol  Hojas\n");
   
   while (a != NULL){
      printf("%d %d\n",i,hojas(a->izq));
      i++;
      a = a->der;
   }

}

unsigned short int arbClavPar(){
   while 
}

int main() {


   return 0;
}