/* Recodificar en el lenguaje C los siguientes ejercicios de Programación I desarrollados en Pascal:
a) Sea V un arreglo de enteros, se pide:
I. Calcular e informar la suma de sus elementos.
II. Mostrar sus elementos.
III. Mostrar sus elementos en orden inverso.
b) Sea A un arreglo de reales y un valor X real ingresado por teclado, se pide determinar en
que posición se encuentra la primera ocurrencia de X o -1 en caso de no encontrarlo.
Implementar:
I. Considerando el arreglo desordenado, una búsqueda lineal recursiva.
II. Para un arreglo ordenado en forma ascendente, una búsqueda binaria recursiva.
c) Crear una función recursiva que busque el elemento mínimo de una matriz cuadrada.
d) Desarrollar un procedimiento recursivo que devuelva en un arreglo los máximos de cada fila
de una matriz de MxN.
e) Dado dos arreglos de enteros A y B ordenados ascendentemente, mezcle ambos arreglos en
otro C manteniendo el orden pero sin pasar los elementos repetidos. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

int sumaElem(int Vec[],int);
void muestraElem(int Vec[],int);
void muestraElemI(int Vec[],int);
int posXLin(float Vec[],int,float);
int posXBin(float Vec[],int,int,float);
//int minMat(int Mat[][],int);
//void VecMinMat(int Mat[][],int,int,int* Vec[]);
//void fusionaVecs(int Vec[],int,int Vec[],int,int* Vec[]);

int main() {
    int A[MAX] = {-2,1,2,3,4,5,6,7,8};
    int B[MAX] = {2,3,2,-4,8,1,7,-10};
    float F[MAX] = {2.7,3.0,2.2,-7.1,1.5,6.6,5.3};
    float G[MAX] = {-0.5,0.4,1.2,1.5,4.5};
    int nA=9, nB=8, nF=7, nG=5;
    float X=1.5;

    printf("La suma de lo elementos del vector A es %d\n", sumaElem(A,nA-1));
    muestraElemI(A,nA-1);
    printf("\n");
    muestraElem(A,nA-1);
    printf("\n");
    printf("La posicion de %.2f en el vector G es: %d\n",X,posXBin(G,0,nG-1,X));


    return 0;
}

int sumaElem(int Vec[],int n){
    int suma;
    if (n==0)
        return Vec[0];
    else
        suma = Vec[n] + sumaElem(Vec,n-1);
}

void muestraElemI(int Vec[],int n){
    if (n>=0){
        printf("%d ",Vec[n]);
        muestraElemI(Vec,n-1);
    }
}

void muestraElem(int Vec[],int n){
    if (n>=0){
        muestraElem(Vec,n-1);
        printf("%d ",Vec[n]);
    }
}

int posXLin(float Vec[],int n,float X){
    if (n<0)
        return -1;
    else{
        if (Vec[n]==X)
            return n;
        else
            return posXLin(Vec,n-1,X);
    }
}

int posXBin(float Vec[],int i,int n,float X){
    int a,b;
    if (n<0)
        return -1;
    else{
        if (Vec[n/2]==X)
            return n/2;
        else
            if (Vec[n/2]>X){
                a = n/2;
                return posXBin(Vec,0,a,X);
            }
            else{
                b = n;
                return posXBin(Vec,b,n,X);
            }
    }
}