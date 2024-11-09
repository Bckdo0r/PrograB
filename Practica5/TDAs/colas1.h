#include "tipos.h"
#define MAX 10000

typedef int TElementoC;

typedef struct {
	TElementoC datos[MAX];
    int pri, ult; 
} TCola;

void iniciaC(TCola *C);
int vaciaC(TCola C);
void poneC(TCola *C,TElementoC x);
TElementoC consultaC(TCola C);
void sacaC(TCola *C, TElementoC *x);