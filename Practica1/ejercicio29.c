/*Un sensor de temperatura realiza mediciones periódicas (una cada 5 seg.). Las mismas son
registradas en un archivo binario, donde cada elemento es de tipo float. Implementar un
programa que genere dicho archivo y, otro programa que lo lea y muestre por pantalla
temperatura promedio, máxima y mínima.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main() {
	float temp,suma=0,min,max;
	int i=0;
	FILE* archT=NULL;
	FILE* archB= NULL;

	if ((archT = fopen("datos29.txt","r")) && (archB = fopen("datos29.dat","wb+"))) {
		fscanf(archT,"%f",&temp);
		while(!feof(archT)) {
			fwrite(&temp, sizeof(float), 1, archB);
			fscanf(archT,"%f",&temp);
		}

		fseek(archB, 0, 0);

		fread(&temp, sizeof(float), 1, archB);
		min = temp;
		max = temp;
		while(!feof(archB)) {
			i++;
			suma += temp;
			if (temp < min)
				min = temp;
			else if  (temp > max)
				max = temp;

			fread(&temp, sizeof(float), 1, archB);			
		}

		fclose(archT); fclose(archB);

		printf("Temperatura promedio: %.2f\n", suma/i);
		printf("Temperatura maxima: %.2f\n", max);
		printf("Temperatura minima: %.2f\n", min);
	} 

	else
		printf("Error lens!\n");	


}