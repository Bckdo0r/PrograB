# Ejercicio 1

a) grados de entrada y salida de cada vértice.
b) todos los ciclos que pasan por el vértice C
c) todos los caminos del vértice A al E
d) todos los caminos del vértice B al D
e) todos los caminos de longitud 4 con origen en el vértice A
f) la matriz de adyacencia que lo representa.
g) la lista de adyacencia que lo representa.
h) la matriz de adyacencia que lo representa, suponiendo que no es un grafo dirigido. 

a)
        ENTRADA     SALIDA
A ->       1          2  
B ->       1          1  
C ->       1          2  
D ->       4          2  
E ->       1          1  
F ->       3          2
G ->       1          2  

b)
C-A-D-B-C
C-F-G-E-D-B-C
C-F-D-B-C
C-A-F-G-E-D-B-C
C-A-F-G-D-B-C
C-A-F-D-B-C

c)
A-D-F-G-E
A-F-G-E
A-D-B-C-F-G-E

d)
B-C-F-G-E-D
B-C-A-D
B-C-A-F-D
B-C-A-F-G-D
B-C-A-F-G-E-D

f)
  A  B  C  D  E  F  G
A[0][0][0][1][0][1][0]
B[0][0][1][0][0][0][0]
C[1][0][0][0][0][1][0]
D[0][1][0][0][0][1][0]
E[0][0][0][1][0][0][0]
F[0][0][0][1][0][0][1]
G[0][0][0][1][1][0][0]

g)
[
A -> [D,F]
B -> [C]
C -> [A,F] 
D -> [B,F]
E -> [D]
F -> [D,G]
G -> [D,E]
]

h)
  A  B  C  D  E  F  G
A[0][0][1][1][0][1][0]
B[0][0][1][1][0][0][0]
C[1][1][0][0][0][1][0]
D[1][1][0][1][1][1][1]
E[0][0][0][1][0][0][1]
F[1][0][1][1][0][0][1]
G[0][0][0][1][1][1][0]