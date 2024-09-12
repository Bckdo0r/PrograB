/* Desarrollar un subprograma que duplique los elementos de un vector ubicados en las
posiciones pares. Implementar 3 veces utilizando for, while y do while */

#include <stdio.h>
#define MAX 10

void Duplica1 (int V[] , int n){
	int i;

	for (i=0 ; i<n ; i++)
		if ((i+1) % 2 == 0)
			V[i] *= 2;

}

void Duplica2 (int V[] , int n){
	int i=0;

	while (i<n){
		
		if ((i+1) % 2 == 0)
			V[i] *= 2;

		i++;
	}

}

void Duplica3 (int V[] , int n){
	int i=0;

	do {
		
		if ((i+1) % 2 == 0)
			V[i] *= 2;

		i++;
	} while (i<n);

}

void main() {
	int i, n = 10;
	int V1[MAX], V2[MAX], V3[MAX];

	for (i = 0; i < n; i++) {
		V1[i] = i;
		V2[i] = i;
		V3[i] = i;
	}
	

	Duplica1(V1,n);
	Duplica2(V2,n);
	Duplica3(V3,n);

}