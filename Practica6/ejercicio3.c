/* Escribir un programa que lea desde un archivo un texto que contiene una cantidad desconocida
de palabras (una en cada línea) y genere una lista ordenada de todas las palabras existentes en
el texto con su frecuencia de aparición.  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

typedef char string[MAX + 1];

typedef struct nodoD
{
    string palabra;
    int frecuencia;
    struct nodoD *sig;
} nodoD;

typedef nodoD *Lista;

void cargaLista(Lista *);
void muestraLista(Lista);

int main()
{

    Lista L;

    cargaLista(&L);
    muestraLista(L);

    return 0;
}

void cargaLista(Lista *L)
{
    FILE *arch;
    Lista nuevo, ant, act;
    string palabra;
    *L = NULL;

    if ((arch = fopen("datosEJ3.txt", "r")) == NULL)
        printf("Error lens\n");
    else
    {

        // Bucle para leer archivo
        while (fscanf(arch, "%s", palabra) == 1)
        {
            act = *L;
            ant = NULL;

            // Bucle para comprobar si la palabra leida esta en la lista
            while (act != NULL && strcmp(act->palabra, palabra) < 0)
            {
                ant = act;
                act = act->sig;
            }

            //! Verificacion de condicion de salida
            // Si sale porque esta en la lista, se aumenta la frecuencia
            if (act != NULL && strcmp(act->palabra, palabra) == 0)
                act->frecuencia++;

            // Si sale porque no esta, se crea un nodo para agregar a la lista
            else
            {
                nuevo = (Lista)malloc(sizeof(nodoD));

                // Se pega la palabra y se inicia el contador de frecuencia
                strcpy(nuevo->palabra, palabra);
                nuevo->frecuencia = 1;

                //! Que el puntero del nuevo nodo apunte a actual
                nuevo->sig = act;

                // TODO para que son estos condicionales?
                if (act == *L)
                    *L = nuevo;
                else
                    ant->sig = nuevo;
            }
        }
    }
}

void muestraLista(Lista L)
{
    while (L != NULL)
    {
        printf("%s: %d\n", L->palabra, L->frecuencia);
        L = L->sig;
    }
}