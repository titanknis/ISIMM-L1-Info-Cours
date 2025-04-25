#include <stdlib.h>
#include <assert.h>
#include "ListeDoublement.h"

void creer_liste (struct liste* ll) {
    ll->premier = NULL;
    ll->dernier = NULL;
}

unsigned liste_vide(struct liste* ll) {
    return ((ll->premier == NULL) && (ll->dernier == NULL));
}

void inserer_apres(int info, struct noeud* p) {
    struct noeud* q;
    q = (struct noeud*) malloc(sizeof(struct noeud));
    q->cle = info;
    q->succ = p->succ;
    q->pred = p;
    p->succ->pred = q;
    p->succ = q;
}

void inserer_avant(int info, struct noeud* p) {
    struct noeud* q;
    q = (struct noeud*) malloc(sizeof(struct noeud));
    q->cle = info;
    q->pred = p->pred;
    q->succ = p;
    p->pred->succ = q;
    p->pred = q;
}

void inserer_avant_premier(int info, struct liste* ll) {
    struct noeud* q;
    q = (struct noeud*) malloc(sizeof(struct noeud));
    if (liste_vide(ll)) {
        q->cle = info;
        q->succ = NULL;
        q->pred = NULL;
        ll->premier = q;
        ll->dernier = q;
    }
    else {
        q->cle = info;
        q->succ = ll->premier;
        q->pred = NULL;
        ll->premier->pred = q;
        ll->premier = q;
    }
}

void inserer_apres_dernier(int info, struct liste* ll) {
    struct noeud* q = malloc(sizeof(struct noeud));
    if (liste_vide(ll)) {
        q->cle = info;
        q->succ = NULL;
        q->pred = NULL;
        ll->premier = q;
        ll->dernier = q;
    }
    else {
        q->cle = info;
        q->succ = NULL;
        q->pred = ll->dernier;
        ll->dernier->succ = q;
        ll->dernier = q;
    }
}

void supprimer_elem(struct noeud* p) {
    struct noeud* q1, * q2;
    /* on suppose que p admet un successeur et un predeseseur*/
    assert((p->succ) && (p->pred));
    q1 = p->succ;
    q2 = p->pred;
    *p = *q1;
    p->pred = q2;
    if(p->succ)
        p->suuc->pred=p;
    free(q1);
}

void supprimer_premier (struct liste * ll){
      struct noeud* q ;
      assert (!liste_vide (ll))  ;
      q=ll->premier ;
      ll->premier = q->succ;

      free (q) ;
      if (ll->premier== NULL)
          ll->dernier= NULL ;
      else
        ll->premier->pred= NULL;

}

void supprimer_dernier(struct liste *ll) {
    struct noeud* q;
    if (ll->premier == ll->dernier) {
        supprimer_premier(ll);
    }
    else{
        q = ll->dernier;
        ll->dernier = q->pred;
        ll->dernier ->succ =NULL;
        free(q);

    }
}

struct noeud* chercher (int info, struct noeud* p) {
    while(p && (p->cle !=info))
		p=p->succ;

    return (p);
}

void parcours (struct noeud* p, void (*oper) (struct noeud*) ) {
       while (p) {
           (*oper) (p);
            p=p->succ;
      }
}

void afficher (struct noeud* q) {
     printf("%d \t", q->cle);

}
