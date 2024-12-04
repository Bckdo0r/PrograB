
/*
Ej 2.- Un sistema de reproducción de música administra las playlists públicas en una lista doblemente
enlazada LP con la siguiente estructura:
• Id Playlist (Numérico, ordenada)
• Sublista de canciones
    Id Canción (cadena de 15, los primeros 4 caracteres determinan el intérprete)
    Título canción (Cadena de 20)
    Duración (en segundos)

Se tiene una playlist C que ha tomado a su vez canciones de LP, implementada mediante una cola,
en la que cada elemento contiene Id Playlist (ordenada por este criterio), Id Canción.
Se pide: utilizando el TDA COLA
a) En un único recorrido de la cola resolver (sin perder la cola ni cambiar el orden de la misma):
i) Hallar el tiempo en horas y minutos de reproducción de la playlist C (sin considerar las que se
eliminan en ii))
ii) Eliminar de C aquellas canciones que estén interpretadas por "DUKI" y sean de la playlist X (X es
dato de entrada)
b) Dado un Id Interprete (cadena de 4), eliminar sin recorrer LP más de una vez todas las canciones disponibles de él en las playlists X e Y de LP (X e Y datos validados) y listarlas (con el formato siguiente)
XXXXXXXXXXX
c) Suponiendo la cola circular definir su tipo y desarrollar los operadores PoneC() y VaciaC(). Indicar
donde estarían estas definiciones.
Intérprete: XXXX
PLAYLIST 99999

Id Canción
Titulo Cancion
XXXXXXXXXXX
XXXXXXXXXXXXXXXXXXXX

XXXXXXXXXXXXXXXXXXXX
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Practica5/TDAs/colas1.h"
#include "../Practica7/TDA/N-ario.h"
#include "../Practica7/TDA/arboles.h"
#include "../Practica8/grafo.h"

typedef char st4[5];
typedef char st15[16];
typedef char st20[21];

typedef struct nodito
{
    st15 idCancion;
    st20 titulo;
    unsigned int duracion;
    struct nodito *sig;
} nodito, *pSubLista;

typedef struct nodoD
{
    int idPlaylist;
    pSubLista sub;
    struct nodoD *ant, *sig;
} nodoD;
typedef nodoD *PnodoD;
typedef struct
{
    struct nodoD *pri, *ult;
} ListaD;

typedef struct
{
    int horas, minutos;
} Duracion;

Duracion calcularDuracionPlayList(TCola *, ListaD);

int main(int argc, char const *argv[])
{
    TCola C;
    ListaD LP;
    Duracion duracion;
    cargaC(&C);
    cargaLD(&LP);

    duracion = calcularDuracionPlayList(&C, LP);

    printf("%d:%d", duracion.horas, duracion.minutos);

    return 0;
}

Duracion calcularDuracionPlayList(TCola *C, ListaD LP)
{
    int segundos = 0;
    Duracion duracion;
    TElementoC X, centinela;
    pSubLista cancion;

    centinela.idPlayList = -1;
    poneC(C, centinela);
    sacaC(C, &X);

    while (X.idPlayList != centinela.idPlayList)
    {
        cancion = buscaCancion(LP, X.idPlayList, X.idCancion);

        if (cancion)
            segundos += cancion->duracion;

        poneC(C, X);
        sacaC(C, &X);
    }

    duracion.minutos = (int)(segundos / 60);
    duracion.horas = (int)(duracion.minutos / 60);

    return duracion;
}

pSubLista buscaCancion(ListaD LP, int idPlayList, st15 idCancion)
{
    PnodoD act = LP.pri;
    pSubLista sub;

    while (act != NULL && strcmp(act->idPlaylist, idPlayList) < 0)
        act = act->sig;

    if (act == NULL || strcmp(act->idPlaylist, idPlayList) != 0)
        return NULL;

    sub = act->sub;

    while (sub != NULL && strcmp(sub->idCancion, idCancion) < 0)
        sub = sub->sig;

    return sub != NULL &&
                   strncmp(sub->idCancion, "DUKI", 4) != 0 &&
                   strcmp(sub->idCancion, idCancion) == 0
               ? sub
               : NULL;
}

/*Eliminar de C aquellas canciones que estén interpretadas por "DUKI" y sean de la playlist X (X es
dato de entrada)*/
void eliminaCola(TCola *C, ListaD LP, int X)
{
    TElementoC elem, centinela;
    centinela.idPlayList = -1;
    pSubLista cancion;

    poneC(C, centinela);
    sacaC(C, &elem);

    while (elem.idPlayList != centinela.idPlayList)
    {
        cancion = buscaCancion(LP, X, elem.idCancion);

        if (cancion)
            poneC(C, elem);

        sacaC(C, &elem);
    }
}

/* Dado un Id Interprete (cadena de 4), eliminar sin recorrer LP más de una vez todas las
canciones disponibles de él en las playlists X e Y de LP (X e Y datos validados) y listarlas */
void eliminaLista(ListaD LP, st4 idInterprete, int X, int Y)
{
    PnodoD act = LP.pri;
    pSubLista sub;
    int cont = 0;

    printf("Intérprete: %s\n", idInterprete);

    while (cont != 2)
    {
        if (strcmp(act->idPlaylist, X) != 0 || strcmp(act->idPlaylist, Y) != 0)
        {
            cont++;
            eliminaDeSubLista(&act->sub, idInterprete);
        }

        printf("PLAYLIST %s\n", act->idPlaylist);
        printf("\tId cancion \t\tTitulo cancion\n");

        sub = act->sub;
        while (sub != NULL)
        {
            printf("\t%s \t\t%s\n", sub->idCancion, sub->titulo);
            sub = sub->sig;
        }

        act = act->sig;
    }
}

void eliminaDeSubLista(pSubLista *sub, st4 idInterprete)
{
    pSubLista act = *sub, ant = NULL, elim;

    while (act != NULL)
    {
        if (strncmp(act->idCancion, idInterprete, 4) == 0)
        {
            elim = act;
            act = act->sig;

            if (elim == *sub)
                *sub = act;
            else
                ant->sig = act;

            free(elim);
        }
        else
        {
            ant = act;
            act = act->sig;
        }
    }
}

/*
Ej 3.- (Utilizar TDA N-Ario) Dado un árbol A N-Ario de enteros, determinar si hay exactamente K nodos
no hoja que tienen grado igual al nivel en el que se encuentran.
*/
void determina(arbol0 A, posicion p, int K, int nivel, int *cont)
{
    posicion c, h;
    int gr = 0;

    if (*cont < K)
    {
        c = h = HijoMasIzq(p, A);

        while (!Nulo(c) && *cont < K)
        {
            gr++;
            determina(A, c, K, nivel + 1, cont);
            c = HermanoDer(c, A);
        }

        if (!Nulo(h) && gr == nivel)
            (*cont)++;
    }
}

int main3()
{
    arbol0 A;
    int K = 3, cont = 0;

    determina(A, Raiz(A), K, 0, &cont);

    if (cont == K)
        printf("anashe");
    else
        printf("anashen't");
}
