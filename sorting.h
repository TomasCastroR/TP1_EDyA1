#ifndef __SORTING_H__
#define __SORTING_H__

#include "glist.h"

typedef int (*Comparar) (void *dato1, void *dato2);


GList* glist_insertion_sort (GList *lista, Comparar compare);

GList* glist_selection_sort (GList *lista, Comparar compare);

GList* glist_merge_sort (GList *lista, Comparar compare);

GList* merge (GList *lista1, GList *lista2, Comparar compare);

void swap_dato (void **dato1, void **dato2);

#endif