#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Liste.h"


void creer_liste(struct liste *ll) {
    ll->premier = NULL;
    ll->dernier = NULL;
}

unsigned liste_vide(struct liste *ll) {
    return (ll->premier == NULL && ll->dernier == NULL);
}

void inserer_apres(int cle, struct cellule *p) {
    struct cellule *q = (struct cellule *)malloc(sizeof(struct cellule));
    q->cle = cle;
    q->suivant = p->suivant;
    p->suivant = q;
}

void inserer_avant(int cle, struct cellule *p) {
    struct cellule *q = (struct cellule *)malloc(sizeof(struct cellule));
    *q = *p;
    p->cle = cle;
    p->suivant = q;
}

void inserer_avant_premier(int cle, struct liste *ll) {
    struct cellule *q = (struct cellule *)malloc(sizeof(struct cellule));
    q->cle = cle;
    q->suivant = ll->premier;

    ll->premier = q;
    if (ll->dernier == NULL) {
        ll->dernier = q;
    }
}

void inserer_apres_dernier(int cle, struct liste *ll) {
    struct cellule *q = (struct cellule *)malloc(sizeof(struct cellule));
    q->cle = cle;
    q->suivant = NULL;

    if (liste_vide(ll)) {
        ll->premier = q;
        ll->dernier = q;
    } else {
        ll->dernier->suivant = q;
        ll->dernier = q;
    }
}

void supprimer_elem(struct cellule *p) {
    assert(p->suivant != NULL);
    struct cellule *q = p->suivant;
    *p = *q;
    free(q);
}

void supprimer_premier(struct liste *ll) {
    assert(!liste_vide(ll));
    struct cellule *q = ll->premier;
    ll->premier = q->suivant;
    free(q);

    if (ll->premier == NULL)
        ll->dernier = NULL;
}

void supprimer_dernier(struct liste *ll) {
    assert(!liste_vide(ll));
    if (ll->premier == ll->dernier) {
        supprimer_premier(ll);
    } else {
        struct cellule *q = ll->premier;
        while (q->suivant != ll->dernier)
            q = q->suivant;

        free(ll->dernier);
        q->suivant = NULL;
        ll->dernier = q;
    }
}

struct cellule *chercher(int cle, struct cellule *p) {
    while (p && p->cle != cle)
        p = p->suivant;
    return p;
}


void parcours(struct cellule *p, void (*oper)(struct cellule *)) {
    while (p) {
        (*oper)(p);
        p = p->suivant;
    }
}

void afficher_cellule(struct cellule *p) {
    if(p->suivant)
        printf("%d -> ", p->cle);
    else
        printf("%d ", p->cle);
}
