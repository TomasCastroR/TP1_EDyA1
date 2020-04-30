#include "generar.h"
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <wchar.h>

#define LARGO_BUFFER 100
#define RANGO_EDAD 100

int cantidad_de_lineas (FILE *archivo) {
  int lineas = 0;
  wchar_t buffer[LARGO_BUFFER];
  wint_t caracter = fgetwc (archivo);
  while (caracter != WEOF) {
    fgetws (buffer, LARGO_BUFFER, archivo);
    caracter = fgetwc (archivo);
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
  wchar_t buffer[LARGO_BUFFER];
  int capacidad = 0;
  FILE *archivo;
  archivo = fopen (nombreArchivo, "r");
  capacidad = cantidad_de_lineas (archivo);
  rewind (archivo);
  ArregloStrings *nuevoArreglo = malloc (sizeof(ArregloStrings));
  assert(nuevoArreglo);
  nuevoArreglo->strings = malloc (sizeof(wchar_t*) * capacidad);
  assert(nuevoArreglo->strings);
  nuevoArreglo->capacidad = capacidad;
  for (int i = 0; i < capacidad; ++i) {
    fwscanf (archivo, L"%[^\n]\n", buffer);
    nuevoArreglo->strings[i] = malloc (sizeof(wchar_t) * (wcslen(buffer) + 1));
    assert(nuevoArreglo->strings[i]);
    wcscpy (nuevoArreglo->strings[i], buffer);
    nuevoArreglo->strings[i][wcslen(buffer)] = '\0';
  }
  fclose (archivo);
  return nuevoArreglo;
}

void crear_archivo_personas (int cantPersonas,char *archivoNombres,
                                      char *archivoPaises, char *nombreSalida) {
  FILE *archivoSalida;
  int random1, random2, edad;
  ArregloStrings *arregloNombres = crear_arreglo_strings (archivoNombres);
  ArregloStrings *arregloPaises = crear_arreglo_strings (archivoPaises);
  archivoSalida = fopen (nombreSalida, "w");
  srand (time(NULL));
  for (int i = 0; i < cantPersonas; i++) {
    random1 = rand() % arregloNombres->capacidad;
    random2 = rand() % arregloPaises->capacidad;
    edad = (rand() % RANGO_EDAD) + 1;
    fwprintf (archivoSalida, L"%ls, %d, %ls\n", arregloNombres->strings[random1],
                                         edad, arregloPaises->strings[random2]);
  }
  fclose (archivoSalida);
  liberar_arreglo_strings (arregloNombres);
  liberar_arreglo_strings (arregloPaises);
}

