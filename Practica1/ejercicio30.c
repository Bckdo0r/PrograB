/* Desarrollar un programa que lea y procese un archivo de texto generado por un radar vigía.
Cada línea contiene patente de un vehículo, velocidad registrada, velocidad máxima permitida,
fecha y hora de la medición. Cada dato está separado por un espacio. El programa debe
generar un archivo binario con los registros donde la velocidad registrada supere en más de un
20% a la velocidad máxima. Cada registro del archivo binario contiene los mismos datos que el
archivo de texto. Mostrar, al final del proceso, la cantidad de mediciones procesadas y la
cantidad de registros generados en el archivo binario. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char st7[8];
typedef char st20[21];


typedef struct {
	st7 pat;
	st20 date;
	int speed,maxSpeed;
} RegRad;

int main() {
	RegRad R;
	FILE* archT=NULL;
	FILE* archB=NULL;
	int medTot=0,regGen=0;

	if ((archT = fopen("datos30.txt","r")) && (archB = fopen("datos30.dat","wb+"))){
		fscanf(archT,"%s %d %d %s",R.pat,&R.speed,&R.maxSpeed,R.date);
		while(!feof(archT)){

			if (R.speed > (R.maxSpeed+R.maxSpeed*0.8)){
				fwrite(&R, sizeof(RegRad),1,archB);
				regGen ++;
			}

			medTot ++;

			fscanf(archT,"%s %d %d %s",R.pat,&R.speed,&R.maxSpeed,R.date);
		}

		fclose(archT); fclose(archB);
		printf("Mediciones totales: %d\n",medTot);
		printf("Registros generados: %d\n",regGen);
	}
	else
		printf("Error lens!\n");


	return 0;
}