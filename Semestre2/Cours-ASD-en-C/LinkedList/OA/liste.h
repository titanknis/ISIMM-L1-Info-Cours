/**** partie interface ******/
/******Fonction creer_liste*******/
void creer_liste();
/******Fonction liste_vide*******/
int liste_vide();
/******Fonction inserer_avant_premier******/
void inserer_avant_premier(int);
/**Fonction Remplir 1 en utilisant inserer_avant_premier**/
void remplir1();
/******Fonction inserer_apres_dernier******/
void inserer_apres_dernier(int);
/**Fonction Remplir 1 en utilisant inserer_aprés_dernier**/
void remplir2();
/****Fonction TAILLE***/
unsigned taille();
/**** Fonction recherche_référence****/
struct cellule* recherche_reference(int);
/***Fonction affiche***/
void affiche();
/****Fonction insertion après élément référencée*****/
void inserer_apres_reference(struct cellule*, int);
/****Fonction insertion avant élément référencée*****/
void inserer_avant_reference(struct cellule*, int);
/*****Fonction suppression du premier élément****/
void supprimer_premier();
/*****Fonction suppression du dernier élément****/
void supprimer_dernier();
/*****Fonction suppression d’un élément référencée******/
void supprimer_element_reference(struct cellule*);
/*****Fonction supprimer_apres_reference******/
void supprimer_apres_reference(struct cellule*);
/*****Fonction supprimer_avant_reference******/
void supprimer_avant_reference(struct cellule*);
