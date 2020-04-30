#ifndef __SORTING_H__
#define __SORTING_H__

#include "glist.h"

typedef int (*Comparar) (void *dato1, void *dato2);

void glist_insertion_sort (GList *lista, Comparar compare);

void glist_selection_sort (GList *lista, Comparar compare);

void glist_merge_sort (GList *lista, Comparar compare);

void swap_dato (void **dato1, void **dato2);

#endif