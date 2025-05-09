/*Cette solution peut être considérée comme une solution de chiffrement, et non de hachage, car la complexité de la recherche d'un élément est en O(n).*/
#include <stdio.h>
#include <string.h>
#include<assert.h>

#define MAX_USERS 100

typedef struct {
    char username[50];
    unsigned hashed_password;
} User;

static User users [MAX_USERS];
static unsigned UserNb=0;

unsigned hash(char *pwd) {
    unsigned i, Hcode = 0;
    for (i = 0; pwd[i] != '\0'; i++) {
        Hcode = Hcode * 31 + pwd[i];  /* Multiplicateur premier */
    }
    return Hcode;
}

/* Enregistre un nouvel utilisateur */
void register_user( ) {
    char username[50], password[10];
    assert(UserNb < MAX_USERS);
    printf("Nom d'utilisateur : ");
    scanf("%s", username);
    printf("Mot de passe : ");
    scanf("%s", password);

    users[UserNb].hashed_password = hash(password);
    strcpy(users[UserNb].username, username);
    UserNb++;

    printf(" Tilisateur enregistré avec succès.\n");
}

/* Vérifie les identifiants d'un utilisateur */
int login( ) {
    char username[50], password[50];
    printf("Nom d'utilisateur : ");
    scanf("%s", username);
    printf("Mot de passe : ");
    scanf("%s", password);

    unsigned i=0, Hcode = hash(password);

    while (i< UserNb && (!strcmp(users[i].username, username) ||  users[i].hashed_password != Hcode))
        i++;

    if (i<UserNb)
        printf(" Connexion réussie.\n");
    else
        printf(" Nom d'utilisateur ou mot de passe incorrect.\n");

    return i<UserNb ;
}

int main() {

    int choice;

    do {
        printf("=== MENU ===\n");
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
