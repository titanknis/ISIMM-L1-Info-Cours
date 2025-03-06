/* partie implementation */
/****************Pile.c****************/
#include "pile.h"
#include <assert.h>
#include <stdlib.h>
struct element *creer_pile() { return NULL; }
unsigned pile_vide(struct element *p) { return (p == NULL); }
int dernier(struct element *p) {
  assert(!pile_vide(p));
  return p->cle;
}
void empiler(int info, struct element **p) {
  struct element *q;
  q = (struct element *)malloc(sizeof(struct element));
  q->cle = info;
  q->suivant = *p;
  *p = q;
}
void depiler(struct element **p) {
  struct element *q;
  assert(!pile_vide(*p));
  q = *p;
  *p = (*p)->suivant;
  free(q);
}
