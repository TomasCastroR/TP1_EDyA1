#ifndef __GENERAR_H__
#define __GENERAR_H__

#include <stdio.h>
#define LARGO_BUFFER 100
#define RANGO_EDAD 100

int cantidad_de_lineas (FILE *archivo);

void liberar_memoria (char **localidades, int largo);

void crear_array_localidades (FILE *archivo, int largo, char **localidades);

void arreglo_num_random (int *array_random, int cantPersonas, int totalPersonas);

void lectura_escritura(int cantPersonas, int arregloRandom[], char *archivoNombres, char *archivoPaises, char *archivoProg1);

#endif