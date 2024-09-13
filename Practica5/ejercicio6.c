/* Desarrollar subprogramas (con estructuras iterativas) que trabajando sobre una pila de 
enteros: 
a. cuente la cantidad de ceros que contiene. 
b. obtenga el valor promedio (sin perder la información de la pila)
c. calcule los valores máximo y mínimo de la pila (sin perder la información de la pila) 
d. quite todos los valores mayores al último.  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDAs/pilasE.h"

void cargaPila(TPila *);
void cantCeros(TPila *,int *);
void promPila(TPila *,float *);
void minMax(TPila *,int *,int *);
void mayoresUlt(TPila *,TPila *);

int main() {
	TPila P,AUX;
	TElemento n;
	int ceros = 0,min,max;
	float prom;

	cargaPila(&P);
	cantCeros(&P,&ceros);
	printf("Cantidad de ceros de la pila: %d \n",ceros);
	promPila(&P,&prom);
	printf("Promedio de la pila: %.2f \n",prom);
	minMax(&P,&min,&max);
	printf("Minimo: %d ; Maximo: %d\n",min,max);
	mayoresUlt(&P,&AUX);
	printf("Elemenos de la pila excluyendo los mayores al ultimo: \n");
	while (!vaciaP(AUX)){
		sacaP(&AUX,&n);
		printf("%d\n",n);
	}

	return 0;
}

void cargaPila(TPila *P){
	FILE *arch;
	TElemento n;

	arch = fopen("datosEJ6.txt","r");

	iniciaP(P);
	if (arch == NULL)
		printf("Error lens \n");
	else {
		while((fscanf(arch,"%d",&n)) == 1)
			poneP(P,n);
	}
	fclose(arch);	
}

void cantCeros(TPila *P,int *ceros){
	TElemento n;
	TPila AUX;

	iniciaP(&AUX);
	while (!vaciaP(*P)){
		sacaP(P,&n);
		poneP(&AUX,n);
		if (n == 0)
			(*ceros)++;
	}

	while (!vaciaP(AUX)){
		sacaP(&AUX,&n);
		poneP(P,n);
	}

}

void promPila(TPila *P, float *prom){
	TElemento n;
	TPila AUX;
	int suma=0,cont=0;

	iniciaP(&AUX);
	while (!vaciaP(*P)){
		sacaP(P,&n);
		poneP(&AUX,n);
		cont ++;
		suma += n;
	}
	
	while (!vaciaP(AUX)){
		sacaP(&AUX,&n);
		poneP(P,n);
	}

	if (cont>0)
		*prom = suma/cont;
	else
		printf("ERROR. Pila vacia\n");

}

void minMax(TPila *P,int *min,int *max){
	TElemento n;
	TPila AUX;

	iniciaP(&AUX);

	if (!vaciaP(*P)){
		sacaP(P,&n);
		poneP(&AUX,n);
		*min = n;
		*max = n;
	}

	while (!vaciaP(*P)){
		sacaP(P,&n);
		poneP(&AUX,n);
		
		if(n<(*min))
			*min = n;
		else if (n>(*max))
			*max = n;	
	}
	
	while (!vaciaP(AUX)){
		sacaP(&AUX,&n);
		poneP(P,n);
	}

}

void mayoresUlt(TPila *P,TPila *AUX){
	TElemento n;
	int ult;	

	iniciaP(AUX);
	
	if (!vaciaP(*P)){
		sacaP(P,&n);
		poneP(AUX,n);
		ult = n;
	}

	while (!vaciaP(*P)){ 
		sacaP(P,&n);
		if (n<ult)
			poneP(AUX,n);
	}	
		
}