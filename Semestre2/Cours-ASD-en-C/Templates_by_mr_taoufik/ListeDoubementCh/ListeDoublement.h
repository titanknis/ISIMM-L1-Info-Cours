struct noeud{
    int cle;
    struct noeud* succ;
    struct noeud* pred;
};

struct liste {
    struct noeud* premier;
    struct noeud* dernier;
};

void creer_liste(struct liste *ll) ;
unsigned liste_vide (struct liste*ll);
void inserer_apres (int info, struct noeud*p) ;
void inserer_avant (int info, struct noeud*p) ;
void  inserer_avant_premier (int info, struct liste *ll) ;
void inserer_apres_dernier(int info, struct liste *ll) ;
void supprimer_elem (struct noeud* p ) ;
void supprimer_premier (struct liste * ll);
void supprimer_dernier(struct liste *ll) ;
struct noeud* chercher (int info, struct noeud* p);
void parcours (struct noeud* p, void (*oper) (struct noeud*) ) ;
void afficher (struct noeud* q) ;

