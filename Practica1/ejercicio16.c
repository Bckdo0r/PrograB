/* Desarrollar un subprograma que reciba una cantidad de segundos y devuelva su equivalente en
el formato horas:minutos:segundos */

#include <stdio.h>

void HsMinSeg(unsigned);

int main(){
  unsigned Segs;

  printf("Ingrese un tiempo en segundos: ");
  scanf("%u",&Segs);

  HsMinSeg(Segs);
  
  return 0;
}

void HsMinSeg(unsigned Segs){
  unsigned Hs=0,Min=0,Seg=0;

  Seg = Segs % 60;
  Min = Segs / 60;
  
  if (Min > 60){
    Hs = Min / 60;
    Min = Min % 60;
  }

  printf("%02u : %02u : %02u \n",Hs,Min,Seg);
}
