#include <stdio.h>
#include <stdlib.h>
#include "TableHash.h"
//#include "Liste.h"    NOOOO double importation d'un meme fichier

int main() {
    printf("Création de la Table de hachage...\n");
    createHashTab();

    insert(22);
    insert(21);
    insert(11);
    insert(14);
    insert(25);
    insert(26);
    insert(144);
    insert(82);

    afficherHashTab();
    printf("hhhhhhhh\n");
    removee(11);
    afficherHashTab();

    return 0;
}
