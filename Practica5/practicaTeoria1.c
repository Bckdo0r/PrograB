#include "TDAs/tdapilasD.h"

void verifOrden(TPila *P, int *resul) {
   TElemento n;

   if (!vaciaP(*P)) {
      sacaP(P, &n);
      if (!vaciaP(*P)) {
         
         if (n < consultaP(*P)) {
            verifOrden(P, *resul);
            poneP(P, n);
         }
         else
            *resul = 0;
      }
   }
   else
      *resul = 1;
}