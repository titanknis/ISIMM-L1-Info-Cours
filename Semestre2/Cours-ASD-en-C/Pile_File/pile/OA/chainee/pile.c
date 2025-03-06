
/* partie implementation */
/****************Pile.c****************/
#include "pile.h"
#include <assert.h>
#include <stdlib.h>
struct element {
  int cle;
  struct element *suivant;
};
struct element *p;

void creer_pile() { p = NULL; }
unsigned pile_vide() { return (p == NULL); }
int dernier() {
  assert(!pile_vide());
  return p->cle;
}
void empiler(int info) {
  struct element *q;
  q = (struct element *)malloc(sizeof(struct element));
  q->cle = info;
  q->suivant = p;
  p = q;
}
void depiler() {
  struct element *q;
  assert(!pile_vide());
  q = p;
  p = p->suivant;
  free(q);
}
