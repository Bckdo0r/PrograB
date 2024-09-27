/* Dadas dos listas simplemente enlazadas de enteros L1 y L2:
a) verificar si son iguales. Considerar que están ordenadas.
b) añadir L2 al final de L1, en el caso de que el primer elemento de L2 sea mayor al último de
L1. En otro caso, añadir L1 al final de L2.
c) eliminar de L1 los nodos cuyas posiciones se encuentran en L2, la cual está ordenada. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDAs/listas.h"

/*typedef struct nodo
{
   int dato;
   struct nodo *sig;
} nodoL;

typedef nodoL *Lista;
*/
//void agregaNodoSO(Lista *, int); // SO = sin orden
//void agregaNodo(Lista *, int);
void cargaLista(ListaS *, ListaS *);
int verificaIgual(ListaS, ListaS);
void juntaListas(ListaS, ListaS);
void eliminaNodos(ListaS *, ListaS);
void muestraLista(ListaS);

int main()
{
   ListaS L1, L2;

   L1 = NULL;
   L2 = NULL;

   cargaLista(&L1, &L2);
   printf("L1: ");
   muestraLista(L1);
   printf("L2: ");
   muestraLista(L2);
   printf("Las listas son iguales? %s", verificaIgual(L1, L2) ? "SI" : "NO");
   printf("\n");
   juntaListas(L1, L2);
   printf("L1: ");
   muestraLista(L1);
   printf("L2: ");
   muestraLista(L2);
   eliminaNodos(&L1, L2);
   printf("L1: ");
   muestraLista(L1);

   return 0;
}

/*void agregaNodoSO(Lista *L, int n)
{
   Lista aux, new;
   new = (Lista)malloc(sizeof(nodoL));
   new->dato = n;
   aux = *L;
   while (aux->sig != NULL)
      aux = aux->sig;

   new->sig = NULL;
}

void agregaNodo(Lista *L, int dato)
{
   Lista new, ant, act;
   new = (nodoL *)malloc(sizeof(nodoL));
   new->dato = dato;

   if (*L == NULL || (*L)->dato > dato)
   {
      new->sig = *L;
      *L = new;
   }
   else
   {
      act = *L;
      while (act != NULL && dato > act->dato)
      {
         ant = act;
         act = act->sig;
      }
      new->sig = act;
      ant->sig = new;
   }
}*/

void cargaLista(ListaS *L1, ListaS *L2)
{
   FILE *arch;
   int i, j, dato;

   arch = fopen("datosEJ1.txt", "r");

   if (arch == NULL)
      printf("Error al abrir el archivo\n");
   else
   {
      fscanf(arch, "%d", &i);
      for (j = 0; j < i; j++)
      {
         fscanf(arch, "%d", &dato);
         agregaNodoLsOrd(L1, dato);
      }
      fscanf(arch, "%d", &i);
      for (j = 0; j < i; j++)
      {
         fscanf(arch, "%d", &dato);
         agregaNodoLsOrd(L2, dato);
      }
   }
   fclose(arch);
}

int verificaIgual(ListaS L1, ListaS L2)
{
   while (L1 != NULL && L2 != NULL && L1->dato == L2->dato)
   {
      L1 = L1->sig;
      L2 = L2->sig;
   }

   return L1 == NULL && L2 == NULL;
}

/*añadir L2 al final de L1, en el caso de que el primer elemento de L2 sea mayor al último de
L1. En otro caso, añadir L1 al final de L2. */

//! Complex
void juntaListas(ListaS L1, ListaS L2)
{
   ListaS aux;
   int n;

   aux = L1;
   while (aux->sig != NULL)
      aux = aux->sig;

   n = aux->dato;

   if (L2->dato > n)
   {
      aux->sig = L2;
      muestraLista(L1);
      printf("\n");
   }

   else
   {
      aux = L2;
      while (aux->sig != NULL)
         aux = aux->sig;

      aux->sig = L1;
      muestraLista(L2);
      printf("\n");
   }
}

// eliminar de L1 los nodos cuyas posiciones se encuentran en L2, la cual está ordenada.

void eliminaNodos(ListaS *L1, ListaS L2)
{
   ListaS ant, act, elim;
   int i = 1;

   act = *L1;

   while (act != NULL)
   {

      while (L2 != NULL && L2->dato <= 0)
         L2 = L2->sig;

      if (L2 != NULL)
      {
         while (i < L2->dato)
         {
            i++;
            ant = act;
            act = act->sig;
         }

         if (act == *L1)
            *L1 = (*L1)->sig;
         else
            ant->sig = act->sig;

         elim = act;
         act = act->sig;
         free(elim);
         i = 1;
      }

      L2 = L2->sig;
   }
}

void muestraLista(ListaS L)
{
   while (L != NULL)
   {
      printf("%d ", L->dato);
      L = L->sig;
   }
   printf("\n");
}