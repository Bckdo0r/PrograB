#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*  
    Grafos: Estructura de datos no lineal, no jerarquica
    Usos:   -mapas
            -conexiones (de redes)
            -representacion de proyectos

    Peso/Ponderacion > 0
    G = (V,E)
    V = {a,b,c,d}
    E = {(a,a):3,(a,b):4,...}
    |V| = orden del grafo

    *Grafos -> pares NO ordenados de vertices
    *Digrafo -> pares ordenados de vertices

    CAMINO: P(Vi,Vf) = (),()...
    CAMINO SIMPLE: no se repiten aristas
    CICLO: camino con Vi = Vf

    !VERTICES
    
    GRAFO 
    Grado -> aristas que se realcionan con el o que inciden en el

    DIGRAFO
    Grado de E -> aristas que tienen al vertice como destino (1 UNOS)
    Grado de S -> aristas que tienen el vertice como origen (0 CEROS)

    *Grafo conexo: Si existe en camino entre cada par de nodos
    *Digrafo conexo: si el grafo subyacente es conexo
    ?Grafo subyacente:  se obtiene de quitarle la direccion a la aristas

    *Matriz de adyacencia de NxN: (0 Y 1) // (0 Y costos)
    *Lista de adyacencia: Vector de registros/punteros a una lista no ordenada de nodos que representan aristas
    
    !ALGORITMOS (recorridos)

    En Amplitud(BFS)
    -Se elije un nodo inicial, se visita y se marca como visitado
    -Se visitan los nodos adyacentes y se marcan como visitados
    -Se visitan los nodos adyacentes a los ya visitados, en orden
    -Se repite el ciclo hasta que no haya nodos sin visitar

    Ejemplo -> F-B-G-A-C-E-H-D
    
    TODO implementacion:
    iterativa (usa colas):
    N vertices: Visitados o no Vector visitados
    -Mientras el vector tenga elementos en 0 (el vertice no fue visitado), ir almacenando lo elementos en la cola


    En profundidad(DFS)
    -


*/

int main() {


    return 0;
}