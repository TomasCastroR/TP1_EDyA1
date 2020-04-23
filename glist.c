#include "glist.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

GList glist_crear(){
  GList lista = malloc(sizeof(GList));
  lista->primero = NULL;
  lista->ultimo = NULL;
  return lista;
}

void glist_destruir(GList lista, Destruir nombresignificativo ){
  GNodo *nodoAEliminar, *otroNodo = lista->primero;
  while (otroNodo != NULL) {
    nodoAEliminar = otroNodo;
    otroNodo = otroNodo->sig;
    nombresignificativo(nodoAEliminar->dato);
    free(nodoAEliminar);
  }
  free(lista);
}

void glist_agregar_final(GList *lista, void *dato){
  GNodo *nuevoNodo = malloc(sizeof(GNodo));
  nuevoNodo->dato = dato;
  nuevoNodo->sig = NULL;
  if ((*lista)->ultimo != NULL)
    (*lista)->ultimo->sig = nuevoNodo;
  (*lista)->ultimo = nuevoNodo;
  if((*lista)->primero == NULL)
    (*lista)->primero = nuevoNodo;
 }

Persona* crear_persona (char* nombre, int edad, char* localidad){
  Persona* nuevapersona = malloc(sizeof(Persona));
  nuevapersona->nombre = malloc(sizeof(char)*strlen(nombre)+1);
  strcpy(nuevapersona->nombre, nombre);
  nuevapersona->nombre[strlen(nombre)] = '\0';
  nuevapersona->edad = edad;
  nuevapersona->localidad = malloc(sizeof(char)*strlen(localidad) + 1);
  strcpy(nuevapersona->localidad, localidad);
  nuevapersona->localidad[strlen(localidad)] = '\0';
  return nuevapersona;
}

GList extraer_personas (char* nombrearchivo, int cantidadpersonas){
  char nombre[100], localidad[100];
  int edad;
  FILE* archivopersonas;
  GList lista = glist_crear();
  Persona* persona;
  archivopersonas = fopen(nombrearchivo,"r");
  for(int i=0; i<cantidadpersonas; ++i){
    fscanf(archivopersonas,"%[^,], %d, %[^\n]\n", nombre, &edad, localidad);
    persona = crear_persona(nombre, edad, localidad);
    glist_agregar_final(&lista, persona);
  }
  return lista;
}