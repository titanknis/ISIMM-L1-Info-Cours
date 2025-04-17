#include <stdio.h>
#include <stdlib.h>
/*****Liste bidirectionnelle*/
struct cellule
{
    struct cellule *avant;
    int info;
    struct cellule *suivant;
};
struct liste
{
    struct cellule* premier;
    struct cellule* dernier;
};
/******Fonction creer_liste*******/
void creer_liste(struct liste *L)
{
    L->premier=NULL ;
    L->dernier=NULL ;
}
/******Fonction tester_liste_vide*******/
int tester_liste_vide(struct liste L)
{
    return L.premier==NULL;
}
/******Fonction Ajout inserer_avant_premier *******/
void inserer_avant_premier(struct liste *L,int x)
{
    struct cellule * p;
    p=(struct cellule*)malloc(sizeof(struct cellule));
    p->info=x;
    p->suivant=L->premier;
    p->avant=NULL;
    if(L->premier==NULL)
        L->dernier=p;
    else
        (L->premier)->avant=p;
    L->premier=p;
}
/**Fonction Remplir 1 en utilisant inserer_avant_premier**/
void remplir1(struct liste * L , int n)
{
    int i, x;
    for(i=1 ; i<=n ; i++)
    {
        printf("Donner un entier : ");
        scanf("%d",&x);
        inserer_avant_premier(L , x);
    }
}
/******Fonction Ajout inserer_aprés_dernier *******/
void inserer_apres_dernier(struct liste *L,int x)
{
    struct cellule * p;
    p=(struct cellule*)malloc(sizeof(struct cellule));
    p->info=x;
    p->avant=L->dernier;
    p->suivant=NULL;
    if(L->dernier==NULL)
        L->premier=p;
    else
        (L->dernier)->suivant=p;
    L->dernier=p;
}
/**Fonction Remplir 2 en utilisant inserer_avant_premier**/
void remplir2(struct liste * L , int n)
{
    int i, x;
    for(i=1 ; i<=n ; i++)
    {
        printf("Donner un entier : ");
        scanf("%d",&x);
        inserer_apres_dernier(L , x);
    }
}
/****Fonction TAILLE***/
int taille(struct liste L)
{
    struct cellule * p;
    unsigned t=0;
    if(tester_liste_vide(L))
        return(0);
    else
    {
        p=L.premier;
        while(p!=NULL)
        {
            p=p->suivant;
            t++;
        }
        return(t);
    }
}
/**** Fonction recherche_référence****/
 struct cellule * recherche_reference(struct liste L , int x)
 {
     struct cellule * p=L.premier;
     while (p)
        if(p->info==x)
            return p;
        else
            p=p->suivant;
    return NULL;
}
/****Fonction insertion après élément référencée*****/
void inserer_apres_reference(struct cellule * p, int x)
{
    struct cellule *q;
    q = (struct cellule*)malloc(sizeof(struct cellule));
    q->info = x;
    q->suivant = p->suivant ;
    q->avant=p;
    p->suivant->avant=q;
    p->suivant=q;
}
/****Fonction insertion après élément référencée*****/
void inserer_avant_reference(struct cellule * p, int x)
{
    struct cellule *q;
    q = (struct cellule*)malloc(sizeof(struct cellule));
    q->info = x;
    q->suivant = p ;
    q->avant=p->avant;
    p->avant->suivant=q;
    p->avant=q;
}
/****Fonction supprimer_premier*****/
void supprimer_premier(struct liste *L)
{
    struct cellule * p;
    if (tester_liste_vide(*L))
        printf ("Liste vide\n" );
    else
        if (L->premier==L->dernier)
        {
            free(L->premier);
            L->premier=NULL;
            L->dernier=NULL;
        }
        else
        {
            p=L->premier;
            (p->suivant)->avant=NULL;
            L->premier=p->suivant;
            free(p);
        }
}
/****Fonction supprimer_dernier*****/
void supprimer_dernier(struct liste *L)
{
    struct cellule * p;
    if (tester_liste_vide(*L))
        printf ("Liste vide\n" );
    else
        if (L->premier==L->dernier)
        {
            free(L->premier);
            L->premier=NULL;
            L->dernier=NULL;
        }
        else
        {
            p=L->dernier;
            (p->avant)->suivant=NULL;
            L->dernier=p->avant;
            free(p);
        }
}
/*****suppression d’un élément référencée******/
void supprimer_element_reference( struct cellule *p)
{
    p->avant->suivant=p->suivant;
    p->suivant->avant=p->avant;
    free(p);
}
/*****Fonction supprimer_apres_reference******/
void supprimer_apres_reference(struct cellule * p)
{
    struct cellule * q=p->suivant;
    p->suivant=q->suivant;
    q->suivant->avant=p;
    free(q);
}
/*****Fonction supprimer_avant_reference******/
void supprimer_avant_reference(struct cellule * p)
{
    struct cellule * q=p->avant;
    p->avant=q->avant;
    q->avant->suivant=p;
    free(q);
}
/****Fonction Affiche*****/
void affiche(struct liste L)
{
    struct cellule * p ;
    if (tester_liste_vide(L))
        printf ("Liste vide\n" );
    else
        if (L.premier == L.dernier)
            printf ("La liste à un seul élément : %d " ,L.premier->info);
        else
        {
            p=L.premier;    /* p= L.queue : de gauche à droite */
            while (p)
            {
                printf ("%d\t",p->info);
                p= p->suivant;
            }
         }
    printf("\n");
}
/****Fonction Affiche*****/
void affiche_adresse(struct liste L)
{
    struct cellule * p ;

    p=L.premier;    /* p= L.queue : de gauche à droite */
    printf ("%X\t",L.premier);
    while (p)
    {
        printf ("%X\t",p->suivant);
        p= p->suivant;
    }
    printf("\n");
}
void INVERSE_LISTE(struct liste L)
{
    int aux;
    struct cellule *  p1=L.premier;
    struct cellule * p2=L.dernier;
    while(p1!=p2 && p1->avant!=p2)
    {
        aux =p1->info;
        p1->info=p2->info;
        p2->info=aux;
        p1=p1->suivant;
        p2=p2->avant;
    }
}
int main()
{
    struct liste L1;
    int n =6,x,y;
    struct cellule * p;
    creer_liste(&L1) ;
    /*remplir1(&L1,n);
    printf("***Contenu de L1***\n");
    affiche(L1);*/
    printf("****Chargement de L1****\n");
    remplir2(&L1,n);
    printf("***Contenu de L1***\n");
    affiche(L1);
    INVERSE_LISTE(L1);
    printf("***Contenu de L1***\n");
    affiche(L1);




    /*****inserer_avant_premier *****/
    /*printf("****inserer_avant_premier ****\n",130,130,130);
    printf("Donner l'entier d'insertion : ");
    scanf("%d",&y);
    inserer_avant_premier(&L1,y);
    printf("***Contenu de L1 apr%cs insertion avant premier***\n");
    affiche(L1);*/

    /*****inserer_aprés_dernier d'un élément donné*****/
    /*printf("****inserer apres dernier ****\n");
    printf("Donner l'entier d'insertion : ");
    scanf("%d",&y);
    inserer_apres_dernier(&L1,y);
    printf("***Contenu de L1 apr%cs insertion apr%cs dernier***\n",130,130);
    affiche(L1);
    getch();*/
    /*****inserer_apres_reference d'un élément donné*****/
    /*printf("****inserer apr%cs r%cf%crence  d'un %cl%cment donn%c****\n",130,130,130,130,130,130);
    printf("Donner un entier de recherche : ");
    scanf("%d",&x);
    p=recherche_reference(L1,x);
    if(p)
    {
        printf("%d existe dans la liste et son r%cf%crence =%x\n",x,130,130,p);
        printf("Donner l'entier d'insertion : ");
        scanf("%d",&y);
        inserer_apres_reference(p,y);
        printf("***Contenu de L1 apr%cs insertion***\n",130);
        affiche(L1);
    }
    else
        printf("La r%cf%crence de %d n'existe pas dans la liste\n",130,130,x);
    */
    /*****inserer_avant_reference d'un élément donné*****/
    /*printf("****inserer avant r%cf%crence d'un %cl%cment donn%c****\n",130,130,130,130,130);
    printf("Donner un entier : ");
    scanf("%d",&x);
    p=recherche_reference(L1,x);
    if(p)
    {
        printf("%d existe dans la liste et son r%cf%crence =%x\n",x,130,130,p);
        printf("Donner l'entier d'insertion : ");
        scanf("%d",&y);
        inserer_avant_reference(p,y);
        printf("***Contenu de L1 apr%cs insertion***\n",130);
        affiche(L1);
    }
    else
        printf("La r%cf%crence de %d n'existe pas dans la liste\n",130,130,x);*/

    /*****Suppression du premier élément de la liste*****/
    /*printf("****Suppression du premier %cl%cment de la liste****\n",130,130);
    supprimer_premier(&L1);
    printf("***Contenu de L1 apr%cs suppresion premier***\n",130);
    affiche(L1);*/

    /*****Suppression du dernier élément de la liste*****/
    /*printf("****Suppression du dernier %cl%cment de la liste****\n",130,130);
    supprimer_dernier(&L1);
    printf("***Contenu de L1 apr%cs suppresion dernier***\n",130);
    affiche(L1);*/

    /*****suppression d’un élément référencé******/
    /*printf("****suppression d'un %cl%cment %c partir d'une r%cf%crence donn%c****\n",130,130,133,130,130,130);
    printf("Donner un entier : ");
    scanf("%d",&x);
    p=recherche_reference(L1,x);
    if(p)
    {
        printf("%d existe dans la liste et son r%cf%crence =%x\n",x,130,130,p);
        supprimer_element_reference(p);
        printf("***Contenu de L1 apr%cs suppression***\n",130);
        affiche(L1);
    }
    else
        printf("La r%cf%crence de %d n'existe pas dans la liste\n",130,130,x);*/

     /*****suppression d’un élément avant une référence******/
    /*printf("****suppression d'un %cl%cment avant une r%cf%crence donn%c****\n",130,130,130,130,130);
    printf("Donner un entier : ");
    scanf("%d",&x);
    p=recherche_reference(L1,x);
    if(p)
    {
        printf("%d existe dans la liste et son r%cf%crence =%x\n",x,130,130,p);
        supprimer_avant_reference(p);
        printf("***Contenu de L1 avant suppression***\n");
        affiche(L1);
    }
    else
        printf("La r%cf%crence de %d n'existe pas dans la liste\n",130,130,x);*/

    /*****suppression d’un élément apres une référence******/
    /*printf("****suppression d'un %cl%cment apr%cs une r%cf%crence donn%c****\n",130,130,130,130,130,130);
    printf("Donner un entier : ");
    scanf("%d",&x);
    p=recherche_reference(L1,x);
    if(p)
    {
        printf("%d existe dans la liste et son r%cf%crence =%x\n",x,130,130,p);
        supprimer_apres_reference(p);
        printf("***Contenu de L1 apr%cs suppression***\n",130);
        affiche(L1);
    }
    else
        printf("La r%cf%crence de %d n'existe pas dans la liste\n",130,130,x);
    printf("La taille de la liste = %d\n",taille(L1));
    return 0;*/
}
