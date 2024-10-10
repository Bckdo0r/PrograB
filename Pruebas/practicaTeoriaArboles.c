#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//!1-7-12-5-17-10-16-59-26-24-33-50-30
//*1-7-10-12-5-17-30-50-16-33-24-59-26

//1-7-12-5-17-10-16-59-26-24-33-50-30

typedef struct nodo{
   int dato;
   struct nodo *izq,*der;
} nodo;

typedef nodo *Arbol;

void cantHojas(Arbol A, int *cont){
   if (A != NULL){
      if (A->izq == NULL && A->der == NULL)
         (*cont)++;
      else{
         cantHojas(A->izq,cont);
         cantHojas(A->der,cont);      
      }   
   }
}

int contHojas(Arbol A){
   if (A != NULL){
      if (A->izq == NULL && A->der == NULL)
         return 1 + contHojas(A);

   }

}
int main() {


   return 0;
}