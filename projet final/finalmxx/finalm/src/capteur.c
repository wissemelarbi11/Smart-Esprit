#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "capteur.h"
#include "callbacks.h"
#include <gtk/gtk.h>

enum
{
	ID,
	TYPE,
	BLOC,
	MARQUE,
	DATE,
	COLUMNS
};

enum
{
	JOUR,
	HEURE,
	ID1,
	VALEUR,
	COLUMNS1
};

void ajoutergh(capteur u, char *fname){
GtkWidget *pQuestion, *pInfo;
FILE *f;
int b=0;
gpointer user_data;
capteur p;
f=fopen(fname,"a+");
if(f!=NULL)
{	while(fscanf(f,"%s %d %s %s %d %d %d\n",p.id,&(p.type),p.bloc,p.marque,&(p.d.j),&(p.d.m),&(p.d.a))!=EOF)
	{	
		if(strcmp(u.id,p.id)==0)
		b++;
	}
	if(b==0){
	fprintf(f,"%s %d %s %s %d %d %d\n",u.id,u.type,u.bloc,u.marque,u.d.j,u.d.m,u.d.a);
	pQuestion=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Capteur ajouté avec succès !");
	switch(gtk_dialog_run(GTK_DIALOG(pQuestion)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pQuestion);
	break;
	}
	}
	if(b!=0){
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_WARNING,GTK_BUTTONS_OK,"Capteur déja existant !");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	}
	fclose(f);
}
}

void modifiergh(capteur u, char *fname){
capteur p;
GtkWidget *pInfo;
gpointer user_data;
FILE *f, *g;
f=fopen(fname,"r");
g=fopen("dump.txt","w");
if(f==NULL||g==NULL)
{
	return;
}
else{
	while(fscanf(f,"%s %d %s %s %d %d %d\n",p.id,&(p.type),p.bloc,p.marque,&(p.d.j),&(p.d.m),&(p.d.a))!=EOF)
	{
		if(strcmp(p.id,u.id)!=0)
			fprintf(g,"%s %d %s %s %d %d %d\n",p.id,p.type,p.bloc,p.marque,p.d.j,p.d.m,p.d.a);
		else
			fprintf(g,"%s %d %s %s %d %d %d\n",p.id,u.type,u.bloc,u.marque,p.d.j,p.d.m,p.d.a);
	}
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Capteur modifié avec succès !");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	fclose(f);
	fclose(g);
remove(fname);
rename("dump.txt",fname);
}
}

void affichergh(GtkWidget *liste, char *fname)
{
capteur p;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
gchar date_achat[50], type[20];
FILE *f;


store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" ID", renderer,"text",ID, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Type", renderer,"text",TYPE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Bloc", renderer,"text",BLOC, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Marque", renderer,"text",MARQUE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_resizable(column,TRUE);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Date d'achat", renderer,"text",DATE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);



store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen(fname,"r");
if(f!=NULL)

{ f = fopen(fname,"a+");
		while(fscanf(f,"%s %d %s %s %d %d %d\n",p.id,&(p.type),p.bloc,p.marque,&(p.d.j),&(p.d.m),&(p.d.a))!=EOF)
	{
sprintf(date_achat,"%d/%d/%d",p.d.j,p.d.m,p.d.a);
sprintf(type,p.type==0?"Température":p.type==1?"Débit d'eau":p.type==2?"Mouvement":"Fumée");
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,ID,p.id,TYPE,type,BLOC,p.bloc,MARQUE,p.marque,DATE,date_achat,-1);
	}
	fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
gtk_tree_view_set_enable_search(GTK_TREE_VIEW(liste),TRUE);
}

void supprimergh(capteur u, char *fname)
{
capteur p;
GtkWidget *pInfo;
gpointer user_data;
FILE *f, *g;
f=fopen(fname,"r");
g=fopen("dump.txt","w");
if(f!=NULL&&g!=NULL){
	while(fscanf(f,"%s %d %s %s %d %d %d\n",p.id,&(p.type),p.bloc,p.marque,&(p.d.j),&(p.d.m),&(p.d.a))!=EOF)
	{
		if(strcmp(p.id,u.id)!=0)
			fprintf(g,"%s %d %s %s %d %d %d\n",p.id,p.type,p.bloc,p.marque,p.d.j,p.d.m,p.d.a);
	}
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Capteur supprimé avec succès");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	fclose(f);
	fclose(g);
remove(fname);
rename("dump.txt",fname);
}
}

void alarme(GtkWidget *liste, char *fname, char *fname1)
{
mesure p;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
gchar statut[20];
FILE *f, *g;


store=gtk_tree_view_get_model(liste);
if(store==NULL)
{

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Jour", renderer,"text",JOUR, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Heure", renderer,"text",HEURE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" ID", renderer,"text",ID1, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Valeur", renderer,"text",VALEUR, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);



store=gtk_list_store_new(COLUMNS1, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING);
f=fopen(fname,"r");
if(f!=NULL)
{
		while(fscanf(f,"%d %d %d %d\n",&(p.jour),&(p.heure),&(p.id),&(p.valeur))!=EOF)
	{
if(p.valeur==1&&p.heure>=0&&p.heure<6){
sprintf(statut,"Mouvement");
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,JOUR,p.jour,HEURE,p.heure,ID1,p.id,VALEUR,statut,-1);
}
	}
	fclose(f);
g=fopen(fname1,"r");
if(f!=NULL)
{
		while(fscanf(g,"%d %d %d %d\n",&(p.jour),&(p.heure),&(p.id),&(p.valeur))!=EOF)
	{
if(p.valeur==1&&p.heure>=0&&p.heure<6){
sprintf(statut,"Fumée");
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,JOUR,p.jour,HEURE,p.heure,ID1,p.id,VALEUR,statut,-1);
}
	}
	fclose(g);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
}
gtk_tree_view_set_enable_search(GTK_TREE_VIEW(liste),TRUE);
}

