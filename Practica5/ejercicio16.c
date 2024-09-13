/*
Simular un juego de naipes donde N jugadores van tomando un naipe del mazo por turno. El 
juego finaliza cuando el mazo queda vacío. El puntaje de cada jugador consiste en la sumatoria 
de los números de los naipes que fue tomando. Si el palo del naipe tomado coincide con el palo 
del levantado en el turno anterior el número se duplica. Implementar utilizando las estructuras 
(pilas y/o colas) que considere necesarias. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDAs/pilasD.h"
#include "TDAs/colas.h"

void cargaMazo(TPila *);
void mezclarMazo(TPila *);
void cargaJugadores(TCola *);
void juego(TPila *, TCola *);
void muestraPuntajes(TCola *);

unsigned short int main() {

	TPila mazo;
	TCola jugadores;

	cargaMazo(&mazo);
	cargaJugadores(&jugadores);
	juego(&mazo, &jugadores);
	muestraPuntajes(&jugadores);

	return 0;
}

void cargaMazo(TPila *mazo) {

	TElementoP carta;
	iniciaP(mazo);

	char palos[4] = {'O', 'C', 'E', 'B'};

	for (int i = 0; i < 12; i++) 
		for (int j = 0; j < 4; j++) {
			carta.palo = palos[j];
			carta.valor = i;
			poneP(mazo, carta);
		}

	mezclarMazo(mazo);
}

void cargaJugadores(TCola *jugadores) {
	TElementoC jugador;
	FILE *arch;

	iniciaC(jugadores);

	arch = fopen("datosEJ16.txt", "r");

	while (fscanf(arch, "%s", jugador.nombre) == 1)  {
		jugador.puntaje = 0;
		poneC(jugadores, jugador);
	}

	fclose(arch);
	
}

void juego(TPila *Mazo,TCola *Jug){
	TElementoP carta;
	TElementoC jugador;
	char ant = '$';

	while (!vaciaP(*Mazo)){
		sacaP(Mazo,&carta);
		sacaC(Jug,&jugador);
		jugador.puntaje += (ant == carta.palo ? 2 : 1) * carta.valor; //!pedilo ya
		ant = carta.palo;		
		poneC(Jug,jugador);
	}
}

void muestraPuntajes(TCola *Jug){
	TElementoC jugador;
	TCola AUX;

	iniciaC(&AUX);

	while (!vaciaC(*Jug)){
		sacaC(Jug,&jugador);
		printf("%s: %d\n",jugador.nombre,jugador.puntaje);
		poneC(&AUX,jugador);
	}

	while (!vaciaC(AUX)){
		sacaC(&AUX,&jugador);
		poneC(Jug,jugador);
	}
}

void mezclarMazo(TPila *P){

}