#ifndef FONCTIONAHMADAC_H_INCLUDED
#define FONCTIONAHMADAC_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
typedef struct produit{
char nom[50];
char type[50];
char ident[50];
char poids[50] ;
char dans[50];
char unite[50];
}prod;
void ajouter_prod1(prod a_p);
int verif(char ident[]);
void supprimer_prod1(char aindet[]);
void modif_prod1(prod a_p,char ch111[]);
void rech_prod1(char aindet[],char ch333[]);
void afiche_prod1(GtkWidget *liste);
void alarme_rupture(char ch222[]);
#endif
