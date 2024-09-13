/*
Simular una fila de empleados para usar un horno microondas en el comedor de una empresa. 
Para cada empleado se tiene: su número de legajo, el momento de arribo (en segundos a partir 
de las 12:00) y la cantidad de segundos que piensa usar el horno. El programa debe mostrar 
para cada empleado el tiempo en que empieza y termina el uso del horno. Al finalizar mostrar 
tiempo promedio de espera y legajo con mayor tiempo de espera.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDAs/colas.h"

typedef str9 char[10];

void cargaC(TCola *);
void procesaC(TCola *);

int main() {
	TCola C;

	cargaC(&C);
	procesaC(&C);

	return 0;
}

void cargaC(TCola *C) {
	FILE *arch;
  	Empleado E;

  	iniciaC(C);

  	if ((arch = fopen("datosEJ11.txt", "r")) == NULL)
  		printf("Error lens\n");
  	else {

  		while ((fscanf(arch, "%s %d %d", E.legajo, &E.arribo, &E.hovenUsageInSeconds)) == 3)
  			poneC(C, E);

  		fclose(arch);
  	}
}

void procesaC(TCola *C) {
	TElementoC x;
	unsigned int suma = 0, cont = 0, mayor = 0;
	str9 mayorLegajo;

	while(!vaciaC(*C)) {
		sacaC(C, &x);

		suma += x.hovenUsageInSeconds;
		cont++;

		if (x.hovenUsageInSeconds > mayor) {
			mayor = x.hovenUsageInSeconds;
			strcpy(mayorLegajo, x.legajo);
		}

		printf("El empleado con el legajo \"%s\" empieza a los %d segundos y termina %d segundos despues\n", x.legajo, x.arribo, x.hovenUsageInSeconds);
	}

	if (cont) 
		printf("Tiempo promedio de espera: %.2f\n", (float) suma / cont);

	if (mayorLegajo)
		printf("El legajo con el mayor tiempo de espera es: \"%s\"", mayorLegajo);
}