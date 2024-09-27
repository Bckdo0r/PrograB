#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

void agregaNodoLs(ListaS *L,ElementoL x) {
   ListaS new = (ListaS)malloc(sizeof(nodoLs));

   new->dato = x;
   new->sig = *L;
   *L = new;
}

void agregaNodoLsOrd(ListaS *L,ElementoL x){
   ListaS new,ant,act;
   new = (ListaS)malloc(sizeof(nodoLs));
   new->dato = x;

   act = *L;
   ant = NULL;
   while (act != NULL && x > act->dato){
      ant = act;
      act = act->sig;
   };

   if (act == *L){
      new->sig = act;
      *L = new;
   }
   else {
      new->sig = act;
      ant->sig = new;
   }     

}

void agregaNodoLc(ListaC *L,ElementoL x){
   ListaC new = (ListaC)malloc(sizeof(nodoLs));
   new->dato = x;

   if (*L == NULL){
      new->sig = new;
      *L = new;
   }
   else{
      new->sig = (*L)->sig;
      (*L)->sig = new;
      *L = new;
   }
   
}

void agregaNodoLcOrd(ListaC *L,ElementoL x){
   ListaC ant,act,new = (ListaC)malloc(sizeof(nodoLs));
   new->dato = x;
   
   if (*L == NULL){
      new->sig = new;
      *L = new;
   }
   else {

      act = *L;
      act = act->sig;
      ant = act;

      while (act != *L && x > act->dato){
         ant = act;
         act = act->sig;
      }
      
      if (act == *L){
         new->sig = act->sig;
         act->sig = new;
         *L = new;
      }
      else{
         ant->sig = new;
         new->sig = act;
      }
   }
}

void agregaNodoLd(ListaD *L,ElementoL x){
   pnodoD new = (pnodoD)malloc(sizeof(nodoD));
   new->dato = x;

   if (L->pri == NULL){
      new->ant = NULL;
      L->pri = new;
      L->ult = new;
   }

   else{
      new->ant = L->ult;
      L->ult = new;
   }

   new->sig = NULL;
}

void agregaNodoLdOrd(ListaD *L,ElementoL x){
   pnodoD aux;
   pnodoD new = (pnodoD)malloc(sizeof(nodoD));
   new->dato = x;

   if (L->pri == NULL){
      new->ant = NULL;
      L->pri = new;
      L->ult = new;
   }

   else{
      aux = L->pri;
      while (aux != NULL && x > aux->dato){
         aux = aux->sig;
      }

      if (aux == L->pri){
         new->ant = NULL;
         new->sig = L->pri->sig;
         L->pri->sig->sig = new;
         L->pri = new;
      }
      else if (aux == L->ult){
         new->sig = NULL;
         new->ant = L->ult->sig;
         L->ult->sig->sig = new;
         L->ult = new;
      }
      else{
         new->sig = aux;
         new->ant = aux->ant;
         aux->ant->sig = new;
         aux->ant = new;
      }
   }
}