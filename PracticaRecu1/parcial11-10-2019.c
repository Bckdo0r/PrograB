#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Practica5/TDAs/colas1.h"
#include "../Practica5/TDAs/tipos.h"
#define Ni 20
#define Nj 50

typedef struct{
    unsigned int numEmp;
    ST8 fechaCertif;
    char recertif;
}regSL;

typedef struct nodito{
    regSL dato;
    struct nodito *sig;
}nodoSL;

typedef nodoSL *pSubL;

typedef struct nodo{
    unsigned int norma,cantCertif;
    ST8 nomNorma;
    pSubL sub;
    struct nodo *sig;
}nodoL;

typedef nodoL *pLista;

typedef char TMat[Ni][Nj];

void cargaListas(pLista *);
void agregaASub(pSubL *,regSL);
int cuentaCertif(pLista,int);
void generaMat(pLista,TMat);
void recorreMat(TMat,int,int,int,TCola *,int,int *);
void eliminaE(pLista,int,TCola *);
void eliminaDeSub(pLista,int);

int main() {
    pLista L = NULL;
    TCola C;
    int X,E,N,contEmp = 0;
    TMat M;

    iniciaC(&C);
    do {
        printf("Ingrese los valores de N, X, E respectivamente: "); //? esta ingreso de datos es suficiente
        scanf("%d %d %d",&N,&X,&E);
    } while(E < 50 && N < 50);

    cargaListas(&L);
    muestraNormas(L,N);
    generaMat(L,M);
    recorreMat(M,0,0,X,&C,0,&contEmp);
    eliminaE(L,E,&C);

    return 0;
}

void cargaListas(pLista *L){ //! A)
    regSL RSL;
    FILE *arch;
    pLista nuevo,vecP[Ni] = {NULL};
    int i = 0,j = 0;

    arch = fopen("CARGACTUAL.TXT","r");

    if (arch != NULL){
        nuevo = (pLista) malloc(sizeof(nodoSL));
        
        while (scanf(arch,"%d %s %d",&nuevo->norma,nuevo->nomNorma,&nuevo->cantCertif) == 3){ //?es eficiente
            nuevo->sub = NULL;
            vecP[nuevo->norma] = nuevo;
            nuevo->sig = NULL;

            while (scanf(arch,"%d %s %c",&RSL.numEmp,RSL.fechaCertif,&RSL.recertif) == 3)
                agregaASub(&nuevo->sub,RSL); 

            i++;
            nuevo = (pLista) malloc(sizeof(nodoSL));
        }
        
        for (i = 0; i < Ni - 1; i++){ //? dudoso
            if (vecP[i] != NULL && vecP[i+1] != NULL)
                vecP[i]->sig = vecP[i+1];
            
            else if (vecP[i] != NULL && vecP[i+1] == NULL){
                j = i;
                
                while (j < Ni-1 && vecP[j+1] != NULL)
                    j++;
                
                if (j < Ni -1)
                    vecP[i]->sig = vecP[j+1];
            }    
        }

        *L = vecP[0];
        fclose(arch);
    }
    else
        printf("Error en archivo.\n");
}

void agregaASub(pSubL *S,regSL R){
    pSubL ant,act,nuevo = (pSubL) malloc(sizeof(nodoSL));
    nuevo->dato = R;

    if (*S == NULL || nuevo->dato.numEmp < (*S)->dato.numEmp){
        nuevo->sig = *S;
        *S = nuevo;
    }
    
    else{
        act = *S;
        
        while(act != NULL && act->dato.numEmp < nuevo->dato.numEmp){
            ant = act;
            act = act->sig;
        }

        ant->sig = nuevo;
        nuevo->sig = act;
    }
}

void muestraNormas(pLista L,int N){ //! B)
    int k,i,max = 0,maxEmp = 0,cant;

    for (i = 0; i<N ; i++){
        
        do{
            printf("Ingrese un numero para la empresa a buscar (0..49): "); //? esto es lo que pide
            scanf("%d",k);
        }while (k<50);
        
        cant = cuentaCertif(L,k);
        printf("\nLa empresa %d certifico %d normas\n",k,cant);
        
        if (cant > max){
            max = cant;
            maxEmp = k;
        }
    }
    printf("La empresa %d fue la que mas normas certifico (de las buscadas).",maxEmp);
}

int cuentaCertif(pLista L,int k){
    int cont = 0;

    while (L != NULL){
        
        while (L->sub != NULL && L->sub->dato.numEmp < k)
            L->sub = L->sub->sig;
        
        cont += L->sub != NULL && L->sub->dato.numEmp == k;
        
        L = L->sig;    
    }
    return cont;
}

void generaMat(pLista L,TMat M){ //! C) i
    int i,j;

    for (i = 0; i < Ni ;i++)
        for (j = 0; j < Nj ;j++)
            M[i][j] = 'N';

    while (L != NULL){
        
        while (L->sub != NULL){ //? es eficiente
            M[L->norma][L->sub->dato.numEmp] = L->sub->dato.recertif;
            L->sub = L->sub->sig;
        }

        L = L->sig;
    }
}

void recorreMat(TMat M,int i,int j,int X,TCola *C,int contNorm,int *contEmp){ //! C) ii
    if (j < Ni)
        
        if (i < Nj)
            M[i][j] == 'S' ? recorreMat(M,i+1,j,X,C,contNorm+1,contEmp) : recorreMat(M,i+1,j,X,C,contNorm,contEmp); 
        
        else
            if (contNorm >= X){
                recorreMat(M,Ni,j+1,X,C,0,contEmp+1); 
                poneC(C,j);
            }
            else
                recorreMat(M,Ni,j+1,X,C,0,contEmp);
}

void eliminaE(pLista L,int E,TCola *C){ //! D)
    TCola aux;
    iniciaC(&aux);
    TElementoC x;

    if (!vaciaC(*C)){
        sacaC(C,&x);

        while(!vaciaC(*C) && x != E){
            poneC(&aux,x);
            sacaC(C,&x);
        }

        if (x == E){
            poneC(&aux,x);
            eliminaDeSub(L,E);
        }

        while(!vaciaC(aux)){
            sacaC(&aux,&x);
            poneC(C,x);
        }
    }
        
}

void eliminaDeSub(pLista L,int E){
    pSubL act,ant;

    while (L != NULL){
        act = L->sub;
        while (act->dato.numEmp != E){ //? se supone que todas las empresas estan en la sub
            ant = act;
            act = act->sig;
        } 

        if (act->dato.recertif == 'N'){
            if (act == L->sub)
                L->sub = L->sub->sig;
            else
                ant->sig = act->sig;
            free(act);        
        }

        L = L->sig;
    }
}