#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<conio.h>
#include<string.h>
#include "structures.h"
#include "traitement.h"
#include "traitement.c"
#include "fonctions.h"
#include "fonctions.c"



int Menu_AjouterVoitures(list_voitures *Mes_Voitures){
    int idVoiture;
    char marque[15];
    char couleur[15];
    int nbplaces;
    int prixjour;
    char EnLocation[4];

    printf("\t\tId : ");
    scanf("%d",&idVoiture);
    printf("\t\tMarque : ");
    scanf("%s",&marque);
    printf("\t\tCouleur : ");
    scanf("%s",&couleur);
    printf("\t\tNombre de place: ");
    scanf("%d",&nbplaces);
    printf("\t\tPrix Jour : ");
    scanf("%d",&prixjour);
    printf("\t\tEn Location : ");
    scanf("%s",&EnLocation);

    Ajouter_voiture(Mes_Voitures,idVoiture,marque,couleur,nbplaces,prixjour,EnLocation);

    printf("Voiture Bien ajoutée (taper une touche pour retour) :");

    getch();
    return 2;

}

int Menu_AffichageVoiture(list_voitures *Mes_Voitures){
    system("cls");
    Affichage_voiture(*Mes_Voitures);

    printf("Taper une touche pour retour :");
    getch();

    return 2;
}


void ChargerVoituresFromFichier(list_voitures *Mes_Voitures){

    Voiture v;
    FILE* fichier = NULL;
    fichier = fopen("voitures.txt", "r+");



    if (fichier!=NULL) {
        while(fscanf(fichier, "%d,%[^,],%[^,],%d,%d,%[^\n]\n", &v.idVoiture, v.marque, v.couleur, &v.nbplaces,&v.prixjour,v.EnLocation) != EOF) {
            Ajouter_voiture(Mes_Voitures,v.idVoiture, v.marque, v.couleur, v.nbplaces,v.prixjour,v.EnLocation);

        }

        fclose(fichier);


    }
    else
    {
        printf("problem ouverture de fichier");
    }

}





int Menu_AjouterClients(list_clients *Mes_clients){

    int idClient;
    char nom[20];
    char prenom[20];
    char cin[20];
    char adresse[30];
    char tel[30];
    char temp;

    printf("\t\tId Client : ");
    scanf("%d",&idClient);
    printf("\t\tNom : ");
    scanf("%s",nom);
    printf("\t\tPrenom : ");
    scanf("%s",prenom);
    printf("\t\tCIN : ");
    scanf("%s",cin);
    printf("\t\tAdresse : ");
    //scanf("%s",adresse);
    //scanf("%c",temp);
    scanf("\n%[^\n]",adresse);
    printf("\t\tTelephone : ");
    scanf("%s",tel);

    Ajouter_client(Mes_clients,idClient,prenom,nom,cin,adresse,tel);

    printf("Client Bien ajouté (taper une touche pour retour) :");

    getch();
    return 3;

}

int Menu_AffichageClient(list_clients *Mes_clients){
    system("cls");
    Affichage_client(*Mes_clients);

    printf("Taper une touche pour retour :");
    getch();

    return 3;
}


int main()
{
    int choix;
    list_voitures Mes_Voitures;
    list_clients Mes_clients;
	list_contrats Mes_contrats;

	/*La liste doit obligatoirement être initialisé avant utilisation*/
    Init_listVoitures(&Mes_Voitures);
    Init_listclients(&Mes_clients);
    Init_listcontrats(&Mes_contrats);

    //Menu_AjouterClients(&Mes_clients);


    ChargerVoituresFromFichier(&Mes_Voitures);



    choix = menuPrincipale();
    do {

        switch(choix){
            case 1: choix = menuLocation();break;
            case 2: choix = menuVoitures(); break;
            case 3: choix = menuClients(); break;
            case 11: choix = Menu_AffichageVoiture(&Mes_Voitures);break;
            case 12: choix = Menu_AjouterVoitures(&Mes_Voitures);break;

            case 21: choix = Menu_AffichageClient(&Mes_clients);break;
            case 22: choix = Menu_AjouterClients(&Mes_clients);break;

            case 15: case 26: case 36: choix = menuPrincipale();break;
            default: choix = menuPrincipale();break;

        }
    } while(choix!=4);

    printf("\n");




    return 0;
}








