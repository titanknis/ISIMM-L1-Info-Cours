#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>
#include "pileChaine.h"
void main (){
    struct element *p1;
    char * x;
    int i,j;
    for (i=0;i<5;i++){
		x = (char*)malloc(20 * sizeof(char));
        printf ("entrer le nom ");
        scanf ("%s",x);
        empiler (x,&p1);
    }
    for (j=0;j<5;j++){
        assert(!vide(p1));
        x=dernier(p1);
        puts(x);
        depiler(&p1);
        printf("\n");
    }
}



