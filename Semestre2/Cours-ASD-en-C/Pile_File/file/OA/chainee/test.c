/****************test.c****************/
#include "file.h"
#include <stdio.h>
void main() {
  unsigned i;
  creer_file();
  for (i = 1; i <= 4; i++)
    enfiler(i);
  printf("****Contenu de la file ****\n");
  while (!file_vide()) {
    printf("%d \t ", premier());
    defiler();
  }
  if (file_vide())
    printf("\nc'est bon la file est vide..");
  else
    printf("\nprobleme");
}
