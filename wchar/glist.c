#include "glist.h"
#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>
#include <assert.h>

GList* glist_crear() {
  GList *lista = malloc (sizeof(GList));
  assert(lista);
  lista->primero = NULL;
  lista->ultimo = NULL;
  return lista;
}

void glist_destruir (GList *lista, Destruir funcionDestruir) {
  GNodo *nodoAEliminar, *current = lista->primero;
  while (current != NULL) {
    nodoAEliminar = current;
    current = current->sig;
    funcionDestruir (nodoAEliminar);
  }
  free(lista);
}

void glist_agregar_final (GList **lista, void *dato) {
  GNodo *nuevoNodo = malloc (sizeof(GNodo));
  assert(nuevoNodo);
  nuevoNodo->dato = dato;
  nuevoNodo->ant = (*lista)->ultimo;
  nuevoNodo->sig = NULL;
  if ((*lista)->ultimo != NULL)
    (*lista)->ultimo->sig = nuevoNodo;
  if ((*lista)->primero == NULL)
    (*lista)->primero = nuevoNodo;
  (*lista)->ultimo = nuevoNodo;
}

void copiar_lista (GList *lista) {
  GList *listaCopiada = glist_crear();
  for (GNodo *temp = lista->primero; temp != NULL; temp = temp->sig)
    glist_agregar_final (&listaCopiada, temp->dato);
}

Persona* crear_persona (wchar_t* nombre, int edad, wchar_t* localidad) {
  Persona* nuevaPersona = malloc (sizeof(Persona));
  assert(nuevaPersona);
  nuevaPersona->nombre = malloc (sizeof(wchar_t) * (wcslen (nombre) + 1));
  assert(nuevaPersona->nombre);
  wcscpy (nuevaPersona->nombre, nombre);
  nuevaPersona->nombre[wcslen (nombre)] = '\0';
  nuevaPersona->edad = edad;
  nuevaPersona->localidad = malloc (sizeof(wchar_t) * (wcslen (localidad) + 1));
  assert(nuevaPersona->localidad);
  wcscpy (nuevaPersona->localidad, localidad);
  nuevaPersona->localidad[wcslen (localidad)] = '\0';
  return nuevaPersona;
}

GList* crear_lista_personas (char* nombrearchivo, int cantidadpersonas) {
  wchar_t nombre[100], localidad[100];
  int edad;
  GList *lista = glist_crear();
  Persona* persona;
  FILE* archivoPersonas = fopen (nombrearchivo,"r");
  for(int i = 0; i < cantidadpersonas; ++i) {
    fwscanf (archivoPersonas,L"%[^,], %d, %[^\n]\n", nombre, &edad, localidad);
    persona = crear_persona (nombre, edad, localidad);
    glist_agregar_final (&lista, persona);
  }
  fclose (archivoPersonas);
  return lista;
}

void liberar_nodo (void *nodoALiberar) {
  GNodo *nodoAux = (GNodo*)nodoALiberar;
  Persona *personaAux = (Persona*)nodoAux->dato;
  free (personaAux->nombre);
  free (personaAux->localidad);
  free (nodoAux->dato);
  free (nodoALiberar);
}
