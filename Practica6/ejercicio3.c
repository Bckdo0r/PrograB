/* Escribir un programa que lea desde un archivo un texto que contiene una cantidad desconocida
de palabras (una en cada línea) y genere una lista ordenada de todas las palabras existentes en
el texto con su frecuencia de aparición.  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

typedef struct nodo
{
    char palabra[MAX];
    int frecuencia;
    struct nodo *sig;
} nodo;

typedef nodo *Lista;

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
    char palabra[MAX];

    if ((arch = fopen("datosEJ3.txt", "r")) == NULL)
        printf("Error lens\n");
    else
    {

        while (fscanf(arch, "%s", palabra) == 1)
        {
            act = *L;
            ant = NULL;

            while (act && strcmp(act->palabra, palabra) < 0)
            {
                ant = act;
                act = act->sig;
            }

            printf("Palabra: %s\n", palabra);

            if (strcmp(act->palabra, palabra) == 0)
                act->frecuencia++;
            else
            {
                printf("entro a else: %s\n", palabra);
                nuevo = (Lista)malloc(sizeof(nodo));

                strcpy(nuevo->palabra, palabra);
                nuevo->frecuencia = 1;

                if (act == *L)
                {
                    nuevo->sig = *L;
                    *L = nuevo;
                }
                else
                {
                    nuevo->sig = act;
                    ant->sig = nuevo;
                }
            }
        }
    }
}

void muestraLista(Lista L)
{
    while (L)
    {
        printf("%s: %d\n", L->palabra, L->frecuencia);
        L = L->sig;
    }
}