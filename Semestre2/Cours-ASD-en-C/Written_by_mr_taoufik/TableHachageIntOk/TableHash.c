#include <stdio.h>
#include <assert.h>
#include "TableHash.h"
//#include "Liste.h"    NOOOO double importation d'un meme fichier

#define N 5


static struct liste TabListe[N];

int hash(int x){
    return x%N ;
}

void createHashTab(){
    for (int i = 0; i < N; i++)
        creer_liste(&TabListe[i]);

}

void insert (int x){
    int pos=hash(x);
    inserer_apres_dernier(x,&TabListe[pos]);

}

struct cellule* search(int x){
    int pos=hash(x);
    return chercher(x, TabListe[pos].premier);
}
void removee(int x){
    int pos=hash(x);

struct cellule *p =search(x);
    assert(p);
    if(p->suivant==NULL)
        supprimer_dernier(&TabListe[pos]);
    else if (p==TabListe[pos].premier)
        supprimer_premier(&TabListe[pos]);
    else
        supprimer_elem(p);

}


void afficherHashTab() {
    for (int i = 0; i < N; i++) {
        printf("Ligne %d : ", i);
        parcours(TabListe[i].premier, afficher_cellule);
        printf("\n");
    }
}
