#define MAX 10000

typedef char ST7[8];
typedef char ST5[6];
typedef char ST3[4];


typedef struct{
    int cantP;
    char VIP, rViaje;
} reg;

typedef struct {
    reg dato;
} TElementoC;

typedef struct {
	TElementoC datos[MAX];
    int pri, ult; 
} TCola;

void iniciaC(TCola *C);
int vaciaC(TCola C);
void poneC(TCola *C,TElementoC x);
TElementoC consultaC(TCola C);
void sacaC(TCola *C, TElementoC *x);