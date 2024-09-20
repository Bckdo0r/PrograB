#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodito
{
   char fecha[15];
   float imp;
   struct nodito *sig;
} nodito;

typedef nodito *SubLista;

typedef struct nodo
{
   int num;
   float cred, deuda;
   struct nodo *sig;
   SubLista *sub;
} nodo;

typedef nodo *Lista;

void insertaPago(Lista, int, char *, float imp);

int main()
{

   return 0;
}

void insertaPago(Lista L, int numC, char *fecha, float imp)
{
   SubLista antS, auxS, nuevoS;

   while (L->num != numC)
      L = L->sig;

   L->deuda -= imp;
   auxS = L->sub;

   while (auxS != NULL && strcmp(auxS->fecha, fecha) > 0) {
      antS = auxS;
      auxS = auxS->sig;
   }

   nuevoS = (SubLista)malloc(sizeof(nodito));
   strcpy(nuevoS->fecha, fecha);
   nuevoS->imp = imp;

   if (auxS == L->sub) {
      nuevoS->sig = auxS;
      L->sub = nuevoS;
   }
   else {
      antS->sig = nuevoS;
      nuevoS->sig = auxS;
   }
}

void eliminaPago(Lista L, int numC, char *fecha) {
   SubLista antS, actS, elimS;

   while(L != NULL && L->num < numC) 
      L = L->sig;
   
   if (L != NULL && L->num == numC) {
      actS = L->sub;

      while (actS != NULL && strcmp(actS->fecha, fecha) > 0) {
         antS = actS;
         actS = actS->sig;
      }

      if (actS != NULL && strcmp(actS->fecha, fecha) == 0) {
         L->deuda += actS->imp;
         elimS = actS;

         if (actS == L->sub) 
            L->sub = actS->sig;
         else 
            antS->sig = actS->sig;

         free(elimS);
      }
   }
}

void eliminaCliente(Lista *L,int numC, int *cont){
   Lista ant,elim;
   SubLista antS,auxS;

   *cont = 0;

   ant = NULL;
   elim = *L;
   while (elim != NULL && elim->num < numC){
      ant = elim;
      elim = elim->sig;
   }

   if (elim != NULL && elim->num == numC){
      auxS = elim->sub;
      antS = NULL;

      while (auxS != NULL){
         antS = auxS;
         free(antS);
         auxS = auxS->sig;
         (*cont)++;
      }

      //!CABECERA
      if (elim == *L)
         *L = (*L)->sig;
      else
         ant->sig = elim->sig;
      
      free(elim);      
   }
}