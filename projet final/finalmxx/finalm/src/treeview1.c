#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treeview1.h"
#include <gtk/gtk.h>

enum
{
EPTIDEJ,
EPTIDEJ1,
EPTIDEJ2,
EDEJ,
EDEJ1,
EDEJ2,
EDINNER,
EDINNER1,
EDINNER2,
ESEMAINE,
EJOUR,
COLUMNS,
};




void ajouter_menu(menu m)
{
FILE *f;
// ouvrir le fichier :
f=fopen("zutilisateur.txt","a+");

if (f!=NULL)
{
// ecrire dans le ficher
fprintf(f,"%s %s %s %s %s %s %s %s %s %s %s  \n",m.semaine,m.jour,m.ptidej,m.ptidej1,m.ptidej2,m.dej,m.dej1,m.dej2,m.dinner,m.dinner1,m.dinner2);
fclose(f);
}
}


void afficher_menu(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char semaine[30];
char jour[30];

char entree[30];
char repas_principal[30];
char dessert[30];

char entree1[30];
char repas_principal1[30];
char dessert1[30];

char entree2[30];
char repas_principal2[30];
char dessert2[30];



store=NULL;
menu m;
FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("semaine",renderer, "text",ESEMAINE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("jour",renderer, "text",EJOUR,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("entree",renderer, "text",EPTIDEJ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("repas_principal",renderer, "text",EPTIDEJ1,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("dessert",renderer, "text",EPTIDEJ2,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);



renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("entree1",renderer, "text",EDEJ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("repas_principal1",renderer, "text",EDEJ1,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("dessert1",renderer, "text",EDEJ2,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("entree2",renderer, "text",EDINNER,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("repas_principal2",renderer, "text",EDINNER1,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("dessert2",renderer, "text",EDINNER2,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
}

store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING );
f=fopen("zutilisateur.txt","r");
if(f==NULL)
{return;}
else
{
f= fopen("zutilisateur.txt","a+");
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s \n",semaine,jour,entree,repas_principal,dessert,entree1,repas_principal1,dessert1,entree2,repas_principal2,dessert2)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter,ESEMAINE, semaine, EJOUR, jour, EPTIDEJ, entree, EPTIDEJ1, repas_principal, EPTIDEJ2, dessert,EDEJ , entree1,EDEJ1 , repas_principal1,EDEJ2 , dessert1, EDINNER,entree2, EDINNER1,repas_principal2, EDINNER2,dessert2,-1);
}
fclose(f);
gtk_tree_view_set_model( GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref (store);
gtk_tree_view_set_enable_search(GTK_TREE_VIEW(liste),TRUE);
}




}

void supprimer_menu(menu m)
{
	
	FILE *f,*g;
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
	f=fopen("zutilisateur.txt","r");
	g=fopen("dump.txt","a+");
	if(f==NULL)
		{
			return;
		}
	else
		{
			while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s  \n",semaine,jour,ptidej,ptidej1,ptidej2,dej,dej1,dej2,dinner,dinner1,dinner2)!=EOF)
				{
			if( strcmp(m.semaine,semaine)!=0 || strcmp(m.jour,jour)!=0 )
fprintf(g,"%s %s %s %s %s %s %s %s %s %s %s \n",m.semaine,m.jour,ptidej,ptidej1,ptidej2,dej,dej1,dej2,dinner,dinner1,dinner2);
				}
fclose(f);
fclose(g);

}
}









void afficher_menu2(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char semaine[30];
char jour[30];

char entree[30];
char repas_principal[30];
char dessert[30];

char entree1[30];
char repas_principal1[30];
char dessert1[30];

char entree2[30];
char repas_principal2[30];
char dessert2[30];



store=NULL;
menu m;
FILE *f;
FILE *f1;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("semaine",renderer, "text",ESEMAINE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("jour",renderer, "text",EJOUR,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("entree",renderer, "text",EPTIDEJ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("repas_principal",renderer, "text",EPTIDEJ1,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("dessert",renderer, "text",EPTIDEJ2,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);



renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("entree1",renderer, "text",EDEJ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("repas_principal1",renderer, "text",EDEJ1,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("dessert1",renderer, "text",EDEJ2,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("entree2",renderer, "text",EDINNER,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("repas_principal2",renderer, "text",EDINNER1,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("dessert2",renderer, "text",EDINNER2,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
}

store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING );
f=fopen("zutilisateur.txt","r");
if(f==NULL)
{return;}
else
{
f1= fopen("zchercher.txt","a+");
while(fscanf(f1,"%s %s %s %s %s %s %s %s %s %s %s \n",semaine,jour,entree,repas_principal,dessert,entree1,repas_principal1,dessert1,entree2,repas_principal2,dessert2)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter,ESEMAINE, semaine, EJOUR, jour, EPTIDEJ, entree, EPTIDEJ1, repas_principal, EPTIDEJ2, dessert,EDEJ , entree1,EDEJ1 , repas_principal1,EDEJ2 , dessert1, EDINNER,entree2, EDINNER1,repas_principal2, EDINNER2,dessert2,-1);
}
fclose(f);
fclose(f1);
gtk_tree_view_set_model( GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}

}


void chercher_menu(menu m,char j[20])
{



FILE *f;
FILE *f1;
// ouvrir le fichier :
f=fopen("zutilisateur.txt","r");
f1=fopen("zchercher.txt","a+");


if (f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s \n",m.semaine,m.jour,m.ptidej,m.ptidej1,m.ptidej2,m.dej,m.dej1,m.dej2,m.dinner,m.dinner1,m.dinner2)!=EOF)
{
    if (strcmp(m.jour,j) == 0)
   {
  

    fprintf(f1,"%s %s %s %s %s %s %s %s %s %s %s \n",m.semaine,j,m.ptidej,m.ptidej1,m.ptidej2,m.dej,m.dej1,m.dej2,m.dinner,m.dinner1,m.dinner2);
   }

}
  }  
fclose(f);
fclose(f1);

}






int meilleur_menu(int semaine)
{

    FILE *f;
FILE *f1;
FILE *g;
int j1,r1,n,z,b1,b3=1,c=0,day=0,c1=0,j=1;
float d1,somme=0,min=2000,b2;




if (semaine==1)
    n=8;

if (semaine==2)
    n=15;

if (semaine==3)
    n=22;

if (semaine==4)
    n=29;

if (semaine==5)
    n=36;

f=fopen("dechets.txt","a+");
g=fopen("z2.txt","a+");
f1=fopen("z1.txt","a+");

if (f!=NULL)
while(fscanf(f,"%d %d %f.2 \n",&j1,&r1,&d1)!=EOF)
{c++;
 somme=somme+d1;
if (c==3)
{
day++;
fprintf(f1,"%d %f \n",day,somme);
somme=0;
c=0;
}
}
fclose(f);
fclose(f1);
f1=fopen("z1.txt","a+");


while(fscanf(f1,"%d %f \n",&day,&somme)!=EOF)
{
    if(day>(n-8) && day<n)
{
 fprintf(g,"%d %f \n",b3,somme);
 b3++;
}

}
fclose(g);
g=fopen("z2.txt","r");
while(fscanf(g,"%d %f \n",&b1,&b2)!=EOF)
{

    if(b2<min)
 { min=b2;

 }

}

 fclose(g);
g=fopen("z2.txt","r");

while(fscanf(g,"%d %f \n",&b1,&b2)!=EOF)
{

    if(min==b2)
 {break;}
}
z=b1;





   fclose(f1);
   fclose(g);
    remove("z1.txt");
   remove("z2.txt");
   return z;
}

