#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctionseif.h"
#include <gtk/gtk.h>

enum{
	NOM,
	PRENOM,
	ID,
	NIVEAU,
	SEXE,
	JOUR,
	MOIS,
	ANNEE,
	CLASSE,
	BLOC,	
	COLUMNS,	
};


//----------Fonction ajouter------------//

void ajt_e(etudiant e){

	FILE *f;
	f = fopen("fichier.txt","a+");
	if(f!=NULL){

		fprintf(f,"%s %s %s %s %s %d %d %d %s %s\n",e.nom,e.prenom,e.id,e.niveau, e.sexe,e.d.jour,e.d.mois,e.d.annee, e.classe,e.bloc);

		fclose(f);
	}
}



//----------Fonction afficher etudiant rechercher------------//

void affichage_rechercher(GtkWidget *liste)
{
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
	char nom[30];
	char prenom[30];
	char id[30];
    char niveau[30];
	char sexe[30];
 	char jour[30];
	char mois[30];
	char annee[30];
  	char classe[30];
	char bloc[30];

	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model(liste);
	if(store==NULL){
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("id",renderer,"text",ID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("niveau",renderer,"text",NIVEAU,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",SEXE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer = gtk_cell_renderer_text_new();
    	column = gtk_tree_view_column_new_with_attributes("jour",renderer,"text",JOUR,NULL);
    	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    	renderer = gtk_cell_renderer_text_new();
    	column = gtk_tree_view_column_new_with_attributes("mois",renderer,"text",MOIS,NULL);
    	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    	renderer = gtk_cell_renderer_text_new();
   	 column = gtk_tree_view_column_new_with_attributes("annee",renderer,"text",ANNEE,NULL);
   	 gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("classe",renderer,"text",CLASSE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("bloc",renderer,"text",BLOC,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f = fopen("tr1.txt","r");
	if(f==NULL){
		return;
	}
	else{
		f = fopen("tr1.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s\n",nom,prenom,id,niveau,sexe,jour,mois,annee,classe,bloc)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,NOM,nom,PRENOM,prenom,ID,id,NIVEAU,niveau, SEXE,sexe,JOUR,jour,MOIS,mois,ANNEE,annee, CLASSE,classe,BLOC,bloc,-1);
		}
		fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		g_object_unref(store);
	}
   }
}





//----------Fonction afficher------------//

void aff_e(GtkWidget *liste)
{

	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char nom [30];
	char prenom [30];
	char id[30];
    	char niveau[30];
    	char sexe[30];
    	char jour[30];
	char mois[30];
	char annee[30];
    	char classe[30];
	char bloc[30];

	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model(liste);
	if(store==NULL){

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("id",renderer,"text",ID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("niveau",renderer,"text",NIVEAU,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",SEXE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer = gtk_cell_renderer_text_new();
    	column = gtk_tree_view_column_new_with_attributes("jour",renderer,"text",JOUR,NULL);
    	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    	renderer = gtk_cell_renderer_text_new();
    	column = gtk_tree_view_column_new_with_attributes("mois",renderer,"text",MOIS,NULL);
    	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    	renderer = gtk_cell_renderer_text_new();
   	 column = gtk_tree_view_column_new_with_attributes("annee",renderer,"text",ANNEE,NULL);
   	 gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("classe",renderer,"text",CLASSE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("bloc",renderer,"text",BLOC,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f = fopen("fichier.txt","r");
	if(f==NULL){
		return;
	}
	else{
		f = fopen("fichier.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s\n",nom,prenom,id,niveau,sexe,jour,mois,annee,classe,bloc)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,NOM,nom,PRENOM,prenom,ID,id,NIVEAU,niveau, SEXE,sexe,JOUR,jour,MOIS,mois,ANNEE,annee, CLASSE,classe,BLOC,bloc,-1);
		}
		
		fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		g_object_unref(store);
	}
   }
}


//----------Fonction supprimer------------//

void sup_e(etudiant e){
	char nom [30];
	char prenom [30];
	char id[30];
    	char niveau[30];
    	char sexe[30];
    	char jour[30];
	char mois[30];
	char annee[30];
    	char classe[30];
	char bloc[30];
	FILE *f,*t;
	f = fopen("fichier.txt","r");
	t = fopen("temp.txt","w");
	if(f==NULL || t==NULL){
		return;
	}
	else{
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s\n",nom,prenom,id,niveau,sexe,jour,mois,annee,classe,bloc)!=EOF)
		{

		if(strcmp(e.id,id)!=0)
			fprintf(t,"%s %s %s %s %s %s %s %s %s %s\n",nom,prenom,id,niveau,sexe,jour,mois,annee,classe,bloc);
		}

		fclose(f);
		fclose(t);
		remove("fichier.txt");
		rename("temp.txt","fichier.txt");
	}	
}

//----------Fonction modifier------------//

void modf_e(etudiant e)
{
	char nom [30];
	char prenom [30];
	char id[30];
    	char niveau[30];
    	char sexe[30];
    	char jour[30];
	char mois[30];
	char annee[30];
    	char classe[30];
	char bloc[30];

	FILE *f,*t;
	f = fopen("fichier.txt","r");
	t = fopen("temp.txt","w");

	if(f!=NULL){
	while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s\n",nom,prenom,id,niveau,sexe,jour,mois,annee,classe,bloc)!=EOF)
	{
		if(strcmp(e.id,id)==0)
		{
		fprintf(t,"%s %s %s %s %s %d %d %d %s %s \n",e.nom,e.prenom,e.id,e.niveau, e.sexe,e.d.jour,e.d.mois,e.d.annee, e.classe,e.bloc);
		}
		else
		fprintf(t,"%s %s %s %s %s %s %s %s %s %s\n",nom,prenom,id,niveau,sexe,jour,mois,annee,classe,bloc);

	}
	}
		fclose(f);
		fclose(t);
	remove("fichier.txt");
	rename("temp.txt","fichier.txt");

}



//-----------Fonction Chercher---------------//


void rechercher(etudiant e,char id1[30])
{
	char nom [30];
	char prenom [30];
	char id[30];
    	char niveau[30];
    	char sexe[30];
    	char jour[30];
	char mois[30];
	char annee[30];
    	char classe[30];
	char bloc[30];

FILE *f;
FILE *f1;
f = fopen("fichier.txt","r");
f1 = fopen("tr.txt","w");

while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s\n",nom,prenom,id,niveau,sexe,jour,mois,annee,classe,bloc)!=EOF)
	{
        if(strcmp(id,id1)==0)
		{
		fprintf(f1,"%s %s %s %s %s %s %s %s %s %s\n",nom,prenom,id,niveau,sexe,jour,mois,annee,classe,bloc);
		}
	

    }
fclose(f);
fclose(f1);
remove("tr1.txt");
rename("tr.txt","tr1.txt");
}


//--------Nombre des etudiant---------//

int nombre_etudiant()
{
  FILE *f;
  FILE *b;
  
  f = fopen("fichier.txt","r");
  b = fopen("etage1.txt","w");
  

  etudiant tr;
  int i=0;

  int x;
  
  char etage1[10] = "etage1";
 char nom [30];
	char prenom [30];
	char id[30];
    	char niveau[30];
    	char sexe[30];
    	char jour[30];
	char mois[30];
	char annee[30];
    	char classe[30];
	char bloc[30];

  if(f != NULL)
	{
		
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s\n",nom,prenom,id,niveau,sexe,jour,mois,annee,classe,bloc)!=EOF)
			{
			i+=1;
			}
		
	}
	return i;
}		

//----------Nombre des etage2------------//

int nombre_etage2()
{

	   char nom [30];
	char prenom [30];
	char id[30];
    	char niveau[30];
    	char sexe[30];
    	char jour[30];
	char mois[30];
	char annee[30];
    	char classe[30];
	char bloc[30];
		
	FILE *f;
	f = fopen("fichier.txt","r");
	FILE *v;
	v = fopen("etage2.txt","w");
	char etage2[10] = "etage2";
	etudiant e;
	int e2;

if(f != NULL)
	{

	while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s\n",nom,prenom,id,niveau,sexe,jour,mois,annee,classe,bloc)!=EOF)
		{
			if((strcmp(niveau, etage2))==0)
			{		
			fprintf(v,"%s %s %s %s %s %s %s %s %s %s\n",nom,prenom,id,niveau,sexe,jour,mois,annee,classe,bloc);

			}
		}
	fclose(f);
	fclose(v);
	v = fopen("etage2.txt","r");
	while(fscanf(v,"%s %s %s %s %s %s %s %s %s %s\n",nom,prenom,id,niveau,sexe,jour,mois,annee,classe,bloc)!=EOF)
			{
			e2+=1;
			}	
	}
	return e2;
}

//------------Nombre des etage1----------//


int nombre_etage1()
{

     char nom [30];
	char prenom [30];
	char id[30];
    	char niveau[30];
    	char sexe[30];
    	char jour[30];
	char mois[30];
	char annee[30];
    	char classe[30];
	char bloc[30];	
		
	FILE *f;
	f = fopen("fichier.txt","r");
	FILE *b;
	b = fopen("etage1.txt","w");
	char etage1[10] = "etage1";
	etudiant e;
	int e1;

if(f != NULL)
	{
	while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s\n",nom,prenom,id,niveau,sexe,jour,mois,annee,classe ,bloc)!=EOF)
		{
			if((strcmp(niveau, etage1))==0)
			{		

			fprintf(b,"%s %s %s %s %s %s %s %s %s %s\n",nom,prenom,id,niveau,sexe,jour,mois,annee,classe,bloc);
			
			}
		}
	fclose(f);
	fclose(b);
	b = fopen("etage1.txt","r");
	while(fscanf(b,"%s %s %s %s %s %s %s %s %s %s\n",nom,prenom,id,niveau,sexe,jour,mois,annee,classe,bloc)!=EOF)
			{
			e1+=1;
			}	
	}
	return e1;
}		
		
			



