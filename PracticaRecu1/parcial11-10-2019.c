#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Practica5/TDAs/colas1.h"
#include "../Practica5/TDAs/tipos.h"
#define Ni 20
#define Nj 50
typedef struct{
    unsigned int norma,cantCertif;
    ST8 nomNorma;
}regL;

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
    regL dato;
    pSubL sub;
    struct nodo *sig;
}nodoL;

typedef nodoL *pLista;

typedef char TMat[Ni][Nj];

int main() {


    return 0;
}

void cargaListas(pLista *L){ //! A)
    regL RL;
    regSL RSL;
    FILE *arch;
    pLista new;

    arch = fopen("CARGACTUAL.TXT","r");

    if (arch != NULL){
        while (scanf(arch,"%d %s %d",&RL.norma,RL.nomNorma,&RL.cantCertif) == 3){ //?es eficiente
            new = (pLista) malloc(sizeof(nodoSL));
            new->dato = RL;
            new->sub = NULL;
            agregaALista(L,new);

            while (scanf(arch,"%d %s %c",&RSL.numEmp,RSL.fechaCertif,&RSL.recertif) == 3)
                agregaASub(&new->sub,RSL); //? esta bien pasada la sublista

        }
        fclose(arch);
    }
    else
        printf("Error en archivo.\n");
}

void agregaALista(pLista *L,pLista new){
    pLista act;

    if (*L == NULL){
        new->sig = NULL;
        *L = new;
    }

    else{
        act = *L;
        
        while (act->sig != NULL)
            act = act->sig;
        
        act->sig = new;
    }
}

void agregaASub(pSubL *S,regSL R){
    pSubL ant,act,new = (pSubL) malloc(sizeof(nodoSL));
    new->dato = R;

    if (*S == NULL || new->dato.numEmp < (*S)->dato.numEmp){
        new->sig = *S;
        *S = new;
    }
    
    else{
        act = *S;
        
        while(act != NULL && act->dato.numEmp < new->dato.numEmp){
            ant = act;
            act = act->sig;
        }

        ant->sig = new;
        new->sig = act;
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
            M[L->dato.norma][L->sub->dato.numEmp] = L->sub->dato.recertif;
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
            eliminaDeSub(L,E)
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