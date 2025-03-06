
/* partie interface */
/****************Pile.h****************/
struct element {
  int cle;
  struct element *suivant;
};

struct element *creer_pile();
unsigned pile_vide(struct element *);
int dernier(struct element *);
void empiler(int, struct element **);
void depiler(struct element **);
