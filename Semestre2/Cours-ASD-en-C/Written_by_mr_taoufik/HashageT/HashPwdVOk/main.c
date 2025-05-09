#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_USERS 100

static char* usersName[MAX_USERS] = { NULL };  /* Initialisé à NULL */

unsigned hash(char *pwd) {
    unsigned i, Hcode = 0;
    for (i = 0; pwd[i] != '\0'; i++) {
        Hcode = Hcode * 31 + pwd[i];  /* Multiplicateur premier */
    }
    return Hcode % MAX_USERS;
}

/* Enregistre un nouvel utilisateur */
void register_user() {
    char username[50], password[50];
    unsigned index ;
    printf("Nom d'utilisateur : ");
    scanf("%s", username);
    printf("Mot de passe : ");
    scanf("%s", password);

    index = hash(password);

    /* Vérifie si un utilisateur existe déjà à cet emplacement */
    while (usersName[index] != NULL) {
        printf("Ce mot de passe est deja utilise. Donnez un autre mot de passe : ");
        scanf("%s", password);
        index = hash(password);
    }

    usersName[index] = strdup(username);  /* Allocation dynamique et copie */

    /*  solution 2
      usersName[index] = (char*) malloc(strlen(username) + 1);
      strcpy(usersName[index], username);*/

    printf("Utilisateur enregistre avec succes.\n");
}

/* Vérifie les identifiants d'un utilisateur */
void login() {
    char username[50], password[50];
    printf("Nom d'utilisateur : ");
    scanf("%s", username);
    printf("Mot de passe : ");
    scanf("%s", password);

    unsigned index = hash(password);

    if (usersName[index] != NULL && strcmp(usersName[index], username) == 0) {
        printf("Connexion reussie.\n");
    } else {
        printf("Nom d'utilisateur ou mot de passe incorrect.\n");
    }
}

int main() {
    int choice;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Enregistrer un utilisateur\n");
        printf("2. Se connecter\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                register_user();
                break;
            case 2:
                login();
                break;
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choice != 0);

    return 0;
}
