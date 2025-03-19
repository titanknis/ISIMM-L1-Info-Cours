
/* partie implementation */
/****************File.c****************/
#include "file.h"
#include <assert.h>
#include <stdlib.h>
struct element {
  int cle;
  struct element *suivant;
};
struct file {
  struct element *tete;
  struct element *queue;
};
struct file f;
void creer_file() {
  f.tete = NULL;
  f.queue = NULL;
}
unsigned file_vide() { return ((f.tete == NULL) && (f.queue == NULL)); }
int premier() {
  assert(!file_vide());
  return ((f.tete)->cle);
}
void enfiler(int info) {
  struct element *e;
  e = (struct element *)malloc(sizeof(struct element));
  e->cle = info;
  e->suivant = NULL;
  if (!file_vide()) {
    f.queue->suivant = e;
    f.queue = e;
  } else {
    f.tete = e;
    f.queue = e;
  }
}
void defiler() {
  struct element *q;
  assert(!file_vide());
  q = f.tete;
  f.tete = q->suivant;
  free(q);
  if (f.tete == NULL)
    f.queue = NULL;
}
