#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
typedef struct dateghaylen
{
    int j;
    int m;
    int a;
}dateghaylen;

typedef struct mesure
{
    int jour;
    int heure;
    int id;
    int valeur;
}mesure;


typedef struct capteur
{
    char id[20];
    int type;
    char bloc[2];
    char marque[20];
    dateghaylen d;
}capteur;

void ajoutergh(capteur u, char *fname);
void supprimergh(capteur u, char *fname);
void modifiergh(capteur u, char *fname);
void affichergh(GtkWidget *liste, char *fname);
void alarme(GtkWidget *liste, char *fname, char *fname1);

