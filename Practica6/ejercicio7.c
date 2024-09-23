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

typedef struct nodito
{
   string nombre;
   int edad;
   char estado;
   struct nodito *sig;
} nodito;

typedef nodito *SubLista;

typedef struct nodo
{
   string club;
   int puntos;
   SubLista jug;
   struct nodo *sig;
} nodo;

typedef nodo *Lista;

//! funcion para agregar nodos a la lista
void agregaNodoL(Lista *, string, int);
//! funcion para agregar nodos a la sublista
void agregaNodoSL(SubLista *, string, int, char);

void cargaEquipos(Lista *);
void listaJugK(Lista, char);
void listaClubMasX(Lista, int);
int verifica(Lista, string, int);
void eliminaInactivos(Lista);

int main()
{
   Lista L;

   cargaEquipos(&L);
   listaJugK(L, 'C');
   listaClubMasX(L, 2);
   /*
   printf("Boca tiene 10 puntos? %s\n", verifica(L, "Boca", 10) ? "Si" : "No");
   eliminaInactivos(L); */

   return 0;
}

void agregaNodoL(Lista *L, string club, int puntos)
{
   Lista new, ant, act;

   new = (Lista)malloc(sizeof(nodo));
   act = *L;
   ant = NULL;

   strcpy(new->club, club);
   new->puntos = puntos;
   new->jug = NULL;

   while (act != NULL && act->puntos > puntos)
   {
      ant = act;
      act = act->sig;
   }

   if (ant == NULL)
   {
      new->sig = *L;
      *L = new;
   }
   else
   {
      ant->sig = new;
      new->sig = act;
   }
}

void agregaNodoSL(SubLista *sL, string nombre, int edad, char estado)
{
   SubLista nuevo = (SubLista)malloc(sizeof(nodito));

   strcpy(nuevo->nombre, nombre);
   nuevo->edad = edad;
   nuevo->estado = estado;

   nuevo->sig = *sL;
   *sL = nuevo;
}

void cargaEquipos(Lista *L)
{
   FILE *arch;
   int puntos, edad, n, i;
   char estado;
   Lista act = NULL;
   string nombre, club;

   *L = NULL;
   arch = fopen("datosEJ7.txt", "r");

   if (arch == NULL)
      printf("Error lens.");
   else
   {
      while (fscanf(arch, "%s %d %d", club, &puntos, &n) == 3)
      {
         agregaNodoL(L, club, puntos);

         if (act == NULL)
            act = *L;

         for (i = 0; i < n; i++)
         {
            fscanf(arch, "%s %d %c", nombre, &edad, &estado);
            agregaNodoSL(&(act->jug), nombre, edad, estado);
         }

         act = act->sig;
      }
   }
}

/*
a) Listar para todos los clubes los jugadores cuyo nombre comienza con la letra K (dato). Al
finalizar mostrar cantidad de jugadores listados y el club que tiene más jugadores que
cumplan el criterio solicitado.
*/
void listaJugK(Lista L, char K)
{
   SubLista actS;

   int cantJug = 0, cantMax = -1, cantJugPorClub = 0;
   string clubMax;
   clubMax[0] = '\0';

   while (L != NULL)
   {
      actS = L->jug;
      cantJugPorClub = 0;
      while (actS != NULL)
      {
         if (actS->nombre[0] == K)
         {
            printf("%s\n", actS->nombre);
            cantJug++;
            cantJugPorClub++;
         }

         actS = actS->sig;
      }
      if (cantJugPorClub > cantMax)
      {
         cantMax = cantJugPorClub;
         strcpy(clubMax, L->club);
      }

      L = L->sig;
   }

   printf("Cantidad de jugadores listados: %d\n", cantJug);
   printf("Club con mas jugadores que cumplen el criterio: %s\n", clubMax);
}

/*
b) Listar los clubes que tienen un mínimo de X (dato) puntos junto con todos sus jugadores,
mostrando edad promedio de cada equipo.
*/
void listaClubMasX(Lista L, int puntos)
{

   SubLista auxS;
   int suma = 0, cont = 0;

   while (L != NULL)
   {
      if (L->puntos > puntos)
      {
         auxS = L->jug;
         printf("%s tiene %d puntos\n", L->club, L->puntos);
         while (auxS != NULL)
         {
            printf("\t %s: %d %c\n", auxS->nombre, auxS->edad, auxS->estado);
            auxS = auxS->sig;
            suma += auxS->edad;
            cont++;
         }
         printf("Promedio de edad: %.2f\n", ((float)suma) / cont);
      }
      L = L->sig;
   }
}

/*d) Eliminar los jugadores que se encuentren en estado inactivo en todos los equipos. */
void eliminaInactivos(Lista L)
{

   SubLista antS, actS, elimS;

   while (L != NULL)
   {
      actS = L->jug;

      while (actS != NULL)
      {
         if (actS->estado == 'S')
         {
            if (actS == L->jug)
               L->jug = actS->sig;
            else
               antS->sig = actS->sig;

            elimS = actS;
            actS = actS->sig;
            free(elimS);
         }
         else
         {
            antS = actS;
            actS = actS->sig;
         }
      }
      L = L->sig;
   }
}

int verifica(Lista L, string club, int puntos)
{
   while (L != NULL && strcmp(L->club, club) != 0)
      L = L->sig;

   return L != NULL && L->puntos == puntos;
}