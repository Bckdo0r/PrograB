#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Practica5/TDAs/colas2.h"
typedef struct nodoc{
    ST7 pat;
    ST3 radioC;
    reg dato;
    char libre;
    struct nodoc *sig;
} nodoLc;

typedef struct{
    int cantV,cantP;
}Tret;

typedef nodoLc *ListaC;

typedef struct nodo{
    ST7 pat;
    TCola C;
    struct nodo *sig;
} nodoLs;

typedef nodoLs *ListaS;

typedef Tret TVec[3];

ListaS buscaTaxi(ListaS, ST7); 
ListaC buscaDisponible(ListaC,reg);
void cargaListaS(ListaS *);
void cargaListaC(ListaC *);
void procesaPedidos(ListaS *,ListaC);
void depuraColas(ListaS);
void daDeBaja(ListaS *,ListaC *,ST7,TVec);
void creaVec(TCola *,TVec);
void eliminaDeLs(ListaS *,ListaS,ListaS);
void eliminaDeLc(ListaC *,ListaC,ListaC);
int verifica(ListaC,reg);
void agregaAListaS(ListaS *,ListaC);

int main() {
    ListaC Lc = NULL;
    ListaS Ls = NULL;
    TVec resumen;
    ST7 P;
    
    for (int i = 0; i<3 ;i++){
        resumen[i].cantP = 0;
        resumen[i].cantV = 0;
    }

    cargaListaC(&Lc);
    cargaListaS(&Ls); // aca se inician las colas
    
    printf("Ingrese P: ");
    scanf("%d\n",P);

    procesaPedidos(&Ls,Lc);
    depuraColas(Ls);
    daDeBaja(&Lc,&Ls,P,resumen);

    return 0;
}

ListaS buscaTaxi(ListaS L,ST7 pat){
    while (L != NULL && strcmp(L->pat,pat) < 0)
        L = L->sig;

    return L != NULL && strcmp(L->pat,pat) == 0 ? L : NULL;    
}

int verifica(ListaC L,reg R){
    int i = 0,verif;

    while (L->radioC[i] != '\0' && R.rViaje != L->radioC[i])
        i++;

    verif = R.VIP == 'N' || L->dato.VIP == 'S';

    return L->libre == 'S' && R.cantP <= L->dato.cantP && i<3 && verif;    
}

ListaC buscaDisponible(ListaC L,reg R){
    ListaC aux = L->sig;
    int verif = 0;

    do {
        verif = verifica(aux,R);
        if (!verif)
            aux = aux->sig;
    } while (aux != L && !verif);

    return verif ? aux : NULL;
}

void agregaAListaS(ListaS *L,ListaC aux){
    ListaS ant,act,new = (ListaS) malloc(sizeof(nodoLs));
    TElementoC x;
    
    x.dato = aux->dato;
    iniciaC(&new->C);
    poneC(&new->C,x);
    strcpy(new->pat,aux->pat);
    
    if (*L == NULL || strcmp((*L)->pat,new->pat) > 0){
        new->sig = *L;
        *L = new; 
    }
    
    else{
        act = *L;
        while (act != NULL && strcmp(act->pat,new->pat) < 0){
            ant = act;
            act = act->sig;
        }

        ant->sig = new;
        new->sig = act;
    }
}

void procesaPedidos(ListaS *Ls,ListaC Lc){ //! A)
    FILE *arch;
    reg R;
    ListaS auxLS;
    ListaC auxLC;
    TElementoC x;
    arch = fopen("VIAJES.DAT","rb");
    
    if (arch != NULL){
        while (fread(&R,sizeof(reg),1,arch) == 1){
            auxLC = buscaDisponible(Lc,R);
            
            if (auxLC != NULL){
                auxLC->libre = 'N';
                auxLS = buscaTaxi(*Ls,auxLC->pat); //? va asterisco
                
                if (auxLS != NULL){
                    x.dato = R;
                    poneC(&auxLS->C,x);
                }
                else
                    agregaAListaS(Ls,auxLC);
            }
            
            else
                printf("No puede asignare el viaje.\n");   
        }
        fclose(arch);
    }
    else
        printf("Error lens.\n");
}

void depuraColas(ListaS L){ //! B)
    TCola aux;
    TElementoC x;
    int maxElim = 0,cont;
    ST7 maxPat = ' ';

    iniciaC(&aux);
    while (L != NULL){
        cont = 0;
        
        while (!vaciaC(L->C)){
            sacaC(&L->C,&x);
            if (x.dato.cantP != 0)
                poneC(&aux,x);
            else
                cont++;    
        }
        
        if (cont >= maxElim){
            maxElim = cont;
            strcpy(maxPat,L->pat);
        }

        while (!vaciaC(aux)){
            sacaC(&aux,&x);
            poneC(&L->C,x);
        }

        L = L->sig;
    }
    printf("El taxi con patente %s fue el que mas viajes incompletos tuvo\n",maxPat);
}

void daDeBaja(ListaS *Ls,ListaC *Lc,ST7 P,TVec resumen){ //! C)
    ListaC actC,antC;
    ListaS actS,antS;

    actC = (*Lc)->sig;
    actS = *Ls;

    while (strcmp(actS->pat,P) != 0){
        antS = actS;
        actS = actS->sig;
    }

    do {
        antC = actC;
        actC = actC->sig;
    } while (strcmp(actC->pat,P) != 0);

    creaVec(&actS->C,resumen); //aca se vacia la cola y se crea el vector
    
    if (actS == *Ls)
        *Ls = actS->sig; 
    else
        antS->sig = actS->sig;
    
    if (actC == *Lc){
        
        if (actC->sig == actC)
            *Lc = NULL;
        
        else{
            antC->sig = actC->sig;
            *Lc = antC;
        }    
    }
    else
        antC->sig = actC->sig;

    free(actC);
    free(actS);
}

void creaVec(TCola *C,TVec resumen){
    reg R;
    TElementoC x;
    int i;
    char radio;

    while (!vaciaC(*C)){
        sacaC(C,&x);
        int i;
        radio = x.dato.rViaje;

        if (radio == 'U')
            i = 0;
        else if (radio == 'R')
            i = 1;
        else
            i = 2;

        resumen[i].cantP += x.dato.cantP;
        resumen[i].cantV ++;
    }
}