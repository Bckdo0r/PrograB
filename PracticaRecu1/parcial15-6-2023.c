#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Practica5/TDAs/colas.h"

typedef char ST3[4];

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

void procesaPedidos(ListaS Ls,ListaC Lc){
    FILE *arch;
    reg R;
    ListaS auxLS;
    ListaC auxLC;
    TelementoC x;
    arch = fopen("VIAJES.DAT","rb");
    
    if (arch != NULL){
        while (fread(R,sizeof(reg),1,arch) == 1){
            auxLC = buscaDisponible(Lc,R);
            
            if (auxLC != NULL){
                auxLC->libre = 'N';
                auxLS = buscaTaxi(Ls,auxLC->pat);
                
                if (auxLS != NULL){
                    x.dato = R;
                    strcpy(x.pat,auxLS->pat); 
                    poneC(auxLS->C,x);
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

void depuraColas(ListaS L){
    TCola aux;
    TelementoC x;
    int maxElim = 0,cont;

    iniciaC(&aux);
    while (L != NULL){
        cont = 0;
        
        while (!vaciaC(L->C)){
            sacaC(&L->C,&x);
            if (x.dato.cantP != 0){}
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

void eliminaLc(ListaC *L){
    ListaC act,ant;

    if (*L == )
}

void eliminaLs(ListaS *L){
    ListaS act,ant;
}