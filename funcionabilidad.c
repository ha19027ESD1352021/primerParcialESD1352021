#include "funcionabilidad.h"

int contarlineas(char *nombrearch) {
    FILE *pa = fopen(nombrearch, "r");
    //prevee el error de archivo incorrecto
    if (pa == NULL) {
        printf("Problema al abrir el archivo %s.", nombrearch);
        exit(-1);
    }
    int n = 0; //almacenara el numero de lineas en el archivo
    char c = fgetc(pa);
    while (!feof(pa)) {
        if (c == '\n') {
            n++; //contador aumentado en uno para el numero de lineas
        }
        c = fgetc(pa);
    }
    fclose(pa);
    return n - 1; //se resta uno por que en la primer lineas estan los encabezados
}

const char* integrantes(char *archivo) {
    FILE *texto = fopen(archivo, "r");
    if (texto == NULL) {
        printf("Problema al abrir el archivo %s.", archivo);
        exit(-1);
    }
    char temp[100];
    fgets(temp, 1000, texto);
    int n = contarlineas(archivo);
    int caracteres=0;
    for (int i = 0; i < n; i++) {
        fgets(temp, sizeof (temp), texto);
        tmp[caracteres] += '#';
        caracteres++;
        for (int c = 0; c < 7; c = c++) {
            temp[caracteres] += tmp[c];
            caracteres++;
        }
        if (!(i==(n-1))) {
            temp[caracteres] += ',';
            caracteres++;
        }
    }
    fclose(texto);
    return tmp;
}

