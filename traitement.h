#ifndef TRAITEMENT_H_INCLUDED
#define TRAITEMENT_H_INCLUDED

void Init_listVoitures(list_voitures *l);
void Init_listclients(list_clients *l);
void Init_listcontrats(list_contrats *l);

void Ajouter_voiture(list_voitures *l, int id,char m[],char c[],int nbp,int prix,char etat[]);
void Ajouter_client(list_clients *l, int id,char p[],char n[],char c[],char ad[],char t[]);
void Ajouter_contrat(list_contrats *l, int n,int iv,int ic,char dd[],char df[],float c);

void Affichage_voiture(list_voitures l);
void Affichage_client(list_clients l);
void Affichage_contrat(list_contrats l);


#endif // TRAITEMENT_H_INCLUDED
