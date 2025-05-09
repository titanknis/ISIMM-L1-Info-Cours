
#include<stdio.h>
#include <assert.h>
#include <malloc.h>
#include<string.h>
#include "pileEtudiant.h"
struct element* creer_pile(void){
    return NULL;
}
unsigned vide (struct element*p){
    return(p==NULL);
}
etudiant dernier (struct element*p){
    assert (!vide(p));
    return (p->cle);
}
void empiler (etudiant x,struct element**p){
    struct element *q;
    q=(struct element*)malloc(sizeof(struct element));
    q->cle=x;
    q->suivant=*p;
    *p=q;
}
void depiler (struct element**p){
    struct element *q;
    assert (!vide(*p));
    q=*p;
    *p=q->suivant;
    free(q);
}
