#include "generar.h"
#include "glist.h"
#include <stdlib.h>
#include <assert.h>
#include <locale.h>

int main (int argc, char *argumentos[]) {
  assert (argc == 5);
  int cantidad = atoi (argumentos[3]);
  crear_archivo_personas (argumentos[1], argumentos[2], cantidad, argumentos[4]);
  GList *lista = crear_lista_personas (argumentos[4], cantidad);
  glist_destruir (lista, liberar_nodo);
  /*Persona *persona;
  for(GNodo *temporal = lista->primero; temporal != NULL; temporal = temporal->sig ) {
    persona = (Persona*)temporal->dato;
    printf("%s, %d, %s\n" , persona->nombre, persona->edad, persona->localidad);
  }*/
  return 0;
}
