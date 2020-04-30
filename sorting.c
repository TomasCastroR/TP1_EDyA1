#include "sorting.h"
#include "glist.h"

GList* glist_insertion_sort (GList *lista, Comparar compare) {
  GNodo *inicio = lista->primero;
  while (inicio->sig != NULL) {
    GNodo *aux = inicio->sig;
	  while (aux->ant != NULL && compare (aux->dato, aux->ant->dato) > 0) {
      swap_dato (&aux->dato, &aux->ant->dato);
      aux = aux->ant;
	  }
	  inicio = inicio->sig;
  }
  return lista;
}

GList* glist_selection_sort (GList *lista, Comparar compare) {
  GNodo *inicio = lista->primero;
  GNodo *menor = inicio;
  while (inicio->sig != NULL) {
    GNodo *aux = inicio->sig;
    while (aux != NULL) {
      if (compare (aux->dato, menor->dato) > 0)
        menor = aux;
      aux = aux->sig;
    }
	  swap_dato (&menor->dato, &inicio->dato);
	  inicio = inicio->sig;
    menor = inicio;
  }
  return lista;
}

GList* merge (GList *lista1, GList *lista2, Comparar compare) {
  GList *listaMerge = glist_crear();
  GNodo *temp1 = lista1->primero, *temp2 = lista2->primero;
  while (temp1 != NULL && temp2 != NULL) {
    if (compare (temp1->dato, temp2->dato) > 0) {
      glist_agregar_final (&listaMerge, temp1->dato);
      temp1 = temp1->sig;
    }
    else {
      glist_agregar_final (&listaMerge, temp2->dato);
      temp2 = temp2->sig;
    }
  }
  while (temp1 != NULL) {
    glist_agregar_final (&listaMerge, temp1->dato);
    temp1 = temp1->sig;
  }
  while (temp2 != NULL) {
    glist_agregar_final (&listaMerge, temp2->dato);
    temp2 = temp2->sig;
  }
  glist_destruir (lista1, liberar_nodo);
  glist_destruir (lista2, liberar_nodo);

  return listaMerge;
}

GList* glist_merge_sort (GList *lista, Comparar compare) {
  if (lista->primero == lista->ultimo)
    return lista;
  GList *izquierda = glist_crear(), *derecha = glist_crear();
  GNodo *aux1 = lista->primero, *aux2 = aux1->sig;
  for (; aux2 != NULL;) {
    aux1 = aux1->sig;
    aux2 = aux2->sig;
    if (aux2 != NULL)
      aux2 = aux2->sig;
  }
  izquierda->primero = lista->primero;
  izquierda->ultimo = aux1->ant;
  izquierda->ultimo->sig = NULL;
  derecha->primero = aux1;
  derecha->primero->ant = NULL;
  derecha->ultimo = lista->ultimo;
  izquierda = glist_merge_sort (izquierda, compare);
  derecha = glist_merge_sort (derecha, compare);
  free (lista);
  return merge (izquierda, derecha, compare);;
}

void swap_dato (void **dato1, void **dato2) {
  void *datoAux = *dato1;
  *dato1 = *dato2;
  *dato2 = datoAux;
}
