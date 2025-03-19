
/* partie interface */
/****************File.h****************/
struct element {
  int cle;
  struct element *suivant;
};
struct file {
  struct element *tete;
  struct element *queue;
};
void creer_file(struct file *);
unsigned file_vide(struct file);
int premier(struct file);
void enfiler(int, struct file *);
void defiler(struct file *);
