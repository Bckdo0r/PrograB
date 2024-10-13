/* El draw de un torneo de tenis se representa mediante un árbol binario invertido. Desarrollar 
subprogramas que muestren: 
a) el nombre del ganador. 
b) los nombres de los 2 finalistas. 
c) los nombres de los 4 semifinalistas. 
d) los nombres de todos los competidores y la cantidad. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDA/arboles.h"

void muestraGanador(arbol a);
void muestraFinal(arbol a);
void muestraSemi(arbol a);
void muestraParticipantes(arbol a);

int main() {
    arbol A;

    addNodo(&A->izq->izq->izq,"Rune");
    addNodo(&A->izq->izq->der,"Dimitrov");
    // Ganador del partido Rune vs Dimitrov
    addNodo(&A->izq->izq,"Rune");
    
    addNodo(&A->izq->der->izq,"Djokovic");
    addNodo(&A->izq->der->der,"Fritz");
    // Ganador del partido Djokovic vs Fritz
    addNodo(&A->izq->der,"Djokovic");
    
    // Ganador del partido Rune vs Djokovic
    addNodo(&A->izq,"Djokovic");
    
    // Similar para el lado derecho del cuadro
    addNodo(&A->der->izq->izq,"Paul");
    addNodo(&A->der->izq->der,"Alcaraz");
    // Ganador del partido Paul vs Alcaraz
    addNodo(&A->der->izq,"Alcaraz");
    
    addNodo(&A->der->der->izq,"Sinner");
    addNodo(&A->der->der->der,"Rublev");
    // Ganador del partido Sinner vs Rublev
    addNodo(&A->der->der,"Sinner");
    
    // Ganador del partido Alcaraz vs Sinner
    addNodo(&A->der,"Sinner");
    
    // Final: Djokovic vs Sinner
    addNodo(&A,"Djokovic");

    muestraGanador(A);
    muestraFinal(A);
    muestraSemi(A);
    muestraParticipantes(A);

    return 0;
}

void muestraGanador(arbol A){

}