#ifndef __PERSONA_H__
#define __PERSONA_H__
#include "glist.h"
#include "sorting.h"
#include <stdlib.h>
#include <stdio.h>
typedef struct {
  char* nombre;
  int edad;
  char* localidad;
}Persona;

typedef void (*funcionOrdenar) (GList *lista, Comparar compare); /// aca no tendriamos que cambiar el nombre de funcionOrdenar? (hay mas)

/* crear_persona: char*, int, char* -> persona 
  Recibe un nombre, edad y localidad.
    Retorna una estructura del tipo Persona con esos datos. */
Persona* crear_persona (char* nombre, int edad, char* localidad);

/* crear_lista_personas: char*, int -> GList
  Recibe el nombre del archivo de personas, y la cantidad de personas.
   Retorna una estructura del tipo GList con una lista de personas. */
GList* crear_lista_personas (char* nombrearchivo, int cantidadpersonas);

/* ordenar_escribir_lista: char*, GList, funcionOrdenar, Comparar
 Recibe el nombre del archivo de salida, una lista, una funcion Ordena del tipo 
funcionOrdenar y una funcion compare del tipo Comparar.
  Escribe sobre un archivo la lista ordenada en la forma pedida, calcula el tiempo
tardado y la libera cuando termina. */
void ordenar_escribir_lista (char* nombreSalida, GList *lista,
                                       funcionOrdenar ordena, Comparar compare);
/* liberar_persona: void*
  Recibe un dato del tipo void*, libera todos los elementos que contiene y el nodo. */
void liberar_persona (void *nodoALiberar);

/* menor_edad: void*, void* ->int
  Toma 2 datos del tipo void*, compara sus edades y devuelve 1 si el primero es menor,
  0 si son iguales o -1 si el segundo es menor. */
int menor_edad (void *dato1, void *dato2);/// menor_edad, bastante turbio el nombre no?

/* ordena_nombre: void*, void* ->int
  Toma 2 datos del tipo void*, compara sus nombres y devuelve 1 si el primero es menor,
  0 si son iguales o -1 si el segundo es menor.*/
int ordena_nombre (void *dato1, void *dato2);
#endif