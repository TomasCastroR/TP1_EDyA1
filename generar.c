#include "generar.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#define LARGO_BUFFER 100
#define RANGO_EDAD 100

int cantidad_de_lineas (FILE *archivo) {
  int lineas = 0;
  char buffer[LARGO_BUFFER], caracter;
  while (caracter != EOF) {
    fgets (buffer, LARGO_BUFFER, archivo);
    caracter = fgetc (archivo);
    lineas++;
  }
  return lineas;
}


void liberar_arreglo_strings (ArregloStrings *arreglo) {
  for (int i = 0; i < arreglo->capacidad; ++i) {
    free (arreglo->strings[i]);
  }
  free (arreglo->strings);
  free (arreglo);
}


ArregloStrings* crear_arreglo_strings (char *nombreArchivo) {
  char buffer[LARGO_BUFFER];
  int capacidad = 0;
  FILE *archivo;
  archivo = fopen (nombreArchivo, "r");
  capacidad = cantidad_de_lineas (archivo);
  rewind (archivo);
  ArregloStrings *nuevoArreglo = malloc (sizeof(ArregloStrings));
  assert(nuevoArreglo);
  nuevoArreglo->strings = malloc (sizeof(char*) * capacidad);
  assert(nuevoArreglo->strings);
  nuevoArreglo->capacidad = capacidad;
  for (int i = 0; i < capacidad; ++i) {
    fscanf (archivo, "%[^\n]\n", buffer);
    nuevoArreglo->strings[i] = malloc (sizeof(char) * (strlen(buffer) + 1));
    assert(nuevoArreglo->strings[i]);
    strcpy (nuevoArreglo->strings[i], buffer);
    nuevoArreglo->strings[i][strlen(buffer)] = '\0';
  }
  fclose (archivo);
  return nuevoArreglo;
}

void lectura_escritura (int cantPersonas, ArregloStrings *arregloNombres,
                           ArregloStrings *arregloPaises, char *nombreSalida) {
  FILE *archivoSalida;
  int random1, random2, edad;
  archivoSalida = fopen (nombreSalida, "w");
  srand (time(NULL));
  for (int i = 0; i < cantPersonas; i++) {
    random1 = rand() % arregloNombres->capacidad;
    random2 = rand() % arregloPaises->capacidad;
    edad = (rand() % RANGO_EDAD) + 1;
    fprintf (archivoSalida, "%s, %d, %s\n", arregloNombres->strings[random1],
                                         edad, arregloPaises->strings[random2]);
  }
  fclose (archivoSalida);
  liberar_arreglo (arregloNombres);
  liberar_arreglo (arregloPaises);
}

void crear_archivo_personas (char *archivoNombres, char *archivoPaises,
                                       int cantPersonas, char *archivoSalida) {
  ArregloStrings *arregloNombres = crear_arreglo (archivoNombres);
  ArregloStrings *arregloPaises = crear_arreglo (archivoPaises);
  lectura_escritura (cantPersonas, arregloNombres, arregloPaises, archivoSalida);
}