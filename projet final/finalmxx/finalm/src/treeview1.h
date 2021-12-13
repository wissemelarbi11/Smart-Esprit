#include<gtk/gtk.h>



typedef struct{
char jour[30];
char semaine[30];
char ptidej[30];
char ptidej1[30];
char ptidej2[30];

char dej[30];
char dej1[30];
char dej2[30];
char dinner[30];
char dinner1[30];
char dinner2[30];
}menu;
menu m;
void ajouter_menu(menu m);
void afficher_menu(GtkWidget *liste);
void afficher_menu2(GtkWidget *liste);
void supprimer_menu(menu m);
void chercher_menu(menu m,char j[20]);
int meilleur_menu(int semaine);
