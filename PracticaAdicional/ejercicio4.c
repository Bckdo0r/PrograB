/* Desarrollar un programa que gestione las reservas de pasajes para los vuelos de una aerolínea.
Para ello se cuenta con una lista de destinos con la siguiente estructura:
• Destino
• Sublista ordenada de Vuelos (a dicho destino)
   o Código de vuelo
   o Fecha y horario de salida
   o Capacidad de pasajeros
   o Sublista de pasajes vendidos (para dicho vuelo)
      ▪ Documento del pasajero

Tanto para la reserva como para su cancelación se solicita: destino, código de vuelo y
documento del pasajero. El programa debe además permitir agregar destinos y vuelos. Cada
vuelo tiene una fecha y horario de salida y capacidad de pasajeros. El programa debe también
listar el estado (cantidad de reservas, lugares disponibles, etc.) de todos los vuelos de un
destino solicitado al operador.

NOTA: Dado que no se requieren cálculos con las fechas y horarios de salida, se sugiere almacenar dicho campo
como una cadena */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef char string[100];

typedef struct noditoP
{
   string doc;
   struct noditoP *sig;
} noditoP;

typedef noditoP *SubListaP;
typedef struct noditoV
{
   string codV;
   string fecha;
   int capacity;
   struct noditoV *sig;
   SubListaP Pvendidos;
} noditoV;

typedef noditoV *SubListaV;

typedef struct nodo
{
   string destino;
   SubListaV Vuelos;
   struct nodo *sig;
} nodoLs;

typedef nodoLs *ListaS;

void agregarDestino(ListaS *, string);
void agregarPasaje(SubListaP *, string);
void agregarVuelo(ListaS, string, string, int);
void reservaPasaje(ListaS, string, string, string);
void cancelaPasaje(ListaS, string, string, string);
int cantPasajeros(SubListaP);
void generarCodigoAlfanumerico(char *, int);
void estadoVuelos (ListaS,string);

int main()
{
   ListaS L = NULL;
   string destino1, destino2, destino3, cod, doc, fecha1, fecha2, fecha3;
   strcpy(destino1, "Barca");
   strcpy(destino2, "Madrid");
   strcpy(destino3, "Valencia");
   strcpy(doc, "43999303");
   strcpy(fecha1, "14 de Julio, 20:00hs");
   strcpy(fecha2, "15 de Julio, 20:00hs");
   strcpy(fecha3, "16 de Julio, 20:00hs");

   agregarDestino(&L, destino1);
   agregarDestino(&L, destino2);
   agregarDestino(&L, destino3);
   agregarVuelo(L, destino1, fecha1, 100);
   agregarVuelo(L, destino2, fecha2, 100);
   agregarVuelo(L, destino3, fecha3, 100);
   estadoVuelos(L, destino1);
   estadoVuelos(L, destino2);
   estadoVuelos(L, destino3);

   printf("Ingrese cod: ");
   scanf("%s", cod);
   reservaPasaje(L,destino2, cod, doc);
   estadoVuelos(L, destino3);

   return 0;
}

ListaS buscaPorDestino(ListaS L, string destino)
{
   while (L != NULL && strcmp(L->destino, destino) != 0)
      L = L->sig;
   return L;
}

void generarCodigoAlfanumerico(char *codigo, int longitud)
{
   const char caracteres[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
   int numCaracteres = sizeof(caracteres) - 1;

   // Inicializar la semilla para los números aleatorios
   srand(time(NULL));

   for (int i = 0; i < longitud; i++)
   {
      int indice = rand() % numCaracteres;
      codigo[i] = caracteres[indice];
   }
   codigo[longitud] = '\0'; // Terminar el string
}

int cantPasajeros(SubListaP P)
{
   int cont = 0;

   while (P != NULL)
   {
      cont++;
      P = P->sig;
   }

   return cont;
}

void agregarPasaje(SubListaP *P, string doc)
{
   SubListaP aux = *P, new = (SubListaP)malloc(sizeof(noditoP));
   strcpy(new->doc, doc);

   while (aux != NULL && strcmp(aux->doc, doc) != 0)
      aux = aux->sig;

   if (aux == NULL)
   {
      new->sig = *P;
      *P = new;
   }
}

void removerPasaje(SubListaP *P, string doc)
{
   SubListaP ant, aux = *P;

   if (strcmp((*P)->doc, doc) != 0)
      *P = (*P)->sig;
   else
   {
      while (aux != NULL && strcmp(aux->doc, doc) != 0)
      {
         ant = aux;
         aux = aux->sig;
      }

      if (aux != NULL)
         ant->sig = aux->sig;
   }

   if (aux != NULL)
      free(aux);
}

/*
Tanto para la reserva como para su cancelación se solicita: destino, código de vuelo y
documento del pasajero.
*/
void reservaPasaje(ListaS L, string destino, string codV, string doc)
{
   SubListaV subV;

   L = buscaPorDestino(L, destino);

   if (L != NULL)
   {

      subV = L->Vuelos;

      while (subV != NULL && strcmp(codV, subV->codV) > 0)
         subV = subV->sig;

      if (subV != NULL && subV->capacity >= 1+ cantPasajeros(subV->Pvendidos))
         agregarPasaje(&subV->Pvendidos, doc);
   }
}

void cancelaPasaje(ListaS L, string destino, string codV, string doc)
{
   SubListaV subV;

   while (L != NULL && strcmp(L->destino, destino) != 0)
      L = L->sig;

   if (L != NULL)
   {

      subV = L->Vuelos;

      while (subV != NULL && strcmp(subV->codV, codV) < 0)
         subV = subV->sig;

      if (subV != NULL && subV->Pvendidos != NULL)
         removerPasaje(&subV->Pvendidos, doc);
   }
}

/* El programa debe además permitir agregar destinos y vuelos. Cada
vuelo tiene una fecha y horario de salida y capacidad de pasajeros. */

void agregarDestino(ListaS *L, string destino)
{
   ListaS new = (ListaS)malloc(sizeof(nodoLs));
   strcpy(new->destino, destino);

   new->Vuelos = NULL;
   new->sig = *L;
   *L = new;
}

void agregarVuelo(ListaS L, string destino, string fecha, int capacity)
{
   ListaS actS = buscaPorDestino(L, destino);
   SubListaV actV, antV, new;
   
   if (actS != NULL)
   {
      new = (SubListaV)malloc(sizeof(noditoV));
      generarCodigoAlfanumerico(new->codV, 7);
      strcpy(new->fecha, fecha);
      new->capacity = capacity;
      new->Pvendidos = NULL;

      actV = actS->Vuelos;
      
      if (actV == NULL || strcmp(new->codV, actV->codV) < 0) {
         
         new->sig = actS->Vuelos;
         actS->Vuelos = new;
      } else {

         while (actV != NULL && strcmp(new->codV, actV->codV) > 0) {
            antV = actV;
            actV = actV->sig;
         }

         antV->sig = new;
         new->sig = actV;
      }
   }
}

/* El programa debe también listar el estado (cantidad de reservas, lugares disponibles, etc.) 
de todos los vuelos de un destino solicitado al operador. */

void estadoVuelos (ListaS L, string destino){
   int reservas;
   ListaS aux = buscaPorDestino(L, destino);
   SubListaV auxV;

   if (aux != NULL){
      auxV = aux->Vuelos;
      printf("Codigo de vuelo | Cant de reservas | Lugares disponibles | Fecha\n");
      while (auxV != NULL){
         reservas = cantPasajeros(auxV->Pvendidos);
         printf("  %s\t\t%d\t\t   %d\t\t   %s\n",auxV->codV,reservas,auxV->capacity-reservas,auxV->fecha);
         auxV = auxV->sig;
      }
   }
}