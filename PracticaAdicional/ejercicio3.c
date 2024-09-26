/*
Simular un gestor de archivos simplificado mediante listas de carpetas que contengan sublistas
de carpetas y archivos. Implementar el listado del contenido de una carpeta ingresada como
dato. No es necesario listar el contenido de las subcarpetas de dicha carpeta.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo
{
   char nombre[100];
   struct nodo *sig, *sub;
} nodo;

typedef nodo *Lista;

void agregarFicheroADirectorio(Lista *, Lista);
void crearFichero(Lista *, char *);

void mostrarDirectorio(Lista, int);

int main()
{

   Lista D = NULL, archivo1, archivo2, archivo3, carpeta1, carpeta2, carpeta3;

   crearFichero(&archivo1, "archivo1.txt");
   crearFichero(&archivo2, "archivo2.txt");
   crearFichero(&archivo3, "archivo3.txt");
   crearFichero(&carpeta1, "carpetaFI");
   crearFichero(&carpeta2, "Progra");
   crearFichero(&carpeta3, "carpetaVacia");

   agregarFicheroADirectorio(&carpeta1->sub, archivo2);
   agregarFicheroADirectorio(&carpeta1->sub, carpeta2);
   agregarFicheroADirectorio(&carpeta2->sub, archivo3);
   agregarFicheroADirectorio(&D, archivo1);
   agregarFicheroADirectorio(&D, carpeta1);
   agregarFicheroADirectorio(&D, carpeta3);

   mostrarDirectorio(D, 0);

   return 0;
}

void agregarFicheroADirectorio(Lista *D, Lista fichero)
{
   fichero->sig = *D;
   *D = fichero;
}

void crearFichero(Lista *fichero, char *nombre)
{
   *fichero = (Lista)malloc(sizeof(nodo));
   strcpy((*fichero)->nombre, nombre);
   (*fichero)->sub = NULL;
   (*fichero)->sig = NULL;
}

void mostrarDirectorio(Lista D, int profundidad)
{
   while (D != NULL)
   {
      for (int i = 0; i < profundidad; i++)
         printf("   ");

      printf("%s\n", D->nombre);

      if (D->sub != NULL)
         mostrarDirectorio(D->sub, profundidad + 1);

      D = D->sig;
   }
}
 