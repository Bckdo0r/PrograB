#define MAX 10000

typedef char ST7[8];
typedef char ST5[6];
typedef struct {
    ST5 codA,horaM;
    ST7 pat;
    unsigned int fecha,Tabon,Tocup;
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