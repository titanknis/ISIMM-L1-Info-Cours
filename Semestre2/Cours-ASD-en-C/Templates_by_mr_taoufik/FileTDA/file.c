
#include "file.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
void creer_file(struct file* f) {
    f->tete   = NULL;
    f->queuee = NULL;
}
unsigned file_vide(struct file f) {
    return ((f.tete == NULL) && (f.queuee == NULL));
}
int premier(struct file f) {
    assert(!file_vide(f));
    return ((f.tete)->cle);
}
void enfiler(int info, struct file* f) {
    struct element* e;
    e          = (struct element*)malloc(sizeof(struct element));
    e->cle     = info;
    e->suivant = NULL;
    if (!file_vide(*f)) {
        f->queuee->suivant = e;
        f->queuee          = e;
    } else {
        f->tete   = e;
        f->queuee = e;
    }
}
void defiler(struct file* f) {
    struct element* q;
    assert(!file_vide(*f));
    q       = f->tete;
    f->tete = q->suivant;
    free(q);
    if (f->tete == NULL)
        f->queuee = NULL;
}
void defiler_enfiler(struct file* f1, struct file* f2) {
    enfiler(premier(*f1), f2);
    defiler(f1);
}
unsigned comparer(struct file f1, struct file f2) {
    if (premier(f1) >= premier(f2))
        return 1;
    else
        return 0;
}
unsigned comparer2(struct file f1, struct file f2) {
    if (premier(f1) >= f2.queuee->cle)
        return 1;
    else
        return 0;
}
