#include "liste.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
/*****Liste unidirectionnelle*/
struct cellule {
    int             cle;
    struct cellule* suivant;
};
struct liste {
    struct cellule* premier;
    struct cellule* dernier;
};
static struct liste L;
/******Fonction creer_liste*******/
void creer_liste() {
    L.premier = NULL;
    L.dernier = NULL;
}
/******Fonction liste_vide*******/
int liste_vide() {
    return L.premier == NULL;
}
/******Fonction inserer_avant_premier******/
void inserer_avant_premier(int x) {
    struct cellule* p;
    p          = (struct cellule*)malloc(sizeof(struct cellule));
    p->cle     = x;
    p->suivant = L.premier;
    if (L.premier == NULL)
        L.dernier = p;
    L.premier = p;
}
/**Fonction Remplir 1 en utilisant inserer_avant_premier**/
void remplir1() {
    int      x;
    unsigned rep, i = 1;
    do {
        printf("Donner un entier %d de la liste: ", i);
        scanf("%d", &x);
        inserer_avant_premier(x);
        do {
            printf("Voulez vous inserer un autre entier ds la liste(1:oui,0:non): ");
            scanf("%u", &rep);
        } while (!(rep == 1 || rep == 0));
        i++;
    } while (rep);
}
/******Fonction inserer_apres_dernier******/
void inserer_apres_dernier(int x) {
    struct cellule* p;
    p          = (struct cellule*)malloc(sizeof(struct cellule));
    p->cle     = x;
    p->suivant = NULL;
    if (L.dernier == NULL)
        L.premier = p;
    else
        (L.dernier)->suivant = p;
    L.dernier = p;
}
/**Fonction Remplir 1 en utilisant inserer_aprés_dernier**/
void remplir2() {
    int      x;
    unsigned rep, i = 1;
    do {
        printf("Donner un entier %d de la liste: ", i);
        scanf("%d", &x);
        inserer_apres_dernier(x);
        do {
            printf("Voulez vous inserer un autre entier ds la liste(1:oui,0:non): ");
            scanf("%u", &rep);
        } while (!(rep == 1 || rep == 0));
        i++;
    } while (rep);
}
/****Fonction TAILLE***/
unsigned taille() {
    struct cellule* p;
    unsigned        t = 0;
    if (liste_vide())
        return (0);
    else {
        p = L.premier;
        while (p != NULL) {
            p = p->suivant;
            t++;
        }
        return (t);
    }
}
/**** Fonction recherche_référence****/
struct cellule* recherche_reference(int x) {
    struct cellule* p = L.premier;
    while (p && p->cle != x)
        p = p->suivant;
    return p;
}
/***Fonction affiche***/
void affiche() {
    struct cellule* q = L.premier;
    assert(!(liste_vide()));
    while (q != NULL) {
        printf("%d\t", q->cle);
        q = q->suivant;
    }
    printf("\n");
}
/****Fonction insertion après élément référencée(la référence est différente du premier et
 * dernier)*****/
void inserer_apres_reference(struct cellule* p, int x) {
    struct cellule* q;
    q          = (struct cellule*)malloc(sizeof(struct cellule));
    q->cle     = x;
    q->suivant = p->suivant;
    p->suivant = q;
}
/****Fonction insertion avant élément référencée(la référence est différente du premier et
 * dernier)*****/
void inserer_avant_reference(struct cellule* p, int x) {
    struct cellule* q;
    q          = (struct cellule*)malloc(sizeof(struct cellule));
    *q         = *p;
    p->cle     = x;
    p->suivant = q;
}
/*****Fonction suppression du premier élément****/
void supprimer_premier() {
    struct cellule* p;
    assert(!(liste_vide()));
    p         = L.premier;
    L.premier = p->suivant;
    free(p);
    /* exception une liste formée d’un seul élément */
    if (L.premier == NULL)
        L.dernier = NULL;
}
/*****Fonction suppression du dernier élément****/
void supprimer_dernier() {
    struct cellule* p; /*pour parcourir ll */
    assert(!(liste_vide()));
    if (L.premier == L.dernier) /* liste formé d’un seul élément*/
        supprimer_premier();
    else {
        p = L.premier;
        while (p->suivant != L.dernier)
            p = p->suivant;
        p->suivant = NULL; /* mise à jour */
        free(L.dernier);   /* libérer le dernier */
        L.dernier = p;     /* mise à jour */
    }
}
/*****Fonction suppression d’un élément référencée(la référence est différente du premier et
 * dernier)******/
void supprimer_element_reference(struct cellule* p) {
    struct cellule* q;
    assert(!(liste_vide()));
    q  = p->suivant;
    *p = *q;
    free(q);
}
/*****Fonction supprimer_apres_reference(la référence est différente du premier et dernier)******/
void supprimer_apres_reference(struct cellule* p) {
    struct cellule* q;
    assert(!(liste_vide()));
    q          = p->suivant;
    p->suivant = q->suivant;
    free(q);
}
void supprimer_avant_reference(struct cellule* p) {
    struct cellule* q = L.premier;
    while (q->suivant != p)
        q = q->suivant;
    supprimer_element_reference(q);
    if (q->suivant == NULL)
        L.dernier = q;
}
