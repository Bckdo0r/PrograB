/* Corregir los errores del siguiente fragmento de código para que muestre los números naturales
impares hasta el 15 inclusive. */

#include <stdio.h>
#define N 15

int main () {
  int i;
  
  for(i=1 ; i <= N ; i+=2)
    printf("%d \n", i);
  
  return 0;  
} 
