#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include <time.h>
#define NB_MAX 2


// Declaration de variables globales

GtkWidget* pFenetre;
GtkWidget* pBouton0;
GtkWidget* pBouton1;
GtkWidget* pBouton2;
GtkWidget* pBouton3;
GtkWidget* recommencer;
GtkWidget* pScore;
GtkWidget* pLabel;
GtkWidget* coffreF;
GtkWidget* vide;
GtkWidget* remplie;
//GtkWidget* choix;
//GtkWidget* choice[3];
int defaites=0, victoires=0;
//Declaration dde la boite horizontale
GtkWidget* pHBox;
GtkWidget* pVBox;
//Declaration des fonctions
//void scores_mise_a_jour();
void choix_coffre(GtkWidget* pBouton, gpointer data);
void scores_mise_a_jour();
void choix_coffre_autre(GtkWidget* pBouton);
void rejouer();
int main(int argc, char** argv)
{
  // Initialisation de l’environnement gtk
  gtk_init(&argc, &argv);

  // Creation d’une fenêtre
  pFenetre = gtk_window_new(GTK_WINDOW_TOPLEVEL);

  // Titre de la fenêtre
  gtk_window_set_title(GTK_WINDOW(pFenetre), "Le jeu du trésor");
  pLabel = gtk_label_new("Choisissez un coffre !");
  pScore = gtk_label_new("Victoires: Défaites:");

  // Taille de la fenêtre
  gtk_window_set_default_size(GTK_WINDOW(pFenetre), 700, 200); 
  // Création d'un bouton
  pBouton1 = gtk_button_new();
  pBouton2 = gtk_button_new();
  pBouton3 = gtk_button_new();
  recommencer = gtk_button_new_with_label("Recommencer");
  //Ajout des images aux boutons
  coffreF = gtk_image_new_from_file("./coffreF.jpg");
  gtk_button_set_image(GTK_BUTTON(pBouton1), coffreF);

  coffreF = gtk_image_new_from_file("./coffreF.jpg");
  gtk_button_set_image(GTK_BUTTON(pBouton2), coffreF);

  coffreF = gtk_image_new_from_file("./coffreF.jpg");
  gtk_button_set_image(GTK_BUTTON(pBouton3), coffreF);
  //Création de la boîte
  pHBox = gtk_hbox_new(TRUE,10);
  pVBox = gtk_vbox_new(FALSE,0);
  //Ajout des bouton à la boîte
  gtk_box_pack_start(GTK_BOX(pHBox), pBouton1, FALSE, TRUE, 10);
  gtk_box_pack_start(GTK_BOX(pHBox), pBouton2, FALSE, TRUE, 10);
  gtk_box_pack_start(GTK_BOX(pHBox), pBouton3, FALSE, TRUE, 10);
  gtk_box_pack_start(GTK_BOX(pVBox), pLabel, FALSE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(pVBox), pScore, FALSE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(pVBox), recommencer, FALSE, TRUE, 0);


  // Ajout de la boîte à la fenêtre
  gtk_container_add(GTK_CONTAINER(pVBox), pHBox);
  gtk_container_add(GTK_CONTAINER(pFenetre), pVBox);

  // Affichage de la fenêtre
  gtk_widget_show_all(pFenetre);

  //gtk_widget_set_sensitive(recommencer, FALSE);
	gtk_signal_connect(GTK_OBJECT(pFenetre), "destroy", G_CALLBACK(gtk_main_quit), NULL);
        gtk_signal_connect(GTK_OBJECT(pBouton1), "clicked", G_CALLBACK(choix_coffre_autre), NULL);
	gtk_signal_connect(GTK_OBJECT(pBouton2), "clicked", G_CALLBACK(choix_coffre_autre), NULL);
	gtk_signal_connect(GTK_OBJECT(pBouton3), "clicked", G_CALLBACK(choix_coffre_autre), NULL);
	gtk_signal_connect(GTK_OBJECT(recommencer), "clicked", G_CALLBACK(rejouer), NULL);
	gtk_widget_set_sensitive(recommencer, FALSE);


  // Lancement de la boucle événementielle
  gtk_main();

  return EXIT_SUCCESS;
}

//Définitions des fonctions
void choix_coffre(GtkWidget* pBouton, gpointer date) /* afiiche perdu si le bouton contient image tresor vide et affiche gagné si contient 								image gagné */
{	
	 srand(time(NULL));
	 int coffre_tresor = rand() % (3-2+1) + 2;
		if(coffre_tresor == 2)
			{
			 vide = gtk_image_new_from_file("./coffreV.jpg");
		 	 gtk_button_set_image(GTK_BUTTON(pBouton), vide);
			 gtk_label_set_label(GTK_LABEL(pLabel),"Perdu");
			 defaites++;
			}
		else
			{
			 remplie = gtk_image_new_from_file("./tresor.jpg");
		 	 gtk_button_set_image(GTK_BUTTON(pBouton), remplie);
			 gtk_label_set_label(GTK_LABEL(pLabel),"Gagné");
			 victoires++;
				
			}
	    		gtk_widget_set_sensitive(recommencer, TRUE);
			scores_mise_a_jour();
}

void choix_coffre_autre(GtkWidget* pBouton)
{
        gtk_signal_connect(GTK_OBJECT(pBouton1), "clicked", G_CALLBACK(choix_coffre), NULL);
 	gtk_signal_connect(GTK_OBJECT(pBouton2), "clicked", G_CALLBACK(choix_coffre), NULL);
	gtk_signal_connect(GTK_OBJECT(pBouton3), "clicked", G_CALLBACK(choix_coffre), NULL);
	if(pBouton == pBouton1)
	{
	 srand(time(NULL));
 	 int coffre_tresor = rand() % (2-1+1) + 1;
		if (coffre_tresor == 1)
		{
		 gtk_button_set_image(GTK_BUTTON(pBouton2), gtk_image_new_from_file("./coffreV.jpg"));	
		}	
		else
		{
	 	 gtk_button_set_image(GTK_BUTTON(pBouton3), gtk_image_new_from_file("./coffreV.jpg"));
		} 
	}
	else if(pBouton == pBouton2)
	{
	 srand(time(NULL));
 	 int coffre_tresor = rand() % (2-0+1) + 1;
		if(coffre_tresor == 0)
		{
		 gtk_button_set_image(GTK_BUTTON(pBouton1), gtk_image_new_from_file("./coffreV.jpg"));			 
		}
		else
		{
		 gtk_button_set_image(GTK_BUTTON(pBouton3), gtk_image_new_from_file("./coffreV.jpg"));			 		 
		}	
	}
	else if(pBouton == pBouton3)
	{
	 srand(time(NULL));
 	 int coffre_tresor = rand() % (1-0+1) + 1;
		if(coffre_tresor == 0)
		{
		 gtk_button_set_image(GTK_BUTTON(pBouton1), gtk_image_new_from_file("./coffreV.jpg"));			 
		}
		else
		{
		 gtk_button_set_image(GTK_BUTTON(pBouton2), gtk_image_new_from_file("./coffreV.jpg"));			 		 
		}	
	}
}


void scores_mise_a_jour()
{
	char message[100];
	sprintf(message,"Victoire: %d Défaites: %d",victoires,defaites);
	gtk_label_set_text(GTK_LABEL(pScore), message);
}

void rejouer()
{
	gtk_button_set_image(GTK_BUTTON(pBouton1), gtk_image_new_from_file("./coffreF.jpg"));
	gtk_button_set_image(GTK_BUTTON(pBouton2), gtk_image_new_from_file("./coffreF.jpg"));
	gtk_button_set_image(GTK_BUTTON(pBouton3), gtk_image_new_from_file("./coffreF.jpg"));
	gtk_widget_set_sensitive(recommencer, FALSE);
	gtk_label_set_label(GTK_LABEL(pLabel),"Choisissez un coffre !");
}
