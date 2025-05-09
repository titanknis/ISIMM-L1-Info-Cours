#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>
#include "pileEtudiant.h"
void main (){
    struct element *p1;
    etudiant x;
    int i,j;
    for (i=0;i<2;i++){
        printf ("entrer le nom ");
        scanf ("%s",x.nom);
        printf ("entrer la moyenne: ");
        scanf ("%f",&(x.moy));
        empiler (x,&p1);
    }
    for (j=0;j<2;j++){
        assert(!vide(p1));
        x=dernier(p1);
        puts(x.nom);
        printf("\t %f.2",x.moy);
        depiler(&p1);
        printf("\n");
    }}



