#ifndef __GLIST_H__
#define __GLIST_H__

#include <stdio.h>

typedef struct _GNodo {
  void* dato;
  struct _GNodo *sig;
  struct _GNodo *ant;
}GNodo;

typedef struct {
  GNodo* primero;
  GNodo* ultimo;
}GList;

typedef void (*Destruir) (void *dato);
/*glist_crear:->  Glist*
  Crea y retorna una lista vacia.*/
GList* glist_crear ();

/* glist_destruir: Glist*, Destruir
  Recibe una lista y una funcion destruir.
  Libera la lista y los espacios dentro de la misma.*/
void glist_destruir (GList *lista, Destruir funcionDestruir);

/* glist_agregar_final: GList**, void*
  Recibe una lista y un dato del tipo void*.
  Agrega este dato al final de esta lista como ultimo elemento. */
void glist_agregar_final (GList **lista, void *dato);

/*glist_copiar: GList* -> GList*
  Recibe una lista y la copia elemento por elemento. */
GList* glist_copiar (GList *lista);

/*liberar_nodo: void*
  Recibe un un dato del tipo void* y lo libera. */
void liberar_nodo (void *nodo);

#endif
