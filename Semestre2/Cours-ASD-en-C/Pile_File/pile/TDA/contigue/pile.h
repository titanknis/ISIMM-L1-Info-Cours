
/* partie interface */
/****************Pile.h****************/
#define n 100
struct pile {
  int cle[n];
  int sommet;
};

void creerpile(struct pile *);
unsigned pile_vide(struct pile);
int dernier(struct pile);
void empiler(int, struct pile *);
void depiler(struct pile *);
