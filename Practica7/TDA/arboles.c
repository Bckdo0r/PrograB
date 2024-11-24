#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arboles.h"

void addNodo0(arbol0 *a, int e)
{
    *a = (arbol0)malloc(sizeof(NODO0));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}

void cargaArbolEnteros(arbol0 *a){
    addNodo0(&(*a), 1);                                          
    addNodo0(&(*a)->izq, 4);                           
    addNodo0(&(*a)->izq->der, 5);
    addNodo0(&(*a)->izq->der->izq, 6);        
    addNodo0(&(*a)->izq->der->izq->der, 8);        
    addNodo0(&(*a)->izq->der->der, 15);
    addNodo0(&(*a)->izq->der->der->izq, 11);
    addNodo0(&(*a)->izq->der->der->izq->der, 12);
    addNodo0(&(*a)->izq->der->der->izq->der->der, 13);
    addNodo0(&(*a)->izq->der->der->izq->der->der->izq, 14);
    addNodo0(&(*a)->izq->der->der->izq->der->der->izq->der, 16);
    addNodo0(&(*a)->izq->der->der->izq->der->der->izq->der->der, 17);
    addNodo0(&(*a)->izq->der->der->izq->der->der->izq->der->der->der, 18);
    addNodo0(&(*a)->izq->der->der->izq->der->der->izq->der->der->der->izq, 0);
    addNodo0(&(*a)->izq->der->der->izq->der->der->izq->izq, 6);
    addNodo0(&(*a)->izq->der->der->izq->der->der->izq->izq->der, 12);
    addNodo0(&(*a)->izq->der->der->izq->der->der->izq->izq->der->der, 9);
    addNodo0(&(*a)->izq->izq, 1);                           
    addNodo0(&(*a)->izq->izq->der, 1);                           
    addNodo0(&(*a)->izq->izq->der->izq, 8);                           
    addNodo0(&(*a)->izq->izq->der->izq->der, 10);                           
    addNodo0(&(*a)->izq->izq->der->der, 2);
    addNodo0(&(*a)->izq->izq->izq, 21);
    addNodo0(&(*a)->izq->izq->izq->der, 11);
    addNodo0(&(*a)->izq->izq->izq->der->der, 17);

    //addNodo0(&(*a)->der, 4);                                          
    //addNodo0(&(*a)->der->izq, 15);                                          
    //addNodo0(&(*a)->der->izq->der, 11);                                          
    //addNodo0(&(*a)->der->izq->der->izq, 10);                                          
    //addNodo0(&(*a)->der->izq->der->izq->der, 20);                                          
    //addNodo0(&(*a)->der->izq->der->izq->der->der, 20);                                          
    //addNodo0(&(*a)->der->izq->der->izq->der->der->der, 2);                                          
    //addNodo0(&(*a)->der->izq->izq, 1);                                          
    //addNodo0(&(*a)->der->izq->izq->der, 21);
    //                                          
    //addNodo0(&(*a)->der->der, 19);                                          
    //addNodo0(&(*a)->der->der->izq, 28);                                          
    //addNodo0(&(*a)->der->der->izq->izq, 24);                                          
    //addNodo0(&(*a)->der->der->izq->izq->der, 13);                                          
    //addNodo0(&(*a)->der->der->izq->izq->der->der, 21);
    //addNodo0(&(*a)->der->der->izq->izq->der->der, 21);
}

void addNodo1(arbol1 *a, char e)
{
    *a = (arbol1)malloc(sizeof(NODO1));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}

void cargaArbolCaracteres(arbol1 *a){
    addNodo1(&(*a), 'A');                                         
    addNodo1(&(*a)->izq, 'B');                           
    addNodo1(&(*a)->izq->der, 'C');
    addNodo1(&(*a)->izq->der->izq, 'D');        
    addNodo1(&(*a)->izq->der->izq->der, 'E');        
    addNodo1(&(*a)->izq->der->der, 'F');
    addNodo1(&(*a)->izq->der->der->izq, 'G');
    addNodo1(&(*a)->izq->der->der->izq->der, 'H');
    addNodo1(&(*a)->izq->der->der->izq->der->der, 'I');
    addNodo1(&(*a)->izq->der->der->izq->der->der->izq, 'J');
    addNodo1(&(*a)->izq->der->der->izq->der->der->izq->der, 'K');
    addNodo1(&(*a)->izq->der->der->izq->der->der->izq->der->der, 'L');
    addNodo1(&(*a)->izq->der->der->izq->der->der->izq->der->der->der, 'M');
    addNodo1(&(*a)->izq->der->der->izq->der->der->izq->der->der->der->izq, '0');
    addNodo1(&(*a)->izq->der->der->izq->der->der->izq->izq, 'N');
    addNodo1(&(*a)->izq->der->der->izq->der->der->izq->izq->der, 'O');
    addNodo1(&(*a)->izq->der->der->izq->der->der->izq->izq->der->der, 'P');
    addNodo1(&(*a)->izq->izq, 'Q');                           
    addNodo1(&(*a)->izq->izq->der, 'R');                           
    addNodo1(&(*a)->izq->izq->der->izq, 'S');                           
    addNodo1(&(*a)->izq->izq->der->izq->der, 'T');                           
    addNodo1(&(*a)->izq->izq->der->der, 'U');
    addNodo1(&(*a)->izq->izq->izq, 'V');
    addNodo1(&(*a)->izq->izq->izq->der, 'W');
    addNodo1(&(*a)->izq->izq->izq->der->der, 'X');

    addNodo1(&(*a)->der, 'Y');                                          
    addNodo1(&(*a)->der->izq, 'Z');                                          
    addNodo1(&(*a)->der->izq->der, 'b');                                          
    addNodo1(&(*a)->der->izq->der->izq, 't');                                          
    addNodo1(&(*a)->der->izq->der->izq->der, 's');                                          
    addNodo1(&(*a)->der->izq->der->izq->der->der, 'q');                                          
    addNodo1(&(*a)->der->izq->der->izq->der->der->der, 'x');                                          
    addNodo1(&(*a)->der->izq->izq, 'r');                                          
    addNodo1(&(*a)->der->izq->izq->der, 'g');
                                              
    addNodo1(&(*a)->der->der, 'h');                                          
    addNodo1(&(*a)->der->der->izq, 'o');                                          
    addNodo1(&(*a)->der->der->izq->izq, 'p');                                          
    addNodo1(&(*a)->der->der->izq->izq->der, 'm');                                          
    addNodo1(&(*a)->der->der->izq->izq->der->der, 'a');
}

void addNodo2(arbol2 *a, const char *e){
    *a = (arbol2)malloc(sizeof(NODO2));
    (*a)->dato = (char *)malloc(strlen(e) + 1);
    if ((*a)->dato == NULL) {
        printf("Error al asignar memoria para la cadena.\n");
        exit(1);
    }
    strcpy((*a)->dato, e); // Copiar la cadena
    (*a)->izq = NULL;
    (*a)->der = NULL;
}

void cargaArbolCadenas(arbol2 *a){
    addNodo2(&(*a), "Root");                                          
    addNodo2(&(*a)->izq, "oLeft");                           
    addNodo2(&(*a)->izq->der, "Middle");
    addNodo2(&(*a)->izq->der->izq, "&Deep");        
    addNodo2(&(*a)->izq->der->izq->der, "Last");        
    addNodo2(&(*a)->izq->der->der, "Another");
    addNodo2(&(*a)->izq->der->der->izq, "&Nested");
    addNodo2(&(*a)->izq->der->der->izq->der, "More");
    addNodo2(&(*a)->izq->der->der->izq->der->der, "Final");
    addNodo2(&(*a)->izq->der->der->izq->der->der->izq, "Char");
    addNodo2(&(*a)->izq->der->der->izq->der->der->izq->der, "aTree");
    addNodo2(&(*a)->izq->der->der->izq->der->der->izq->der->der, "Leaf");
    addNodo2(&(*a)->izq->der->der->izq->der->der->izq->der->der->der, "End");
    addNodo2(&(*a)->izq->der->der->izq->der->der->izq->izq, "eBranch");
    addNodo2(&(*a)->izq->der->der->izq->der->der->izq->izq->der, "iPath");
    addNodo2(&(*a)->izq->der->der->izq->der->der->izq->izq->der->der, "aWay");
    addNodo2(&(*a)->izq->der->der->izq->der->der->izq->der->der->der->izq, "0cero");
    addNodo2(&(*a)->izq->izq, "Subtree");                           
    addNodo2(&(*a)->izq->izq->der, "Node");                           
    addNodo2(&(*a)->izq->izq->der->izq, "Level");                           
    addNodo2(&(*a)->izq->izq->der->izq->der, "Height");                           
    addNodo2(&(*a)->izq->izq->der->der, "!Depth");
    addNodo2(&(*a)->izq->izq->izq, "#Floor");
    addNodo2(&(*a)->izq->izq->izq->der, "Ceiling");
    addNodo2(&(*a)->izq->izq->izq->der->der, "Roof");

    addNodo2(&(*a)->der, "Right");                                          
    addNodo2(&(*a)->der->izq, "$Fork");                                          
    addNodo2(&(*a)->der->izq->der, "0Pathway");                                          
    addNodo2(&(*a)->der->izq->der->izq, "Road");                                          
    addNodo2(&(*a)->der->izq->der->izq->der, "*Trail");                                          
    addNodo2(&(*a)->der->izq->der->izq->der->der, "Journey");                                          
    addNodo2(&(*a)->der->izq->der->izq->der->der->der, "Quest");                                          
    addNodo2(&(*a)->der->izq->izq, "Track");                                          
    addNodo2(&(*a)->der->izq->izq->der, "!Step");
                                              
    addNodo2(&(*a)->der->der, "iDestination");                                          
    addNodo2(&(*a)->der->der->izq, "Checkpoint");                                          
    addNodo2(&(*a)->der->der->izq->izq, "Marker");                                          
    addNodo2(&(*a)->der->der->izq->izq->der, "uSpot");                                          
    addNodo2(&(*a)->der->der->izq->izq->der->der, "eFinish");
}