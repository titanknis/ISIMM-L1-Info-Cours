/****************Partie Test****************/
#include "liste.h"
#include <stdio.h>
int main() {
    int             x, y;
    struct cellule* p;
    creer_liste();
    /*****Remplissage de la liste*****/
    printf("***Remplissage de la liste ***\n");
    remplir2();
    printf("***Contenu de la liste ***\n");
    affiche();
    printf("La taille de la liste = %u\n", taille());

    /*****inserer_avant_premier un élément donné*****/
    printf("****Inserer un %cl%cment donn%c avant le premier****\n", 130, 130, 130);
    printf("Donner l'entier d'insertion : ");
    scanf("%d", &y);
    inserer_avant_premier(y);
    printf("***Contenu de la liste apr%cs insertion avant premier***\n", 130);
    affiche();
    printf("La taille de la liste = %u\n", taille());

    /*****inserer_aprés_dernier un élément donné*****/
    printf("****Inserer un %cl%cment donn%c apr%cs le dernier****\n", 130, 130, 130, 130);
    printf("Donner l'entier d'insertion : ");
    scanf("%d", &y);
    inserer_apres_dernier(y);
    printf("***Contenu de la liste apr%cs insertion apr%cs dernier***\n", 130, 130);
    affiche();
    printf("La taille de la liste = %u\n", taille());

    /*****inserer_apres_reference un élément donné(la référence est différente du premier et
     * dernier)*****/
    printf("*inserer un %clt. apr%cs r%cf%crence(la r%cf. est diff%crente du premier et dernier)*",
           130,
           130,
           130,
           130,
           130,
           130);
    printf("Donner un entier de recherche : ");
    scanf("%d", &x);
    p = recherche_reference(x);
    if (p) {
        printf("%d existe dans la liste et son r%cf%crence =%x\n", x, 130, 130, p);
        printf("Donner l'entier d'insertion : ");
        scanf("%d", &y);
        inserer_apres_reference(p, y);
        printf("***Contenu de la liste apr%cs insertion***\n", 130);
        affiche();
        printf("La taille de la liste = %u\n", taille());
    } else
        printf("La r%cf%crence de %d n'existe pas dans la liste\n", 130, 130, x);

    /*****inserer_avant_reference un élément donné(la réf.est différente du premier et
     * dernier)*****/
    printf("*inserer un %clt. avant r%cf%crence(la r%cf. est diff%crente du premier et dernier)*",
           130,
           130,
           130,
           130,
           130);
    printf("Donner un entier : ");
    scanf("%d", &x);
    p = recherche_reference(x);
    if (p) {
        printf("%d existe dans la liste et son r%cf%crence =%x\n", x, 130, 130, p);
        printf("Donner l'entier d'insertion : ");
        scanf("%d", &y);
        inserer_avant_reference(p, y);
        printf("***Contenu de L1 apr%cs insertion***\n", 130);
        affiche();
        printf("La taille de la liste = %u\n", taille());
    } else
        printf("La r%cf%crence de %d n'existe pas dans la liste\n", 130, 130, x);

    /*****Suppression du premier élément de la liste*****/
    printf("****Suppression du premier %cl%cment de la liste****\n", 130, 130);
    supprimer_premier();
    printf("***Contenu de la liste apr%cs suppression premier***\n", 130);
    affiche();
    printf("La taille de la liste = %u\n", taille());

    /*****Suppression du dernier élément de la liste*****/
    printf("****Suppression du dernier %cl%cment de la liste****\n", 130, 130);
    supprimer_dernier();
    printf("***Contenu de la liste apr%cs suppression dernier***\n", 130);
    affiche();
    printf("La taille de la liste = %u\n", taille());

    /**suppression d’un élément référencé(la référence est différente du premier et dernier)**/
    printf("*supp. d'1 %clt. %c partir d'une r%cf donn%ce(r%cf. diff. du premier et dernier)*\n",
           130,
           133,
           130,
           130,
           130);
    printf("Donner un entier : ");
    scanf("%d", &x);
    p = recherche_reference(x);
    if (p) {
        printf("%d existe dans la liste et son r%cf%crence =%x\n", x, 130, 130, p);
        supprimer_element_reference(p);
        printf("***Contenu de la liste apr%cs suppression***\n", 130);
        affiche();
        printf("La taille de la liste = %u\n", taille());
    } else
        printf("La r%cf%crence de %d n'existe pas dans la liste\n", 130, 130, x);

    /*****suppression d’un élément apres une référence(la référence est différente du premier et
     * dernier)******/
    printf("*supp. d'1 %clt. apr%cs une r%cf donn%c(r%cf. est diff. du premier et dernier)*\n",
           130,
           130,
           130,
           130);
    printf("Donner un entier : ");
    scanf("%d", &x);
    p = recherche_reference(x);
    if (p) {
        printf("%d existe dans la liste et son r%cf%crence =%x\n", x, 130, 130, p);
        supprimer_apres_reference(p);
        printf("***Contenu de la liste apr%cs suppression***\n", 130);
        affiche();
        printf("La taille de la liste = %u\n", taille());
    } else
        printf("La r%cf%crence de %d n'existe pas dans la liste\n", 130, 130, x);

    return 0;
}
