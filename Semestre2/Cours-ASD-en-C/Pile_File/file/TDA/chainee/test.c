/****************test.c****************/
#include "file.h"
#include <stdio.h>
void main() {
  unsigned i;
  struct file f1, f2;
  creer_file(&f1);
  creer_file(&f2);
  for (i = 1; i <= 4; i++)
    enfiler(i, &f1);
  for (i = 10; i <= 50; i += 10)
    enfiler(i, &f2);
  printf("****Contenu de la file F1****\n");
  while (!file_vide(f1)) {
    printf("%d \t ", premier(f1));
    defiler(&f1);
  }
  printf("\n****Contenu de la file F2****\n");
  while (!file_vide(f2)) {
    printf("%d \t ", premier(f2));
    defiler(&f2);
  }
  if (file_vide(f1) && file_vide(f2))
    printf("\nc'est bon les deux files sont vides..");
  else
    printf("\nprobleme");
}
