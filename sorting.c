#include "sorting.h"
#include "glist.h"

void glist_insertion_sort (GList *lista, Comparar compare) {
  GNodo *inicio = lista->primero;
  while (inicio != NULL) {
    GNodo *aux = inicio->sig;
	  while (aux->ant != NULL && compare(aux->ant, aux) > 0) {
      aux = aux->ant;
	  }
  if (aux->ant)
	  aux = aux->sig;
  swap_dato (aux, inicio->sig);
	inicio = inicio->sig;
  }
}

void glist_selection_sort (GList *lista, Comparar compare) {
  GNodo *inicio = lista->primero;
  GNodo *aux = inicio->sig;
  GNodo *menor = inicio;
  while (inicio->sig != NULL) {
    while (aux != NULL) {
      if (compare (menor->dato, aux->dato) > 0)
        menor = aux;
    }
	swap_dato (&menor->dato, &inicio->dato);
	inicio = inicio->sig;
  menor = inicio;
  }
}

void glist_merge_sort (GList *lista, Comparar compare) {

}

void swap_dato (void **dato1, void **dato2) {
  void *datoAux = *dato1;
  *dato1 = *dato2;
  *dato2 = datoAux;
}