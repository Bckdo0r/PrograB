/*
Desarrollar un subprograma para mostrar el camino de un vértice v a un vértice w a partir de la
matriz P generada por el algoritmo de Floyd. (v, w datos).
*/

#include <stdio.h>
#define INF 1000000
#define N 4

typedef int TMat[N][N];

void floydWarshall(TMat ady, TMat P)
{
    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (ady[i][k] + ady[k][j] < ady[i][j])
                {
                    ady[i][j] = ady[i][k] + ady[k][j];
                    P[i][j] = P[k][j];
                }
            }
        }
    }
}

void printPath(TMat P, int i, int j)
{
    if (i == j)
        printf("%d ", i);
    else if (P[i][j] == -1)
        printf("No hay camino de %d a %d\n", i, j);
    else
    {
        printPath(P, i, P[i][j]);
        printf("%d ", j);
    }
}

int main()
{
    // Matriz de adyacencia
    TMat ady = {
        {0, 3, INF, 7},
        {8, 0, 2, INF},
        {5, INF, 0, 1},
        {2, INF, INF, 0}};

    TMat P;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j || ady[i][j] == INF)
                P[i][j] = 0;
            else
                P[i][j] = i;
        }
    }

    floydWarshall(ady, P);

    printf("Matriz de distancias mínimas:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (ady[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", ady[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz de predecesores:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%7d", P[i][j]);
        printf("\n");
    }

    int start = 0, end = 3;
    printf("\nCamino mínimo de %d a %d: ", start, end);
    printPath(P, start, end);
    printf("\n");

    return 0;
}
