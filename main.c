#include <stdio.h>
#include <stdlib.h>
#include "funcionabilidad.h"

int main(int argc, char** argv) {
    char nombreArchivo[100];
    printf("Ingrese la ruta del archivo .csv: ");
    scanf("%s", nombreArchivo);
    printf("\n");

    int n = contarlineas(nombreArchivo); //contar el numero de lineas
    //printf("El numero de lineas en el documento es %d\n", n);
    int matriznormal[n][6];
    //Abrir el archivo
    FILE *pEnt = fopen(nombreArchivo, "r");
    if (pEnt == NULL) {
        printf("Problema al abrir el archivo %s.", nombreArchivo);
        exit(-1);
    }

    //llegamos a la segunda lineas
    char temp[100];
    fgets(temp, 1000, pEnt);

    //recorremos las demas lineas
    char lineas[80];

    //vaciamos los datos en la matriz
    char tmp[1];
    for (int i = 0; i < n; i++) {
        int cont = 0;
        fgets(lineas, sizeof (lineas), pEnt);
        for (int c = 8; c < 19; c = c + 2) {
            tmp[0] = lineas[c];
            matriznormal[i][cont] = atoi(tmp);
            cont++;
        }
    }
    fclose(pEnt);

    //mostrar matriz normal
    for (int fila = 0; fila < n; fila++) {
        for (int columna = 0; columna < 6; columna++) {
            if (columna == 0) {
                printf("%i", matriznormal[fila][columna]);
            } else {
                printf("\t%i", matriznormal[fila][columna]);
            }
        }
        printf("\n");
    }

    int matriztranspuesta[6][n];

    //obtener matriz matrizproducto
    for (int fila = 0; fila < n; fila++) {
        for (int columna = 0; columna < 6; columna++) {
            matriztranspuesta[columna][fila] = matriznormal[fila][columna];
        }
    }
    //mostrar matriz matriztranspuesta
    printf("\nMatrix matriztranspuesta\n\n");

    for (int fila = 0; fila < 6; fila++) {
        for (int columna = 0; columna < n; columna++) {
            if (columna == 0) {
                printf("%i", matriztranspuesta[fila][columna]);
            } else {
                printf("\t%i", matriztranspuesta[fila][columna]);
            }
        }
        printf("\n");
    }
    //printf("filas: %i\ncolumnas: %i", (int)((sizeof (matriznormal)/4)/(sizeof(matriznormal[0])/4)),(int)(sizeof(matriznormal[0])/4));
    int matrizproducto[n][n];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrizproducto[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int h = 0; h < 6; h++) {
                matrizproducto[i][j] += matriznormal[i][h] * matriztranspuesta[h][j];
            }
        }
    }
    printf("\nMatriz matrizproducto\n");
    for (int fila = 0; fila < n; fila++) {
        for (int columna = 0; columna < n; columna++) {
            if (columna == 0) {
                printf("%i", matrizproducto[fila][columna]);
            } else {
                printf("\t%i", matrizproducto[fila][columna]);
            }
        }
        printf("\n");
    }
    char integrantesl[1000];

    return (EXIT_SUCCESS);
}

