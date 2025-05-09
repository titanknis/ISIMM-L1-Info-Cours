
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Liste.h"

void creer_liste(struct liste *ll) {
    ll->premier = NULL;
    ll->dernier = NULL;
}

unsigned liste_vide (struct liste*ll) {
	return((ll->premier==NULL)&&(ll->dernier==NULL));
}
void inserer_apres (int info, struct noeud *p) {
	struct noeud *q;
	q=(struct noeud *) malloc (sizeof (struct noeud));
	q->cle=info;
	q->suivant=p->suivant;

	/*mise à jour du successeur de p*/
	p->suivant=q;
}

void inserer_avant (int info, struct noeud *p) {
     /*le problème: la liste est unidirectionnelle à partir de p,
         on ne peut pas passer à son prédécesseur */

        struct noeud * q;
        q=(struct  noeud*) malloc (sizeof (struct noeud ));
        *q=*p;           /*   q->cle=p->cle; q->suivant=p->suivant ; */
   /*mise à jour l’espace référencé par p*/

        p->cle=info;
        p->suivant=q;
}

void  inserer_avant_premier (int info, struct liste *ll) {
        struct noeud * q;
        q=(struct noeud*) malloc (sizeof(struct noeud));
        if (liste_vide (ll)) {
              q->cle=info;
              q->suivant=NULL ;
              ll->premier=q ;
              ll->dernier=q ;
       }
       else {
             q->cle = info;
             q->suivant = ll->premier ;
             ll->premier = q ;
      }
}
void inserer_apres_dernier(int info, struct liste *ll) {
    struct noeud *nouveauNoeud = malloc(sizeof(struct noeud));
    nouveauNoeud->cle = info;
    nouveauNoeud->suivant = NULL;

    if (ll->dernier == NULL) {
        ll->premier = nouveauNoeud;
        ll->dernier = nouveauNoeud;
    } else {
        ll->dernier->suivant = nouveauNoeud;
        ll->dernier = nouveauNoeud;
    }
}
void supprimer_elem (struct noeud * p ) {
     struct noeud* q ;
    /* on suppose que p admet un successeur*/
    assert(p->suivant) ;
     q=p->suivant ;
     *p=*q ;
     free (q) ;
}

/* sol 1
void supprimer_premier(struct liste *ll) {

    struct noeud* q = ll->premier;
    ll->premier = q->suivant;

    if (q == ll->dernier) {
        ll->dernier = NULL;
    }
    free(q);
}
*/
void supprimer_premier (struct liste * ll){
      struct noeud * q ;
      assert (!liste_vide (ll))  ;
      q=ll->premier ;
      ll->premier = q->suivant;
     free (q) ;
      if (ll->premier== NULL)
          ll->dernier= NULL ;

}

void supprimer_dernier(struct liste *ll) {
    struct noeud* q;
    if (ll->premier == ll->dernier) {
        supprimer_premier(ll);
    }
    else{
        q = ll->premier;
            while (q->suivant != ll->dernier)
                q = q->suivant;

    q->suivant = NULL;
    free(ll->dernier);
    ll->dernier = q;
    }
}


struct noeud * chercher (int info, struct noeud* p) {
          while(p && (p->cle !=info))  /* l’ordre des deux sous expressions est significatif*/
		p=p->suivant;
         /*à la sortie de la boucle!p || p->clé==info
                        échec:!p ==> (p== NULL)  ==> return p
	         succès:p->clé==info    ==> return p  */
          return (p);
}

void parcours (struct noeud* p, void (*oper) (struct noeud*) ) {
       while (p) {
           /*  appliquer à l’élément porté par p le traitement fourni par oper    */
           (*oper) (p);
           /*  passer à l’élément suivant */
           p=p->suivant;
      }
}

void afficher (struct noeud * q) {
     printf("%d \t", q->cle);       /* afficher l'élément visité */

}
void incrementer (struct noeud *q)    {
     q->cle++;                             /* incrémenter l'élément visité  */

}

struct liste * concatenerListes0 (struct liste *L1, struct liste *L2) {
    struct liste *nouvelleListe=(struct liste *) malloc(sizeof(struct liste));

    if (liste_vide(L1)) {
        nouvelleListe->premier = L2->premier;
        nouvelleListe->dernier = L2->dernier;
    } else {
        nouvelleListe->premier = L1->premier;
        nouvelleListe->dernier  = L2->dernier;
        L1->dernier->suivant = L2->premier;
    }

    return nouvelleListe;
}

struct liste * concatenerListes1(struct liste *liste1, struct liste *liste2) {
    struct liste *nouvelleListe =(struct liste *) malloc(sizeof(struct liste));   ///obligatoire !!!
    creer_liste(nouvelleListe);
    while(! liste_vide(liste1)){
        inserer_apres_dernier(liste1->premier->cle, nouvelleListe);
        supprimer_premier(liste1);
    }
    while(! liste_vide(liste2)){
        inserer_apres_dernier(liste2->premier->cle, nouvelleListe);
        supprimer_premier(liste2);
    }


    return nouvelleListe;
}
struct liste * concatenerListes2(struct liste *L1, struct liste *L2) {
    struct noeud *P1, *P2;
    struct liste * L= (struct liste *) malloc(sizeof(struct liste));   ///obligatoire !!!
    creer_liste(L) ;
    P1= L1-> premier;
    while (P1){
        inserer_apres_dernier(P1->cle, L);
        P1=P1-> suivant;
    }
    P2= L2-> premier;
    while (P2){
        inserer_apres_dernier(P2->cle, L) ;
        P2=P2-> suivant;
    }
    return L ;
}


void Separer0 (struct liste *L , struct liste * L1, struct liste * L2) {///OK  c'est operationnelle
    struct noeud* P ;
    P = L->premier;
    int  B = 1;
    creer_liste (L1); ///obligatoire
    creer_liste (L2);///obligatoire
    while (P) {
        if (B>0)
            inserer_apres_dernier(P->cle, L1);
         else
            inserer_apres_dernier(P->cle, L2);
        B *= -1;
        P = P->suivant;
    }
}

void Separer (struct liste *L , struct liste * L1, struct liste * L2) {

    int  B = 1;
    creer_liste (L1); ///obligatoire
    creer_liste (L2);///obligatoire
    while (!liste_vide(L)) {
        if (B>0)
            inserer_apres_dernier(L->premier->cle, L1);
        else
            inserer_apres_dernier(L->premier->cle, L2);
        supprimer_premier(L);
        B *= -1;
    }
}


struct liste * Fusion22 (struct liste * L1, struct liste * L2) {/// OK operationnelle
    struct liste * L = (struct liste *) malloc(sizeof(struct liste)); ///not obligatoire !!!
    struct noeud *P1 , *P2;
    P1= L1->premier;
    P2= L2->premier;
    creer_liste(L);/// obligatoire
    while (P1 && P2 ) {
        if (P1->cle < P2->cle) {
            inserer_apres_dernier(P1->cle, L);
            P1 = P1->suivant;
            supprimer_premier(L1);
        } else {
            inserer_apres_dernier (P2->cle, L);
            P2 = P2->suivant;
            supprimer_premier(L2);
        }
    }
    while (P1 ) {
        inserer_apres_dernier (P1->cle, L);
        P1 = P1->suivant;
    }
    while (P2) {
        inserer_apres_dernier (P2->cle, L);
        P2 = P2->suivant;
    }
    return L;
}

struct liste *Fusion (struct liste * L1, struct liste * L2) {
    struct liste *L =(struct liste *) malloc(sizeof(struct liste)); ///obligatoire
    creer_liste(L);

    while (!liste_vide(L1) && !liste_vide(L2) ) {

        if (L1->premier->cle < L2->premier->cle) {
            inserer_apres_dernier(L1->premier->cle, L);
            supprimer_premier(L1);
        } else {
            inserer_apres_dernier(L2->premier->cle, L);
            supprimer_premier(L2);
        }
    }

    return (liste_vide(L1)? concatenerListes0(L, L2) : concatenerListes0(L, L1));
}


struct liste* TriFusion(struct liste * Le) {
    struct liste *L1=malloc(sizeof(struct liste));
    struct liste *L2=malloc(sizeof(struct liste));
    struct liste *L1b;//=malloc(sizeof(struct liste));zeyed deja implementer dans TriFusion
    struct liste *L2b;//=malloc(sizeof(struct liste)); zeyed deja implementer dans TriFusion
    assert(!liste_vide(Le));
    if(Le->premier->suivant)  { // contient plus qu'un élément
        Separer(Le, L1, L2);
        L1b= TriFusion(L1);
        L2b= TriFusion(L2);
        return Fusion22(L1b, L2b);
    }
    else {
        creer_liste(L1);
        inserer_avant_premier(Le->premier->cle, L1);
        return L1;
    }

}




