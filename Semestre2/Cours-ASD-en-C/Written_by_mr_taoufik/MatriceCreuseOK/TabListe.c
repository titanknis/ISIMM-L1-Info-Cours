#include <stdio.h>
#include <assert.h>
#include "TabListe.h"
//#include "Liste.h"    NOOOO double importation d'un meme fichier

#define N 7

static struct liste TabListe[N];

void creerMatCreuse() {
    for (int i = 0; i < N; i++) {
        creer_liste(&TabListe[i]);
    }
}

struct cellule* ElementAT(unsigned ligne, unsigned col) {
    return chercher2(col, TabListe[ligne].premier);
}

void ModifElem(int info, unsigned ligne, unsigned col) {
    assert(ligne < N);

    struct cellule *p = TabListe[ligne].premier;
    struct cellule *prec = NULL;

    while (p && p->col != col) {
        prec = p;
        p = p->suivant;
    }

    if (p) {
        if (info != 0) {
            p->cle = info;
        } else {
            if (prec == NULL) {
                supprimer_premier(&TabListe[ligne]);
            } else if (p->suivant == NULL) {
                supprimer_dernier(&TabListe[ligne]);
            } else {
                supprimer_elem(prec);
            }
        }
    } else {
        if (info != 0)
            inserer_apres_dernier(info, col, &TabListe[ligne]);
    }
}

void afficherMatCreuse() {
    for (int i = 0; i < N; i++) {
        printf("Ligne %d : ", i);
        parcours(TabListe[i].premier, afficher_cellule);
        printf("\n");
    }
}
