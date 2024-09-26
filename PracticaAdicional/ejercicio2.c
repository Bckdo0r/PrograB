/*A partir de una lista simplemente enlazada ordenada de enteros, generar dos listas 
simplemente enlazadas de salida: una conteniendo los valores impares ordenados 
descendentemente, y la segunda con los valores pares ordenados de manera ascendente. No 
se deberá crear nuevos nodos, sino utilizar los de la lista original generando nuevos enlaces.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo{
    int num;
    struct nodo *sig;
} nodoL;

typedef nodoL *Lista;

void agregaNodo(Lista *,int);
void cargaLista(Lista *);
void imprimeLista(Lista);
void generaListas(Lista *,Lista *,Lista *);

int main() {
    Lista L,LI,LP; //LI = Lista impares descendentes, LP = Lista pares ascendentes
    L = NULL;
    LI = NULL;
    LP = NULL;

    cargaLista(&L);
    printf("Lista main: ");
    imprimeLista(L);
    generaListas(&L,&LI,&LP);
    printf("\nLista impares descendentes: ");
    imprimeLista(LI);
    printf("\nLista pares ascendentes: ");
    imprimeLista(LP);

    return 0;
}

void agregaNodo(Lista *L,int num){
    Lista new,ant,act;
    new = (nodoL*)malloc(sizeof(nodoL));
    new->num=num;
    
    if (*L == NULL || (*L)->num > num){
        new->sig = *L;
        *L = new;
    }
    else{
        act = *L;
        while (act != NULL && num > act->num){
            ant = act;
            act = act->sig;
        }
        new->sig = act;
        ant->sig = new;
    }        
}

void cargaLista(Lista *L){
    int num;
    FILE *arch;
    arch = fopen("datosEJ2.txt","r");
    if(arch == NULL) 
        printf("Error al abrir archivo\n");
    else{
        while(fscanf(arch,"%d",&num) == 1)
            agregaNodo(L,num);
        fclose(arch);    
    }
}

void imprimeLista(Lista L){
    while (L != NULL){
        printf("%d ",L->num);
        L = L->sig;
    }
}

void generaListas(Lista *L,Lista *LI,Lista *LP){
    Lista aux,ultP;

    *LP = *LI = NULL;
    while (*L != NULL) {
        aux = *L;
        *L = (*L)->sig;
        if (aux->num % 2 != 0){
            aux->sig = *LI;
            *LI = aux;
        }
        else {
            if (*LP == NULL){
                *LP = aux;
                ultP = *LP;
            }    
            else {
                ultP->sig = aux;
                ultP = aux;
            } 
        }
    }
    ultP->sig = NULL;
}