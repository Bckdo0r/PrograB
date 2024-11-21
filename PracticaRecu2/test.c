#include <stdio.h>
#include <stdlib.h>

// Definición de un nodo de un árbol binario
typedef struct Nodo {
    int dato;
    struct Nodo *izq; // Hijo
    struct Nodo *der; // Hermano
} Nodo;

typedef Nodo* arbol;

// Función para crear un nodo nuevo
arbol crearNodo(int dato) {
    arbol nuevo = (arbol)malloc(sizeof(Nodo));
    nuevo->dato = dato;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
}

// Función para agregar un nodo al árbol
void addNodo(arbol* a, int dato) {
    if (*a == NULL) {
        *a = crearNodo(dato);
    } else {
        printf("Error: Nodo ya existente. Uso manual para insertar hijos/hermanos.\n");
    }
}

// Calcular el grado de un nodo (cantidad de hijos directos y hermanos)
int calcularGrado(arbol nodo) {
    if (!nodo) return 0;

    int grado = 0;

    // Contar el hijo izquierdo
    if (nodo->izq) grado++;

    // Contar los hermanos derechos
    arbol hermano = nodo->der;
    while (hermano) {
        grado++;
        hermano = hermano->der;
    }

    return grado;
}

// Función auxiliar para contar nodos de grado K en un árbol
int cuentaNodosGradoK(arbol a, int K) {
    if (a == NULL) return 0;

    // Calcular el grado del nodo actual
    int grado = calcularGrado(a);

    // Contar este nodo si su grado es K
    int cuenta = (grado == K) ? 1 : 0;

    // Recorrer recursivamente hijos y hermanos
    cuenta += cuentaNodosGradoK(a->izq, K); // Recorre el hijo izquierdo
    cuenta += cuentaNodosGradoK(a->der, K); // Recorre el hermano derecho

    return cuenta;
}

int verificaArbol(arbol a, int K) {
    if (a == NULL) return 0;

    // Contar nodos con grado K en este árbol completo
    int nodosGradoK = cuentaNodosGradoK(a, K);

    // Retorna 1 si hay exactamente un nodo con grado K, 0 en caso contrario
    return (nodosGradoK == 1);
}

int cuentaArboles(arbol bosque, int K) {
    int contador = 0;

    while (bosque != NULL) { // Recorre cada árbol en el bosque
        // Verificar si el árbol actual (su raíz) tiene exactamente un nodo de grado K
        if (verificaArbol(bosque, K)) {
            contador++;
        }
        // Avanza al siguiente árbol en el bosque (hermano derecho)
        bosque = bosque->der;
    }

    return contador;
}

// Prueba del programa con el bosque dado
int main() {
    arbol a = NULL;

    // Construcción del bosque proporcionado
    addNodo(&a, 1);
    addNodo(&a->izq, 4);
    addNodo(&a->izq->der, 5);
    addNodo(&a->izq->der->izq, 6);
    addNodo(&a->izq->der->izq->der, 8);
    addNodo(&a->izq->der->der, 15);
    addNodo(&a->izq->der->der->izq, 11);
    addNodo(&a->izq->der->der->izq->der, 12);
    addNodo(&a->izq->der->der->izq->der->der, 13);
    addNodo(&a->izq->der->der->izq->der->der->izq, 14);
    addNodo(&a->izq->der->der->izq->der->der->izq->der, 16);
    addNodo(&a->izq->der->der->izq->der->der->izq->der->der, 17);
    addNodo(&a->izq->der->der->izq->der->der->izq->der->der->der, 18);
    addNodo(&a->izq->der->der->izq->der->der->izq->izq, 6);
    addNodo(&a->izq->der->der->izq->der->der->izq->izq->der, 12);
    addNodo(&a->izq->der->der->izq->der->der->izq->izq->der->der, 9);
    addNodo(&a->izq->izq, 5);
    addNodo(&a->izq->izq->der, 7);
    addNodo(&a->izq->izq->der->izq, 8);
    addNodo(&a->izq->izq->der->izq->der, 10);
    addNodo(&a->izq->izq->der->der, 12);
    addNodo(&a->izq->izq->izq, 21);
    addNodo(&a->izq->izq->izq->der, 11);
    addNodo(&a->izq->izq->izq->der->der, 17);

    addNodo(&a->der, 4);
    addNodo(&a->der->izq, 15);
    addNodo(&a->der->izq->der, 11);
    addNodo(&a->der->izq->der->izq, 10);
    addNodo(&a->der->izq->der->izq->der, 20);
    addNodo(&a->der->izq->der->izq->der->der, 20);
    //addNodo(&a->der->izq->der->izq->der->der->der, 2);
    addNodo(&a->der->izq->izq, 1);
    addNodo(&a->der->izq->izq->der, 21);

    addNodo(&a->der->der, 19);
    addNodo(&a->der->der->izq, 28);
    addNodo(&a->der->der->izq->izq, 24);
    addNodo(&a->der->der->izq->izq->der, 13);
    addNodo(&a->der->der->izq->izq->der->der, 21);
    addNodo(&a->der->der->izq->izq->der->der->der, 21);


    // Evaluación
    int K = 4; // Cambiar según el grado deseado
    int resultado = cuentaArboles(a, K);

    printf("Cantidad de árboles con exactamente un nodo de grado %d: %d\n", K, resultado);

    return 0;
}


