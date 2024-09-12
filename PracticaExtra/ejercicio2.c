/* Escribe un programa que solicite al usuario la cantidad de elementos que desea almacenar en un array de enteros. 
Luego, usa malloc para asignar dinámicamente la memoria necesaria. Permite al usuario ingresar los valores en el array, 
y finalmente, imprime esos valores en orden inverso. No olvides liberar la memoria al final. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

int* iniciaVar(int);
void muestraVec(int Vec[],int N);

int main() {
    int i=0,N,num,Vec[MAX];

    printf("Ingrese la cantidad de elementos que desea almacenar en un array de enteros: ");
    scanf("%d",&N);

    for (i = 0; i < N; i++){
        printf("%d: ",i+1);
        scanf("%d",&num);
        Vec[i] = iniciaVar(num);
    }
    
    muestraVec(Vec,N);

    return 0;
}

int* iniciaVar(int n){
    int* var = (int*) malloc(sizeof(int));

    *var = n;
    return var;
}

void muestraVec(int Vec[], int n){
    printf("Vector mostrado en orden inverso: ");
    n -= 1;
    
    while (n>=0){
        printf("%d ",Vec[n--]);    
    }
    printf("\n");
    
}