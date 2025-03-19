/****************Partie Test****************/
#include "pile.h"
#include <assert.h>
#include <stdio.h>
void main() {
  unsigned i, x, m;
  struct pile p1;
  struct pile p2;
  creerpile(&p1);

  printf("entrer nombre d'elements : ");
  scanf("%d", &m);
  printf("Chargement de P1\n");
  for (i = 1; i <= m; i++) {
    printf("donner un entier :");
    scanf("%d", &x);
    empiler(x, &p1);
  }

  printf("Chargement de P2\n");
  creerpile(&p2);
  for (i = 1; i <= m; i++) {
    printf("donner un entier :");
    scanf("%d", &x);
    empiler(x, &p2);
  }
  printf("zzz= %d \n", pile_vide(p1));
  printf("Contenu de P1\n");
  while (!pile_vide(p1)) {
    printf("%d\t", dernier(p1));
    depiler(&p1);
  }
  printf("zzz= %d \n", pile_vide(p1));
  printf("\nContenu de P2\n");
  while (!pile_vide(p2)) {
    printf("%d\t", dernier(p2));
    depiler(&p2);
  }
}
