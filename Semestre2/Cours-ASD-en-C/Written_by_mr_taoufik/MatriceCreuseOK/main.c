#include <stdio.h>
#include <stdlib.h>
#include "TabListe.h"
//#include "Liste.h"    NOOOO double importation d'un meme fichier

int main() {
    printf("Cr�ation de la matrice creuse...\n");
    creerMatCreuse();

    ModifElem(9, 0, 0);
    ModifElem(1, 1, 3);
    ModifElem(2, 2, 4);
    ModifElem(3, 3, 0);
    ModifElem(4, 3, 2);
    printf("\n Matrice creuse apr�s modifications 1:\n");
    afficherMatCreuse();

    ModifElem(55, 3, 3);
    printf("\n Matrice creuse apr�s modifications 2:\n");
    afficherMatCreuse();

    ModifElem(0, 3, 3);
    printf("\n Matrice creuse apr�s modifications 3 :\n");
    afficherMatCreuse();

    return 0;
}
