#include <stdio.h>
#include <stdlib.h>
#include "ListeDoublement.h"
int main() {
    struct liste *liste1 = malloc(sizeof(struct liste));
    struct liste *liste2 = malloc(sizeof(struct liste));
    struct noeud *p;

   // struct noeud* chercher (int info, struct noeud* p)
    creer_liste(liste1);
   inserer_apres_dernier(-10, liste1);
   inserer_apres_dernier(2, liste1);
   inserer_apres_dernier(30, liste1);
   inserer_apres_dernier(-40, liste1);
   inserer_apres_dernier(88, liste1);
   inserer_apres_dernier(-990, liste1);
   inserer_avant_premier(100, liste1);
   parcours(liste1->premier, afficher);

   p= chercher(88, liste1->premier);
   inserer_apres(8,p);
   printf("\n");
   parcours(liste1->premier, afficher);


}
