#include "glist.h"
#include <stdlib.h>
#include <string.h>
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

void glist_agregar_nodo (GList **lista, GNodo *nodo) {
  if ((*lista)->primero == NULL)
    (*lista)->primero = nodo;
  if ((*lista)->ultimo != NULL)
    (*lista)->ultimo->sig = nodo;
  (*lista)->ultimo = nodo;
}

void glist_split (GList *lista, GList **izquierda, GList **derecha) {
  GNodo *medio = lista->primero, *aux = medio->sig;
  while (aux != NULL) {
    medio = medio->sig;
    aux = aux->sig;
    if (aux != NULL)
      aux = aux->sig;
  }
  (*izquierda)->primero = lista->primero;
  (*izquierda)->ultimo = medio->ant;
  (*izquierda)->ultimo->sig = NULL;
  (*derecha)->primero = medio;
  (*derecha)->primero->ant = NULL;
  (*derecha)->ultimo = lista->ultimo;
}

GList* glist_copiar (GList *lista) {
  GList *listaCopiada = glist_crear();
  for (GNodo *temp = lista->primero; temp != NULL; temp = temp->sig)
    glist_agregar_final (&listaCopiada, temp->dato);
  return listaCopiada;
}

void liberar_nodo (void *nodo) {
  GNodo *auxNodo = nodo;
  free (auxNodo);
}
