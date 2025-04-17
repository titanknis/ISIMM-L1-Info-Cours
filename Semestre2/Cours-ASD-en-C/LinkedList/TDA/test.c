/****************Partie Test****************/
#include "liste.h"
#include <stdio.h>
int main() {
    int             x, y;
    struct liste    L1, L2;
    struct cellule* p;
    creer_liste(&L1);
    creer_liste(&L2);
    /*****Remplissage de la liste L1*****/
    printf("***Remplissage de la liste L1***\n");
    remplir2(&L1);
    /*****Remplissage de la liste L2*****/
    printf("***Remplissage de la liste L2***\n");
    remplir2(&L2);
    printf("***Contenu de la liste L1***\n");
    affiche(L1);
    printf("La taille de la liste L1 = %u\n", taille(L1));
    printf("***Contenu de la liste L2***\n");
    affiche(L2);
    printf("La taille de la liste L2 = %u\n", taille(L2));

    /*****inserer_avant_premier un élément donné dans L1*****/
    printf("****Inserer un %cl%cment donn%c avant le premier dans L1****\n", 130, 130, 130);
    printf("Donner l'entier d'insertion : ");
    scanf("%d", &y);
    inserer_avant_premier(&L1, y);
    printf("***Contenu de la liste L1 apr%cs insertion (avant premier)***\n", 130);
    affiche(L1);
    printf("La taille de la liste L1 = %u\n", taille(L1));

    /*****inserer_aprés_dernier un élément donné dans L2*****/
    printf("****Inserer un %cl%cment donn%c apr%cs le dernier  ds L2****\n", 130, 130, 130, 130);
    printf("Donner l'entier d'insertion : ");
    scanf("%d", &y);
    inserer_apres_dernier(&L2, y);
    printf("***Contenu de L2 apr%cs insertion (apr%cs dernier)***\n", 130, 130);
    affiche(L2);
    printf("La taille de la liste L2 = %u\n", taille(L2));

    /*****inserer_apres_ref. un élément donné ds L1(la référence est différente du premier et
     * dernier)*****/
    printf("*inserer un %clt. apr%cs r%cf. ds L1(la r%cf. est diff. du premier et dernier)*\n",
           130,
           130,
           130,
           130);
    printf("Donner un entier de recherche : ");
    scanf("%d", &x);
    p = recherche_reference(L1, x);
    if (p) {
        printf("%d existe dans L1 et son r%cf%crence =%x\n", x, 130, 130, p);
        printf("Donner l'entier d'insertion : ");
        scanf("%d", &y);
        inserer_apres_reference(p, y);
        printf("***Contenu de la liste L1 apr%cs insertion***\n", 130);
        affiche(L1);
        printf("La taille de la liste L1 = %u\n", taille(L1));
    } else
        printf("La r%cf%crence de %d n'existe pas dans L1 \n", 130, 130, x);

    /*****inserer_avant_ref. un élément donné ds L2(la réf.est différente du premier et
     * dernier)*****/
    printf("*inserer un %clt. avant r%cf. ds L2(la r%cf. est diff. du premier et dernier)*\n",
           130,
           130,
           130);
    printf("Donner un entier : ");
    scanf("%d", &x);
    p = recherche_reference(L2, x);
    if (p) {
        printf("%d existe dans L2 et son r%cf%crence =%x\n", x, 130, 130, p);
        printf("Donner l'entier d'insertion : ");
        scanf("%d", &y);
        inserer_avant_reference(p, y);
        printf("***Contenu de L2 apr%cs insertion***\n", 130);
        affiche(L2);
        printf("La taille de la liste L2 = %u\n", taille(L2));
    } else
        printf("La r%cf%crence de %d n'existe pas dans L2\n", 130, 130, x);

    /*****Suppression du premier élément de la liste L1*****/
    printf("****Suppression du premier %cl%cment de L1 ****\n", 130, 130);
    supprimer_premier(&L1);
    printf("***Contenu de L1 apr%cs suppression premier***\n", 130);
    affiche(L1);
    printf("La taille de la liste L1 = %u\n", taille(L1));

    /*****Suppression du dernier élément de la liste L2*****/
    printf("****Suppression du dernier %cl%cment de la liste L2****\n", 130, 130);
    supprimer_dernier(&L2);
    printf("***Contenu de L2 apr%cs suppression dernier***\n", 130);
    affiche(L2);
    printf("La taille de la liste L2 = %u\n", taille(L2));

    /**suppression d’un élément référencé de L1(la réf. est différente du premier et dernier)**/
    printf("*supp. d'1 %clt. %c partir d'1e r%cf donn%ce de L1/r%cf. diff. du premier et dernier",
           130,
           133,
           130,
           130,
           130);
    printf("Donner un entier : ");
    scanf("%d", &x);
    p = recherche_reference(L1, x);
    if (p) {
        printf("%d existe dans L1 et son r%cf%crence =%x\n", x, 130, 130, p);
        supprimer_element_reference(p);
        printf("***Contenu de la liste L1 apr%cs suppression***\n", 130);
        affiche(L1);
        printf("La taille de la liste L1 = %u\n", taille(L1));
    } else
        printf("La r%cf%crence de %d n'existe pas dans L1\n", 130, 130, x);

    /*****suppression d’un élément apres une réf. de L2(la référence est différente du premier et
     * dernier)******/
    printf("*supp. d'1 %clt. apr%cs une r%cf donn%c de L2/r%cf. est diff. du premier et dernier\n",
           130,
           130,
           130,
           130);
    printf("Donner un entier : ");
    scanf("%d", &x);
    p = recherche_reference(L2, x);
    if (p) {
        printf("%d existe dans L2 et son r%cf%crence =%x\n", x, 130, 130, p);
        supprimer_apres_reference(p);
        printf("***Contenu de L2 apr%cs suppression***\n", 130);
        affiche(L2);
        printf("La taille de la liste L2 = %u\n", taille(L2));
    } else
        printf("La r%cf%crence de %d n'existe pas dans L2\n", 130, 130, x);
    return 0;
}
