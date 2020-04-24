#include "generar.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define LARGO_BUFFER 100
#define RANGO_EDAD 100

/*cantidad_de_lineas: File* -> Int
Recibe un archivo, devuelve la cantidad de lineas que posee el archivo*/
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

/*liberar_memoria: char**, int
Recibe un arreglo de punteros char y su tamaño,
libera los espacios de memoria de cada puntero en el arreglo*/
void liberar_arreglo (ArregloStrings *arreglo) {
  for (int i = 0; i < arreglo->capacidad; ++i) {
    free (arreglo->arreglo[i]);
  }
  free (arreglo->arreglo);
  free (arreglo);
}

/* crear_arreglo_localidades: FILE* , int , char**
Recibe un archivo de localidades, la cantidad de lineas del archivo
y un arreglo de punteros char. 
Le asigna a cada puntero char una localidad del archivo */
ArregloStrings* crear_arreglo (char *nombreArchivo) {
  char buffer[LARGO_BUFFER];
  int capacidad = 0;
  FILE *archivo;
  archivo = fopen (nombreArchivo, "r");
  capacidad = cantidad_de_lineas (archivo);
  rewind (archivo);
  ArregloStrings *nuevoArreglo = malloc (sizeof(ArregloStrings));
  nuevoArreglo->arreglo = malloc (sizeof(char*) * capacidad);
  nuevoArreglo->capacidad = capacidad;
  for (int i = 0; i < capacidad; ++i) {
    fscanf (archivo, "%[^\n]\n", buffer);
    nuevoArreglo->arreglo[i] = malloc (sizeof(char) * (strlen(buffer) + 1));
    strcpy (nuevoArreglo->arreglo[i], buffer);
    nuevoArreglo->arreglo[i][strlen(buffer)] = '\0';
  }
  fclose (archivo);
  return nuevoArreglo;
}

/* lectura_escritura: int, int *, char*, char*, char* 
  Recibe la cantidad de personas, el arreglo de numeros random, el nombre 
  del archivo de personas, el nombres del archivo de paises, el nombre del archivo
  que devuelve.
  Escribe sobre un archivo las personas, con una edad aleatoria que va del 1 al
  100 y una localidad aleatoria del archivo de localidades*/
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
    fprintf (archivoSalida, "%s, %d, %s\n", arregloNombres->arreglo[random1],
                                         edad, arregloPaises->arreglo[random2]);
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