
#ifndef FONCTIONSEIF_H_INCLUDED
#define FONCTIONSEIF_H_INCLUDED

#include <gtk/gtk.h>

typedef struct {
int jour;
int mois;
int annee;
}date;


typedef struct
{
    char nom[30];
    char prenom[30];
    char id[30];
    char niveau[30];
    char sexe[30];

    date d;
	char jour[30];
	char mois[30];
	char annee[30];
    char classe[30];
	char bloc[30];
} etudiant;

void ajt_e(etudiant e);

void affichage_rechercher(GtkWidget *liste);

void modf_e(etudiant e);

void sup_e(etudiant e);

void aff_e(GtkWidget *liste);



int nombre_etudiant();

int nombre_etage2();

int nombre_etage1();


void rechercher(etudiant e,char id1[30]);

#endif 

