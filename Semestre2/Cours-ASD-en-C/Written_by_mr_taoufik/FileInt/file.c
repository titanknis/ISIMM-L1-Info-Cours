#include "file.h"
#include <assert.h>
#include <stdlib.h>

void creeFile(struct file* f) {

    f->tete  = NULL;
    f->queue = NULL;
}

int file_vide(struct file f) {

    return ((f.queue) == NULL);
}

void enfiler(int x, struct file* f) {

    struct Cellule* p;

    p          = (struct Cellule*)malloc(sizeof(struct Cellule));
    p->cle     = x;
    p->suivant = NULL;
    if (file_vide(*f)) {

        f->tete  = p;
        f->queue = p;

    } else {
        (f->queue)->suivant = p;
        f->queue            = p;
    }
}

void defiler(struct file* f) {

    struct Cellule* q;
    assert(!file_vide(*f));

    q       = (f->tete);
    f->tete = (f->tete)->suivant;

    free(q);
    if (f->tete == NULL)
        f->queue = NULL;
}

int premier(struct file f) {

    assert(!file_vide(f));

    return (f.tete)->cle;
}
