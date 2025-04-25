typedef struct {
  char nom [20];
  float moy;
}etudiant;
struct element {
    etudiant cle;
    struct element * suivant;
};
struct element* creer_pile (void);
unsigned vide (struct element*);
etudiant dernier(struct element*);
void empiler (etudiant,struct element**);
void depiler (struct element**);

