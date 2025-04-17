
/**** partie interface ******/
/*****Liste unidirectionnelle*/
struct cellule {
    int             cle;
    struct cellule* suivant;
};
struct liste {
    struct cellule* premier;
    struct cellule* dernier;
};

/******Fonction creer_liste*******/
void creer_liste(struct liste*);
/******Fonction liste_vide*******/
int liste_vide(struct liste);
/******Fonction inserer_avant_premier******/
void inserer_avant_premier(struct liste*, int);
/**Fonction Remplir 1 en utilisant inserer_avant_premier**/
void remplir1(struct liste*);
/******Fonction inserer_apres_dernier******/
void inserer_apres_dernier(struct liste*, int);
/**Fonction Remplir 1 en utilisant inserer_aprés_dernier**/
void remplir2(struct liste*);
/****Fonction TAILLE***/
int taille(struct liste);
/**** Fonction recherche_référence****/
struct cellule* recherche_reference(struct liste, int);
/***Fonction affiche***/
void affiche(struct liste);
/****Fonction insertion après élément référencée*****/
void inserer_apres_reference(struct cellule*, int);
/****Fonction insertion avant élément référencée*****/
void inserer_avant_reference(struct cellule*, int);
/*****Fonction suppression du premier élément****/
void supprimer_premier(struct liste*);
/*****Fonction suppression du dernier élément****/
void supprimer_dernier(struct liste*);
/*****Fonction suppression d’un élément référencée******/
void supprimer_element_reference(struct cellule*);
/*****Fonction supprimer_apres_reference******/
void supprimer_apres_reference(struct cellule*);

void supprimer_avant_reference(struct liste*, struct cellule*);
