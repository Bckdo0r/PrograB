/* Desarrollar un programa que muestre la suma de un conjunto de números naturales ingresados
por teclado. La serie finaliza al ingresar el número 0. */

#include <stdio.h>

int Suma (int,int);

int main (){
  int n, acum=0;
  
  do {
    printf("Ingrese un numero o 0 para finalizar: ");
    scanf("%d",&n);
    acum = Suma(acum,n);
  } while (n!=0);

  printf("La suma del conjunto ingresado es: %d \n",acum);
  return 0;
}

int Suma(int sum, int num) {
  return sum + num;
}
