#ifndef __GENERAR_H__
#define __GENERAR_H__

#include <stdio.h>

typedef struct {
  char **arreglo;
  int capacidad;
}ArregloStrings;

int cantidad_de_lineas (FILE *archivo);

void liberar_memoria (ArregloStrings *arreglo);

ArregloStrings* crear_arreglo (char *nombreArchivo);

void lectura_escritura (int cantPersonas, ArregloStrings *arregloNombres,
                             ArregloStrings *arregloPaises, char *nombreSalida);

void crear_archivo_personas (char *archivoNombre, char *archivoPaises,
                                         int cantPersonas, char *archivoSalida);

#endif