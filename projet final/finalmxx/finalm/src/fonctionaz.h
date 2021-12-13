
#ifndef FONCTIONAZ_H_INCLUDED
#define FONCTIONAZ_H_INCLUDED

#include <gtk/gtk.h>

typedef struct {
int jour;
int mois;
int annee;
}dateaz;


typedef struct
{
  
     char nom[30];
    char prenom[30];
    char id[30];
    char type[30];
    char sexe[30];
    
    dateaz d;
	char jour[30];
	char mois[30];
	char annee[30];
    char role[30];
	char texte[50];

} rec;

void ajt_r(rec r);

void affichage_rechercheraz(GtkWidget *liste);

void modf_r(rec r);

void sup_r(rec r);

void aff_tr(GtkWidget *liste);



int nombre_rec();

int nombre_resto();

int nombre_foyer();

int rec_etudiant();

void rechercheraz(rec r,char id1[30]);

#endif 

