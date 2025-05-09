
struct element {
    char * cle;
    struct element * suivant;
};
struct element* creer_pile (void);
unsigned vide (struct element*);
char* dernier(struct element*);
void empiler (char*,struct element**);
void depiler (struct element**);

