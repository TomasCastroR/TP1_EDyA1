#include "generar.h"
#include "glist.h"
#include <stdlib.h>

int main (int argc, char *argumentos[]) {
  int lineas = 0, cantidad = atoi(argumentos[3]);
  FILE *fEntrada;
  fEntrada = fopen(argumentos[1], "r");
  lineas = cantidad_de_lineas (fEntrada);
  fclose(fEntrada);
  while ((cantidad > lineas)||(cantidad<0)){
    printf("Por favor ingrese una cantidad menor a %d y mayor a 0: ", lineas);
    scanf("%d",&cantidad);
  }
  int *arrayRandom= malloc (sizeof(int) * cantidad);
  arreglo_num_random (arrayRandom, cantidad, lineas);
  lectura_escritura (cantidad, arrayRandom, argumentos[1], argumentos[2], argumentos[4]);
  return 0;
}