
/*****partie test *******/
#include "pile.h"
#include <stdio.h>
void main() {
  struct element *p1, *p2;
  int i, x, n;
  printf("Chargement de P1\n");
  printf("entrer nombre d'elements : ");
  scanf("%d", &n);
  p1 = creer_pile();
  for (i = 1; i <= n; i++) {
    printf("donner un entier :");
    scanf("%d", &x);
    empiler(x, &p1);
  }
  printf("Chargement de P2\n");
  printf("entrer nombre d'elements : ");
  scanf("%d", &n);
  p2 = creer_pile();
  for (i = 1; i <= n; i++) {
    printf("donner un entier :");
    scanf("%d", &x);
    empiler(x, &p2);
  }
  printf("\n ****le contenu de la pile P1**** \n");
  while (!pile_vide(p1)) {
    printf("%d\t ", dernier(p1));
    depiler(&p1);
  }
  printf("\n ****le contenu de la pile P2**** \n");
  while (!pile_vide(p2)) {
    printf("%d\t ", dernier(p2));
    depiler(&p2);
  }
}
