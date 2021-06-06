#ifndef structures
#define structures

typedef struct {
    int numChoix;
    char* textChoix;


} listeMenu;

// la définition des structures
typedef struct Voiture
        {
                int idVoiture;
                char marque[15];
                char couleur[15];
                int nbplaces;
                int prixjour;
                char EnLocation[4];
                struct voiture *prev;
                struct voiture *next;
        } Voiture ;
typedef struct Client
        {
                int idClient;
                char nom[20];
                char prenom[20];
                char cin[20];
                int prixjour;
                char adresse[30];
                char tel[30];
                struct Client *prev;
                struct Client *next;
        } Client ;
typedef struct contratLocation
        {
                int numContrat;
                int idVoiture;
                int idClient;
                char date_debut[30];
                char date_fin[30];
                float cout;
                struct contratLocation *prev;
                struct contratLocation *next;
        } contratLocation ;

// Les listes doublement chainee pour stockage des donnees
typedef struct
        {
          Voiture *first;
          Voiture *last;
        }list_voitures;
typedef struct
        {
          contratLocation *first;
          contratLocation *last;
        }list_contrats;
typedef struct
        {
          Client *first;
          Client *last;
        }list_clients;

#endif // FONCTIONS_H_INCLUDED


