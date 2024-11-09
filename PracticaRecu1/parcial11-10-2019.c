#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Practica5/TDAs/colas1.h"
#include "../Practica5/TDAs/tipos.h"

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

typedef char TMat[20][50];

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

