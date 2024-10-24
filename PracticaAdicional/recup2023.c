#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Practica5/TDAs/colas.h"

typedef char ST30[31];
typedef char ST7[8];

typedef struct nodito{
    ST7 cod;
    unsigned int dest,prodS,prodE;
    struct nodito *sig;
} nodoSL;

typedef nodoSL *subL;

typedef struct nodoC{
    unsigned int idP,prodTs;
    ST30 nom;
    subL sub;
    struct nodoC *sig;
} nodoLc;

typedef nodoLc *ListaC;

typedef struct nodoS{
    unsigned int idR,idP;
    TCola C;
    struct nodoS *sig;
} nodoLs;

typedef nodoLs *ListaS;

void cargaLc(ListaC *);
void cargaLs(ListaS *);
void actualizaLC(ListaC *);
void encuentraNodoLc(ListaC *,int,ST30,int,ListaC *);
void actualizaSubL(subL *,int,ST7,int);
void preparacionPedidos(ListaS,ListaC);
ListaC buscaPuesto(ListaC,int);
ListaS buscaRobot(ListaS,int);
void eliminaProd(ListaC,ListaS,ST7,int);
void eliminaDeSL(subL *,ST7);
void eliminaDeCola(TCola *,ST7);
void trasbasaProd(subL *,int *,ListaC);

int main(){
    int x = 5;
    ListaC Lc;
    ListaS Ls;
    ST7 cod = "XA0D001";
    
    cargaLc(&Lc);
    cargaLs(&Ls);

    actualizaLC(&Lc);
    preparacionPedidos(Ls,&Ls);
    eliminaProd(Lc,Ls,cod,x);

    return 0;
}

void actualizaLc(ListaC *Lc){
    FILE *arch;
    int id,cantPs,dest,cantP,i;
    ST30 nom;
    ST7 cod;
    ListaC aux;
    
    arch = fopen("PEDIDOS.TXT","r");

    if (arch != NULL){
        while ((fscanf(arch,"%d %s %d",&id,nom,&cantPs) == 3)){
            
            encuentraNodoLc(Lc,id,nom,cantPs,&aux);

            for (i=0; i<cantPs ;i++){
                fscanf(arch,"%d %s %d",&dest,cod,&cantP);
                actualizaSubL(&(aux->sub),dest,cod,cantP);
            }    

        }
        fclose(arch);
    }
    else
        printf("Error lens\n");
}

void enceuntraNodoLc(ListaC *Lc,int id,ST30 nom,int cantPs,ListaC *aux){
    ListaC act,ant,new;
    
    new = (ListaC) malloc(sizeof(nodoLc));
    strcpy(new->nom,nom);
    new->idP = id;
    
    if (*Lc == NULL){
        new->sig = new;
        new->prodTs = cantPs;    
        *Lc = *aux = new;
    }
    else if((*Lc)->idP < id){
        new->sig = (*Lc)->sig;
        new->prodTs = cantPs;
        (*Lc)->sig = new;
        *aux = new;
    }
    else{
        act = (*Lc)->sig;
        ant = (*Lc);

        while (act->idP != id || act->idP < id){
            act = act->sig;
            ant = ant->sig;
        }

        if (act->idP == id){
            *aux = act;
            (*aux)->prodTs += cantPs;
            free(new);
        }
        else {
            ant->sig = new;
            new->sig = act;
            new->prodTs = cantPs;
            *aux = new;
        }
    }
}

void actualizaSubL(subL *sub,int dest,ST7 cod,int cantP){
    subL new,act;

    new = (subL)malloc(sizeof(nodoSL));
    strcpy(new->cod,cod);
    new->dest = dest;
    new->prodE = cantP;
    new->sig = NULL;
    new->prodE = 0;

    if (*sub == NULL){
        new->sig = NULL;
        *sub = new;
    }
    else{
        act = *sub;
        while (strcmp(act->cod,cod) != 0 && act->dest != dest && act->sig != NULL)
            act = act->sig;
        
        if (strcmp(act->cod,cod) == 0 && act->dest == dest){
            act->prodS += cantP;
            free(new);
        }
        else
            act->sig = new;        
    }
}

void preparacionPedidos(ListaS Ls, ListaC Lc){
    ListaC aux;
    TCola ColaAux;
    TElementoC x;

    iniciaC(&ColaAux);
    while (Ls != NULL){
        aux = buscaPuesto(Lc,Ls->idP);

        if (aux != NULL){

            while (!vaciaC(Ls->C)){
                sacaC(&Ls->C,&x);

                while (x.cantP > 0 && aux->sub != NULL){
                    if (aux->sub->cod == x.cod)
                        trasbasaProd(&aux->sub,&x.cantP,aux);
                    aux->sub = aux->sub->sig;    
                }
                if (x.cantP > 0)
                    poneC(&ColaAux,x);    
            }

            while(!vaciaC(ColaAux)){
                sacaC(&ColaAux,&x);
                poneC(&Ls->C,x);
            }
        }
        else
            printf("El PUESTO: %d que tiene seleccionado el ROBOT: %d no se encuentra en la lista de puestos",Ls->idP,Ls->idR);

        Ls = Ls->sig;
    }
}

ListaC buscaPuesto(ListaC Lc,int idP){
    ListaC aux;
    aux = Lc->sig;
    while (aux != Lc && aux->idP < idP)
        aux = aux->sig;
    
    return aux->idP == idP? aux:NULL;
}

void trasbasaProd(subL *SL,int *canP,ListaC Lc){
    
    while ((*canP) > 0 || (*SL)->prodS > (*SL)->prodE || Lc->prodTs > 0){
        (*canP)--;
        (*SL)->prodE++;
        Lc->prodTs--;
    }

}

void eliminaProd(ListaC Lc,ListaS Ls,ST7 cod,int puesto){
    int i=1;
    ListaC act;
    ListaS auxLs;

    act = Lc->sig;
    while (act != Lc && i <= puesto){
        eliminaDeSL(&act->sub,cod);
        
        auxLs = buscaRobot(Ls,i);
        eliminaDeCola(&auxLs->C, cod);
        
        i++;
        act = act->sig;
    }
}

void eliminaDeSL(subL *SL,ST7 cod){
    subL ant,act,elim;
    
    while (strcmp((*SL)->cod,cod) == 0){
        elim = *SL;
        *SL = (*SL)->sig;
        free(elim);
    }
    
    act = (*SL)->sig;
    ant = *SL;
    while(act != NULL){
        
        if (strcmp(act->cod,cod) == 0)
            elim = act;
            
        act = act->sig;
        ant->sig = act;
        free(elim);    
    }
}

void eliminaDeCola(TCola *C,ST7 cod){
    TCola aux;
    TElementoC x;
    iniciaC(&aux);

    if (!vaciaC(*C))
        sacaC(C,&x);

    while (!vaciaC(*C) && strcmp(x.cod,cod) < 0){
        poneC(&aux,x);
        sacaC(C,&x);
    }

    if (strcmp(x.cod,cod) > 0)
        poneC(&aux,x);

    while (!vaciaC(aux)){
        sacaC(&aux,&x);
        poneC(C,x);
    }    
}

ListaS buscaRobot(ListaS Ls,int idP){
    while (Ls != NULL && Ls->idP != idP)
        Ls = Ls->sig;

    return (Ls != NULL && Ls->idP == idP) ? Ls : NULL;    
} 