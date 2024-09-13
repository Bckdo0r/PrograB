/*
   Rehacer los ejercicios 2 y de 3 de pilas mediante subprogramas recursivos. Las pilas no deben
   perder su información.

   Ingresar en una pila los caracteres almacenados (uno por línea) en un archivo de texto. Mostrar
   el contenido de la pila.

   Ingresar los números de DNI de los votantes de una mesa a medida que van votando y mostrar
   los últimos N (es dato) votantes
   a. en orden inverso, comenzando por el último votante.
   b. en el orden que sufragaron.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDAs/pilasD.h"
#include "TDAs/pilasE.h"

void leeArch1(TPila *);
void leeArch2(TPila *);
void caracteres(TPila *);
void votantes(TPila *, int,int);

unsigned short int main()
{
   TPila PCar, PVotantes;

   leeArch1(&PCar);
   leeArch2(&PVotantes);

   caracteres(&PCar);
   votantes(&PVotantes,4,0);
   return 0;
}

void caracteres(TPila *P)
{
   TElemento car;
   if (!vaciaP(*P)){
      sacaP(P, &car);
      printf("%c \n", car);
      caracteres(P);
      poneP(P, car);
   }
}

void votantes(TPila *P,int N,int cont){
   TElementoP votante;
   if (!vaciaP(*P) && cont<N){
      sacaP(P, &votante);
      printf("%s \n",votante);
      votantes(P,N,cont+1);
      poneP(P,votante);
   }
}

void leeArch1(TPila *P){
   FILE *arch = fopen("datosEJ2.txt","r");
   TElemento car;
   
   iniciaP(P);
   while ((fscanf(arch,"%c",&car) == 1))
      poneP(P,car);

   fclose(arch);   
}

void leeArch2(TPila *P){
   FILE *arch = fopen("datosEJ3.txt","r");
   TElementoP doc;

   iniciaP(P);
   while ((fscanf(arch,"%ld",&doc) == 1))
      poneP(P,doc);
      //!>-->O
      

   fclose(arch);   
}
