#include "N-ario.h"

// Verifica si el árbol está vacío
int Vacio(Arbol A)
{
    return A == NULL;
}

// Verifica si una posición es nula
int Nulo(Posicion p)
{
    return p == NULL;
}

// Devuelve el hijo más a la izquierda del nodo p
Posicion HijoMasIzq(Posicion p, Arbol A)
{
    if (p != NULL)
        return p->hijoIzq;
    // Si p es NULL, tira un error
}

// Devuelve el hermano a la derecha del nodo p
Posicion HermanoDer(Posicion p, Arbol A)
{
    if (p != NULL)
        return p->hermanoDer;
    // Si p es NULL, tira un error
}

// Devuelve el dato almacenado en la posición p
TElementoA Info(Posicion p, Arbol A)
{
    if (p != NULL)
        return p->dato;
    // Si p es NULL, tira un error
}

// Devuelve la raíz del árbol
Posicion Raiz(Arbol A)
{
    return A; // La raíz es simplemente el nodo principal
}

// Devuelve el padre de la posición p
Posicion Padre(Posicion p, Arbol A)
{
    if (p == A || A == NULL)
    {
        return NULL; // Si p es la raíz o el árbol está vacío, no tiene padre
    }
    // Búsqueda recursiva del padre
    Posicion actual = A;
    if (actual->hijoIzq == p || actual->hermanoDer == p)
    {
        return A;
    }
    // Buscar en subárboles
    Posicion encontrado = Padre(p, actual->hijoIzq);
    if (encontrado != NULL)
        return encontrado;
    return Padre(p, actual->hermanoDer);
}