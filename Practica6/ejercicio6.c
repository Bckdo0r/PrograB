/* Una lista contiene en cada nodo una cola de números enteros. Desarrollar un programa que 
genere una pila con los elementos máximos de cada cola de la lista. (Utilizar TDA pila dinámica 
y TDA cola circular). */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Practica5/TDAs/pilasD.h"
#include "../Practica5/TDAs/colasC.h"

typedef struct nodo{
   TCola Cc;
   struct nodo *sig;
} nodo;

typedef nodo *Lista;

void cargaLista(Lista *);
void pilaMaxElem(Lista,TPila *);
void muestraPila(TPila *);

int main() {
   Lista L;
   TPila P;

   cargaLista(&L);
   pilaMaxElem(L,&P);
   muestraPila(&P);
   return 0;
}

void cargaLista(Lista *L){
   FILE *arch;
   Lista nuevo,ant,act;
   int i,n,dato;
   arch = fopen("datosEJ6.txt","r");
   *L = NULL;
   
   if (arch == NULL){
      printf("Error al abrir el archivo\n");
   }
   else {
      while (fscanf(arch,"%d",&n) == 1){
         nuevo = (Lista)malloc(sizeof(nodo));
         iniciaC(&(nuevo->Cc));
         
         for (i=0; i<n ;i++){
            fscanf(arch,"%d",&dato);
            poneC(&nuevo->Cc,dato);
         }
         //Que el puntero del nuevo nodo apunte a donde apuntaba *L
         nuevo->sig = *L;
         //Que *L apunte al nodo agregado
         *L = nuevo;
      }
      fclose(arch);
   }
}

void pilaMaxElem(Lista L,TPila *P){
   int max,num;
   TCola aux;

   iniciaP(P);
   while (L != NULL){   
      max = -9000;
      iniciaC(&aux);
      
      //Mientras que no este vacia la cola del nodo de la lista, guardar el maximo.
      while (!vaciaC(L->Cc)) {
         sacaC(&(L->Cc),&num);
         poneC(&aux,num);
         
         if (num > max)
            max = num;
      }
      poneP(P,max);

      //Procedimiento para no perder la cola
      while (!vaciaC(aux)) {
         sacaC(&aux,&num);
         poneC(&(L->Cc),num);
      }

      //Avanzo de nodo
      L = L->sig;
   }
}

void muestraPila(TPila *P){
   TPila aux;
   int num,i=1;
   iniciaP(&aux);

   printf("El maximo elemento de cada cola: \n");
   while (!vaciaP(*P)) {
      sacaP(P,&num);
      poneP(&aux,num);
      printf("Nodo %d: %d",i++,num);
   }
   
   while (!vacia(aux)) {
      sacaP(&aux,&num);
      poneP(P,num);
   }
   
}