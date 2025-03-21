/* partie implementation */
/****************Pile.c****************/
#include "pile.h"
#include <assert.h>
void creerpile(struct pile* p) {
    p->sommet = -1;
}
unsigned pile_vide(struct pile p) {
    return (p.sommet == -1);
}

int dernier(struct pile p) {
    assert(!pile_vide(p));
    return (p.cle[p.sommet]);
}
void empiler(int info, struct pile* p) {
    p->sommet++;
    p->cle[p->sommet] = info;
}

void depiler(struct pile* p) {
    assert(!pile_vide(*p));
    p->sommet--;
}
