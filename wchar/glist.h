#ifndef __GLIST_H__
#define __GLIST_H__
#include <wchar.h>
typedef struct _GNodo {
  void* dato;
  struct _GNodo *sig;
  struct _GNodo *ant;
}GNodo;

typedef struct {
  GNodo* primero;
  GNodo* ultimo;
}GList;

typedef struct {
  wchar_t* nombre;
  int edad;
  wchar_t* localidad;
}Persona;

typedef void (*Destruir) (void *dato);

GList* glist_crear();

void glist_destruir(GList *lista, Destruir funcionDestruir);

void glist_agregar_final(GList **lista, void *dato);

void copiar_lista (GList *lista);

Persona* crear_persona (wchar_t* nombre, int edad, wchar_t* localidad);

GList* crear_lista_personas (char* nombrearchivo, int cantidadpersonas);

void liberar_nodo (void *nodoALiberar);


#endif
