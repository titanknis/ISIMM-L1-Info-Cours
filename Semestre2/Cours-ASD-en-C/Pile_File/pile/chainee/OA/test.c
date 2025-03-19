
#include "pile.h"
#include <stdio.h>
void main() {
  int i, x, n;
  printf("Chargement de P\n");
  printf("entrer nombre d'elements : ");
  scanf("%d", &n);
  creer_pile();
  for (i = 1; i <= n; i++) {
    printf("donner un entier :");
    scanf("%d", &x);
    empiler(x);
  }
  printf("\n ****le contenu de la pile P**** \n");
  while (!pile_vide()) {
    printf("%d\t ", dernier());
    depiler();
  }
}
