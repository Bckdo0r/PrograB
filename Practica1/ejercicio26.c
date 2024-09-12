/* Declarar un tipo struct para almacenar nombre, matrícula y promedio de un alumno.
Desarrollar una función que realice lectura de una variable del tipo creado. */

#include <stdio.h>

typedef struct {
	char nombre[30], matricula[30];
	float promedio;
} TAlumno;

void crearAlumno(TAlumno *);
void mostrarAlumno(TAlumno);

int main() {
	TAlumno alumno;

	crearAlumno(&alumno);
	mostrarAlumno(alumno);

	return 0;	
}

void crearAlumno(TAlumno *alumno) {
	printf("Ingrese nombre, matricula y promedio: ");
	scanf("%s %s %f", alumno->nombre, alumno->matricula, &alumno->promedio);
}

void mostrarAlumno(TAlumno alumno) {
	printf("Nombre: %s\n", alumno.nombre);
	printf("Matricula: %s\n", alumno.matricula);
	printf("Promedio: %.2f\n", alumno.promedio);
}
