/* Dadas dos listas simplemente enlazadas de enteros L1 y L2: 
a) verificar si son iguales. Considerar que están ordenadas. 
b) añadir L2 al final de L1, en el caso de que el primer elemento de L2 sea mayor al último de 
L1. En otro caso, añadir L1 al final de L2. 
c) eliminar de L1 los nodos cuyas posiciones se encuentran en L2, la cual está ordenada. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo{
   int num;
   struct nodo *sig;
} nodoL;

typedef nodoL *Lista;

void agregaNodoSO(Lista *,int); //SO = sin orden
void agregaNodo(Lista *,int);
void cargaLista(Lista *,Lista *);
int verificaIgual(Lista ,Lista);
void juntaListas(Lista,Lista);
void eliminaNodos(Lista *,Lista);
void muestraLista(Lista);

int main() {
   Lista L1,L2;

   L1 = NULL;
   L2 = NULL;

   cargaLista(&L1,&L2);
   muestraLista(L1);
   printf("\n");
   muestraLista(L2);
   printf("\n");
   printf("Las listas son iguales? %s",verificaIgual(L1,L2)? "SI":"NO");
   printf("\n");
   juntaListas(L1,L2);
   //muestraLista(L1);
   //muestraLista(L2);
   //eliminaNodos(&L1,L2);
   //muestraLista(L1);

   return 0;
}

void agregaNodoSO(Lista *L,int n){
   Lista aux,new;
   new = (Lista)malloc(sizeof(nodoL));
   new->num = n;
   aux = *L;
   while (aux->sig != NULL)
      aux = aux->sig;
   
   new->sig = NULL;
   
}

void agregaNodo(Lista *L,int n){
   Lista new,ant,act;
   new = (Lista)malloc(sizeof(nodoL));
   new->num = n;
   ant = NULL;

   //*Si la lista esta vacia
   if (*L == NULL){
      new->sig = NULL;
      *L = new;
   }

   //*Si es la cabeza
   else if (n < (*L)->num){
      new->sig = (*L)->sig;
      *L = new;
   }

   //*Si se encuentra en el medio
   else {
      act = *L;
      while (act != NULL && n > act->num) {
         ant = act;
         act = act->sig;
      }

      if (act == NULL) {
         ant->sig = new;
         new->sig = NULL;
      }
      else {
         new->sig = act;
         ant->sig = new;
      }
   }
}

void cargaLista(Lista *L1,Lista *L2){
   FILE *arch;
   int i,j,num;

   arch = fopen("datosEJ1.txt","r");

   if (arch == NULL)
      printf("Error al abrir el archivo\n");
   else{
      fscanf(arch,"%d",&i);
      for (j=0; j<i ;j++){
         fscanf(arch,"%d",&num);
         agregaNodo(L1,num);
      }
      fscanf(arch,"%d",&i);
      for (j=0; j<i ;j++){
         fscanf(arch,"%d",&num);
         agregaNodo(L2,num);
      }
   }
   fclose(arch);   
}

int verificaIgual(Lista L1,Lista L2){
   while (L1 != NULL && L2 != NULL && L1->num == L2->num){
      L1 = L1->sig;
      L2 = L2->sig;
   }
   
   return L1 == NULL && L2 == NULL;   
}

/*añadir L2 al final de L1, en el caso de que el primer elemento de L2 sea mayor al último de 
L1. En otro caso, añadir L1 al final de L2. */


//!Complex
void juntaListas(Lista L1,Lista L2){
   Lista aux;
   int n;

   aux = L1;
   while (aux->sig != NULL)
      aux = aux->sig;
   
   n = aux->num;

   if (L2->num > n){
      aux->sig = L2; 
      muestraLista(L1);
      printf("\n");
   }
      
   else {
      aux = L2;
      while (aux->sig != NULL)
         aux = aux->sig;

      aux->sig = L1;
      muestraLista(L2);
      printf("\n");
   }
   
}

//eliminar de L1 los nodos cuyas posiciones se encuentran en L2, la cual está ordenada.

void eliminaNodos(Lista *L1,Lista L2){
   Lista ant,act;
   int i,j;

   while (L2 != NULL){
      
      i = L2->num;
      ant = NULL;
      act = *L1;

      
      
   }
}

void muestraLista(Lista L){
   while (L != NULL){
      printf("%d ",L->num);
      L = L->sig;
   }     
}