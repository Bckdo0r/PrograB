/*
Dado un vértice determinado de un digrafo representado en una lista de adyacencia,
implementar funciones que devuelvan:
a) su grado de entrada
b) su grado de salida
c) el grado de dicho vértice
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 7

typedef struct nodo{
    char nodo;
    struct nodo *sig;
}nodoL;

typedef nodoL *Lista;

typedef struct{
    char nodo;
    Lista L;
}reg;

typedef reg TVec[N];

void insertarEnLista(Lista *L, char nodo) {
    Lista nuevoNodo = (Lista)malloc(sizeof(nodoL));
    
    nuevoNodo->nodo = nodo;
    nuevoNodo->sig = *L;
    *L = nuevoNodo;
}

void carga(TVec V) {
    int i;

    // Inicializar los nodos del grafo
    V[0].nodo = 'A'; V[0].L = NULL;
    V[1].nodo = 'B'; V[1].L = NULL;
    V[2].nodo = 'C'; V[2].L = NULL;
    V[3].nodo = 'D'; V[3].L = NULL;
    V[4].nodo = 'E'; V[4].L = NULL;
    V[5].nodo = 'F'; V[5].L = NULL;
    V[6].nodo = 'G'; V[6].L = NULL;

    // Cargar adyacencias
    // A -> [D, F]
    insertarEnLista(&V[0].L, 'F');
    insertarEnLista(&V[0].L, 'D');

    // B -> [C]
    insertarEnLista(&V[1].L, 'C');

    // C -> [A, F]
    insertarEnLista(&V[2].L, 'F');
    insertarEnLista(&V[2].L, 'A');

    // D -> [B, F]
    insertarEnLista(&V[3].L, 'F');
    insertarEnLista(&V[3].L, 'B');

    // E -> [D]
    insertarEnLista(&V[4].L, 'D');

    // F -> [D, G]
    insertarEnLista(&V[5].L, 'G');
    insertarEnLista(&V[5].L, 'D');

    // G -> [D, E]
    insertarEnLista(&V[6].L, 'E');
    insertarEnLista(&V[6].L, 'D');
}

unsigned short int retornaBucles(Lista);
reg buscaVertice(TVec,char);
int retornaGrE(Lista);
int retornaGrS(Lista);
int retornaGrVer(Lista);

int main(void) {


    return 0;
}

reg buscaVertice(TVec vec,char V){
    
}

int retornaGrE(Lista L){
    
    return ;
}

int retornaGrS(Lista L){
    
    return ;
}

unsigned short int retornaBucles(Lista L){

}

int retornaGrVer(Lista L){
    return retornaGrE(L) + retornaGrS(L) - retornaBucles(L);
}