#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "mySinglyList.h"

struct cellule
{
    int             cle;
    struct cellule *suivant;
};

struct liste
{
    struct cellule *premier;
    struct cellule *dernier;
};

void creer_liste(struct liste *l)
{
    l->premier = l->dernier = NULL;
}
unsigned liste_vide(struct liste l)
{
    return l.premier == NULL && l.dernier == NULL;
}

void inserer_avant_premier(struct liste *l, int x)
{
    struct cellule *p = (struct cellule *)malloc(sizeof(struct cellule));
    p->cle            = x;
    p->suivant        = l->premier;
    if (l->premier == NULL)
        l->dernier = p;
    l->premier = p;
}

void inserer_apres_dernier(struct liste *l, int x)
{
    struct cellule *p = (struct cellule *)malloc(sizeof(struct cellule));
    p->cle            = x;
    p->suivant        = NULL;
    if (l->dernier == NULL)
        l->premier = p;
    else
        l->dernier->suivant = p;
    l->dernier = p;
}

int taille(struct liste l)
{
    struct cellule *p = l.premier;
    int             i = 0;
    while (p)
    {
        i++;
        p = p->suivant;
    }
    return i;
}

struct cellule *rechereche_reference(struct liste l, int x)
{
    struct cellule *p = l.premier;
    while (p && p->cle != x)
    {
        p = p->suivant;
    }
    return p;
}

void affiche(struct liste l)
{
    struct cellule *p = l.premier;
    while (p)
    {
        printf("%d\t", p->cle);
        p = p->suivant;
    }
    printf("\n");
}

void inserer_avant_reference(struct cellule *p, int x)
{
    struct cellule *q = (struct cellule *)malloc(sizeof(struct cellule));
    *q                = *p;
    p->cle            = x;
    p->suivant        = q;
}

void inserer_apres_reference(struct cellule *p, int x)
{
    struct cellule *q = (struct cellule *)malloc(sizeof(struct cellule));
    q->cle            = x;
    q->suivant        = p->suivant;
    p->suivant        = q;
}

void supprimer_premier(struct liste *l)
{
    struct cellule *p = l->premier;
    assert(!liste_vide(*l));
    l->premier = p->suivant;
    if (l->premier == NULL)
        l->dernier = NULL;
    free(p);
}

void supprimer_dernier(struct liste *l)
{
    struct cellule *p;
    assert(!liste_vide(*l));
    if (l->premier == l->dernier)
    {
        supprimer_premier(l);
    }
    else
    {
        p = l->premier;
        while (p->suivant != l->dernier)
            p = p->suivant;
        p->suivant = NULL;
        free(l->dernier);
        l->dernier = p;
    }
}

void supprimer_element_referance(struct cellule *p)
{
    struct cellule *q = p->suivant;
    *p                = *q;
    free(q);
}

void supprimer_avant_referance(struct liste *l, struct cellule *p)
{
    struct cellule *q = l->premier;
    while (q->suivant != p)
        q = q->suivant;
    if (q == l->premier)
        supprimer_premier(l);
    else
        supprimer_element_referance(q);
}

int main()
{
    struct liste l;
    creer_liste(&l);
    inserer_apres_dernier(&l, 1);
    inserer_apres_dernier(&l, 2);
    inserer_apres_dernier(&l, 3);
    inserer_apres_dernier(&l, 4);
    affiche(l);
    printf("%p %p\n", l.premier, l.dernier);
    printf("taille = %d\n", taille(l));
    int n = taille(l);
    printf("%p %p\n", l.premier->suivant, l.dernier);
    printf("%d %d\n", l.premier->cle, l.dernier->cle);
    supprimer_element_referance(l.premier->suivant);
    printf("%p %p\n", l.premier->suivant, l.dernier);
    printf("%d %d\n", l.premier->cle, l.dernier->cle);
    supprimer_element_referance(l.premier->suivant);
    printf("%p %p\n", l.premier->suivant, l.dernier);
    printf("%d %d\n", l.premier->cle, l.dernier->cle);
    // supprimer_avant_referance(&l, l.premier->suivant);
    affiche(l);
    printf("%p %p\n", l.premier, l.dernier);
}
