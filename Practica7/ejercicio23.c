#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDA/arboles.h"

int gradoNodo(arbol);
void gradoArbol(arbol, int *);
int gradoBosque(arbol);

int main()
{
    arbol a;

    addNodo(&a, 1);                                          
    addNodo(&a->der, 2);                                     
    addNodo(&a->der->izq, 3);                                
    addNodo(&a->der->izq->der, 4);                           
    addNodo(&a->der->izq->der->izq, 5);                      
    addNodo(&a->der->izq->der->izq->der, 6);                 
    addNodo(&a->der->izq->der->izq->der->izq, 9);            
    addNodo(&a->der->izq->der->izq->der->izq->der, 10);      
    addNodo(&a->der->izq->der->izq->der->izq->der->der, 11); 
    addNodo(&a->der->der, 12);                               
    addNodo(&a->der->der->izq, 13);                          
    addNodo(&a->der->der->izq->der, 14);                     
    addNodo(&a->der->der->izq->der->izq, 15);                
    addNodo(&a->der->der->der, 7);                           
    addNodo(&a->der->der->der->der, 8);                      

    printf("Grado maximo: %d\n", gradoBosque(a));

    return 0;
}

int gradoBosque(arbol a)
{
    int gr = 0;
    int grMax = 0;

    while (a != NULL)
    {
        gradoArbol(a->izq, &gr);

        if (gr > grMax)
            grMax = gr;
        a = a->der;
    }
    return grMax;
}

void gradoArbol(arbol a, int *gr)
{
    if (a != NULL)
    {
        int g = gradoNodo(a);

        if (g > *gr)
            *gr = g;

        gradoArbol(a->izq, gr);
        gradoArbol(a->der, gr);
    }
}

int gradoNodo(arbol a)
{
    int g = 0;
    if (a == NULL)
        return 0;

    a = a->izq;
    while (a != NULL)
    {
        g++;
        a = a->der;
    }

    return g;
}
