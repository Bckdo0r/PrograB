#include <stdlib.h>
#include <stdio.h>
#define MAX 25

typedef struct{
    int edad;
    char nombre[MAX];
    float salario;
} TEmpleado;

TEmpleado* reservaMem(int);

int main (){
    int n,i=0;
    TEmpleado *Empleados;
    FILE *arch;

    if ((arch = fopen("archivosTXT/empleados.txt","r")) == NULL)
        printf("Error lens.");
    else{
        fscanf(arch,"%d",&n);

        Empleados = reservaMem(n);

        if (Empleados != NULL){

            while (fscanf(arch, "%s %d %f", Empleados[i].nombre, &Empleados[i].edad, &Empleados[i].salario) == 3) {
                i++;
            }

            for (i=0; i<n ;i++)
                printf("%s %d %.2f \n",Empleados[i].nombre,Empleados[i].edad,Empleados[i].salario);

        }
        else
            printf("Error al reservar memoria.");

        fclose(arch);
        free(Empleados);
    }

    return 0;
}

TEmpleado* reservaMem(int N){
    return (TEmpleado*) malloc(N * sizeof(TEmpleado));
}

