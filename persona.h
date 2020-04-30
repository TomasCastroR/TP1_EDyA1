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

typedef void (*funcionOrdenar) (GList *lista, Comparar compare);

Persona* crear_persona (char* nombre, int edad, char* localidad);

GList* crear_lista_personas (char* nombrearchivo, int cantidadpersonas);

void ordenar_escribir_lista (char* nombreSalida, GList *lista,
                                       funcionOrdenar ordena, Comparar compare);

void liberar_persona (void *nodoALiberar);

int menor_edad (void *dato1, void *dato2);

int ordena_nombre (void *dato1, void *dato2);
#endif