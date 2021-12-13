#include "fonctionahmadac.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
void ajouter_prod1(prod a_p)
{int n1,nb;
char ch1[50];
FILE *f=NULL;
f=fopen("stock.txt","a+");

if(f!=NULL)
{
if ((verif(a_p.ident)==0))
{fprintf(f,"%s %s %s %s %s %s\n",a_p.nom,a_p.type,a_p.ident,a_p.poids,a_p.unite,a_p.dans);
}

fclose(f);
}
}
/********************************************************************/
int verif(char ident[])
{
int b=0;
char ch1[50];
char ch2[50];
char ch3[50];
char ch4[50];
char ch5[50];
char ch6[50];
FILE *f=NULL;
f=fopen("stock.txt","r");
if (f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s %s\n",ch1,ch2,ch3,ch4,ch5,ch6)!=EOF)
{if (strcmp(ident,ch3)==0){b=1;}
}
fclose(f);
}
return b;
}
/*********************************************************************/
void supprimer_prod1(char aident[])
{
char ch1[50];
char ch2[50];
char ch3[50];
char ch4[50];
char ch5[50];
char ch6[50];
FILE *f=NULL;
FILE *g=NULL;
f=fopen("stock.txt","r");
g=fopen("tmp.txt","w");
while(fscanf(f,"%s %s %s %s %s %s\n",ch1,ch2,ch3,ch4,ch5,ch6)!=EOF)
{if (strcmp(aident,ch3)!=0){fprintf(g,"%s %s %s %s %s %s\n",ch1,ch2,ch3,ch4,ch5,ch6);}
}

fclose(f);
fclose(g);
remove("stock.txt");
rename("tmp.txt","stock.txt");

}
/***************************************************************/
void modif_prod1(prod a_p,char ch111[])
{
char ch1[50];
char ch2[50];
char ch3[50];
char ch4[50];
char ch5[50];
char ch6[50];
char ch8[50];
FILE *f=NULL;
FILE *g=NULL;
f=fopen("stock.txt","r");
g=fopen("tmp.txt","w");
strcpy(ch8,a_p.ident);
/*
while(fscanf(f,"%s %s %s %s %s %s",ch1,ch2,ch3,ch4,ch5,ch6)!=EOF)
{if (strcmp(a_p.ident,ch3)!=0)
  {fprintf(f1,"%s %s %s %s %s %s\n",ch1,ch2,ch3,ch4,ch5,ch6);}
 else {fprintf(f1,"%s %s %s %s %s %s\n",a_p.nom,a_p.type,a_p.ident,a_p.poids,a_p.unite,a_p.dans);}
*/
if (f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s %s",ch1,ch2,ch3,ch4,ch5,ch6)!=EOF)
{if (strcmp(a_p.ident,ch3)!=0)
  {fprintf(g,"%s %s %s %s %s %s\n",ch1,ch2,ch3,ch4,ch5,ch6);}
 else {fprintf(g,"%s %s %s %s %s %s\n",a_p.nom,a_p.type,a_p.ident,a_p.poids,a_p.unite,a_p.dans);
}
}

}
fclose(f);
fclose(g);
remove("stock.txt");
rename("tmp.txt","stock.txt");

}
/*************************************************************************************/
void rech_prod1(char identite[] ,char ch222[])
{
char ch1[50];
char ch2[50];
char ch3[50];
char ch4[50];
char ch5[50];
char ch6[50];
char new[50];
FILE *f=NULL;
f=fopen("stock.txt","r");

if (f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s %s\n",ch1,ch2,ch3,ch4,ch5,ch6)!=EOF)
{if (strcmp(identite,ch3)==0)
  {strcpy(ch222," Le produit  ");
strcat(ch222,ch1);
strcat(ch222," d identite ");
strcat(ch222,ch3);
strcat(ch222, " de poids ");
strcat(ch222,ch4);
strcat(ch222, "d unite  ");
strcat(ch222,ch5);
strcat(ch222, "  ");
strcat(ch222,ch6);}
}
fclose(f);
}
}
/*
while(fscanf(f,"%s %s %s %s %s %s\n",ch1,ch2,ch3,ch4,ch5,ch6)!=EOF)
{if (strcmp(identite,ch3)==0){strcpy(ch222," le produit ");
strcat(ch222,ch1);
strcat(ch222,"  de type ");
strcat(ch222,ch2);
strcat(ch222,"\n  d identite ");
strcat(ch222,ch3);
strcat(ch222, "  de poids : ");
strcat(ch222,ch4);
strcat(ch222, "\n  d unite  ");
strcat(ch222,ch5);}else{strcpy(ch222,"produit n est pas trouver");}
}
*/


/****************************************************************************************************************/

enum
{
PRODUIT,
TYPE,
IDENT,
POIDS,
UNITE,
DANS,
COLUMNS,
};
void afiche_prod1(GtkWidget *liste)
{      
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char ch11[50],ch22[50],ch33[50],ch44[50],ch55[50],ch66[50];
store=NULL;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("produit",renderer,"text",PRODUIT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("ident",renderer,"text",IDENT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("poids",renderer,"text",POIDS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("unite",renderer,"text",UNITE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("dans",renderer,"text",DANS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

}

store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
FILE *f=NULL;
/*f=fopen("stock.txt","r");
if (f!=NULL)
*/
f=fopen("stock.txt","a+");
while(fscanf(f,"%s %s %s %s %s %s\n",ch11,ch22,ch33,ch44,ch55,ch66)!=EOF)
{gtk_list_store_append(store, &iter);
gtk_list_store_set(store, &iter, PRODUIT, ch11, TYPE, ch22, IDENT, ch33, POIDS, ch44, UNITE, ch55, DANS, ch66, -1);}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);

}
/***********************************************************************************************************/
void alarme_rupture(char ch222[])
{
int n1,b=0;
char ch1[50];
char ch2[50];
char ch3[50];
char ch4[50];
char ch5[50];
char ch6[50];
FILE *f=NULL;
f=fopen("stock.txt","r");
strcpy(ch222,"");
if (f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s %s\n",ch1,ch2,ch3,ch4,ch5,ch6)!=EOF)
{if (strcmp(ch4,"0")==0)
  {b=1;
strcpy(ch222," le produit ");
strcat(ch222,ch1);
strcat(ch222," de type ");
strcat(ch222,ch2);
strcat(ch222,"\n d identite ");
strcat(ch222,ch3);
strcat(ch222, " de poids : ");
strcat(ch222,ch4);
strcat(ch222, "\n d unite  ");
strcat(ch222,ch5);
strcat(ch222, "  ");
strcat(ch222,ch6);
strcat(ch222, " est en repture ");
}
}
}
fclose(f);

}


