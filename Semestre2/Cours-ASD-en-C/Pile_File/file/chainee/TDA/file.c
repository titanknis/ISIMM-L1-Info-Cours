
/* partie implementation */
/****************File.c****************/
#include "file.h"
#include <assert.h>
#include <stdlib.h>
void creer_file(struct file *f) {
  f->tete = NULL;
  f->queue = NULL;
}
unsigned file_vide(struct file f) {
  return ((f.tete == NULL) && (f.queue == NULL));
}
int premier(struct file f) {
  assert(!file_vide(f));
  return ((f.tete)->cle);
}
void enfiler(int info, struct file *f) {
  struct element *e;
  e = (struct element *)malloc(sizeof(struct element));
  e->cle = info;
  e->suivant = NULL;
  if (!file_vide(*f)) {
    f->queue->suivant = e;
    f->queue = e;
  } else {
    f->tete = e;
    f->queue = e;
  }
}
void defiler(struct file *f) {
  struct element *q;
  assert(!file_vide(*f));
  q = f->tete;
  f->tete = q->suivant;
  free(q);
  if (f->tete == NULL)
    f->queue = NULL;
}
