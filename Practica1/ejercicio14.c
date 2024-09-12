/* Desarrollar un subprograma que muestre un cuadrado con bordes de N numerales (N es
parámetro de entrada). Por ej: para N = 4 */

#include <stdio.h>

void PisoTecho (int);
void Laterales (int);

int main (){
  int N;
  
  printf("Ingrese el largo del lado del cuadradro (numero entero): ");
  scanf("%d",&N);

  PisoTecho(N);
  Laterales(N);
  PisoTecho(N);

  return 0;
}

void PisoTecho(int N) {
    int i;

    for (i = 1 ; i <= N ; i++) {
        printf("#");
    }
    printf("\n");
}

void Laterales(int N) {
    int i, j;

    // Dibuja N-2 filas de laterales
    for (i = 1 ; i <= N-2 ; i++) {
        printf("#");

        for (j = 2 ; j < N ; j++) {
            printf(" ");
        }

        printf("#\n");
    }
}
