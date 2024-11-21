#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Practica5/TDAs/colas3.h"
#include "../Practica5/TDAs/pilasD.h"
#include "../Practica5/TDAs/tipos.h"
#define MAX 100
typedef struct nodito{
    bolsa dato;
    struct nodo *sig;
} nodoSL;

typedef nodoSL *SubL;

typedef struct nodo{
    char dest;
    SubL sub;
    struct nodo *sig,*ant;
} nodoLD;

typedef struct{
    nodoLD *pri,*ult;
} ListaD;

void cargaLista(ListaD *);
void cargaCola(TCola *);
void procesaEmbolsado(TCola *,ListaD ,TPila *);
void agregaASub(SubL *,bolsa);
bolsa armaBolsa(TCola *,TPila *);
char estableceDest(bolsa);
void atiendePedido(ListaD *,int ,char);
void eliminaDeLista(ListaD *,nodoLD *);
void modifCritDescarte(TCola *,TPila *,int *);

int main() {
    ListaD L;
    TCola C;
    TPila P;
    int cant,cont = 0;
    char dest;
    
    L.pri = NULL;
    L.ult = NULL;
    iniciaC(&C);
    iniciaP(&P);

    printf("Ingrese una cantidad de bolsas: ");
    scanf("%d",&cant);
    
    do{
        printf("\nIngrese un destino (E = exterior, N = nacional, L = local): ");
        scanf("%c",&dest);
        
        if (dest != 'E' && dest != 'N' && dest != 'L')
            printf("Destino incorrecto, vuelva a intentar.\n");

    }while (dest != 'E' && dest != 'N' && dest != 'L');
    
    cargaLista(&L);
    cargaCola(&C);

    procesaEmbolsado(&C,L,&P);
    atiendePedido(&L,cant,dest);
    modifCritDescarte(&C,&P,&cont);

    printf("\nEn la pila %s quedaron papas de calidad 4.\n", cont > 0 ? "SI" : "NO");
    
    return 0;
}

void procesaEmbolsado(TCola *C,ListaD L,TPila *P){ //! A)
    TElementoC x;
    TElementoP y;
    nodoLD *aux,*ultE = NULL,*ultN = NULL,*ultL = NULL;
    SubL nuevo;
    iniciaP(P);
    bolsa B;
    char dest;

    buscaUltimos(L,ultE,ultN,ultL);

    while(!vaciaC(*C)){
        B = armaBolsa(C,P);

        if (B.peso >= 50){
            nuevo = (SubL) malloc(sizeof(nodoSL));
            nuevo->dato = B;
            nuevo->sig = NULL;

            dest = estableceDest(B);

            if (dest == 'L'){
                ultL->sig = nuevo;
                nuevo = ultL;
            }
            else if (dest == 'N'){
                ultN->sig = nuevo;
                nuevo = ultN;
            }
            else{
                ultE->sig = nuevo;
                nuevo = ultE;
            }
                
            sacaC(C,&x);
        }
        
        else
            printf("Se perfieron %.2f Kg de papa.\n",B.peso);
    }
}

void buscaUltimos(ListaD L,nodoLD *ultE,nodoLD *ultN,nodoLD *ultL){
    nodoLD *aux;

    aux = L.pri;
    while(aux->sub != NULL){
        ultL = aux->sub;
        aux->sub = aux->sub->sig;
    }

    aux = aux->sig;
    while(aux->sub != NULL){
        ultE = aux->sub;
        aux->sub = aux->sub->sig;
    }

    aux = aux->sig;
    while(aux->sub != NULL){
        ultE = aux->sub;
        aux->sub = aux->sub->sig;
    }
}

char estableceDest(bolsa B){
    float pesoProm;
    int i,totPapas = 0;

    for (i=0; i<3 ;i++)
        totPapas += B.vec[i];

    if ((float)B.vec[0] / totPapas * 100 >= 50) //? castea bien       
        return 'E';

    else if ( ((float)B.vec[0]+B.vec[1]) / totPapas * 100 > 40)
        return 'N';
    
    else
        return 'L';        
}

bolsa armaBolsa(TCola *C,TPila *P){
    TElementoC x;
    bolsa B;
    
    B.peso = 0;
    for (int i = 0; i<3 ; i++)
        B.vec[i] = 0;

    sacaC(C,&x);
    while (!vaciaC(*C) && B.peso <= 50){
        
        if (x.peso >= 30 && x.calidad != 4 && x.calidad != 5){
            B.peso += (float)(x.peso)/1000;
            B.vec[x.calidad-1] ++;
        }
        
        else
            poneC(P,x);
        
        sacaC(C,&x);    
    }
    return B;
}

void atiendePedido(ListaD *L,int cant, char dest){ //! B)
    float pesoTot = 0;
    int totPapas = 0,cantPapas,i,c = 0;
    FILE *arch;
    nodoLD *aux;
    nodoSL *auxSub,*elim;
    char cantSTR[10] = "N",extension[5] = ".TXT",nombreArch[15];

    sprintf(cant,"%d",cantSTR);
    strcat(nombreArch,strcat(cantSTR,extension));
    L->pri = aux;
    while (aux->dest != dest)
        aux = aux->sig;

    auxSub = aux->sub;
    arch = fopen(nombreArch,"w");

    if (arch != NULL){
        
        while (auxSub != NULL && c < cant){
            cantPapas = 0;
            pesoTot += auxSub->dato.peso;
            for (i = 0; i < 3 ;i++)
                cantPapas += auxSub->dato.vec[i];

            fprintf(arch,"Peso: %.2f | NroPapas: %d\n",auxSub->dato.peso,cantPapas);
            c++;
            
            elim = auxSub;
            auxSub = auxSub->sig;
            free(elim);
        }
        fprintf(arch,"Peso total: %.2f\n",pesoTot);

        if (auxSub == NULL)
            eliminaDeLista(L,aux);//? estan bien pasados los parametros

        fclose(arch);    
    }

}

void eliminaDeLista(ListaD *L,nodoLD *aux){
    
    if (L->pri == L->ult){
        L->pri = NULL;
        L->ult = NULL;        
    }
    
    else if (L->pri == aux){
        L->pri = aux->sig;
        aux->sig->ant = NULL;
    }
    
    else if (L->ult == aux){
        L->ult = aux->ant;
        aux->ant->sig = NULL;
    }
    
    else{
        aux->ant->sig = aux->sig;
        aux->sig->ant = aux->ant;
    }

    free(aux);

}

void modifCritDescarte(TCola *C,TPila *P,int *cont){ //! C)
    TElementoC x;
    TElementoP y;

    if (!vaciaP(*P)){
        sacaP(P,&y);
        x.calidad = y.calidad;
        y.peso = x.peso;
        
        modifCritDescarte(C,P,cont);

        if (y.calidad == 4 && y.peso >= 30)
            poneC(C,x);        
        
        else{
            (*cont) += x.calidad == 4;
            poneP(P,y);
        }
    }
}