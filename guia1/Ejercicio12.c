#include <stdio.h>
void main(){
	int n,Suma=0;
	do {
		printf("Ingrese un numero: \n");
		scanf("%d",&n);
		Suma += n;		
	} while (n!=0);
	
	printf("La suma es: %d \n",Suma);
}