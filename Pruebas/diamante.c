#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    long i,j,k;

    printf("Ingrese un numero alto para la prueba de velocidad: ");
    scanf("%d",&k);
    printf("\n");
    for (i = 0; i <= k ;i++)
        printf("%d\n",i);

    return 0;
}