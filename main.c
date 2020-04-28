#include "generar.h"
#include "glist.h"
#include "sorting.h"
#include <stdlib.h>
#include <assert.h>
#include <locale.h>
#include <ctype.h>

int comparar_edad (void *dato1, void *dato2) {
  Persona *persona1 = (Persona*)dato1;
  Persona *persona2 = (Persona*)dato2;
  return persona1->edad < persona2->edad;
}


int main (int argc, char *argumentos[]) {
  assert (argc == 5);
  setlocale(LC_CTYPE, "spanish");

  int cantidad = atoi (argumentos[3]);
  crear_archivo_personas (cantidad, argumentos[1], argumentos[2], argumentos[4]);
  Persona *persona;
  GList *lista = crear_lista_personas (argumentos[4], cantidad);
  glist_selection_sort (lista, &comparar_edad);
  for(GNodo *temporal = lista->primero; temporal != NULL; temporal = temporal->sig ) {
    persona = (Persona*)temporal->dato;
    wprintf(L"%ls, %d, %ls\n" , persona->nombre, persona->edad, persona->localidad);
  }
  glist_destruir (lista, liberar_nodo);
  return 0;
}
