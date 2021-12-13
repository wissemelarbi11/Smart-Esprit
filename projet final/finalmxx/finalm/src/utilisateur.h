#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
typedef struct date
{
    int j;
    int m;
    int a;
}datewess;

typedef struct utilisateur
{
    int id;
    int role;
    char prenom[50];
    char nom[50];
    char email[50];
    int sexe;
    datewess d ;
    int nv;

}utilisateur;

typedef struct debit {
	int jour;
	int heure;
	int etage;
	float debit;
                  
}debit;

void ajouter(utilisateur u, char *fname);
void supprimer(utilisateur u, char *fname);
void modifier(utilisateur u, char *fname);
void afficher(GtkWidget *liste, char *fname);
utilisateur chercher(int id, char *fname);
void panne(GtkWidget *liste, char *fname);

