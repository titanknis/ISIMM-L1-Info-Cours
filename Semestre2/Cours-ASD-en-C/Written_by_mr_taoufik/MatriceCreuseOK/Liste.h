
struct cellule {
    int cle;
    unsigned col;
    struct cellule *suivant;
};

struct liste {
    struct cellule *premier;
    struct cellule *dernier;
};

void creer_liste(struct liste *ll);
unsigned liste_vide(struct liste *ll);
void inserer_apres(int cle,unsigned col, struct cellule *p);
void inserer_avant(int cle, unsigned col, struct cellule *p);
void inserer_avant_premier(int cle,unsigned col, struct liste *ll);
void inserer_apres_dernier(int cle,unsigned col,  struct liste *ll);
void supprimer_elem(struct cellule *p);
void supprimer_premier(struct liste *ll);
void supprimer_dernier(struct liste *ll);
struct cellule *chercher(int cle, struct cellule *p);
struct cellule *chercher2(unsigned col, struct cellule *p) ;
void parcours(struct cellule *p, void (*oper)(struct cellule *));
void afficher_cellule(struct cellule* p);


