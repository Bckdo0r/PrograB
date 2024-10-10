#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDA/arboles.h"

//* ABB -> siempre incersion como hoja
/* 
    !Eliminacion en ABB:
    -Buscar el nodo
    -Se elmina segun el grado del nodo
        grado 0, se elimina y ya esta
        grado 1, se elimina y se "promueve" a su hijo
        grado 2, se promueve: el nodo mas a la derecha del subarbol izquierdo del nodo a eliminar
                              el nodo mas a la izquierda del subarbol derecho del nodo a eliminar

    ?Uso de los arboles binarios:
    -Almacenar expresiones aritmeticas (operadores) 
    -Indices de bases de datos (no binarios)
    -AB, ABB, AVL, arboles N-arios, arboles N-vias

    !AVL:
    - -1 <= factor de equilibrio <= 1 (por cada nodo)
    TODO para incertar en AVL: AVL? SI : una o mas rotaciones
    TODO para eliminar en AVL: AVL? SI : una o mas rotaciones hasta la raiz                          
    
*/

void inserta(arbol *A, TElementoA x){
    if (*A == NULL){
        *A = (arbol) malloc(sizeof(NODO));
        (*A)->dato = x;
        (*A)->der = NULL;
        (*A)->izq = NULL;
    }
    else
        if (x > (*A)->dato){
            
        }
        

}

int main() {


    return 0;
}