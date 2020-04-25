#ifndef __GENERAR_H__
#define __GENERAR_H__

#include <stdio.h>

typedef struct {
  char **strings;
  int capacidad;
}ArregloStrings;

/*cantidad_de_lineas: File* -> Int
  Recibe un archivo, devuelve la cantidad de lineas que posee el archivo*/
int cantidad_de_lineas (FILE *archivo);

/*liberar_memoria: struct* ArregloStrings
  Recibe una estructura de ArregloStrings,
  y libera los espacios de memoria pedidos */
void liberar_arreglo_strings (ArregloStrings *arreglo);

/* crear_arreglo_strings: char*
  Recibe el nombre del archivo. 
    Devuelve una estructura de tipo ArregloStrings, donde cada linea del archivo
  es un string dentro del arreglo. */
ArregloStrings* crear_arreglo_strings (char *nombreArchivo);

/* lectura_escritura: int, struct ArregloStrings, struct ArregloStrings, char*
  Recibe la cantidad de personas, la estructura de nombre, la estructura con paisas
  y el nombre del archivo de salida.
   Escribe sobre un archivo las personas, con una edad aleatoria que va del 1 al
  100 y una localidad aleatoria del archivo de localidades */
void escribir_archivo_personas (int cantPersonas, ArregloStrings *arregloNombres,
                             ArregloStrings *arregloPaises, char *nombreSalida);

/* crear_archivo_personas: char*, char*, int, char*
 Recibe el nombre del archivo de personas, el nombre del archivo de paises, la
 cantidad de personas y el nombre del archivo de salida.
 Crea el arreglo de nombres y el arreglo de paises y ejecuta escribir_archivo_personas.*/
void crear_archivo_personas (char *archivoNombre, char *archivoPaises,
                                         int cantPersonas, char *archivoSalida);

#endif