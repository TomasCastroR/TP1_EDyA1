#include "glist.h"

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
