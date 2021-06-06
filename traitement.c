
// Fonctions d'initilisation des pointeurs
void Init_listVoitures(list_voitures *l)
{
   l->first = NULL;
   l->last = NULL;
}

void Init_listclients(list_clients *l)
{
   l->first = NULL;
   l->last = NULL;
}
void Init_listcontrats(list_contrats *l)
{
   l->first = NULL;
   l->last = NULL;
}

// Les fonctions de manipulation de Voitures

// ajout

void Ajouter_voiture(list_voitures *l, int id,char m[],char c[],int nbp,int prix,char etat[])
{
   Voiture *nouv = malloc(sizeof(Voiture));
   if(!nouv) exit(EXIT_FAILURE);

   nouv->idVoiture = id;
   strcpy(nouv->marque , m);
   strcpy(nouv->couleur,c);
   strcpy(nouv->EnLocation,etat);
   nouv->nbplaces = nbp;
   nouv->prixjour = prix;

   nouv->next = l->first;
   nouv->prev = NULL;

   if(l->first) l->first->prev = nouv;
   else l->last = nouv;
   l->first = nouv;
}
// Affichage

void Affichage_voiture(list_voitures l)
{
   Voiture *pelem = l.first;
   while(pelem)
   {
    printf("\n--------------------Voiture-------------------------\n");
	printf("id: %d\n",pelem->idVoiture);
    printf("marque: %s\n",pelem->marque);
	printf("couleur: %s\n",pelem->couleur);
    printf("Nombre places: %d\n",pelem->nbplaces);
    printf("Prix jour: %d\n",pelem->prixjour);
    printf("En location : %s\n",pelem->EnLocation);
    pelem = pelem->next;
    printf("\n--------------------------------------------------\n");
   }
}


// Les fonctions de manipulation de Clients

// ajout
void Ajouter_client(list_clients *l, int id,char p[],char n[],char c[],char ad[],char t[])
{
   Client *nouv = malloc(sizeof(Client));
   if(!nouv) exit(EXIT_FAILURE);

   nouv->idClient = id;
   strcpy(nouv->nom , n);
   strcpy(nouv->prenom,p);
   strcpy(nouv->cin,c);
   strcpy(nouv->adresse,ad);
   strcpy(nouv->tel,t);
   nouv->next = l->first;
   nouv->prev = NULL;

   if(l->first) l->first->prev = nouv;
   else l->last = nouv;
   l->first = nouv;
}
// Affichage

void Affichage_client(list_clients l)
{
   Client *pelem = l.first;
   while(pelem)
   {
    printf("\n------------------Client----------------------\n");
	printf("id: %d\n",pelem->idClient);
    printf("Nom: %s\n",pelem->nom);
	printf("Prenom: %s\n",pelem->prenom);
    printf("CIN: %s\n",pelem->cin);
    printf("Telephone: %s\n",pelem->tel);
    printf("Adresse: %s\n",pelem->adresse);

    pelem = pelem->next;
    printf("\n--------------------------------------------------\n");
   }
}


// Les fonctions de manipulation de Contrats

// ajout

void Ajouter_contrat(list_contrats *l, int n,int iv,int ic,char dd[],char df[],float c)
{
   contratLocation *nouv = malloc(sizeof(contratLocation));
   if(!nouv) exit(EXIT_FAILURE);

   nouv->numContrat =n;
   strcpy(nouv->date_debut , dd);
   strcpy(nouv->date_fin,df);
   nouv->idClient = ic;
   nouv->idVoiture = iv;
   nouv->cout = c;

   nouv->next = l->first;
   nouv->prev = NULL;

   if(l->first) l->first->prev = nouv;
   else l->last = nouv;
   l->first = nouv;
}
// Affichage

void Affichage_contrat(list_contrats l)
{
   contratLocation *pelem = l.first;
   while(pelem)
   {
    printf("\n------------------Contrat----------------------\n");
	printf("Numero de contrat: %d\n",pelem->numContrat);
    printf("Id client: %d\n",pelem->idClient);
	printf("Id voiture: %d\n",pelem->idVoiture);
    printf("Date debut: %s\n",pelem->date_debut);
    printf("Date fin: %s\n",pelem->date_fin);
    printf("cout: %.2f\n",pelem->cout);

    pelem = pelem->next;
    printf("\n--------------------------------------------------\n");
   }
}
