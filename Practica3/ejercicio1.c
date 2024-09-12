/* Desarrollar funciones (algunas pueden ser void) para:
a) calcular el producto de dos números enteros positivos a partir de sumas sucesivas.
b) calcular cociente y resto entre dos números enteros positivos a partir de restas sucesivas
c) hallar el máximo elemento de un vector de enteros (realizar una versión void y otra int) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

int productoSuma(int,int);
void cocienteResto(int,int,int*,int*);
int maximo(int Vec[],int);
void max(int Vec[],int,int*);

int main() {
    int a=19,b=7,coc=0,res=0,n=7,maxN;
    int Vec[MAX] = {-5,-20,-3,4,-5,-1,-1,-6};

    printf("Producto entre a y b: %d \n",productoSuma(a,b));
    
    cocienteResto(a,b,&coc,&res);
    printf("El cociente y resto de la division entre a y b(respectivamente) son: %d y %d \n",coc,res);
    
    printf("El maximo elemento del vector Vec es: %d (con funcion int)\n",maximo(Vec,n));

    max(Vec,n,&maxN);
    printf("El maximo elemento del vector Ves es: %d (con void) \n",maxN);

    return 0;
}

int productoSuma(int a, int b){
    if (b==0)
        return 0;
    else
        return a + productoSuma(a,b-1);
}

void cocienteResto(int a, int b, int* coc, int* res){
    if (a>=b){
        a -= b;
        (*coc) ++;
        cocienteResto(a,b,coc,res);
    }
    else
        *res = a;
}

int maximo(int Vec[],int n){
    int max;
    if (n==0)
        return Vec[0];
    else {
        max = maximo(Vec,n-1);
        if (Vec[n]>max)
            return Vec[n];
        else
            return max;
    }                 
}

void max(int Vec[],int n, int* maxN){
    if (n==0)
        *maxN = Vec[0];
    else{
        max(Vec,n-1,maxN);
        
        if (Vec[n]>(*maxN))
            *maxN = Vec[n];    
    }
}

