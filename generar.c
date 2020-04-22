#include "generar.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>

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

void liberar_memoria (char **arreglo, int largo) {
  for (int i = 0; i < largo; ++i) {
    free (arreglo[i]);
  }
  free (arreglo);
}

void crear_arreglo_localidades (FILE *archivo, int largo, char **localidades) {
  char buffer[LARGO_BUFFER];
  for (int i = 0; i < largo; ++i) {
    fscanf (archivo, "%[^\n]\n", buffer);
    localidades[i] = malloc (sizeof(char) * (strlen(buffer) + 1));
    strcpy (localidades[i], buffer);
    localidades[i][strlen(buffer) + 1] = '\0';
  }
}

void arreglo_num_random (int *arregloRandom, int cantPersonas, int totalPersonas) {
  int *arregloIndex = malloc (sizeof(int) * totalPersonas);
  int numeroRandom, inicializador = 0, marcador = -1;
  int cantMarcadores = cantPersonas;
  if (cantPersonas > (totalPersonas/2)) {
    inicializador = -1;
    marcador = 0;
    cantMarcadores = totalPersonas - cantPersonas;
  }
  for (int i = 0; i < totalPersonas; ++i) {
      arregloIndex[i] = inicializador;
  }
  srand ((unsigned int) time (NULL));
  for (int i = cantMarcadores; i > 0; --i) {
    numeroRandom = rand() % totalPersonas;
    while (arregloIndex [numeroRandom] != inicializador) {
      numeroRandom = rand() % totalPersonas;
    }
    arregloIndex[numeroRandom] = marcador;
  }
  int idx = 0;
  for (int i = 0; i < totalPersonas; ++i) {
    if (arregloIndex[i] == marcador) {
      arregloRandom[idx] = i;
      idx++;
    }
  }
  free (arregloIndex);
}

void lectura_escritura (int cantPersonas, int arregloRandom[],
                char *archivoNombres, char *archivoPaises, char *archivoProg1) {
  FILE *archivoPersonas, *archivoLocalidades, *archivoSalida;
  char buffer[LARGO_BUFFER], nombreApellido[LARGO_BUFFER];
  int linea = 0, cantLocalidades, numeroRandom, edad;
  archivoLocalidades = fopen (archivoPaises, "r");
  cantLocalidades = cantidad_de_lineas (archivoLocalidades);
  char **arregloLocalidades = malloc(sizeof(char*) * cantLocalidades);
  rewind (archivoLocalidades);
  crear_arreglo_localidades (archivoLocalidades, cantLocalidades, arregloLocalidades);
  fclose (archivoLocalidades);
  archivoPersonas = fopen (archivoNombres, "r");
  archivoSalida = fopen (archivoProg1, "w");
  srand (time(NULL));
  for (int i = 0; i < cantPersonas; i++) {
    while(linea < arregloRandom[i]) {
      fgets (buffer, LARGO_BUFFER, archivoPersonas);
      linea++;
    }
  fscanf (archivoPersonas, "%[^\n]\n", nombreApellido);
  numeroRandom = rand() % cantLocalidades;
  edad = (rand() % RANGO_EDAD) + 1;
  fprintf (archivoSalida, "%s, %d, %s\n", nombreApellido, edad, arregloLocalidades[numeroRandom]);
  }
  fclose (archivoPersonas);
  fclose (archivoSalida);
  liberar_memoria (arregloLocalidades, cantLocalidades);
  free (arregloRandom);
}