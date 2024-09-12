/* Ingresar en una pila los caracteres almacenados (uno por línea) en un archivo de texto. Mostrar 
el contenido de la pila. 
a. Utilizar la implementación estática. 
b. Utilizar la implementación dinámica. 
c. Mantener la información en la pila.  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDAs/tdapilasD.h"

int main() {
	FILE*arch;
	TPila P,AUX;
	TElemento x;


	if ((arch = fopen("datosEJ2.txt", "r")) == NULL) 
		printf("Error lens\n");
	else {
		iniciaP(&P);
		iniciaP(&AUX);

		fscanf(arch, "%d", &x);
		while (!feof(arch)) {
			poneP(&P, x);
			fscanf(arch, "%d", &x);
		}

		while (!vaciaP(P)) {
			sacaP(&P, &x);
			poneP(&AUX,x);
			printf("%d", x);
		}

		while (!vaciaP(AUX)){
			sacaP(&AUX,&x);
			poneP(&P,x);
		}

	}


	return 0;
}