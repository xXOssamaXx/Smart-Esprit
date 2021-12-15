#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include<string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "agent.h"
int x ;
int choix[]={0,0,0,0,0};
GtkWidget *fenetre_ajout;


void
on_button1_ajouter_clicked            		 (GtkWidget       *objet,
                                        	gpointer         user_data)
{

agent a ;
char text1[30];
GtkWidget *input1 , *input2 ,*input3 ;
GtkWidget *output,*fenetre_oussama_afficher,*poste;
GtkWidget *fenetre_oussama_ajouter;

poste=lookup_widget(objet,"combobox1");
fenetre_oussama_ajouter = lookup_widget (objet,"fenetre_oussama_ajouter") ;
input1 = lookup_widget(objet,"entry1");
input2 = lookup_widget(objet,"entry2");
input3 = lookup_widget(objet,"entry3");

strcpy(a.cin1,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(a.nom1,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(a.id1,gtk_entry_get_text(GTK_ENTRY(input3)));
/////ajouter ici
strcpy(a.role1,gtk_combo_box_get_active_text(GTK_COMBO_BOX(poste)));
ajouter_agent( a);
}


void
on_button2_afficher_clicked            (GtkWidget       *objet,
                                        	gpointer         user_data)
{
GtkWidget *fenetre_oussama_ajouter ;
GtkWidget *fenetre_oussama_afficher;
GtkWidget *treeview1;

fenetre_oussama_ajouter=lookup_widget(objet,"fenetre_oussama_ajouter");


gtk_widget_destroy(fenetre_oussama_ajouter);
fenetre_oussama_afficher=lookup_widget(objet,"fenetre_oussama_afficher");
fenetre_oussama_afficher=create_fenetre_oussama_afficher();

gtk_widget_show(fenetre_oussama_afficher);
treeview1=lookup_widget(fenetre_oussama_afficher,"treeview1");
afficher_agent(treeview1);
}




void
on_checkbutton1_valider_ajout_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
//toggled button

if (gtk_toggle_button_get_active(togglebutton))
{;
}}


void
on_treeview1_row_activated             (GtkTreeView     *treeview1,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter ;
	gchar* nom1;
	gchar* cin1;
	gchar* id1;
	gchar* role1;
	agent a ;

GtkTreeModel *model = gtk_tree_view_get_model(treeview1);
if (gtk_tree_model_get_iter(model,&iter,path))
{
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter ,0,&cin1,1,&nom1,2,&id1,3,&role1,-1);
	strcpy(a.cin1,cin1);
	strcpy(a.nom1,nom1);
	strcpy(a.id1,id1);
	strcpy(a.role1,role1);
	supprimer_agent(a);
	afficher_agent(treeview1);
}
}
///works
////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////ajout et affichage/////////////////////////////////


void
on_button6_aller__menu_clicked         (GtkWidget       *objet,
                                        	gpointer         user_data)
{/*
GtkWidget *fenetre_menu,*fenetre_oussama_afficher;
gtk_widget_destroy(fenetre_oussama_afficher);
fenetre_menu=create_fenetre_menu();
gtk_widget_show(fenetre_menu);*/
}


void
on_button4_aller_chercher_clicked      (GtkWidget       *objet,
                                        	gpointer         user_data)
{
char id [30];
agent a;
 GtkWidget *fenetre_rechercher, *fenetre_oussama_afficher;//ici
 fenetre_oussama_afficher=lookup_widget(objet,"fenetre_oussama_afficher");

 gtk_widget_destroy(fenetre_oussama_afficher);
 fenetre_oussama_afficher=create_fenetre_oussama_afficher();
 gtk_widget_show(fenetre_rechercher);
 verif_agent(id); 
}


void
on_button3_aller_modif_clicked         (GtkWidget       *objet,
                                        	gpointer         user_data)
{
GtkWidget *fenetre_oussama_afficher;
GtkWidget *fenetre_oussama_modifier;
GtkWidget *treeview1;
GtkTreeSelection *selection ;
GtkTreeModel *model;
GtkTreeIter iter;
GSList *group;
	gchar* cin1;
	gchar* nom1;
	
agent a;	
GtkWidget *cin,*nom;
fenetre_oussama_afficher=lookup_widget(objet,"fenetre_oussama_afficher");

   treeview1=lookup_widget(fenetre_oussama_afficher,"treeview1");
   selection=gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview1));

    if(gtk_tree_selection_get_selected(selection,&model,&iter)) {
	gtk_tree_model_get(GTK_LIST_STORE(model), &iter,0,&cin1,1,&nom1,-1);

	strcpy(a.cin1,cin1);
	strcpy(a.nom1,nom1);}
	
gtk_widget_destroy(fenetre_oussama_afficher);

fenetre_oussama_modifier=create_fenetre_oussama_modifier();
gtk_widget_show(fenetre_oussama_modifier);

cin=lookup_widget(fenetre_oussama_modifier,"entry4");
nom=lookup_widget(fenetre_oussama_modifier,"entry5");

gtk_entry_set_text(GTK_ENTRY(nom),a.nom1);
gtk_entry_set_text(GTK_ENTRY(cin),a.cin1);
}


void
on_button2_actualiser_clicked          (GtkWidget       *objet,
                                        	gpointer         user_data)
{
GtkWidget *fenetre_oussama_afficher,*w1;
GtkWidget *treeview1;
w1=lookup_widget(objet,"fenetre_oussama_afficher");
fenetre_oussama_afficher=create_fenetre_oussama_afficher();

gtk_widget_show(fenetre_oussama_afficher);
gtk_widget_hide(w1);
treeview1=lookup_widget(fenetre_oussama_afficher,"treeview1");
vider(treeview1);
afficher_agent(treeview1);
}


void
on_button1_retour_clicked              (GtkWidget       *objet,
                                        	gpointer         user_data)
{

}


void
on_button7_confirm_modif_clicked       (GtkWidget       *objet,
                                        	gpointer         user_data)
{
GtkWidget *fenetre_oussama_modifier;
agent a;
GtkWidget *treeview3,*input1, *input2,*w;
GtkWidget *sortie22;

fenetre_oussama_modifier=lookup_widget(objet,"fenetre_oussama_modifier");
input1=lookup_widget(objet,"entry4");
input2=lookup_widget(objet,"entry5");
sortie22=lookup_widget(objet,"label12");

strcpy(a.cin1,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(a.nom1,gtk_entry_get_text(GTK_ENTRY(input2)));
modifier_agent(a);

///////////////////////////////////////////////////couleur
GdkColor color;
gdk_color_parse("green",&color);
gtk_widget_modify_fg(sortie22,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(sortie22),"client modifié avec succés");
/////////////////////////////////////////////////////////////////////


}


void
on_treeview2_row_activated             (GtkTreeView     *treeview2,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{/*
GtkTreeIter iter ;
	char jour_cap[20];
	char heure_cap[20];
	char num_cap[20];
	char val_debit[20];
	capteur cap;

GtkTreeModel *model = gtk_tree_view_get_model(treeview2);
if (gtk_tree_model_get_iter(model,&iter,path))
{
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter ,0,&jour_cap,1,&heure_cap,2,&num_cap,3,&val_debit,-1);
	strcpy(cap.jour_cap,jour_cap);
	strcpy(cap.heure_cap,heure_cap);
	strcpy(cap.num_cap,num_cap);
	strcpy(cap.val_debit,val_debit);
	afficher_capteur(treeview2);
}
afficher_capteur(treeview2);*/
}


void
on_button5_retour_afficher_clicked     (GtkWidget       *objet,
                                        	gpointer         user_data)
{/*
GtkWidget *fenetre_rechercher, *fenetre_afficher;
fenetre_rechercher=lookup_widget(objet,"fenetre_rechercher");

gtk_widget_destroy(fenetre_rechercher);
fenetre_afficher=create_fenetre_afficher();
gtk_widget_show(fenetre_afficher);*/
}


void
on_radiobutton3_capteurs_administration_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_radiobutton4_blocs_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_button8_affiche_capteur_clicked     (GtkWidget       *objet,
                                        	gpointer         user_data)
{

}


void
on_treeview3_row_activated             (GtkTreeView     *treeview3,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{/*
GtkTreeIter iter ;
	gchar* nom1;
	gchar* cin1;
	gchar* id1;
	gchar* role1;
	agent a ;

GtkTreeModel *model = gtk_tree_view_get_model(treeview3);
if (gtk_tree_model_get_iter(model,&iter,path))
{
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter ,0,&cin1,1,&nom1,2,&id1,3,&role1,-1);
	strcpy(a.cin1,cin1);
	strcpy(a.nom1,nom1);
	strcpy(a.id1,id1);
	strcpy(a.role1,role1);
	
	afficher_agent(treeview3);

}*/	
}


void
on_button1_retour_affichage_cap_clicked
                                        (GtkWidget       *objet,
                                        	gpointer         user_data)

{

}


void
on_button1_recherche_final_clicked     (GtkWidget       *objet,
                                        	gpointer         user_data)
{

}


void
on_button2_retour_affichage_princip_clicked
                                        (GtkWidget       *objet,
                                        	gpointer         user_data)
{
GtkWidget *fenetre_rechercher, *fenetre_oussama_afficher;
fenetre_rechercher=lookup_widget(objet,"fenetre_oussama_afficher");

gtk_widget_destroy(fenetre_rechercher);
fenetre_oussama_afficher=create_fenetre_oussama_afficher();
gtk_widget_show(fenetre_oussama_afficher);
}

