#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDAs/colas.h"
#include "TDAs/pilasD.h"

void cargaC(TCola *);
void esPalindromo(TCola *, int *);

unsigned short int main() {
	TCola C;
	int pal;

	cargaC(&C);
	esPalindromo(&C, &pal);

	printf("Es palindromo? %s", pal ? "Si" : "No");

	return 0;
}

void cargaC(TCola *C) {
	FILE *arch;
	TElementoC x;

	if ((arch = fopen("datosEJ14.txt", "r")) == NULL)
		printf("Error lens\n");
	else {
		iniciaC(C);

		while((fscanf(arch, "%c", &x)) == 1)
			poneC(C, x);

		fclose(arch);
	}
}


void esPalindromo(TCola *C, int *pal) {
	TPila P; TCola aux;
	TElementoP px; TElementoC cx;

	iniciaP(&P); iniciaC(&aux);

	while(!vaciaC(*C)) {
		sacaC(C, &cx);
		poneP(&P, px);
		poneC(&aux, cx);
	}

	do {
		sacaC(&aux, &cx);
		sacaP(&P, &px);		
	} while ((*pal = (cx == px)) && !vaciaP(P)); //* UAN LAIN COUDER

}