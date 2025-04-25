
#include<stdio.h>
#include <assert.h>
#include <malloc.h>
#include<string.h>
#include "pileChaine.h"
struct element* creer_pile(void){
    return NULL;
}
unsigned vide (struct element*p){
    return(p==NULL);
}
char* dernier (struct element*p){
    assert (!vide(p));
    return (p->cle);
}
/*solution 1  */
void empiler (char* x,struct element**p){
    struct element *q;
    q=(struct element*)malloc(sizeof(struct element));
	q->cle = strdup(x);
    q->suivant = *p;
    *p = q;
}
/* solution 2 en utilisant strcpy 
void empiler (char* x,struct element**p){
    struct element *q;
    q=(struct element*)malloc(sizeof(struct element));
	q->cle = (char*) malloc((strlen(x) + 1) * sizeof(char));
    strcpy(q->cle, x);
	q->suivant = *p;
    *p = q;
}
*/	
	
void depiler (struct element**p){
    struct element *q;
    assert (!vide(*p));
    q=*p;
    *p=q->suivant;
    free(q);
}
