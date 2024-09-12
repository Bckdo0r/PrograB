/* Desarrollar una función que reciba tres números enteros y devuelva si son consecutivos entre sí
o si no lo son. */

#include <stdio.h>

void Verifica(int,int,int);

int main(){
  int i,n1,n2,n3;
  
  for (i=1 ; i<=3 ; i++){
    printf("Ingrese el numero %d de la serie: ",i);
    
    if (i==1){
      scanf("%d",&n1);
    }
    
    else if (i==2){
      scanf("%d",&n2);
    }
    
    else {
      scanf("%d",&n3);
    }

  }
  
  Verifica(n1,n2,n3);
}

void Verifica (int n1, int n2, int n3){
  
  if (n1 <= n2 && n1 <= n3 && n2 <= n3){
    printf("Los numeros ingresados son consecutivos entre si.\n");
  }

  else {
    printf("Los numero ingresados NO son conecutivos entre si.\n");
  }

}

