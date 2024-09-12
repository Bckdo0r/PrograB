/* Dada la ecuación de una parábola y=ax2 + bx +c, escribir un programa que mediante un menú de 
opciones iterativo permita: 
a)  Encontrar  el  eje  de  simetría,  sabiendo  que  x1  = -b/(2.a)  y  si  presenta  un mínimo  ó  un máximo  en f(x1). 
b)  Informar hacia dónde es abierta la parábola. 
c)  Calcular  y  mostrar  las  raíces,  informar  en  caso  que  no  existan.  Para  ello  debe  analizar  si  el discriminante, 
D = b2 – 4ac, es mayor, menor ó igual a cero. 
d)  Dado un conjunto de valores de x informar su imagen. 
Usar procedimientos y/o funciones según corresponda */

#include <stdio.h>
#include <math.h>

void IngresoFunc (int*, int*, int*);
int FormaParabola(int);
void EjeSimetria(int, int, int);
void CalcRaices(int, int, int);
void Imagen(int, int, int);
void Menu(int, int, int);

int main(){
  int a,b,c;

  IngresoFunc(&a,&b,&c);
  Menu(a,b,c);

  return 0;
}

void IngresoFunc (int* a, int* b, int* c) {
  printf("El formato de la funcion es: y=ax^2 + bx + c\n");
  
  printf("Ingrese el valor de a: ");
  scanf("%d",a);
  
  printf("Ingrese el valor de b: ");
  scanf("%d",b);
  
  printf("Ingrese el valor de c: ");
  scanf("%d",c);
}

int FormaParabola(int a){
  printf("\n");

  if (a>0)
    return 1;

  else if (a<0)
    return 0;

  else 
    return -1;
}

void EjeSimetria(int a, int b, int c) {
  float x1,y1;
  int formaParabola = FormaParabola(a); 

  printf("\n");
  if (a != 0){
    x1 = -b / (2*a);
    y1 = a*pow(x1,2) + b*x1 + c;

    if (formaParabola)
      printf("La parabola tiene un minimo en (%.2f,%.2f)\n",x1,y1);
    else
      printf("La parabola tiene un maximo en (%.2f,%.2f)\n",x1,y1);
  }
  else 
    printf("La funcion no representa una parabola\n");
}

void CalcRaices(int a, int b, int c){
  float d,r1,r2;
  printf("\n");
  d = pow(b,2) - 4*a*c;

  if (d>0){
    r1 = (-b+sqrt(d))/(2*a);
    r2 = (-b-sqrt(d))/(2*a); 
    printf("Las raices son: r1= %.2f y r2=%.2f\n",r1,r2);  
  }
  else if (d==0){
    r1 = (-b)/(2*a);
    printf("Tiene una raiz doble: r=%.2f\n",r1);
  }
  else 
    printf("No tiene raices reales.\n");
}

void Imagen(int a, int b, int c){
  float x,y;
  printf("\n");
  printf("Ingrese un valor de x para encontrar la imagen: ");
  scanf("%f",&x);
  y = ((a)*pow(x,2)+ (b)*x + (c));
  printf("La imagen de %.2f es %.2f\n",x,y);
}

void Menu (int a, int b, int c){
  int Cod;
  int formaParabola;

  do {

    printf("Menu de opciones (Ingrese el numero de lo que quiere calcular)\n");
    
    printf("0-Para salir.\n");
    printf("1-Encontrar  el  eje  de  simetria y si presenta un maximo o un minimo.\n");
    printf("2-Informar hacia donde es abierta la parabola.\n");
    printf("3-Calcular  y  mostrar  las  raices.\n");
    printf("4-Dado un conjunto de valores de x informar su imagen.\n");
    printf("5-Para reescribir la ecuacion.\n");
    
    scanf("%d",&Cod);
    
    switch(Cod) {
      case 0: break;
      case 1: {
        EjeSimetria(a, b, c);
        break;
      }
      case 2: {
        formaParabola = FormaParabola(a);
        if (formaParabola == -1) printf("No es parabola");
        else if (formaParabola) printf("Para arriba");
        else printf("Para abajo");
        break;
      }
      case 3: {
        CalcRaices(a, b, c);
        break;
      }
      case 4: {
        Imagen(a,b,c);
        break;
      }
      case 5: {
        IngresoFunc(&a, &b, &c);
        break;
      }
      default: printf("Error");
    }

  } while (Cod != 0);
}




