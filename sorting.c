#include "sorting.h"
#include "glist.h"

void glist_insertion_sort (GList *lista, Comparar compare) {
  GNodo *inicio = lista->primero;
  while (inicio->sig != NULL) {
    GNodo *aux = inicio->sig;
	  while (aux->ant != NULL && compare (aux->dato, aux->ant->dato)) {
      swap_dato (&aux->dato, &aux->ant->dato);
      aux = aux->ant;
	  }
	  inicio = inicio->sig;
  }
}

void glist_selection_sort (GList *lista, Comparar compare) {
  GNodo *inicio = lista->primero;
  GNodo *menor = inicio;
  while (inicio->sig != NULL) {
    GNodo *aux = inicio->sig;
    while (aux != NULL) {
      if (compare (aux->dato, menor->dato))
        menor = aux;
      aux = aux->sig;
    }
	  swap_dato (&menor->dato, &inicio->dato);
	  inicio = inicio->sig;
    menor = inicio;
  }
}

/*void glist_merge_sort (GList *lista, Comparar compare) {

}*/

void swap_dato (void **dato1, void **dato2) {
  void *datoAux = *dato1;
  *dato1 = *dato2;
  *dato2 = datoAux;
}