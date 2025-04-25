struct Cellule  {
 	int cle ;
 	struct Cellule * suivant ;
  } ;

  struct file {

  	struct Cellule * tete ;
	struct Cellule * queue ;

  };

void creeFile (struct file *f) ;
int file_vide (  struct file f );
void enfiler (  int x ,  struct file* f ) ;
void defiler (  struct file *f) ;
int  premier (  struct file f ) ;
