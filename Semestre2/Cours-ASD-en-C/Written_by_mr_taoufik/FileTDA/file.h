struct element{
    int cle;
    struct element *suivant;
};
struct file{
    struct element *tete;
    struct element *queuee;
};
void creer_file (struct file*);
unsigned file_vide (struct file);
int premier (struct file);
void enfiler (int,struct file*);
void defiler (struct file*);
void defiler_enfiler (struct file*,struct file*);
unsigned comparer (struct file,struct file);
unsigned comparer2 (struct file,struct file);
