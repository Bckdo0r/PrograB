/* Se tiene una lista con equipos de fútbol (nombre y puntaje en el torneo), la cual está ordenada 
descendentemente por puntaje (los equipos con el mismo puntaje están ordenados 
alfabéticamente). Cada equipo cuenta con una sublista de jugadores (nombre y edad, estado 
([A]ctivo, [S]uspendido)). 
a) Listar para todos los clubes los jugadores cuyo nombre comienza con la letra K (dato). Al 
finalizar mostrar cantidad de jugadores listados y el club que tiene más jugadores que 
cumplan el criterio solicitado. 
b) Listar los clubes que tienen un mínimo de X (dato) puntos junto con todos sus jugadores, 
mostrando edad promedio de cada equipo. 
c) Verificar si el equipo E (dato) tiene P (dato) puntos. 
d) Eliminar los jugadores que se encuentren en estado inactivo en todos los equipos. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char string[20];

typedef struct nodito{
   string nombre;
   int edad;
   char estado;
   struct nodito *sig;
} nodito;

typedef nodito *SubLista;

typedef struct nodo{
   string club;
   int puntos;
   SubLista *jug;
   struct nodo *sig;
} nodo;

typedef nodo *Lista;

//!funcion para agregar nodos a la lista
void agregaNodoL(Lista *,string,int);
//!funcion para agregar nodos a la sublista
void agregaNodoSL(SubLista *,string,int,char);

void cargaEquipos(Lista *);
void listaJugK(Lista *);
void listaClubMasX(Lista *);
int verifica(Lista, string, int);
void eliminaInactivos(Lista *);

int main() {


   return 0;
}

void agregaNodoL(Lista *L,string club,int puntos){
   Lista new,ant,act;
   
   new = (Lista*)malloc(sizeof(nodo));
   act = *L;
   ant = NULL;
   
   strcpy(new->club,club);
   new->puntos = puntos;
   new->jug = NULL;

   while (act != NULL && act->puntos < puntos){
      ant = act;
      act = act->sig;
   }

   if (ant == NULL){
      new->sig = *L;
      *L = new;
   }
   else{
      ant->sig = new;
      new->sig = act;
   }
}

void agregaNodoSL(SubLista *sL,string nombre,int edad,char estado){
   SubLista new;

   new = (SubLista*)malloc(sizeof(nodito));
   strcpy(new->nombre,nombre);
   new->edad = edad;
   new->estado = estado;

   new->sig = *sL;
   *sL = new;
}

void cargaEquipos(Lista *L){
   FILE *arch;
   int puntos,edad,n,i;
   char estado;
   string nombre,club;

   *L = NULL;
   arch = fopen("datosEJ7.txt","r");

   if (arch==NULL)
      printf("Error lens.");
   else {
      while(fscanf(arch,"%s %d %d",club,&puntos,&n) == 3){
        
         
         for (i=0; i<n ;i++){
            fscanf(arch,"%s %d %c",nombre,&edad,&estado);
            
         }

      }
   }


}