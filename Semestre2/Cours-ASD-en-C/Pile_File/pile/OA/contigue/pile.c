/************Partie Implementation***********/
/****************Pile.c****************/
#include "pile.h"
#include <assert.h>
/* representation physique */
#define n 100
struct pile {
  int cle[n];
  int sommet;
};
struct pile p;
void creerpile(void) { p.sommet = -1; }
unsigned pile_vide(void) { return (p.sommet == -1); }
void empiler(int info) {
  p.sommet++;
  p.cle[p.sommet] = info;
}
void depiler(void) {
  assert(!pile_vide());
  p.sommet--;
}
int dernier(void) {
  assert(!pile_vide());
  return (p.cle[p.sommet]);
}
