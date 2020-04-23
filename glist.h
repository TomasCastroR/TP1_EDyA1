#ifndef __GLIST_H__
#define __GLIST_H__

typedef struct _GNodo {
  void* dato;
  struct _GNodo *sig;
}GNodo;

typedef struct {
  GNodo* primero;
  GNodo* ultimo;
}*GList;
typedef struct {
  char* nombre;
  int edad;
  char* localidad;
}Persona;

typedef void (* Destruir ) ( void * dato );

GList glist_crear();

void glist_destruir(GList lista, Destruir nombresignificativo );

void glist_agregar_final(GList *lista, void *dato);




#endif 
