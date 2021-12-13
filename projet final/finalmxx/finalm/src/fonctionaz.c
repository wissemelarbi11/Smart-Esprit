#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctionaz.h"
#include <gtk/gtk.h>


enum{
	NOM,
	PRENOM,
	ID,
	TYPE,
	SEXE,
	JOUR,
	MOIS,
	ANNEE,
	ROLE,
	TEXTE,	
	COLUMNS,	
};


//fFonction ajouter

void ajt_r(rec r){

	FILE *f;
int v=1;
	f = fopen("fichieraz.txt","a+");
	if(v==1){

		fprintf(f,"%s %s %s %s %s %d %d %d %s %s \n",r.nom,r.prenom,r.id,r.type, r.sexe,r.d.jour,r.d.mois,r.d.annee, r.role,r.texte);

		fclose(f);
	}
}



//Fonction afficher rec rechercher

void affichage_rechercheraz(GtkWidget *liste)
{
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;

	char nom [30];
	char prenom [30];
	char id[30];
        char type[30];
	char sexe[30];
 	char jour[30];
	char mois[30];
	char annee[30];
  	char role[30];
	char texte[50];

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
	column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
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
	column=gtk_tree_view_column_new_with_attributes("role",renderer,"text",ROLE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("texte",renderer,"text",TEXTE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	

	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f = fopen("fichieraz.txt","r");
	if(f==NULL){
		return;
	}
	else{
		f = fopen("fichieraz.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s",nom,prenom,id,type,sexe,jour,mois,annee,role,texte)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,NOM,nom,PRENOM,prenom,ID,id,TYPE,type, SEXE,sexe,JOUR,jour,MOIS,mois,ANNEE,annee, ROLE, role, TEXTE, texte,-1);
		}
		fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		g_object_unref(store);
	}
   }
}





//Fonction afficher

void aff_tr(GtkWidget *liste)
{

	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	char nom [30];
	char prenom [30];
	char id[30];
        char type[30];
	char sexe[30];
 	char jour[30];
	char mois[30];
	char annee[30];
  	char role[30];
	char texte[50];


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
	column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
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
	column=gtk_tree_view_column_new_with_attributes("role",renderer,"text",ROLE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("texte",renderer,"text",TEXTE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	f = fopen("azfichier.txt","r");
	if(f==NULL){
		return;
	}
	else{
		f = fopen("azfichier.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s",nom,prenom,id,type,sexe,jour,mois,annee,role,texte)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,NOM,nom,PRENOM,prenom,ID,id,TYPE,type, SEXE,sexe,JOUR,jour,MOIS,mois,ANNEE,annee, ROLE, role, TEXTE, texte,-1);
		}
		fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		g_object_unref(store);
	}
   }
}


//Fonction supprimer

void sup_r(rec r){

    char nom [30];
	char prenom [30];
	char id[30];
    char type[30];
	char sexe[30];
 	char jour[30];
	char mois[30];
	char annee[30];
  	char role[30];
	char texte[50];
	FILE *f,*t;
	f = fopen("azfichier.txt","r");
	t = fopen("temp.txt","w");
	if(f==NULL || t==NULL){
		return;
	}
	else{
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s",nom,prenom,id,type,sexe,jour,mois,annee,role,texte)!=EOF){

		if(strcmp(r.id,id)!=0)
			fprintf(t,"%s %s %s %s %s %s %s %s %s %s \n",nom,prenom,id,type,sexe,jour,mois,annee,role,texte);
		}

		fclose(f);
		fclose(t);
		remove("azfichier.txt");
		rename("temp.txt","azfichier.txt");
	}	
}

//Fonction modifier

void modf_r(rec r)
{

	   char nom [30];
	char prenom [30];
	char id[30];
    char type[30];
	char sexe[30];
 	char jour[30];
	char mois[30];
	char annee[30];
  	char role[30];
	char texte[50];

	FILE *f,*t;
	f = fopen("azfichier.txt","r");
	t = fopen("temp.txt","a+");

	if(f!=NULL){
	while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s",nom,prenom,id,type,sexe,jour,mois,annee,role,texte)!=EOF)
	{
		if(strcmp(r.id,id)==0)
		{
		fprintf(t,"%s %s %s %s %s %d %d %d %s %s \n",r.nom,r.prenom,r.id,r.type, r.sexe,r.d.jour,r.d.mois,r.d.annee, r.role,r.texte);
		}
		else
		fprintf(t,"%s %s %s %s %s %s %s %s %s %s \n",nom,prenom,id,type,sexe,jour,mois,annee,role,texte);

	}
	}
		fclose(f);


		fclose(t);
		remove("azfichier.txt");
		rename("temp.txt","azfichier.txt");

}



//Fonction Chercher


void rechercheraz(rec r,char id1[30])
{
	char nom[30];
    	char prenom[30];
	char id[30];
    	char type[30];
    	char sexe[30];
    	char jour[30];
	    char mois[30];
	    char annee[30];
    	char role[30];
	char texte[50];

FILE *f;
FILE *f1;
f = fopen("azfichier.txt","r");
f1 = fopen("tr.txt","w");

while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s",nom,prenom,id,type,sexe,jour,mois,annee,role,texte)!=EOF)
	{
        

	if(strcmp(id,id1)==0)
		{
		fprintf(f1,"%s %s %s %s %s %s %s %s %s %s\n",nom,prenom,id,type,sexe,jour,mois,annee,role,texte);
		}

	

    }
fclose(f);
fclose(f1);
remove("az.txt");
rename("tr.txt","az.txt");
}


//Nombre des reclamations

int nombre_rec()
{
  FILE *f;
  FILE *b;
  
  f = fopen("azfichier.txt","r");
  b = fopen("foyer.txt","w");
  

  rec r;
  int i=0;

  int x;
  
  char foyer[10] = "foyer";
  char nom[30];
  char prenom[30];
  char id[30];
  char type[30];
  char sexe[30];
  char jour[30];
  char mois[30];
  char annee[30];
  char role[30];
  char texte[50];

  if(f != NULL)
	{
		
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s ",nom,prenom,id,type,sexe,jour,mois,annee,role,texte)!=EOF)
			{
			i+=1;
			}
		
	}
	return i;
}		

//Nombre des restos

int nombre_resto()
{

  char nom[30];
  char prenom[30];
  char id[30];
  char type[30];
  char sexe[30];
  char jour[30];
  char mois[30];
  char annee[30];
  char role[30];
  char texte[50];
		
	FILE *f;
	f = fopen("azfichier.txt","r");
	FILE *v;
	v = fopen("resto.txt","w");
	char resto[10] = "resto";
	rec r;
	int iv;

if(f != NULL)
	{

	while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s",nom,prenom,id,type,sexe,jour,mois,annee,role,texte)!=EOF)
		{
			if((strcmp(type, resto))==0)
			{		
			fprintf(v,"%s %s %s %s %s %s %s %s %s %s\n",nom,prenom,id,type,sexe,jour,mois,annee,role,texte);

			}
		}
	fclose(f);
	fclose(v);
	v = fopen("resto.txt","r");
	while(fscanf(v,"%s %s %s %s %s %s %s %s %s %s",nom,prenom,id,type,sexe,jour,mois,annee,role,texte)!=EOF)
			{
			iv+=1;
			}	
	}
	return iv;
}

//Nombre des foyer


int nombre_foyer()
{

    char nom[30];
    char prenom[30];
    char id[30];
    char type[30];
    char sexe[30];
    char jour[30];
    char mois[30];
    char annee[30];
    char role[30];
    char texte[50];
  		
	FILE *f;
	f = fopen("azfichier.txt","r");
	FILE *b;
	b = fopen("foyer.txt","w");
	char foyer[10] = "foyer";
	rec r;
	int ib;

if(f != NULL)
	{
	while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s",nom,prenom,id,type,sexe,jour,mois,annee,role,texte)!=EOF)
		{
			if((strcmp(type, foyer))==0)
			{		

			fprintf(b,"%s %s %s %s %s %s %s %s %s %s\n",nom,prenom,id,type,sexe,jour,mois,annee,role,texte);
			
			}
		}
	fclose(f);
	fclose(b);
	b = fopen("foyer.txt","r");
	while(fscanf(b,"%s %s %s %s %s %s %s %s %s %s",nom,prenom,id,type,sexe,jour,mois,annee,role,texte)!=EOF)
			{
			ib+=1;
			}	
	}
	return ib;
}		
		
			

//Nombre des reclamation etudiants

int rec_etudiant()
{
  FILE *f;
  FILE *v;
  f = fopen("azfichier.txt","r");
  v = fopen("etudiant.txt","w");

  rec r;
  int i;
  char etat1[30] = "etudiant";
 char nom[30];
  char prenom[30];
  char id[30];
  char type[30];
  char sexe[30];
  char jour[30];
  char mois[30];
  char annee[30];
  char role[30];
  char texte[50];

  if(f != NULL)
  {

 	while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s",nom,prenom,id,type,sexe,jour,mois,annee,role,texte)!=EOF)
	{			
		if((strcmp(role,etat1))==0)
		{		
			fprintf(v,"%s %s %s %s %s %s %s %s %s %s\n",nom,prenom,id,type,sexe,jour,mois,annee,role,texte);
			
		}
	}
	fclose(f);
	fclose(v);
	v = fopen("etudiant.txt","r");
	while(fscanf(v,"%s %s %s %s %s %s %s %s %s %s",nom,prenom,id,type,sexe,jour,mois,annee,role,texte)!=EOF)
			{
			i+=1;
			}


  }
	return i;
}
