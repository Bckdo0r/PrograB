/* Ingresar los números de DNI de los votantes de una mesa a medida que van votando y mostrar 
los últimos N (es dato) votantes 
a. en orden inverso, comenzando por el último votante. 
b. en el orden que sufragaron. */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDAs/tdapilasE.h"

int main() {
	TPila P,AUX;
	TElemento x;
	FILE * arch;
	int i,N = 3;

	if ((arch = fopen("datosEJ3.txt","r")) == NULL)
		printf("Error lens.\n");
	else {
		iniciaP(&P);
		iniciaP(&AUX);

		fscanf(arch,"%ld",&x);
		while(!feof(arch)){
			poneP(&P,x);
			fscanf(arch,"%ld",&x);
		}
		fclose(arch);
		printf("Votantes orden inverso: \n");
		for (i=0; i<N ;i++){
			sacaP(&P,&x);
			poneP(&AUX,x);

			printf("%ld \n",x);
		}
		printf("Votantes INorden: \n" );
		for (i=0; i<N ;i++){
			sacaP(&AUX,&x);
			printf("%ld \n",x);
		}

	}		

	return 0;
}