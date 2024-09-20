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

void cargaEquipos(Lista *);
void listaJugK(Lista *);
void listaClubMasX(Lista *);
int verifica(Lista, string, int);
void eliminaInactivos(Lista *);

int main() {


   return 0;
}

