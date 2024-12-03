
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

    return 0;
}

Duracion calcularDuracionPlayList(TCola *C, ListaD LD)
{
    Duracion duracion;
    int segundos = 0;
    TElementoC X, centinela;
    pSubLista cancion;

    centinela.idPlayList = -1;
    poneC(C, centinela);
    sacaC(C, &X);

    while (X.idPlayList != centinela.idPlayList)
    {
        cancion = buscaCancion(LD, X);

        if (cancion && strncmp(X.idCancion, "DUKI", 4) != 0)
            segundos += cancion->duracion;

        poneC(C, X);
        sacaC(C, &X);
    }

    duracion.minutos = (int)(segundos / 60);
    duracion.horas = (int)(duracion.minutos / 60);

    return duracion;
}

pSubLista buscaCancion(ListaD LD, TElementoC X)
{
    PnodoD act = LD.pri;
    pSubLista sub;

    while (act != NULL && strcmp(act->idPlaylist, X.idPlayList) < 0)
        act = act->sig;

    if (act == NULL || strcmp(act->idPlaylist, X.idPlayList) != 0)
        return NULL;

    sub = act->sub;

    while (sub != NULL && strcmp(sub->idCancion, X.idCancion) < 0)
        sub = sub->sig;

    return sub != NULL && strcmp(sub->idCancion, X.idCancion) == 0 ? sub : NULL;
}