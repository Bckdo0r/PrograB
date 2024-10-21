#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char pws[20],chk[20];
    int i=0;

    printf("Escriba su contrasena: ");
    scanf("%s",pws);

    printf("\nPara entrar a su cuenta, ingrese contrasena: ");
    do {
        scanf("%s",chk);
        i++;
        if (strcmp(pws,chk) != 0)
            printf("\nContrasena incorrecta, vuelva a intentar: ");
        else
            printf("Acceso Valido :)\n");    
    } while (strcmp(pws,chk) != 0 && i<=5);

    return 0;
}