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


int main() {
    ListaC Lc = NULL;
    ListaS Ls = NULL;
    TVec resumen;

    
    
    return 0;
}

ListaS buscaTaxi(ListaS L,ST7 pat){
    while (L != NULL && strcmp(L->pat,pat) != 0)
        L = L->sig;

    return L != NULL && strcmp(L->pat,pat) == 0 ? L : NULL;    
}

ListaC buscaDisponible(ListaC L,reg R){
    ListaC aux = L->sig;
    int verif = 0;

    while (aux != L && !verif){
        verif = aux->libre == 'S' && R.cantP <= aux->dato.cantP && R.rViaje == aux->dato.rViaje && R.VIP == aux->dato.VIP;
        if (!verif)
            aux = aux->sig;
    }
    
    if (!verif)
        verif = aux->libre == 'S' && R.cantP <= aux->dato.cantP && R.rViaje == aux->dato.rViaje && R.VIP == aux->dato.VIP;

    return verif ? aux : NULL;
}

void procesaPedidos(ListaS Ls,ListaC Lc){ //! A)
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
                auxLS = buscaTaxi(Ls,auxLC->pat);
                
                if (auxLS != NULL){
                    x.dato = R;
                    strcpy(x.pat,auxLS->pat); 
                    poneC(&auxLS->C,x); //? va ampersand
                }
                
                else
                    printf("La taxi con patente %s no esta registrado.\n",auxLC->pat);
            }
            
            else
                printf("No puede asignare el viaje.\n");   
        }
        close(arch);
    }
    else
        printf("Error lens.\n");
}

void depuraColas(ListaS L){ //! B)
    TCola aux;
    TElementoC x;
    int maxElim = 0,cont;

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
        
        maxElim = (cont >= maxElim) ? cont : maxElim;

        while (!vaciaC(aux)){
            sacaC(&aux,&x);
            poneC(&L->C,x);
        }

        L = L->sig;
    }
}

void daDeBaja(ListaC *Lc,ListaS *Ls,ST7 P,TVec resumen[]){ //! C)
    ListaC actC,antC;
    ListaS actS,antS;

    actC = (*Lc)->sig;
    actS = *Ls;

    while (actS != NULL && strcmp(actS->pat,P) != 0){
        antS = actS;
        actS = actS->sig;
    }

    do {
        antC = actC;
        actC = actC->sig;
    } while (actC != *Lc && strcmp(actC->pat,P) != 0);

    if (actS != NULL && strcmp(actS->pat,actC->pat) == 0){
        creaVec(&actS->C,resumen); //aca se vacia la cola y se crea el vector
        eliminaDeLs(Ls,actS,antS);
        eliminaDeLc(Lc,actC,antC);
    }

}

void creaVec(TCola *C,TVec resumen[]){
    reg R;
    TElementoC x;
    int i;
    char radio;

    while (!vaciaC(*C)){
        sacaC(C,&x);

        radio = x.dato.rViaje;

        if (radio == 'U'){
            resumen[0]->cantP += x.dato.cantP;
            resumen[0]->cantV ++; 
        }
        
        else if (radio == 'R'){
            resumen[1]->cantP += x.dato.cantP;
            resumen[1]->cantV ++;
        }
        
        else{
            resumen[2]->cantP += x.dato.cantP;
            resumen[2]->cantV ++;
        }

    }
}

void eliminaDeLs(ListaS *L,ListaS act,ListaS ant){
    
    if (act == *L)
        *L = act->sig;
    
    else
        ant->sig = act->sig;
    
    free(act);

}

void eliminaDeLc(ListaC *L,ListaC act,ListaC ant){

    if (act == *L){
        ant->sig = act->sig;
        *L = ant;
    }

    else
        ant->sig = act->sig;

    free(act);

}