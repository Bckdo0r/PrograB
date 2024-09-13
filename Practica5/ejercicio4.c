/* Ingresar en una cola los números almacenados (uno por línea) en un archivo de texto. Mostrar 
el contenido de la cola. 
a. Utilizar la implementación estática no circular. 
b. Utilizar la implementación dinámica. 
c. Mantener la información en la cola.  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDAs/colas.h"

int main() {
	TElementoC x;
	FILE *arch;
	TCola C,AUX;
	
	if((arch = fopen("datosEJ4.txt","r")) == NULL)
		printf("Error lens.\n");
	else {
		iniciaC(&C);
		iniciaC(&AUX);

		while ((fscanf(arch,"%d",&x)) == 1)
			poneC(&C, x);

		fclose(arch);

		while(!vaciaC(C)) {
			sacaC(&C,&x);
			poneC(&AUX,x);
			printf("%d\n",x);
		}

		while(!vaciaC(AUX)) {
			sacaC(&AUX,&x);
			poneC(&C,x);
		}

	}

	return 0;
}

