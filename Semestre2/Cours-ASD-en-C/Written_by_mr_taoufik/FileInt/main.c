#include<stdio.h>
#include<stdlib.h>
#include "file.h"

int main () {

struct file *f1 ;
f1 = ( struct file *)  malloc (sizeof (struct file )) ;

creeFile(f1);
enfiler( 5, f1) ;
enfiler( 15, f1) ;
enfiler( 25, f1) ;
enfiler( 35, f1) ;
printf ("premier est \t %d \n ", premier (*f1)) ;
defiler (f1) ;
printf ("premier est \t %d \n ", premier (*f1)) ;
defiler (f1) ;
printf ("premier est \t %d \n ", premier (*f1)) ;
defiler (f1) ;
printf ("premier est \t %d \n ", premier (*f1)) ;


}
