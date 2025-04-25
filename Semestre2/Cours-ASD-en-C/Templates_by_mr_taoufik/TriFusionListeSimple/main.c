#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

void main() {
    struct liste *liste1 = malloc(sizeof(struct liste));
    struct liste *liste2 ;
    creer_liste (liste1);
    inserer_apres_dernier(-10, liste1);
    inserer_apres_dernier(500, liste1);
    inserer_apres_dernier(300, liste1);
    inserer_apres_dernier(111, liste1);
    inserer_apres_dernier(888, liste1);
    inserer_apres_dernier(-99, liste1);

    printf("\n \t initialement la liste contient \n");
    parcours(liste1->premier, afficher);

    liste2=TriFusion(liste1);
    printf("\n \t finalement la liste contient \n");
    parcours(liste2->premier, afficher);
}
