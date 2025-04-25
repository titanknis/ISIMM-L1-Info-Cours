
struct noeud {
    int cle;
    struct noeud *suivant;
};

struct liste {
    struct noeud *premier;
    struct noeud *dernier;
};

void creer_liste(struct liste *);
unsigned liste_vide (struct liste *) ;
void inserer_apres (int , struct noeud *);
void inserer_avant (int , struct noeud *);
void  inserer_avant_premier (int , struct liste *);
void inserer_apres_dernier(int , struct liste *) ;
void supprimer_elem (struct noeud * );
void supprimer_premier (struct liste *);
void supprimer_dernier(struct liste *);
struct noeud * chercher (int , struct noeud* ) ;
void parcours (struct noeud* , void (*oper) (struct noeud*) );
void afficher (struct noeud * ) ;
void incrementer (struct noeud *) ;
struct liste * concatenerListes0 (struct liste * , struct liste *);
struct liste * concatenerListes1(struct liste * , struct liste * );
struct liste * concatenerListes2(struct liste * , struct liste *);
void Separer0 (struct liste * , struct liste * , struct liste *) ;
void Separer (struct liste * , struct liste * , struct liste * );
struct liste * Fusion22 (struct liste * , struct liste * );
struct liste *Fusion (struct liste * , struct liste * );
struct liste* TriFusion(struct liste * ) ;
