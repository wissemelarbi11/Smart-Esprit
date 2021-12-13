#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"

#include "fonction.h"
#include "fonctionseif.h"
#include "treeview1.h"
#include "fonctionaz.h"
#include "utilisateur.h"
#include "capteur.h"
#include "fonctionahmadac.h"
int x,y,z,a,b,c;
etudiant selected_tr;
rec selected_ttr;
char repture1[200] ;

int t[4]={0,0,0,0};
void
on_treeview1z_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter , *pInfo;
gchar* jour;
gchar* semaine;
gchar* ptidej;
gchar* ptidej1;
gchar* ptidej2;

gchar* dej;
gchar* dej1;
gchar* dej2;


gchar* dinner;
gchar* dinner1;
gchar* dinner2;

menu m;
GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model, &iter, path))
{
gtk_tree_model_get (GTK_LIST_STORE(model), &iter ,0, &semaine ,1, &jour ,2,  &ptidej ,3, &ptidej1 ,4, &ptidej2 ,5, &dej ,6, &dej1 ,7 , &dej2 , 8 , &dinner ,9 ,&dinner1 ,10 , &dinner2 ,-1);

strcpy(m.semaine,semaine);
strcpy(m.jour,jour);
strcpy(m.ptidej,ptidej);
strcpy(m.ptidej1,ptidej1);
strcpy(m.ptidej2,ptidej2);
strcpy(m.dej,dej);
strcpy(m.dej1,dej1);
strcpy(m.dej2,dej2);

strcpy(m.dinner,dinner);
strcpy(m.dinner1,dinner1);
strcpy(m.dinner2,dinner2);

pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_QUESTION,GTK_BUTTONS_YES_NO,"Voulez-vous vraiment\nsupprimer ce capteur?");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_YES:
	gtk_widget_destroy(pInfo);
supprimer_menu(m);
afficher_menu(treeview);
break;
}


}
}


void
on_ajouter1z_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajouterz2 , *bienvenuez;
ajouterz2=create_ajouterz2();
gtk_widget_show (ajouterz2);
bienvenuez=lookup_widget(objet,"bienvenuez");
gtk_widget_destroy(bienvenuez);
}


void
on_modifier1z_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *modifierz3 , *bienvenuez;
modifierz3=create_modifierz3();
gtk_widget_show (modifierz3);
bienvenuez=lookup_widget(objet,"bienvenuez");
gtk_widget_destroy(bienvenuez);
}





void
on_supprimer1z_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *supprimerz4 , *bienvenuez;
supprimerz4=create_supprimerz4();
gtk_widget_show (supprimerz4);
bienvenuez=lookup_widget(objet,"bienvenuez");
gtk_widget_destroy(bienvenuez);
}


void
on_actualiser1z_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview1z;
treeview1z=lookup_widget(button,"treeview1z");
afficher_menu(treeview1z);

}


void
on_rechercher1z_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *chercherz6 ,*bienvenuez;
chercherz6=create_chercherz6();
gtk_widget_show (chercherz6);
bienvenuez=lookup_widget(objet,"bienvenuez");
gtk_widget_destroy(bienvenuez);
}


void
on_treeview2z_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* jour;
gchar* semaine;
gchar* ptidej;
gchar* ptidej1;
gchar* ptidej2;
GtkWidget *pInfo;
gchar* dej;
gchar* dej1;
gchar* dej2;


gchar* dinner;
gchar* dinner1;
gchar* dinner2;

menu m;
GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model, &iter, path))
{
gtk_tree_model_get (GTK_LIST_STORE(model), &iter ,0, &semaine ,1, &jour ,2,  &ptidej ,3, &ptidej1 ,4, &ptidej2 ,5, &dej ,6, &dej1 ,7 , &dej2 , 8 , &dinner ,9 ,&dinner1 ,10 , &dinner2 ,-1);

strcpy(m.semaine,semaine);
strcpy(m.jour,jour);
strcpy(m.ptidej,ptidej);
strcpy(m.ptidej1,ptidej1);
strcpy(m.ptidej2,ptidej2);
strcpy(m.dej,dej);
strcpy(m.dej1,dej1);
strcpy(m.dej2,dej2);

strcpy(m.dinner,dinner);
strcpy(m.dinner1,dinner1);
strcpy(m.dinner2,dinner2);
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_QUESTION,GTK_BUTTONS_YES_NO,"Voulez-vous vraiment\n supprimer ce menu?");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_YES:
	gtk_widget_destroy(pInfo);
supprimer_menu(m);
afficher_menu2(treeview);
break;
}

}
}


void
on_ajouter2z_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ptidej , *ptidej1 , *ptidej2 , *dej , *dej1 , *dej2 , *dinner , *dinner1 , *dinner2;
GtkWidget *ajouterz2;
GtkWidget *bienvenuez;
GtkWidget *treeview1z;
menu m;
ajouterz2=lookup_widget(objet,"ajouterz2");
if(x==1)
{strcpy(m.jour,"Lundi");}
if(x==2)
{strcpy(m.jour,"Mardi");}
if(x==3)
{strcpy(m.jour,"Mercredi");}
if(x==4)
{strcpy(m.jour,"Jeudi");}
if(x==5)
{strcpy(m.jour,"Vendredi");}
if(x==6)
{strcpy(m.jour,"Samedi");}
if(x==7)
{strcpy(m.jour,"Dimanche");}

if(t[0]==1)
{strcpy(m.semaine,"1");}
if(t[1]==1)
{strcpy(m.semaine,"2");}
if(t[2]==1)
{strcpy(m.semaine,"3");}
if(t[3]==1)
{strcpy(m.semaine,"4");}


ptidej=lookup_widget(objet,"ptidej");
ptidej1=lookup_widget(objet,"ptidej1");
ptidej2=lookup_widget(objet,"ptidej2");

dej=lookup_widget(objet,"dej");
dej1=lookup_widget(objet,"dej1");
dej2=lookup_widget(objet,"dej2");
dinner=lookup_widget(objet,"dinner");
dinner1=lookup_widget(objet,"dinner1");
dinner2=lookup_widget(objet,"dinner2");


strcpy(m.ptidej,gtk_entry_get_text(GTK_ENTRY(ptidej)));
strcpy(m.ptidej1,gtk_entry_get_text(GTK_ENTRY(ptidej1)));
strcpy(m.ptidej2,gtk_entry_get_text(GTK_ENTRY(ptidej2)));
strcpy(m.dej,gtk_entry_get_text(GTK_ENTRY(dej)));
strcpy(m.dej1,gtk_entry_get_text(GTK_ENTRY(dej1)));
strcpy(m.dej2,gtk_entry_get_text(GTK_ENTRY(dej2)));
strcpy(m.dinner,gtk_entry_get_text(GTK_ENTRY(dinner)));
strcpy(m.dinner1,gtk_entry_get_text(GTK_ENTRY(dinner1)));
strcpy(m.dinner2,gtk_entry_get_text(GTK_ENTRY(dinner2)));
ajouter_menu(m);



ajouterz2=lookup_widget(objet,"ajouterz2");
gtk_widget_destroy(ajouterz2);

bienvenuez=create_bienvenuez();

gtk_widget_show(bienvenuez);
treeview1z=lookup_widget(bienvenuez,"treeview1z");
afficher_menu(treeview1z);
}


void
on_return2z_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *bienvenuez , *ajouterz2;
bienvenuez=create_bienvenuez();

gtk_widget_show(bienvenuez);

ajouterz2=lookup_widget(objet,"ajouterz2");
gtk_widget_destroy(ajouterz2);
}


void
on_checkbutton1z_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{t[0]=1;}
}


void
on_checkbutton3z_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{t[2]=1;}
}


void
on_checkbutton2z_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{t[1]=1;}
}


void
on_checkbutton4z_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{t[3]=1;}
}


void
on_radiobutton1z_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=1;}
}


void
on_radiobutton2z_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=2;}
}


void
on_radiobutton3z_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=3;}
}


void
on_radiobutton4z_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=4;}
}


void
on_radiobutton5z_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=5;}
}


void
on_radiobutton6z_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=6;}
}


void
on_radiobutton7z_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=7;}
}


void
on_validersjz3_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *spinbuttonz1 ,  *pInfo ,*comboboxz1 , *msgz1,*ptidejmz,*modifierz3;


menu m;
int a , v;
char s[30];
char j[30];
char text1[50]="";
char text2[50]="";
char text3[200]="";
spinbuttonz1=lookup_widget(objet_graphique,"spinbuttonz1");
comboboxz1=lookup_widget(objet_graphique,"comboboxz1");
FILE *f;
FILE *g;
f=fopen("zmodif.txt","a+");
if (f!=NULL)
{


a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonz1));

if(strcmp("Lundi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz1)))==1)
{strcpy(m.jour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz1)));}

if(strcmp("Mardi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz1)))==1)
{strcpy(m.jour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz1)));}

if(strcmp("Mercredi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz1)))==1)
{strcpy(m.jour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz1)));}

if(strcmp("Jeudi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz1)))==1)
{strcpy(m.jour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz1)));}

if(strcmp("Vendredi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz1)))==1)
{strcpy(m.jour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz1)));}

if(strcmp("Samedi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz1)))==1)
{strcpy(m.jour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz1)));}

if(strcmp("Dimanche",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz1)))==1)
{strcpy(m.jour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz1)));}
fprintf(f,"%d %s \n",a,m.jour);

}
fclose(f);

g=fopen("zmodif.txt","r+");
while(fscanf(g," %s %s   \n",m.semaine,m.jour)!=EOF)
{strcpy(j,m.jour);
strcpy(s,m.semaine);}



f=fopen("zutilisateur.txt","a+");

if (f!=NULL)
while(fscanf(f," %s %s %s %s %s %s %s %s %s %s %s \n",m.semaine,m.jour,m.ptidej,m.dej,m.dinner,m.ptidej1,m.dej1,m.dinner1,m.ptidej2,m.dej2,m.dinner2)!=EOF)
{
    if (strcmp(m.jour,j) == 0 && strcmp(m.semaine,s) == 0 )
   {


v=1;
break;

}
else{v=0;}
}
if(v==0)
{

pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"jour introuvable \n vous n'êtes pas capable de faire la modification");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}


}
else
{

sprintf(text3,"             jour trouvé \n \n vous êtes capable de faire \n            la modification %s %s  ",text1,text2);
msgz1= lookup_widget(objet_graphique, "msgz1");
gtk_label_set_text(GTK_LABEL(msgz1),text3);
GdkColor color;
	gdk_color_parse("white",&color);
	gtk_widget_modify_fg(msgz1,GTK_STATE_NORMAL,&color);
	gtk_label_set_text(GTK_LABEL(msgz1),text3);

}
}


void
on_modifier3z_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *modifierz3, *bienvenuez ,*ptidejmz , *dejmz , *dinnermz, *ptidej1mz , *dej1mz , *dinner1mz , *ptidej2mz , *dej2mz , *dinner2mz ,*msgz1;
GtkWidget *treeview1z;
char ba[50];
char ca[50];
char da[50];
char ea[50];
char fa[50];
char ga[50];
char ha[50];
char ia[50];
char ka[50];
char text3[50]="";
char text1[50]="";
char text2[50]="";
menu m;



ptidejmz = lookup_widget (button,"ptidejmz");
dejmz = lookup_widget (button, "dejmz");
dinnermz = lookup_widget (button,"dinnermz");

ptidej1mz = lookup_widget (button,"ptidej1mz");
dej1mz = lookup_widget (button, "dej1mz");
dinner1mz = lookup_widget (button,"dinner1mz");

ptidej2mz = lookup_widget (button,"ptidej2mz");
dej2mz = lookup_widget (button, "dej2mz");
dinner2mz = lookup_widget (button,"dinner2mz");

strcpy(ba, gtk_entry_get_text(GTK_ENTRY(ptidejmz)));
strcpy(ca, gtk_entry_get_text(GTK_ENTRY(dejmz)));
strcpy(da, gtk_entry_get_text(GTK_ENTRY(dinnermz)));
strcpy(ea, gtk_entry_get_text(GTK_ENTRY(ptidej1mz)));
strcpy(fa, gtk_entry_get_text(GTK_ENTRY(dej1mz)));
strcpy(ga, gtk_entry_get_text(GTK_ENTRY(dinner1mz)));
strcpy(ha, gtk_entry_get_text(GTK_ENTRY(ptidej2mz)));
strcpy(ia, gtk_entry_get_text(GTK_ENTRY(dej2mz)));
strcpy(ka, gtk_entry_get_text(GTK_ENTRY(dinner2mz)));
FILE *f;
FILE *f1;
FILE *g;
char j[30];
char s[30];
g=fopen("zmodif.txt","r+");
while(fscanf(g," %s %s   \n",m.semaine,m.jour)!=EOF)
{strcpy(j,m.jour);
strcpy(s,m.semaine);}



// ouvrir le fichier :
f1=fopen("z_modif.txt","a+");

f=fopen("zutilisateur.txt","a+");

if (f!=NULL)
while(fscanf(f," %s %s %s %s %s %s %s %s %s %s %s \n",m.semaine,m.jour,m.ptidej,m.dej,m.dinner,m.ptidej1,m.dej1,m.dinner1,m.ptidej2,m.dej2,m.dinner2)!=EOF)
{
    if (strcmp(m.jour,j) == 0 && strcmp(m.semaine,s) == 0 )
   {
  

    fprintf(f1,"%s %s %s %s %s %s %s %s %s %s %s \n",s,j,ba,ea,ha,ca,fa,ia,da,ga,ka);




   }
else
    {

    fprintf(f1,"%s %s %s %s %s %s %s %s %s %s %s  \n",m.semaine,m.jour,m.ptidej,m.dej,m.dinner,m.ptidej1,m.dej1,m.dinner1,m.ptidej2,m.dej2,m.dinner2);


    }
}
fclose(f1);
fclose(f);
fclose(g);

remove("zutilisateur.txt");
rename("z_modif.txt","zutilisateur.txt");

bienvenuez=create_bienvenuez();

gtk_widget_show(bienvenuez);
treeview1z=lookup_widget(bienvenuez,"treeview1z");


modifierz3=lookup_widget(button,"modifierz3");
gtk_widget_destroy(modifierz3);
afficher_menu(treeview1z);

remove("zmodif.txt");

}


void
on_return3z_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *bienvenuez , *modifierz3;
bienvenuez=create_bienvenuez();

gtk_widget_show(bienvenuez);

modifierz3=lookup_widget(objet,"modifierz3");
gtk_widget_destroy(modifierz3);
}


void
on_returnz4_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *bienvenuez , *supprimerz4;
bienvenuez=create_bienvenuez();

gtk_widget_show(bienvenuez);

supprimerz4=lookup_widget(objet,"supprimerz4");
gtk_widget_destroy(supprimerz4);
}


void
on_Supprimerz4_clicked                 (GtkWidget       *objet_graphique,
					GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview1z ,*bienvenuez ,*spinbuttonz2 , *pInfo ,*comboboxz2 , *msgsz4;
FILE *f;
FILE *f1;
FILE *g;
char z[30];
char a[30];
char c[30];
char text1[30]="";
char text2[30]="";
char text3[30]="";
int b , v;

menu m;
spinbuttonz2=lookup_widget(objet_graphique,"spinbuttonz2");
comboboxz2=lookup_widget(objet_graphique,"comboboxz2");

b=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonz2));

if(strcmp("Lundi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz2)))==1)
{strcpy(a,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz2)));}

if(strcmp("Mardi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz2)))==1)
{strcpy(a,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz2)));}

if(strcmp("Mercredi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz2)))==1)
{strcpy(a,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz2)));}

if(strcmp("Jeudi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz2)))==1)
{strcpy(a,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz2)));}

if(strcmp("Vendredi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz2)))==1)
{strcpy(a,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz2)));}

if(strcmp("Samedi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz2)))==1)
{strcpy(a,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz2)));}

if(strcmp("Dimanche",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz2)))==1)
{strcpy(a,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz2)));}

sprintf(z,"%d",b);
f=fopen("zutilisateur.txt","a+");
f1=fopen("zsup.txt","a+");
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s  \n",m.semaine,m.jour,m.ptidej,m.dej,m.dinner,m.ptidej1,m.dej1,m.dinner1,m.ptidej2,m.dej2,m.dinner2)!=EOF)
{
if ((strcmp(m.jour,a)!=0) || (strcmp(m.semaine,z)!=0))
{
fprintf(f1,"%s %s %s %s %s %s %s %s %s %s %s \n",m.semaine,m.jour,m.ptidej,m.dej,m.dinner,m.ptidej1,m.dej1,m.dinner1,m.ptidej2,m.dej2,m.dinner2);
}
}
fclose(f1);
fclose(f);

remove("zutilisateur.txt");
rename("zsup.txt","zutilisateur.txt");
bienvenuez=create_bienvenuez();
gtk_widget_show(bienvenuez);
treeview1z=lookup_widget(bienvenuez,"treeview1z");
afficher_menu(treeview1z);
   

}


void
on_valider_sz_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *treeview1z ,*bienvenuez ,*spinbuttonz2 , *pInfo ,*comboboxz2 , *msgsz4;
FILE *f;
FILE *f1;
FILE *g;
char z[30];
char a[30];
char c[30];
char text1[30]="";
char text2[30]="";
char text3[200]="";
int b , v;

menu m;
spinbuttonz2=lookup_widget(objet_graphique,"spinbuttonz2");
comboboxz2=lookup_widget(objet_graphique,"comboboxz2");

b=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonz2));

if(strcmp("Lundi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz2)))==1)
{strcpy(a,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz2)));}

if(strcmp("Mardi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz2)))==1)
{strcpy(a,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz2)));}

if(strcmp("Mercredi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz2)))==1)
{strcpy(a,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz2)));}

if(strcmp("Jeudi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz2)))==1)
{strcpy(a,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz2)));}

if(strcmp("Vendredi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz2)))==1)
{strcpy(a,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz2)));}

if(strcmp("Samedi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz2)))==1)
{strcpy(a,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz2)));}

if(strcmp("Dimanche",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz2)))==1)
{strcpy(a,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz2)));}

sprintf(z,"%d",b);
f=fopen("zutilisateur.txt","a+");

if (f!=NULL)
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s  \n",m.semaine,m.jour,m.ptidej,m.dej,m.dinner,m.ptidej1,m.dej1,m.dinner1,m.ptidej2,m.dej2,m.dinner2)!=EOF)
{
    if ((strcmp(m.jour,a)==0) && (strcmp(m.semaine,z)==0))
   {
v=1;
break;
	}

else
{
v=0;

}




}
if(v==0)
{
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"jour introuvable \n essayer de supprimer un jour deja ajouté");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;

	}

}

else
{
sprintf(text3,"                          jour trouvé \n \n vous êtes capable de faire la supression %s %s  ",text1,text2);
msgsz4= lookup_widget(objet_graphique, "msgsz4");
gtk_label_set_text(GTK_LABEL(msgsz4),text3);
GdkColor color;
	gdk_color_parse("orange",&color);
	gtk_widget_modify_fg(msgsz4,GTK_STATE_NORMAL,&color);
	gtk_label_set_text(GTK_LABEL(msgsz4),text3);
}
fclose(f);

}


void
on_afficherz6_clicked                  (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *treeview2z ,*bienvenuez ,*spinbuttonz3 , *pInfo ,*comboboxz3 , *msgz6 , *chercherz6;
FILE *f;
FILE *f1;
FILE *g;
char z[30];
char a[30];
char c[30];
char text1[30]="";
char text2[30]="";
char text3[30]="";
int b , v;

menu m;
spinbuttonz3=lookup_widget(objet_graphique,"spinbuttonz3");
comboboxz3=lookup_widget(objet_graphique,"comboboxz3");

b=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonz3));

if(strcmp("Lundi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz3)))==1)
{strcpy(a,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz3)));}

if(strcmp("Mardi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz3)))==1)
{strcpy(a,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz3)));}

if(strcmp("Mercredi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz3)))==1)
{strcpy(a,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz3)));}

if(strcmp("Jeudi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz3)))==1)
{strcpy(a,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz3)));}

if(strcmp("Vendredi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz3)))==1)
{strcpy(a,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz3)));}

if(strcmp("Samedi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz3)))==1)
{strcpy(a,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz3)));}

if(strcmp("Dimanche",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz3)))==1)
{strcpy(a,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz3)));}

sprintf(z,"%d",b);
f=fopen("zutilisateur.txt","a+");
f1=fopen("zchercher.txt","a+");
if (f!=NULL)
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s  \n",m.semaine,m.jour,m.ptidej,m.dej,m.dinner,m.ptidej1,m.dej1,m.dinner1,m.ptidej2,m.dej2,m.dinner2)!=EOF)
{
if ((strcmp(m.jour,a)==0) && (strcmp(m.semaine,z)==0))
{
    fprintf(f1,"%s %s %s %s %s %s %s %s %s %s %s \n",m.semaine,m.jour,m.ptidej,m.dej,m.dinner,m.ptidej1,m.dej1,m.dinner1,m.ptidej2,m.dej2,m.dinner2);

}
   
}
fclose(f);
fclose(f1);

bienvenuez=create_bienvenuez();
gtk_widget_show(bienvenuez);
treeview2z=lookup_widget(bienvenuez,"treeview2z");
afficher_menu2(treeview2z);
chercherz6=lookup_widget(objet_graphique,"chercherz6");
gtk_widget_destroy(chercherz6);
remove("zchercher.txt");
}

void
on_validercz_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *treeview1z ,*bienvenuez ,*spinbuttonz3 , *pInfo ,*comboboxz3 , *msgz6;
FILE *f;
FILE *f1;
FILE *g;
char z[30];
char a[30];
char c[30];
char text1[30]="";
char text2[30]="";
char text3[200]="";
int b , v;

menu m;
spinbuttonz3=lookup_widget(objet_graphique,"spinbuttonz3");
comboboxz3=lookup_widget(objet_graphique,"comboboxz3");

b=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonz3));

if(strcmp("Lundi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz3)))==1)
{strcpy(a,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz3)));}

if(strcmp("Mardi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz3)))==1)
{strcpy(a,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz3)));}

if(strcmp("Mercredi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz3)))==1)
{strcpy(a,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz3)));}

if(strcmp("Jeudi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz3)))==1)
{strcpy(a,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz3)));}

if(strcmp("Vendredi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz3)))==1)
{strcpy(a,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz3)));}

if(strcmp("Samedi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz3)))==1)
{strcpy(a,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz3)));}

if(strcmp("Dimanche",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz3)))==1)
{strcpy(a,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxz3)));}

sprintf(z,"%d",b);
f=fopen("zutilisateur.txt","a+");

if (f!=NULL)
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s  \n",m.semaine,m.jour,m.ptidej,m.dej,m.dinner,m.ptidej1,m.dej1,m.dinner1,m.ptidej2,m.dej2,m.dinner2)!=EOF)
{
    if ((strcmp(m.jour,a)==0) && (strcmp(m.semaine,z)==0))
   {
v=1;
break;
}
else
{v=0;}



}

if(v==0)
{
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"jour introuvable \n essayer de chercherun jour deja ajouté");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;

	}
}
else
{
sprintf(text3,"jour trouvé  %s %s  ",text1,text2);
msgz6= lookup_widget(objet_graphique, "msgz6");
gtk_label_set_text(GTK_LABEL(msgz6),text3);
GdkColor color;
	gdk_color_parse("white",&color);
	gtk_widget_modify_fg(msgz6,GTK_STATE_NORMAL,&color);
	gtk_label_set_text(GTK_LABEL(msgz6),text3);
}

}


void
on_zied1_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{ 

GtkWidget *jourmm , *vdechetmm ,*nrepasmm , *pInfo;
FILE *f;
char a[50];
char b[50];
char c[50];
jourmm = lookup_widget (button,"jourmm");
vdechetmm = lookup_widget (button, "vdechetmm");
nrepasmm = lookup_widget (button,"nrepasmm");
strcpy(a, gtk_entry_get_text(GTK_ENTRY(jourmm)));
strcpy(b, gtk_entry_get_text(GTK_ENTRY(vdechetmm)));
strcpy(c, gtk_entry_get_text(GTK_ENTRY(nrepasmm)));
f=fopen("dechets.txt","a+");
fprintf(f,"%s %s %s \n",a,c,b);
fclose(f);
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"données ajoutées avec succés");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}

}


void
on_valz_clicked                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *meilleurm ,*bienvenuez;

bienvenuez=lookup_widget(objet,"bienvenuez");
gtk_widget_destroy(bienvenuez);
}


void
on_retourzf_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *meilleurm ,*bienvenuez;
bienvenuez=create_bienvenuez();
gtk_widget_show (bienvenuez);
meilleurm=lookup_widget(objet,"meilleurm");
gtk_widget_destroy(meilleurm);

}










void
on_refrech_seif_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
etudiant e;

	GtkWidget *listedesetudiants;
	GtkWidget *treeview1seif;
	GtkWidget *output;


	listedesetudiants=lookup_widget(objet,"listedesetudiants");


	treeview1seif = lookup_widget(listedesetudiants, "treeview1seif");

	aff_e(treeview1seif);
}


void
on_ajouter_seif_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *listedesetudiants;
	GtkWidget *gestionetudiant;

	listedesetudiants=lookup_widget(objet, "listedesetudiants");
	gtk_widget_destroy(listedesetudiants);

	
	gestionetudiant=create_gestionetudiant();
	gtk_widget_show(gestionetudiant);
}


void
on_modifier_seif_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *listedesetudiants;
GtkWidget *modifieretudiant;

GtkWidget *treeview1;
GtkTreeSelection *selection ;
GtkTreeModel *model;
GtkTreeIter iter;
GtkToggleButton *etage11, *etage22;
GtkWidget *button;
GSList *group;

	gchar* nom;
	gchar* prenom;
	gchar* id;
	gchar* niveau;
	gchar* sexe;
	gchar* jour;
	gchar* mois;
	gchar* annee;
	gchar* classe;
	gchar* bloc;

etudiant tr_modif;



GtkWidget *input7,*input8,*input1,*input4,*input5,*input6,*JOUR,*MOIS,*ANNEE;
GtkWidget *combo2;

	listedesetudiants=lookup_widget(objet,"listedesetudiants");

    treeview1=lookup_widget(listedesetudiants,"treeview1seif");
    selection=gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview1));

    if(gtk_tree_selection_get_selected(selection,&model,&iter)) {
       
        gtk_tree_model_get(GTK_LIST_STORE(model), &iter,0,&nom ,1,&prenom, 2,&id, 3,&niveau, 4,&sexe, 5,&jour, 6,&mois, 7,&annee, 8,&classe, 9,&bloc,-1);

	int jour_i,mois_i,annee_i;
	jour_i=atoi(jour);
	mois_i=atoi(mois);
	annee_i=atoi(annee);
       
	strcpy(tr_modif.nom,nom);        
	strcpy(tr_modif.prenom,prenom);
	strcpy(tr_modif.id,id);
        strcpy(tr_modif.niveau,niveau);
        strcpy(tr_modif.sexe,sexe);
       strcpy(tr_modif.bloc,bloc);

	tr_modif.d.jour=jour_i;
	tr_modif.d.mois=mois_i;
	tr_modif.d.annee=annee_i;
 	strcpy(tr_modif.classe,classe);
    }

    gtk_widget_destroy(listedesetudiants);

    modifieretudiant=create_modifieretudiant();
    gtk_widget_show(modifieretudiant);

    input8=lookup_widget(modifieretudiant,"nomms");
    input7=lookup_widget(modifieretudiant,"prenomms");
    input1=lookup_widget(modifieretudiant,"idms");

    JOUR=lookup_widget(modifieretudiant,"jour1s");
    MOIS=lookup_widget(modifieretudiant,"mois1s");
    ANNEE=lookup_widget(modifieretudiant,"annee1s");
	combo2=lookup_widget(modifieretudiant,"combobox2s");
	
 gtk_entry_set_text(GTK_ENTRY(input8),tr_modif.nom);   
 gtk_entry_set_text(GTK_ENTRY(input7),tr_modif.prenom);
 gtk_entry_set_text(GTK_ENTRY(input1),tr_modif.id);
   gtk_spin_button_set_value(JOUR,tr_modif.d.jour);
   gtk_spin_button_set_value(MOIS,tr_modif.d.mois);
   gtk_spin_button_set_value(ANNEE,tr_modif.d.annee);

	GtkWidget *type1,*genre1,*etat1,*etat2;
	type1=lookup_widget(modifieretudiant,"type11");
	genre1=lookup_widget(modifieretudiant,"genre11");
	etat1=lookup_widget(modifieretudiant,"etat11");
	etat2=lookup_widget(modifieretudiant,"etat1111");
	char etage2[10] = "etage2";
	char etage1[10] = "etage1";
	char male[10] = "Male";
	char female[10] = "Female";
	char prepa[10] = "prepa";
	char ingenieurie[20] = "ingenieurie";
	char A[30]="A";
	char B[30]="B";
	char C[30]="C";
	if((strcmp(niveau, etage2))==0)
	{
	GdkColor color;
	gdk_color_parse("white",&color);
	gtk_widget_modify_fg(type1,GTK_STATE_NORMAL,&color);
	gtk_label_set_text(GTK_LABEL(type1),"etage2");
	
	}
	if((strcmp(niveau, etage1))==0)
	{
	GdkColor color;
	gdk_color_parse("white",&color);
	gtk_widget_modify_fg(type1,GTK_STATE_NORMAL,&color);
	gtk_label_set_text(GTK_LABEL(type1),"etage1");
	
	}

	if((strcmp(sexe, male))==0)
	{
	GdkColor color;
	gdk_color_parse("white",&color);
	gtk_widget_modify_fg(genre1,GTK_STATE_NORMAL,&color);
	gtk_label_set_text(GTK_LABEL(genre1),"Male");
	
	}
	if((strcmp(sexe, female))==0)
	{
	GdkColor color;
	gdk_color_parse("white",&color);
	gtk_widget_modify_fg(genre1,GTK_STATE_NORMAL,&color);
	gtk_label_set_text(GTK_LABEL(genre1),"Female");
	
	}
	if((strcmp(classe, prepa))==0)
	{
	GdkColor color;
	gdk_color_parse("white",&color);
	gtk_widget_modify_fg(etat1,GTK_STATE_NORMAL,&color);
	gtk_label_set_text(GTK_LABEL(etat1),"prepa");
	
	}
	if((strcmp(classe, ingenieurie))==0)
	{
	GdkColor color;
	gdk_color_parse("white",&color);
	gtk_widget_modify_fg(etat1,GTK_STATE_NORMAL,&color);
	gtk_label_set_text(GTK_LABEL(etat1),"ingenieurie");
	
	}
	

	if((strcmp(bloc, A))==0)
	{
	GdkColor color;
	gdk_color_parse("white",&color);
	gtk_widget_modify_fg(etat2,GTK_STATE_NORMAL,&color);
	gtk_label_set_text(GTK_LABEL(etat2),"A");
	
	}

	if((strcmp(bloc, B))==0)
	{
	GdkColor color;
	gdk_color_parse("white",&color);
	gtk_widget_modify_fg(etat2,GTK_STATE_NORMAL,&color);
	gtk_label_set_text(GTK_LABEL(etat2),"B");
	
	}

	if((strcmp(bloc, C))==0)
	{
	GdkColor color;
	gdk_color_parse("white",&color);
	gtk_widget_modify_fg(etat2,GTK_STATE_NORMAL,&color);
	gtk_label_set_text(GTK_LABEL(etat2),"C");
	
	}
}



void
on_button_rechercher_seif_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget  *listedesetudiants,*chercheretudiant;

listedesetudiants=lookup_widget(objet,"listedesetudiants");

gtk_widget_destroy(listedesetudiants);

chercheretudiant=lookup_widget(objet,"chercheretudiant");
chercheretudiant=create_chercheretudiant();
gtk_widget_show(chercheretudiant);
}


void
on_sup_seif_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *listedesetudiants, *treeview1seif;
	GtkTreeModel *model;
	GtkTreeIter iter;
	GtkTreeSelection *selection;

	gchar* nom;
	gchar* prenom;
	gchar* id;
	gchar* niveau;
	gchar* sexe;
	gchar* jour;
	gchar* mois;
	gchar* annee;
	gchar* classe;
	gchar* bloc;
	etudiant e;

	listedesetudiants= lookup_widget(objet,"listedesetudiants");
	treeview1seif=lookup_widget(listedesetudiants,"treeview1seif");
	selection=gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview1seif));

	if(gtk_tree_selection_get_selected(selection,&model,&iter))
	{
	gtk_tree_model_get(GTK_LIST_STORE(model), &iter,0,&nom ,1,&prenom, 2,&id, 3,&niveau, 4,&sexe, 5,&jour, 6,&mois, 7,&annee, 8,&classe, 9,&bloc,-1);
		
		strcpy(e.nom,nom);
		strcpy(e.prenom,prenom);		
		strcpy(e.id,id);
		strcpy(e.niveau,niveau);
		strcpy(e.sexe,sexe);
		strcpy(e.jour,jour);
		strcpy(e.mois,mois);		
		strcpy(e.annee,annee);
		strcpy(e.classe,classe);
		strcpy(e.bloc,bloc);

		listedesetudiants= lookup_widget(objet,"listedesetudiants");
		gtk_widget_destroy(listedesetudiants);
		listedesetudiants= create_listedesetudiants();
		gtk_widget_show(listedesetudiants);
		treeview1seif=lookup_widget(listedesetudiants,"treeview1seif");
		sup_e(e);

		aff_e(treeview1seif);

	}
}




void
on_retour_ajout_seif_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *listedesetudiants, *gestionetudiant,*treeview1seif;

	gestionetudiant = lookup_widget(objet,"gestionetudiant");
	gtk_widget_destroy(gestionetudiant);

	listedesetudiants = create_listedesetudiants();
	gtk_widget_show(listedesetudiants);

	treeview1seif=lookup_widget(listedesetudiants,"treeview1seif");
	
	aff_e(treeview1seif);
}


void
on_etage1_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
		x=1;
	}
}


void
on_etage2_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
		x=2;
	}
}


void
on_femaleseif_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
		y=2;
	}
}


void
on_maleseif_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
		y=1;
	}
}


void
on_ingenieurie_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
		z=2;
	}
}


void
on_prepa_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
		z=1;
	}
}


void
on_conf_ajout_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *gestionetudiant;
	GtkWidget *listedesetudiants;
	GtkWidget *treeview1seif;
	etudiant e;

	GtkWidget *jour;
	GtkWidget *mois;
	GtkWidget *annee;

	GtkWidget *combo1;	

	GtkWidget *input1, *input2, *input3, *input4, *sortie,*input5, *input6,*sortie1,*sortie2;

	input1=lookup_widget(objet,"idseif");
	sortie=lookup_widget(objet,"labelseif");

	input5=lookup_widget(objet,"nomseif");
	

	input6=lookup_widget(objet,"prenomseif");
	

	strcpy(e.id,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(e.nom,gtk_entry_get_text(GTK_ENTRY(input5)));
	strcpy(e.prenom,gtk_entry_get_text(GTK_ENTRY(input6)));

	
	if(x==1)
		strcpy(e.niveau,"etage1");
	else if(x==2)
		strcpy(e.niveau,"etage2");
	

	if(y==1)
		strcpy(e.sexe,"Male");
	else if(y==2)
		strcpy(e.sexe,"Female");

	jour = lookup_widget(objet, "jourseif");
	mois = lookup_widget(objet, "moisseif");
	annee = lookup_widget(objet, "anneeseif");



	e.d.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
	e.d.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
	e.d.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));



	combo1= lookup_widget(objet, "combobox1seif");
strcpy(e.bloc,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo1)));

	


	if(z==1)
		strcpy(e.classe,"prepa");
	else if(z==2)
		strcpy(e.classe,"ingenieurie");
	

	GdkColor color;
	gdk_color_parse("white",&color);
	gtk_widget_modify_fg(sortie,GTK_STATE_NORMAL,&color);
	gtk_label_set_text(GTK_LABEL(sortie),"etudiant ajoutée");
	
	ajt_e(e);
	
	aff_e(treeview1seif);
}


void
on_affichage_seif_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *gestionetudiant;	
	GtkWidget *listedesetudiants;
	GtkWidget *treeview1seif;

	gestionetudiant = lookup_widget(objet,"gestionetudiant");
	gtk_widget_destroy(gestionetudiant);

	
	listedesetudiants = lookup_widget(objet,"etudiant");
	listedesetudiants = create_listedesetudiants();
	gtk_widget_show(listedesetudiants);

	treeview1seif=lookup_widget(listedesetudiants,"treeview1seif");

	aff_e(treeview1seif);
}


void
on_treeview1seif_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* nom;
	gchar* prenom;
	gchar* id;
	gchar* niveau;
	gchar* sexe;
	gchar* jour;
	gchar* mois;
	gchar* annee;
	gchar* classe;
	gchar* bloc;
	
	etudiant e;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if(gtk_tree_model_get_iter(model,&iter,path))
	{
		

	gtk_tree_model_get(GTK_LIST_STORE(model), &iter,0,&nom ,1,&prenom, 2,&id, 3,&niveau, 4,&sexe, 5,&jour, 6,&mois, 7,&annee, 8,&classe, 9,&bloc,-1);
		
		strcpy(e.nom,nom);
		strcpy(e.prenom,prenom);		
		strcpy(e.id,id);
		strcpy(e.niveau,niveau);
		strcpy(e.sexe,sexe);
		e.d.jour=jour;
		e.d.mois=mois;
		e.d.annee=annee;
		strcpy(e.classe,classe);
		strcpy(e.bloc,bloc);
		
		sup_e(e);

		aff_e(treeview);

	}
}



void
on_retour_mod_seif_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *listedesetudiants, *modifieretudiant,*treeview1seif;

	modifieretudiant = lookup_widget(objet,"modifieretudiant");
	gtk_widget_destroy(modifieretudiant);

	listedesetudiants = create_listedesetudiants();
	gtk_widget_show(listedesetudiants);

	treeview1seif=lookup_widget(listedesetudiants,"treeview1seif");
	
	aff_e(treeview1seif);
}


void
on_etage11_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
		a=1;
	}
}


void
on_etage22_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
		a=2;
	}	
}


void
on_male1s_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
		b=1;
	}
}


void
on_female1s_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
		b=2;
	}
}


void
on_prepa1_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
		c=1;
	}

}


void
on_ingenieurie1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
		c=2;
	}
}


void
on_enregistre_seif_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *modifieretudiant;
	GtkWidget *listedesetudiants;
	GtkWidget *treeview1seif;
	etudiant e;
	GtkWidget *input1, *input2, *input3, *input4, *input5, *input6, *input7,*sortie;
	GtkWidget *combo2;
	sortie=lookup_widget(objet,"label77s");
	input1=lookup_widget(objet,"idms");
	input7=lookup_widget(objet,"nomms");
input6=lookup_widget(objet,"prenomms");
	
	

	
	strcpy(e.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(e.nom,gtk_entry_get_text(GTK_ENTRY(input7)));
	strcpy(e.prenom,gtk_entry_get_text(GTK_ENTRY(input6)));

	if(a==1)
		strcpy(e.niveau,"etage1");
	else if(a==2)
		strcpy(e.niveau,"etage2");
	

	if(b==1)
		strcpy(e.sexe,"Male");
	else if(b==2)
		strcpy(e.sexe,"Female");


	input2 = lookup_widget(objet, "jour1s");
	input3 = lookup_widget(objet, "mois1s");
	input4 = lookup_widget(objet, "annee1s");

	e.d.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(input2));
	e.d.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(input3));
	e.d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));

combo2= lookup_widget(objet, "combobox2s");
strcpy(e.bloc,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo2)));
	if(c==1)
		strcpy(e.classe,"prepa");
	else if(c==2)
		strcpy(e.classe,"ingenieurie");


	
	modf_e(e);
	
	

	GdkColor color;
	gdk_color_parse("white",&color);
	gtk_widget_modify_fg(sortie,GTK_STATE_NORMAL,&color);
	gtk_label_set_text(GTK_LABEL(sortie),"etudiant modifier");
}


void
on_aff_mod_seif_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *modifieretudiant;	
	GtkWidget *listedesetudiants;
	GtkWidget *treeview1seif;

	modifieretudiant = lookup_widget(objet,"modifieretudiant");
	gtk_widget_destroy(modifieretudiant);

	
	listedesetudiants = lookup_widget(objet, "listedesetudiants");
	listedesetudiants = create_listedesetudiants();
	gtk_widget_show(listedesetudiants);

	treeview1seif=lookup_widget(listedesetudiants,"treeview1seif");
	
	aff_e(treeview1seif);
}


void
on_return_rech_seif_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget  *chercheretudiant,*listedesetudiants, *treeview1seif;
	chercheretudiant=lookup_widget(objet,"chercheretudiant");

	gtk_widget_destroy(chercheretudiant);
	listedesetudiants=lookup_widget(objet,"listedesetudiants");
	listedesetudiants=create_listedesetudiants();
	gtk_widget_show(listedesetudiants);

	treeview1seif=lookup_widget(listedesetudiants,"treeview1seif");
	
	aff_e(treeview1seif);
}


void
on_rech_etu_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

FILE *f;

f = fopen("tr1.txt","r");	

    char id1[30];
    char type1[30];
	char genre1[30];
	char vide[10]="";
    etudiant e;
    GtkWidget *input1,*input2,*input3,*sortie;
    GtkWidget *chercheretudiant;
    sortie=lookup_widget(objet,"label84s");
    chercheretudiant = lookup_widget(objet,"chercheretudiant");

    input1 = lookup_widget(objet,"id55");


    if(strcmp(id1,gtk_entry_get_text(GTK_ENTRY(input1)))!=0)
    strcpy(id1,gtk_entry_get_text(GTK_ENTRY(input1)));
    rechercher(e,id1);
    gtk_entry_set_text(GTK_ENTRY(input1),"");
    GtkWidget *treeview2seif;
    treeview2seif = lookup_widget(objet, "treeview2seif");

    affichage_rechercher(treeview2seif);

	GdkColor color;
	gdk_color_parse("white",&color);
	gtk_widget_modify_fg(sortie,GTK_STATE_NORMAL,&color);
	gtk_label_set_text(GTK_LABEL(sortie),"etudiant trouvé");
}


void
on_treeview1az_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* nom;
	gchar* prenom;

	gchar* id;
	gchar* type;
	gchar* sexe;
	gchar* jour;
	gchar* mois;
	gchar* annee;
	gchar* role;
	gchar* texte;
	
	rec r;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if(gtk_tree_model_get_iter(model,&iter,path))
	{
		

	 gtk_tree_model_get(GTK_LIST_STORE(model), &iter,0,&nom ,1,&prenom, 2,&id, 3,&type, 4,&sexe, 5,&jour, 6,&mois, 7,&annee, 8,&role, 9,&texte,-1);
		

		strcpy(r.nom,nom);
		strcpy(r.prenom,prenom);		
		strcpy(r.id,id);
		strcpy(r.type,type);
		strcpy(r.sexe,sexe);
		jour=r.d.jour;
		mois=r.d.mois;
		annee=r.d.annee;
		strcpy(r.role,role);
		strcpy(r.texte,texte);
		
		sup_r(r);

		aff_tr(treeview);

	}

}


void
on_aj_tr_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *reclamation;
	GtkWidget *ajouterreclamation;

	reclamation=lookup_widget(objet, "reclamation");
	gtk_widget_destroy(reclamation);

	ajouterreclamation=create_ajouterreclamation();
	gtk_widget_show(ajouterreclamation);
}





void
on_md_tr_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *reclamation;
GtkWidget *modifierreclamation;

GtkWidget *treeview1az;
GtkTreeSelection *selection ;
GtkTreeModel *model;
GtkTreeIter iter;
GtkToggleButton *foyer1, *resto1;
GtkWidget *button;
GSList *group;

	gchar* nom;
	gchar* prenom;
	gchar* id;
	gchar* type;
	gchar* sexe;
	gchar* jour;
	gchar* mois;
	gchar* annee;
	gchar* role;
	gchar* texte;

rec ttr_modif;



GtkWidget *input1,*input4,*input5,*input6,*input7,*input8,*input9,*JOUR,*MOIS,*ANNEE;


reclamation=lookup_widget(objet,"reclamation");

    treeview1az=lookup_widget(reclamation,"treeview1az");
    selection=gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview1az));

    if(gtk_tree_selection_get_selected(selection,&model,&iter)) {
        
        gtk_tree_model_get(GTK_LIST_STORE(model), &iter,0,&nom ,1,&prenom, 2,&id, 3,&type, 4,&sexe, 5,&jour, 6,&mois, 7,&annee, 8,&role, 9,&texte-1);

	int jour_i,mois_i,annee_i;
	jour_i=atoi(jour);
	mois_i=atoi(mois);
	annee_i=atoi(annee);
        strcpy(ttr_modif.nom,nom);
	strcpy(ttr_modif.prenom,prenom);
        strcpy(ttr_modif.id,id);
        strcpy(ttr_modif.type,type);
        strcpy(ttr_modif.sexe,sexe);
        
	ttr_modif.d.jour=jour_i;
	ttr_modif.d.mois=mois_i;
	ttr_modif.d.annee=annee_i;
 	strcpy(ttr_modif.role,role);
	strcpy(ttr_modif.texte,texte);

	


    }

    gtk_widget_destroy(reclamation);

    	modifierreclamation=create_modifierreclamation();
    	gtk_widget_show(modifierreclamation);
	input7=lookup_widget(modifierreclamation,"nomm");
	input8=lookup_widget(modifierreclamation,"prenomm");
    	input1=lookup_widget(modifierreclamation,"id_tr1");
	input9=lookup_widget(modifierreclamation,"text");

    	JOUR=lookup_widget(modifierreclamation,"jour1");
    	MOIS=lookup_widget(modifierreclamation,"mois1");
    	ANNEE=lookup_widget(modifierreclamation,"annee1");

	gtk_entry_set_text(GTK_ENTRY(input7),ttr_modif.nom);
 	gtk_entry_set_text(GTK_ENTRY(input8),ttr_modif.prenom);
    	gtk_entry_set_text(GTK_ENTRY(input1),ttr_modif.id);
   	gtk_spin_button_set_value(JOUR,ttr_modif.d.jour);
   	gtk_spin_button_set_value(MOIS,ttr_modif.d.mois);
   	gtk_spin_button_set_value(ANNEE,ttr_modif.d.annee);

	GtkWidget *type1,*genre1,*etat1;
	type1=lookup_widget(modifierreclamation,"type11");
	genre1=lookup_widget(modifierreclamation,"genre11");
	etat1=lookup_widget(modifierreclamation,"etat11");
	char resto[10] = "resto";
	char foyer[10] = "foyer";
	char male[10] = "Male";
	char female[10] = "Female";
	char etudiant[10] = "etudiant";
	char employer[10] = "employer";
	
	

}


void
on_supp_tr_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *reclamation, *treeview1az;
	GtkTreeModel *model;
	GtkTreeIter iter;
	GtkTreeSelection *selection;

	gchar* nom;
	gchar* prenom;
	gchar* id;
	gchar* type;
	gchar* sexe;
	gchar* jour;
	gchar* mois;
	gchar* annee;
	gchar* role;
	gchar* texte;
	

	rec r;

	reclamation= lookup_widget(objet,"reclamation");
	treeview1az=lookup_widget(reclamation,"treeview1az");
	selection=gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview1az));

	if(gtk_tree_selection_get_selected(selection,&model,&iter))
	{
	 gtk_tree_model_get(GTK_LIST_STORE(model), &iter,0,&nom ,1,&prenom, 2,&id, 3,&type, 4,&sexe, 5,&jour, 6,&mois, 7,&annee, 8,&role, 9,&texte,-1);
		
		strcpy(r.nom,nom);
		strcpy(r.prenom,prenom);		
		strcpy(r.id,id);
		strcpy(r.type,type);
		strcpy(r.sexe,sexe);
		strcpy(r.jour,jour);
		strcpy(r.mois,mois);		
		strcpy(r.annee,annee);
		strcpy(r.role,role);
		strcpy(r.texte,texte);
		
		reclamation= lookup_widget(objet,"reclamation");
		gtk_widget_destroy(reclamation);
		reclamation= create_reclamation();
		gtk_widget_show(reclamation);
		treeview1az=lookup_widget(reclamation,"treeview1az");
		sup_r(r);

		aff_tr(treeview1az);

	}
}


void
on_retour_tr_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *reclamation, *ajouterreclamation,*treeview1az;

	ajouterreclamation = lookup_widget(objet,"ajouterreclamation");
	gtk_widget_destroy(ajouterreclamation);

	reclamation = create_reclamation();
	gtk_widget_show(reclamation);

	treeview1az=lookup_widget(reclamation,"treeview1az");
	
	aff_tr(treeview1az);
}


void
on_checketudiant_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
		z=1;
	}
}


void
on_checkemployer_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
		z=2;
	}
}


void
on_foyer_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
		x=1;
	}
}


void
on_resto_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
		x=2;
	}
}


void
on_conf_tr_clicked                     (GtkWidget       *objet,
					GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ajouterreclamation;
	GtkWidget *reclamation;
	GtkWidget *treeview1az , *comboboxsex;
	rec r;
FILE *f;

	GtkWidget *jour;
	GtkWidget *mois;
	GtkWidget *annee;	

	GtkWidget *input1, *input2, *input3, *input4, *sortie; 
	
	input2=lookup_widget(objet,"nom1");
	

	input3=lookup_widget(objet,"prenom1");
	

        input1=lookup_widget(objet,"id_tr");
		

	input4=lookup_widget(objet,"text");
	sortie=lookup_widget(objet,"label57az");	
	
	

	strcpy(r.id,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(r.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(r.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
	strcpy(r.texte,gtk_entry_get_text(GTK_ENTRY(input4)));

		
	if(x==1)
		strcpy(r.type,"foyer");
	else if(x==2)
		strcpy(r.type,"resto");
	
	

		comboboxsex= lookup_widget(objet, "comboboxsex");
strcpy(r.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxsex)));





		
	jour = lookup_widget(objet, "jour");
	mois = lookup_widget(objet, "mois");
	annee = lookup_widget(objet, "annee");

	r.d.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
	r.d.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
	r.d.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));

	


	


	if(z==1)
		strcpy(r.role,"etudiant");
	else if(z==2)
		strcpy(r.role,"employer");

f=fopen("azfichier.txt","a+");
	
	
	fprintf(f,"%s %s %s %s %s %d %d %d %s %s \n",r.nom,r.prenom,r.id,r.type, r.sexe,r.d.jour,r.d.mois,r.d.annee, r.role,r.texte);

		fclose(f);


	
	GdkColor color;
	gdk_color_parse("white",&color);
	gtk_widget_modify_fg(sortie,GTK_STATE_NORMAL,&color);
	gtk_label_set_text(GTK_LABEL(sortie),"*_* Votre reclamation est ajoutée");
	

	
	
	
	aff_tr(treeview1az);
}


void
on_affichage_tr_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajouterreclamation;	
	GtkWidget *reclamation;
	GtkWidget *treeview1az;

	ajouterreclamation = lookup_widget(objet,"ajouterreclamation");
	gtk_widget_destroy(ajouterreclamation);

	
	reclamation = lookup_widget(objet,"reclamation");
	reclamation = create_reclamation();
	gtk_widget_show(reclamation);

	treeview1az=lookup_widget(reclamation,"treeview1az");

	aff_tr(treeview1az);
}

void
on_button_rechercher_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget  *reclamation,*chercherreclamation;

reclamation=lookup_widget(objet,"reclamation");

gtk_widget_destroy(reclamation);

chercherreclamation=lookup_widget(objet,"chercherreclamation");
chercherreclamation=create_chercherreclamation();
gtk_widget_show(chercherreclamation);
}


void
on_checketudiant1_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
		c=1;
	}
}


void
on_checkemployer1_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
		c=2;
	}
}


void
on_female1_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
		b=2;
	}
}


void
on_male1_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
		b=1;}
}


void
on_foyer1_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
		a=1;
	}
}


void
on_resto1_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
		a=2;
	}
}


void
on_enregistre_tr_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *modifierreclamation;
	GtkWidget *reclamation;
	GtkWidget *treeview1az;
	rec r;
	GtkWidget *input1, *input2, *input3, *input4, *input5, *input6, *input7,*sortie;
	
	
	sortie=lookup_widget(objet,"label51az");
	input1=lookup_widget(objet,"id_tr1");
	input2=lookup_widget(objet, "jour1");
	input3=lookup_widget(objet, "mois1");
	input4=lookup_widget(objet, "annee1");
	input5=lookup_widget(objet,"nomm");
	input6=lookup_widget(objet,"prenomm");
	input7=lookup_widget(objet,"entry2az");
		
	strcpy(r.nom,gtk_entry_get_text(GTK_ENTRY(input5)));
	strcpy(r.prenom,gtk_entry_get_text(GTK_ENTRY(input6)));
	strcpy(r.id,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(r.texte,gtk_entry_get_text(GTK_ENTRY(input7)));
	
	

	if(a==1)
		strcpy(r.type,"foyer");
	else if(a==2)
		strcpy(r.type,"resto");
	

	if(b==1)
		strcpy(r.sexe,"Male");
	else if(b==2)
		strcpy(r.sexe,"Female");


	

	r.d.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(input2));
	r.d.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(input3));
	r.d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));


	if(c==1)
		strcpy(r.role,"etudiant");
	else if(c==2)
		strcpy(r.role,"employer");
	
	
	
	modf_r(r);

	GdkColor color;
	gdk_color_parse("red",&color);
	gtk_widget_modify_fg(sortie,GTK_STATE_NORMAL,&color);
	gtk_label_set_text(GTK_LABEL(sortie),"Reclamation modifier");

}


void
on_aff_tr_md_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *modifierreclamation;	
	GtkWidget *reclamation;
	GtkWidget *treeview1az;

	modifierreclamation = lookup_widget(objet,"modifierreclamation");
	gtk_widget_destroy(modifierreclamation);

	
	reclamation = lookup_widget(objet,"reclamation");
	reclamation = create_reclamation();
	gtk_widget_show(reclamation);

	treeview1az=lookup_widget(reclamation,"treeview1az");

	aff_tr(treeview1az);
}


void
on_return_rech_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget  *chercherreclamation,*reclamation, *treeview1az;
	chercherreclamation=lookup_widget(objet,"chercherreclamation");

	gtk_widget_destroy(chercherreclamation);
	reclamation=lookup_widget(objet,"reclamation");
	reclamation=create_reclamation();
	gtk_widget_show(reclamation);

	treeview1az=lookup_widget(reclamation,"treeview1az");
	
	aff_tr(treeview1az);

}


void
on_rech_tr_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
FILE *f;

f = fopen("tr1.txt","r");	

    char id1[30];
    char type1[30];
	char genre1[30];
	char vide[10]="";
   rec r;
    GtkWidget *input1,*input2,*input3,*sortie;
    GtkWidget *chercherreclamation;
    sortie=lookup_widget(objet,"label45az");
    chercherreclamation = lookup_widget(objet,"chercherreclamation");

    input1 = lookup_widget(objet,"id55");


    if(strcmp(id1,gtk_entry_get_text(GTK_ENTRY(input1)))!=0)
    strcpy(id1,gtk_entry_get_text(GTK_ENTRY(input1)));
    rechercheraz(r,id1);
    gtk_entry_set_text(GTK_ENTRY(input1),"");
    GtkWidget *treeview2az;
    treeview2az = lookup_widget(objet, "treeview2az");

    affichage_rechercheraz(treeview2az);
}


void
on_rt_md_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *reclamation, *modifierreclamation,*treeview1az;

	modifierreclamation = lookup_widget(objet,"modifierreclamation");
	gtk_widget_destroy(modifierreclamation);

	reclamation = create_reclamation();
	gtk_widget_show(reclamation);

	treeview1az=lookup_widget(reclamation,"treeview1az");
	
	aff_tr(treeview1az);
}


void
on_button2_auth_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{

 GtkWidget *username,*password,*	windowEspaceAdmin,*authen,*WindowAuth,*label;
 char user[20];
 char pasw[20];
int trouve;
username =lookup_widget(objet, "entry3_log");
password =lookup_widget(objet, "entry4_Pw"); 
strcpy(user,gtk_entry_get_text(GTK_ENTRY(username)));
strcpy(pasw,gtk_entry_get_text(GTK_ENTRY(password)));
trouve = verifier(user,pasw);
if  (trouve==1)
{windowEspaceAdmin=create_Admin();


authen=lookup_widget(objet,"authen");
gtk_widget_destroy(authen);
 gtk_widget_show(windowEspaceAdmin);
}
else {
label=lookup_widget(objet,"autheNonAssure");
gtk_widget_set_visible(label,TRUE);


 }
}



void
on_button1_ajouter_clicked             (GtkWidget       *objet,
					
                                        gpointer         user_data)
{


FILE *f =NULL;
 GtkWidget *username,*pw,*nom,*prenom,*	WindowAuth,*Windowinsc, *inscription;
 


 char passw[20];
 char Username1[20];
 char Nom[20];
 char Prenom[20];
 int  trouve;
nom=lookup_widget(objet,"entry1_nom");
prenom=lookup_widget(objet,"entry1_prenom");
username=lookup_widget(objet,"entry2_username");
pw =lookup_widget(objet, "entry2_Mot"); 
strcpy(Nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(Prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(Username1,gtk_entry_get_text(GTK_ENTRY(username)));
strcpy(passw,gtk_entry_get_text(GTK_ENTRY(pw)));


	f=fopen("wessutilisateur.txt","a+");
	if (f!=NULL)
	{
		fprintf(f," %s %s %s %s \n",Nom,Prenom,Username1,passw);
		fclose(f);
		WindowAuth=create_authen();

		gtk_widget_show(WindowAuth);
	}
	
	
inscription=lookup_widget(objet,"inscription");

	gtk_widget_destroy(inscription);


}



void
on_Gestion_de_reclamation_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *reclamation, *Admin;

	Admin=lookup_widget(objet,"Admin");

	gtk_widget_destroy(Admin);

	reclamation=create_reclamation();
	gtk_widget_show(reclamation);
}

void
on_Gestionmenu_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *bienvenuez, *Admin;

	Admin=lookup_widget(objet,"Admin");

	gtk_widget_destroy(Admin);

	bienvenuez=create_bienvenuez();
	gtk_widget_show(bienvenuez);
}

void
on_gestion_des_stocks_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *window1ac, *Admin;

	Admin=lookup_widget(objet,"Admin");

	gtk_widget_destroy(Admin);

	window1ac=create_window1ac();
	gtk_widget_show(window1ac);
}

void
on_gestion_des_etudiants_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *listedesetudiants, *Admin;

	Admin=lookup_widget(objet,"Admin");

	gtk_widget_destroy(Admin);

	listedesetudiants=create_listedesetudiants();
	gtk_widget_show(listedesetudiants);

}

void
on_gestion_des_capteurs_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *dashboard, *Admin;

	Admin=lookup_widget(objet,"Admin");

	gtk_widget_destroy(Admin);

	dashboard=create_dashboard();
	gtk_widget_show(dashboard);

}



void
on_dashboards_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *dashboard6, *Admin;

	Admin=lookup_widget(objet,"Admin");

	gtk_widget_destroy(Admin);

	dashboard6=create_dashboard6();
	gtk_widget_show(dashboard6);


}


void
on_gestion_des_utilisateurs_clicked    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *dashboard_utilisateur, *Admin;

	Admin=lookup_widget(objet,"Admin");

	gtk_widget_destroy(Admin);

	dashboard_utilisateur=create_dashboard_utilisateur();
	gtk_widget_show(dashboard_utilisateur);

}


void
on_seconnecter_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *WindowAuth , *inscription;

inscription=lookup_widget(objet,"inscription");

	gtk_widget_destroy(inscription);
WindowAuth=create_authen();

		gtk_widget_show(WindowAuth);
}


void
on_button1_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *aj_utilisateur, *dashboard_utilisateur;

aj_utilisateur=lookup_widget(objet,"aj_utilisateur");
aj_utilisateur=create_aj_utilisateur();
gtk_widget_show(aj_utilisateur);

dashboard_utilisateur=lookup_widget(objet,"dashboard_utilisateur");
gtk_widget_destroy(dashboard_utilisateur);
}


void
on_button2_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *mod_utilisateur, *dashboard_utilisateur;
dashboard_utilisateur=lookup_widget(objet,"dashboard_utilisateur");
gtk_widget_destroy(dashboard_utilisateur);
mod_utilisateur=lookup_widget(objet,"mod_utilisateur");
mod_utilisateur=create_mod_utilisateur();
gtk_widget_show(mod_utilisateur);
}


void
on_button3_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview, *af_utilisateur, *dashboard_utilisateur;
dashboard_utilisateur=lookup_widget(objet,"dashboard_utilisateur");
gtk_widget_destroy(dashboard_utilisateur);
af_utilisateur=lookup_widget(objet,"af_utilisateur");
af_utilisateur=create_af_utilisateur();
gtk_widget_show(af_utilisateur);
treeview=lookup_widget(af_utilisateur,"treeview_utilisateur");
afficher(treeview,"utilisateur.txt");
}





void
on_button_mod_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *mod1, *mod2, *mod3, *mod4, *mod5, *mod6, *pInfo, *mod_utilisateur,*dashboard_utilisateur;
utilisateur u;
int c;
mod1=lookup_widget(objet,"mod1");
mod2=lookup_widget(objet,"mod2");
mod3=lookup_widget(objet,"mod3");
mod4=lookup_widget(objet,"mod4");
mod5=lookup_widget(objet,"mod5");
mod6=lookup_widget(objet,"mod6");
u.id=atoi(gtk_entry_get_text(GTK_ENTRY(mod1)));
u.role = gtk_combo_box_get_active(GTK_COMBO_BOX(mod2))+1;
strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(mod3)));
strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(mod4)));
strcpy(u.email,gtk_entry_get_text(GTK_ENTRY(mod5)));
u.nv = gtk_combo_box_get_active(GTK_COMBO_BOX(mod6))+1;
modifier(u,"utilisateur.txt");
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Utilisateur modifié avec succès");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
mod_utilisateur=lookup_widget(objet,"mod_utilisateur");
gtk_widget_destroy(mod_utilisateur);

dashboard_utilisateur=lookup_widget(objet,"dashboard_utilisateur");
dashboard_utilisateur=create_dashboard_utilisateur();
gtk_widget_show(dashboard_utilisateur);
}


void
on_check_id_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *mod1, *mod2, *mod3, *mod4, *mod5, *mod6, *pInfo;
utilisateur p;
int a=0;
char ch[20];
FILE *f;
mod1=lookup_widget(objet,"mod1");
mod2=lookup_widget(objet,"mod2");
mod3=lookup_widget(objet,"mod3");
mod4=lookup_widget(objet,"mod4");
mod5=lookup_widget(objet,"mod5");
mod6=lookup_widget(objet,"mod6");
int id = atoi(gtk_entry_get_text(GTK_ENTRY(mod1)));
f = fopen("utilisateur.txt","r");
if(f!=NULL){
while(fscanf(f,"%d %d %s %s %s %d %d %d %d %d\n",&(p.id),&(p.role),p.prenom,p.nom,p.email,&(p.sexe),&(p.d.j),&(p.d.m),&(p.d.a),&(p.nv))!=EOF)
	{
		if(p.id==id){
			a=1;
			break;
                 }
	}
fclose(f);
}
if(a==1){
gtk_combo_box_set_active(GTK_COMBO_BOX(mod2),p.role-1);
gtk_entry_set_text(GTK_ENTRY(mod3),p.prenom);
gtk_entry_set_text(GTK_ENTRY(mod4),p.nom);
gtk_entry_set_text(GTK_ENTRY(mod5),p.email);
gtk_combo_box_set_active(GTK_COMBO_BOX(mod6),p.nv-1);
}
else{
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"Utilisateur introuvable");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
}
}


void
on_treeview_utilisateur_row_activated  (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gint id;
	utilisateur u;
	GtkWidget *pInfo;
	GtkTreeModel *model=gtk_tree_view_get_model(treeview);
	if(gtk_tree_model_get_iter(model,&iter,path)){
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,-1);
	u.id=id;
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_QUESTION,GTK_BUTTONS_YES_NO,"Voulez-vous vraiment\nsupprimer cet utilisateur?");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_YES:
	gtk_widget_destroy(pInfo);
	supprimer(u,"utilisateur.txt");
	afficher(treeview,"utilisateur.txt");
	break;
	case GTK_RESPONSE_NO:
	gtk_widget_destroy(pInfo);
	break;
}	
}
}


void
on_button_af_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview, *af_utilisateur;
af_utilisateur=lookup_widget(objet,"af_utilisateur");
gtk_widget_destroy(af_utilisateur);
af_utilisateur=lookup_widget(objet,"af_utilisateur");
af_utilisateur=create_af_utilisateur();
gtk_widget_show(af_utilisateur);
treeview=lookup_widget(af_utilisateur,"treeview_utilisateur");
afficher(treeview,"utilisateur.txt");
}


void
on_button_aj_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *aj1, *aj2, *aj3, *aj4, *aj5, *aj6, *h, *f ,*aj_utilisateur,*dashboard_utilisateur;
GtkCalendar *ajc;
utilisateur u;
guint day, month, year;
aj1=lookup_widget(objet,"aj1");
aj2=lookup_widget(objet,"aj2");
aj3=lookup_widget(objet,"aj3");
ajc=lookup_widget(objet,"ajc");
h=lookup_widget(objet,"h");
f=lookup_widget(objet,"f");
aj4=lookup_widget(objet,"aj4");
aj5=lookup_widget(objet,"aj5");
aj6=lookup_widget(objet,"aj6");
u.id=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(aj1));
strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(aj3)));
strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(aj4)));
strcpy(u.email,gtk_entry_get_text(GTK_ENTRY(aj5)));
u.sexe=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(h))?0:1;
gtk_calendar_get_date(GTK_CALENDAR(ajc), &day, &month, &year);
u.d.j=year;
u.d.m=month+1;
u.d.a=day;
u.role = gtk_combo_box_get_active(GTK_COMBO_BOX(aj2))+1;
u.nv = u.role==6?gtk_combo_box_get_active(GTK_COMBO_BOX(aj6))+1:0;
ajouter(u,"utilisateur.txt");
aj_utilisateur=lookup_widget(objet,"aj_utilisateur");
gtk_widget_destroy(aj_utilisateur);

dashboard_utilisateur=lookup_widget(objet,"dashboard_utilisateur");
dashboard_utilisateur=create_dashboard_utilisateur();
gtk_widget_show(dashboard_utilisateur);
}


void
on_button5_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *recherche, *dashboard_utilisateur;
dashboard_utilisateur=lookup_widget(objet,"dashboard_utilisateur");
gtk_widget_destroy(dashboard_utilisateur);
recherche=lookup_widget(objet,"recherche");
recherche=create_recherche();
gtk_widget_show(recherche);
}


void
on_chercher_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *r1, *r2, *r3, *r4, *r5, *r6, *r7, *r8, *pInfo;
char date_naissance[20], sexe[20], role[30], niveau[20];
r1=lookup_widget(objet,"r1");
r2=lookup_widget(objet,"r2");
r3=lookup_widget(objet,"r3");
r4=lookup_widget(objet,"r4");
r5=lookup_widget(objet,"r5");
r6=lookup_widget(objet,"r6");
r7=lookup_widget(objet,"r7");
r8=lookup_widget(objet,"r8");
int id = atoi(gtk_entry_get_text(GTK_ENTRY(r1)));
utilisateur p = chercher(id,"utilisateur.txt");
if (p.id==-1){
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"ID introuvable");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
}
else{
sprintf(role,p.role==1?"Admin":p.role==2?"Technicien":p.role==3?"Responsable réclamations":p.role==4?"Agent de foyer":p.role==5?"Agent de restaurant":"Etudiant");
gtk_label_set_text(GTK_LABEL(r2),role);
gtk_label_set_text(GTK_LABEL(r3),p.prenom);
gtk_label_set_text(GTK_LABEL(r4),p.nom);
gtk_label_set_text(GTK_LABEL(r5),p.email);
sprintf(sexe,p.sexe==0?"Homme":"Femme");
gtk_label_set_text(GTK_LABEL(r6),sexe);
sprintf(date_naissance,"%d/%d/%d",p.d.j,p.d.m,p.d.a);
gtk_label_set_text(GTK_LABEL(r7),date_naissance);
sprintf(niveau,p.role==6?(p.nv==1?"1ère année":"%déme année"):"Employé",p.nv);
gtk_label_set_text(GTK_LABEL(r8),niveau);
}
}






void
on_button1000_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Admin, *bienvenuez;

bienvenuez=lookup_widget(objet,"bienvenuez");
gtk_widget_destroy(bienvenuez);
Admin=lookup_widget(objet,"Admin");
Admin=create_Admin();
gtk_widget_show(Admin);
}


void
on_button2000_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Admin, *listedesetudiants;

listedesetudiants=lookup_widget(objet,"listedesetudiants");
gtk_widget_destroy(listedesetudiants);
Admin=lookup_widget(objet,"Admin");
Admin=create_Admin();
gtk_widget_show(Admin);
}


void
on_button3000_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Admin, *reclamation;

reclamation=lookup_widget(objet,"reclamation");
gtk_widget_destroy(reclamation);
Admin=lookup_widget(objet,"Admin");
Admin=create_Admin();
gtk_widget_show(Admin);
}


void
on_button4000_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Admin, *dashboard_utilisateur;

dashboard_utilisateur=lookup_widget(objet,"dashboard_utilisateur");
gtk_widget_destroy(dashboard_utilisateur);
Admin=lookup_widget(objet,"Admin");
Admin=create_Admin();
gtk_widget_show(Admin);
}

void
on_button4001_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Admin, *inscription;

Admin=lookup_widget(objet,"Admin");
gtk_widget_destroy(Admin);
Admin=lookup_widget(objet,"Admin");
inscription=create_inscription();
gtk_widget_show(inscription);
}




void
on_button1_gh_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *aj, *dashboard;

aj=lookup_widget(objet,"aj");
aj=create_aj();
gtk_widget_show(aj);

dashboard=lookup_widget(objet,"dashboard");
gtk_widget_destroy(dashboard);


}


void
on_button2_gh_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *mod, *dashboard;
dashboard=lookup_widget(objet,"dashboard");
mod=lookup_widget(objet,"mod");
mod=create_mod();
gtk_widget_show(mod);

dashboard=lookup_widget(objet,"dashboard");
gtk_widget_destroy(dashboard);
}


void
on_button3_gh_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview, *af ,*dashboard;
af=lookup_widget(objet,"af");
af=create_af();
gtk_widget_show(af);
treeview=lookup_widget(af,"treeview");
affichergh(treeview,"capteurs.txt");

dashboard=lookup_widget(objet,"dashboard");
gtk_widget_destroy(dashboard);
}





void
on_button_mod_gh_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *mod1, *mod2, *mod3, *pInfo, *mod4 , *mod,*dashboard;
capteur u;
mod1=lookup_widget(objet,"mod1_gh");
mod2=lookup_widget(objet,"mod2_gh");
mod3=lookup_widget(objet,"mod3_gh");
mod4=lookup_widget(objet,"mod4_gh");
strcpy(u.id,gtk_entry_get_text(GTK_ENTRY(mod1)));
u.type=gtk_combo_box_get_active(GTK_COMBO_BOX(mod2));
strcpy(u.bloc,gtk_combo_box_get_active_text(GTK_COMBO_BOX(mod4)));
strcpy(u.marque,gtk_entry_get_text(GTK_ENTRY(mod3)));
modifiergh(u,"capteurs.txt");
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Capteur modifié avec succès");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}

mod=lookup_widget(objet,"mod");
gtk_widget_destroy(mod);
dashboard=lookup_widget(objet,"dashboard");
dashboard=create_dashboard();
gtk_widget_show(dashboard);
}


void
on_check_id_gh_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *mod1, *mod2, *mod3, *pInfo, *mod4;
capteur p;
int a=0;
char id[50];
FILE *f;
mod1=lookup_widget(objet,"mod1_gh");
mod2=lookup_widget(objet,"mod2_gh");
mod3=lookup_widget(objet,"mod3_gh");
mod4=lookup_widget(objet,"mod4_gh");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(mod1)));
f = fopen("capteurs.txt","r");
if(f!=NULL){
while(fscanf(f,"%s %d %s %s %d %d %d\n",p.id,&(p.type),p.bloc,p.marque,&(p.d.j),&(p.d.m),&(p.d.a))!=EOF)
	{
		if(strcmp(p.id,id)==0){
			a=1;
			break;
                 }
	}
fclose(f);
}
if(a==1){
gtk_combo_box_set_active(GTK_COMBO_BOX(mod2),p.type);
gtk_entry_set_text(GTK_ENTRY(mod3),p.marque);
gtk_combo_box_set_active(GTK_COMBO_BOX(mod4),strcmp(p.bloc,"A")==0?0:strcmp(p.bloc,"B")==0?1:2);
}
else{
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"Capteur introuvable");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
}
}


void
on_button_af_gh_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview, *af;
af=lookup_widget(objet,"af");
gtk_widget_destroy(af);
af=lookup_widget(objet,"af");
af=create_af();
gtk_widget_show(af);
treeview=lookup_widget(af,"treeview_gh");
affichergh(treeview,"capteurs.txt");
}


void
on_button_aj_gh_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *aj1, *aj2, *aj3, *a, *b, *c;
GtkCalendar *ajc;
capteur u;
guint day, month, year;
aj1=lookup_widget(objet,"aj1_gh");
aj2=lookup_widget(objet,"aj2_gh");
aj3=lookup_widget(objet,"aj3_gh");
ajc=lookup_widget(objet,"ajc_gh");
a=lookup_widget(objet,"aj4_gh");
b=lookup_widget(objet,"aj5_gh");
c=lookup_widget(objet,"aj6_gh");
strcpy(u.id,gtk_entry_get_text(GTK_ENTRY(aj1)));
u.type=gtk_combo_box_get_active(GTK_COMBO_BOX(aj2));
strcpy(u.bloc,gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(a))?"A":gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b))?"B":"C");
strcpy(u.marque,gtk_entry_get_text(GTK_ENTRY(aj3)));
gtk_calendar_get_date(GTK_CALENDAR(ajc), &day, &month, &year);
u.d.j=year;
u.d.m=month+1;
u.d.a=day;
ajoutergh(u,"capteurs.txt");
}


void
on_treeview_gh_row_activated              (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gchar *id;
	capteur u;
	GtkWidget *pInfo;
	GtkTreeModel *model=gtk_tree_view_get_model(treeview);
	if(gtk_tree_model_get_iter(model,&iter,path)){
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,-1);
	strcpy(u.id,id);
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_QUESTION,GTK_BUTTONS_YES_NO,"Voulez-vous vraiment\nsupprimer ce capteur?");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_YES:
	gtk_widget_destroy(pInfo);
	supprimergh(u,"capteurs.txt");
	affichergh(treeview,"capteurs.txt");
	break;
	case GTK_RESPONSE_NO:
	gtk_widget_destroy(pInfo);
	break;
}	
}
}







void
on_returndashboard_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Admin, *dashboard;

dashboard=lookup_widget(objet,"dashboard");
gtk_widget_destroy(dashboard);
Admin=lookup_widget(objet,"Admin");
Admin=create_Admin();
gtk_widget_show(Admin);
}


void
on_returnafgh_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *af, *dashboard;

af=lookup_widget(objet,"af");
gtk_widget_destroy(af);
dashboard=lookup_widget(objet,"dashboard");
dashboard=create_dashboard();
gtk_widget_show(dashboard);
}


void
on_returnajgh_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *aj, *dashboard;

aj=lookup_widget(objet,"aj");
gtk_widget_destroy(aj);
dashboard=lookup_widget(objet,"dashboard");
dashboard=create_dashboard();
gtk_widget_show(dashboard);
}


void
on_affmmz_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *spinmmz , *msgmmz;
FILE *g;
int semaine,jour;
char text3[100]="";
char text2[30]="";
char text1[30];
spinmmz=lookup_widget(objet_graphique,"spinmmz");
semaine=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinmmz));
jour=meilleur_menu(semaine);




sprintf(text3,"le meilleur menu de semaine %d est de jour %d",semaine,jour);
msgmmz= lookup_widget(objet_graphique, "msgmmz");
gtk_label_set_text(GTK_LABEL(msgmmz),text3);
GdkColor color;
	gdk_color_parse("blue",&color);
	gtk_widget_modify_fg(msgmmz,GTK_STATE_NORMAL,&color);
	gtk_label_set_text(GTK_LABEL(msgmmz),text3);

}

void
on_afficher_gh_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{



GtkWidget *treeview,*dashboard6;
treeview=lookup_widget(objet,"treeview_def_gh");
alarme(treeview,"mouvement.txt","fumee.txt");
}


void
on_nombre_etudiant_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *sortie, *etage2, *etage1,*prepa;
	GtkWidget *listedesetudiants;
	char nbr_s[10];
	char e1_s[10];
	char e2_s[10];
	
	int nbr,e1,e2;
	sortie=lookup_widget(objet,"nbetudiants");
	etage2=lookup_widget(objet,"nbetage2");
	etage1=lookup_widget(objet,"nbetage1");
	

	etudiant tr;

	

	listedesetudiants=lookup_widget(objet,"listedesetudiants");
	

	nbr=nombre_etudiant();
	sprintf(nbr_s,"%d", nbr);

	GdkColor color;
	gdk_color_parse("blue",&color);
	gtk_widget_modify_fg(sortie,GTK_STATE_NORMAL,&color);
	gtk_label_set_text(GTK_LABEL(sortie),nbr_s);

	e1=nombre_etage2();
	sprintf(e1_s,"%d", e1);


	gdk_color_parse("blue",&color);
	gtk_widget_modify_fg(etage2,GTK_STATE_NORMAL,&color);
	gtk_label_set_text(GTK_LABEL(etage2),e1_s);

	e2=nombre_etage1();
	sprintf(e2_s,"%d", e2);


	gdk_color_parse("blue",&color);
	gtk_widget_modify_fg(etage1,GTK_STATE_NORMAL,&color);
	gtk_label_set_text(GTK_LABEL(etage1),e2_s);

}



void
on_actualiserrecaz_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview1az,*reclamation;
treeview1az=lookup_widget(button,"treeview1az");

	aff_tr(treeview1az);
}




on_result_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *sortie, *resto, *foyer,*etudiant,*msgfinale;
	GtkWidget *reclamation;
	char nbr_s[10];
	char iv_s[10];
	char ib_s[10];
	char ivv_s[10];
	
	int nbr,iv,ib,ivv;
	sortie=lookup_widget(objet,"nbreclamation");
	resto=lookup_widget(objet,"nbresto");
	foyer=lookup_widget(objet,"nbfoyer");
	etudiant=lookup_widget(objet,"nbetudiant");
	reclamation=lookup_widget(objet,"reclamation");
	msgfinale=lookup_widget(objet,"msg");	
	rec r;

	

	
	

	nbr=nombre_rec();
	sprintf(nbr_s,"%d", nbr);

	GdkColor color;
	gdk_color_parse("blue",&color);
	gtk_widget_modify_fg(sortie,GTK_STATE_NORMAL,&color);
	gtk_label_set_text(GTK_LABEL(sortie),nbr_s);

	iv=nombre_resto();
	sprintf(iv_s,"%d", iv);


	gdk_color_parse("blue",&color);
	gtk_widget_modify_fg(resto,GTK_STATE_NORMAL,&color);
	gtk_label_set_text(GTK_LABEL(resto),iv_s);

	ib=nombre_foyer();
	sprintf(ib_s,"%d", ib);


	gdk_color_parse("blue",&color);
	gtk_widget_modify_fg(foyer,GTK_STATE_NORMAL,&color);
	gtk_label_set_text(GTK_LABEL(foyer),ib_s);

	ivv=rec_etudiant();
	sprintf(ivv_s,"%d", ivv);

	gdk_color_parse("blue",&color);
	gtk_widget_modify_fg(etudiant,GTK_STATE_NORMAL,&color);
	gtk_label_set_text(GTK_LABEL(etudiant),ivv_s);
		
		if (iv>ib)
{			
	GdkColor color;
	gdk_color_parse("blue",&color);
	gtk_widget_modify_fg(msgfinale,GTK_STATE_NORMAL,&color);
	gtk_label_set_text(GTK_LABEL(msgfinale),"service de resauration");
}		

		else if (ib>iv)
{			
	GdkColor color;
	gdk_color_parse("blue",&color);
	gtk_widget_modify_fg(msgfinale,GTK_STATE_NORMAL,&color);
	gtk_label_set_text(GTK_LABEL(msgfinale),"service de hebergement (foyer) ");
}
		
		else 
{	
	GdkColor color;
	gdk_color_parse("blue",&color);
	gtk_widget_modify_fg(msgfinale,GTK_STATE_NORMAL,&color);
	gtk_label_set_text(GTK_LABEL(msgfinale),"Reclamation foyer et resto sont egaux");
}

}





void
on_button_debit_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview, *debit;

treeview=lookup_widget(objet,"treeview_debit");
panne(treeview,"debit.txt");
}


void
on_treeview1ac_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

char ch[50];
GtkTreeIter iter;
gchar* produit;
gchar* type;
gchar* ident;
gchar* poids;
gchar* unite;
gchar* dans;
GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&produit,1,&type,2,&ident,3,&poids,4,&unite,5,&dans,-1);
strcpy(ch,ident);
supprimer_prod1(ch);
afiche_prod1(treeview);
}

}


void
on_button2ac_clicked                   (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window2;
GtkWidget *window1;
window1=lookup_widget(objet_graphique,"window1ac");
window2=create_window2ac();
gtk_widget_show(window2);
gtk_widget_hide(window1);
}

/*********************************************************/
void
on_button1ac_clicked                   (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2;
GtkWidget *treeview1;

window1=lookup_widget(objet_graphique,"window1ac");
window2=create_window1ac();
gtk_widget_show(window2);
gtk_widget_hide(window1);
treeview1=lookup_widget(window2,"treeview1ac");
afiche_prod1(treeview1);


}
/****************************************************************/

void
on_button3ac_clicked                   (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window3;
GtkWidget *window1;
window1=lookup_widget(objet_graphique,"window1ac");
window3=create_window3ac();
gtk_widget_show(window3);
gtk_widget_destroy(window1);

}

/***************************************************************************/




void
on_button5ac_clicked                   (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window4;
GtkWidget *window1;
window1=lookup_widget(objet_graphique,"window1ac");
window4=create_window4ac();
gtk_widget_show(window4);
gtk_widget_destroy(window1);
}


void
on_button4ac_clicked                   (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window5;
GtkWidget *window1;
window1=lookup_widget(objet_graphique,"window1ac");
window5=create_window5ac();
gtk_widget_show(window5);
gtk_widget_destroy(window1);
}




void
on_button7return1ac_clicked            (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window2;
GtkWidget *window1;
window2=lookup_widget(objet_graphique,"window2ac");
window1=create_window1ac();
gtk_widget_show(window1);
gtk_widget_destroy(window2);
}

/******************************************************************************/
void
on_button8valider1ac_clicked           (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *anom,*atype,*aident,*apoids;
GtkWidget *aunite,*adans,*un1,*un2,*un3,*err1;
prod a_p;
int n1 ,n2 ;
char ch111[50],ch222[50],texte[100];
anom = lookup_widget(objet_graphique,"entry1ac");
atype = lookup_widget(objet_graphique,"combobox1ac");
aident = lookup_widget(objet_graphique,"spinbutton1ac");
apoids = lookup_widget(objet_graphique,"spinbutton2ac");
un1 = lookup_widget(objet_graphique,"radiobutton1ac");
un2 = lookup_widget(objet_graphique,"radiobutton2ac");
un3 = lookup_widget(objet_graphique,"radiobutton3ac");
adans = lookup_widget(objet_graphique,"checkbutton1ac");

strcpy(a_p.nom,gtk_entry_get_text(GTK_ENTRY(anom)));
strcpy(a_p.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(atype)));
n1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(aident));
sprintf(ch111,"%d",n1);
strcpy(a_p.ident,ch111);
n2=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(apoids));
sprintf(ch222,"%d",n2);
strcpy(a_p.poids,ch222);
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(un1))) {strcpy(a_p.unite,"kg");}
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(un2))) {strcpy(a_p.unite,"litre");} 
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(un3))) {strcpy(a_p.unite,"autre");} 
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(adans))) {strcpy(a_p.dans,"frigo");}
else {strcpy(a_p.dans,"NON");}
ajouter_prod1(a_p);
alarme_rupture( repture1) ;

if((verif(ch111))==1){



sprintf(texte,"%s\n" ,"le produit est ajoute");
err1=lookup_widget(objet_graphique,"label14ac");
gtk_label_set_text(GTK_LABEL(err1),texte);

}else{sprintf(texte,"%s\n" ,"le produit n est pas ajoute");
err1=lookup_widget(objet_graphique,"label14ac");
gtk_label_set_text(GTK_LABEL(err1),texte);

}


}
/**************************************************************/
void
on_button9ac_clicked                   (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *anom,*atype,*aident,*apoids,*adans,*un1,*un2,*un3,*err1;
prod a_p;
int n1 ,n2 ;
char ch111[100],ch222[50],texte[50],ch8[50];
anom = lookup_widget(objet_graphique,"entry2ac");
atype = lookup_widget(objet_graphique,"combobox2ac");
aident = lookup_widget(objet_graphique,"spinbutton3ac");
apoids = lookup_widget(objet_graphique,"spinbutton4ac");
un1 = lookup_widget(objet_graphique,"radiobutton4ac");
un2 = lookup_widget(objet_graphique,"radiobutton5ac");
un3 = lookup_widget(objet_graphique,"radiobutton6ac");
adans = lookup_widget(objet_graphique,"checkbutton2ac");


strcpy(a_p.nom,gtk_entry_get_text(GTK_ENTRY(anom)));
strcpy(a_p.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(atype)));
n1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(aident));
sprintf(ch111,"%d",n1);
strcpy(a_p.ident,ch111);
n2=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(apoids));
sprintf(ch222,"%d\n",n2);
strcpy(a_p.poids,ch222);
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(un1))) {strcpy(a_p.unite,"kg");}
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(un2))) {strcpy(a_p.unite,"litre");} 
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(un3))) {strcpy(a_p.unite,"autre");} 
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(adans))) {strcpy(a_p.dans,"frigo");}
else {strcpy(a_p.dans,"NON");}
modif_prod1(a_p,ch111);

/*
if (verif(ch111)==0){sprintf(texte,"%s \n" ,"le produit est supprimer");
err1=lookup_widget(objet_graphique,"label30ac");
gtk_label_set_text(GTK_LABEL(err1),texte);
*/
/*
if ( verif(ch8)==1) {
sprintf(texte,"%s \n" ,"le produit est modifie");
err1=lookup_widget(objet_graphique,"label23ac");
gtk_label_set_text(GTK_LABEL(err1),texte);}
else{sprintf(texte,"%s \n" ,"le produit n est pas trouvee");*/
strcpy(texte,ch111);
err1=lookup_widget(objet_graphique,"label23ac");
gtk_label_set_text(GTK_LABEL(err1),texte);
}


/**********************************************************************/

void
on_button11ac_clicked                  (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window3;
GtkWidget *window1;;
window3=lookup_widget(objet_graphique,"window3ac");
window1=create_window1ac();
gtk_widget_show(window1);
gtk_widget_destroy(window3);
}
/************************************************************************/

void
on_button12ac_clicked                  (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *aident,*err1 ;
char identite[50],ch222[100],texte[100];
int n1 ;
aident = lookup_widget(objet_graphique,"spinbutton5ac");
n1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(aident));
sprintf(identite,"%d",n1);
rech_prod1(identite,ch222);

strcpy(texte,ch222);

err1=lookup_widget(objet_graphique,"label25ac");
gtk_label_set_text(GTK_LABEL(err1),texte);


}
/*********************************************************************/

void
on_button13ac_clicked                 (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window4;
GtkWidget *window1;
window4=lookup_widget(objet_graphique,"window4ac");
window1=create_window1ac();
gtk_widget_show(window1);
gtk_widget_destroy(window4);
}


void
on_button15ac_clicked                  (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window5;
GtkWidget *window1;
window5=lookup_widget(objet_graphique,"window5ac");
window1=create_window1ac();
gtk_widget_show(window1);
gtk_widget_destroy(window5);
}
/*************************************************************************/

void
on_button14ac_clicked                  (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *aident,*err1 ;
char ch111[50],texte[50];
int n1 ;
aident = lookup_widget(objet_graphique,"spinbutton6ac");
n1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(aident));
sprintf(ch111,"%d",n1);

supprimer_prod1(ch111);
if (verif(ch111)==0){
sprintf(texte,"%s \n" ,"    le produit \n est supprimer");
err1=lookup_widget(objet_graphique,"label30ac");
gtk_label_set_text(GTK_LABEL(err1),texte);


}else{
sprintf(texte,"%s \n" ,"le produit n est pas \n supprimer");
err1=lookup_widget(objet_graphique,"label30ac");
gtk_label_set_text(GTK_LABEL(err1),texte);

}
}

/***********************************************************************/







void
on_buttonalarmeac_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window6;
GtkWidget *window1,*err1;
char ch222[200],texte[200];

/*
verif(ch111)==0){sprintf(texte,"%s \n" ,"le produit est supprimer");
err1=lookup_widget(objet_graphique,"label30ac");
gtk_label_set_text(GTK_LABEL(err1),texte);
*/
alarme_rupture( repture1) ;

strcpy(texte,repture1);
err1=lookup_widget(objet_graphique,"label32ac");
gtk_label_set_text(GTK_LABEL(err1),texte);


GdkColor color;
	gdk_color_parse("blue",&color);
	gtk_widget_modify_fg(err1,GTK_STATE_NORMAL,&color);
	gtk_label_set_text(GTK_LABEL(err1),repture1);

}



void
on_button4444_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Admin, *window1ac;

window1ac=lookup_widget(objet,"window1ac");
gtk_widget_destroy(window1ac);
Admin=lookup_widget(objet,"Admin");
Admin=create_Admin();
gtk_widget_show(Admin);
}


void
on_button4445_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Admin, *dashboard6;

dashboard6=lookup_widget(objet,"dashboard6");
gtk_widget_destroy(dashboard6);
Admin=lookup_widget(objet,"Admin");
Admin=create_Admin();
gtk_widget_show(Admin);
}


void
on_buttonstart_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *inscription, *start;

start=lookup_widget(objet,"start");
gtk_widget_destroy(start);
inscription=lookup_widget(objet,"inscription");
inscription=create_inscription();
gtk_widget_show(inscription);
}


void
on_button44467_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *af_utilisateur, *dashboard_utilisateur;

af_utilisateur=lookup_widget(objet,"af_utilisateur");
gtk_widget_destroy(af_utilisateur);
dashboard_utilisateur=lookup_widget(objet,"dashboard_utilisateur");
dashboard_utilisateur=create_dashboard_utilisateur();
gtk_widget_show(dashboard_utilisateur);
}


void
on_button44468_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *recherche, *dashboard_utilisateur;

recherche=lookup_widget(objet,"recherche");
gtk_widget_destroy(recherche);
dashboard_utilisateur=lookup_widget(objet,"dashboard_utilisateur");
dashboard_utilisateur=create_dashboard_utilisateur();
gtk_widget_show(dashboard_utilisateur);
}

