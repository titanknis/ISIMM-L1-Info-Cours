#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "file.h"
void main (){
    int n,compt=0,x,i;
    struct file f1,f2,f3;
    creer_file (&f1);
    creer_file (&f2);
    creer_file (&f3);
    printf ("Donner 5 elements a enfiler ensuite a trier en utilisant les oper de la file.h \n");
    for (i=0;i<5;i++){
            printf ("Donner l'element numero %d a enfiler = \n", i);
            scanf ("%d",&x);
            enfiler (x,&f1);
    }
    defiler_enfiler(&f1,&f2);
    while(!file_vide(f1)){
        if (comparer2(f1,f2)==1)
           defiler_enfiler(&f1,&f2);

        else{
            while (!file_vide(f2)&& comparer(f1,f2)==1)
                   defiler_enfiler (&f2,&f3);

            defiler_enfiler (&f1,&f3);

            while (!file_vide(f2)){
                defiler_enfiler(&f2,&f3);
            }
            while (!file_vide(f3)){
                defiler_enfiler(&f3,&f2);
            }

         }
   }
    while (!file_vide(f2)){
            printf ("%d",premier (f2));
            printf ("\n");
            defiler (&f2);
    }
}
