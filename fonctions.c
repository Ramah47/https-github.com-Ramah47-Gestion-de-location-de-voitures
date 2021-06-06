

void gotoxy(int x,int y){
    COORD c = {0,0};
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);

}

int creationMenu(int x,int y,listeMenu *menu,int nbr, char *titre){

    int xpos_begin = x, ypos_begin = y , xpos_end, ypos_end  ;

    //char *titre="Gestion des voitures";

    gotoxy(xpos_begin+20,ypos_begin);
    printf("%s",titre);

    ypos_begin = ypos_begin+2;

    int largeur =60, hauteur = 3+nbr*2;

    xpos_end = xpos_begin + largeur;
    ypos_end = ypos_begin + hauteur;

    int i,j;

    gotoxy(xpos_begin,ypos_begin);

    for (i = xpos_begin; i<xpos_end;i++){
        printf("%c",223);
        //printf("\xcd");
    }


    gotoxy(xpos_begin,ypos_end);

    for (i = xpos_begin; i<xpos_end+1; i++){
        printf("%c",223);
        //printf("\xcd");
    }

    for (j=ypos_begin;j<ypos_end; j++){
        gotoxy(xpos_begin,j);
        printf("%c",219);
        //printf("\xba");
        gotoxy(xpos_end,j);
        printf("%c",219);
        //printf("\xba");
    }


    for ( i = 0 ; i<nbr ;i++ ){
        gotoxy(xpos_begin+6,ypos_begin+2+i*2);
        printf("%-45s  %d",(menu+i)->textChoix, (menu+i)->numChoix);

    }

    return ypos_end+1;

}

int menuPrincipale(){
    int ypos_choix,choix;
    listeMenu menu[4] ;

    *menu = (listeMenu){1 , "Location"};
    *(menu+1) = (listeMenu){2 , "Gestion Voitures"};
    *(menu+2) = (listeMenu){3 , "Gestion Clients"};
    *(menu+3) = (listeMenu){4 , "Quitter"};

    system("COLOR 1E");
    system("cls");

    ypos_choix = creationMenu(25,2,menu,4,"Menu principale");

    gotoxy(40,ypos_choix);




    printf("Votre Choix : ");
    scanf("%d",&choix);



    return choix;

}


int menuVoitures(){
    int ypos_choix,choix;
    listeMenu menu[5] ;

    *menu = (listeMenu){1 , "Liste des voitures"};
    *(menu+1) = (listeMenu){2 , "Ajouter voiture"};
    *(menu+2) = (listeMenu){3 , "Modifier voiture"};
    *(menu+3) = (listeMenu){4 , "Supprimer voiture"};
    *(menu+4) = (listeMenu){5 , "Retour"};

    system("COLOR 1E");
    system("cls");

    ypos_choix = creationMenu(25,2,menu,5,"Gestion des Voitures");

    gotoxy(40,ypos_choix);




    printf("Votre Choix : ");
    scanf("%d",&choix);



    return choix + 10;

}

int menuClients(){
    int ypos_choix,choix;
    listeMenu menu[5] ;

    *menu = (listeMenu){1 , "Liste des clients"};
    *(menu+1) = (listeMenu){2 , "Ajouter client"};
    *(menu+2) = (listeMenu){3 , "Modifier client"};
    *(menu+3) = (listeMenu){4 , "Supprimer client"};
    *(menu+4) = (listeMenu){5 , "Retour"};

    system("COLOR 1E");
    system("cls");

    ypos_choix = creationMenu(25,2,menu,5,"Gestion des Clients");

    gotoxy(40,ypos_choix);




    printf("Votre Choix : ");
    scanf("%d",&choix);

    switch(choix){
        case 1: ;break;
        case 2: ; break;
        case 3: ; break;
        case 4: ; break;
        case 5: menuPrincipale(); break;

    }

    return choix + 20;

}


int menuLocation(){
    int ypos_choix,choix;
    listeMenu menu[6] ;

    *menu = (listeMenu){1 , "Visualiser contrat"};
    *(menu+1) = (listeMenu){2 , "Louer voiture"};
    *(menu+2) = (listeMenu){3 , "Retourner voiture"};
    *(menu+3) = (listeMenu){4 , "Modifier contrat"};
    *(menu+4) = (listeMenu){5 , "Supprimer contrat"};
    *(menu+5) = (listeMenu){6 , "Retour"};

    system("COLOR 1E");
    system("cls");

    ypos_choix = creationMenu(25,2,menu,6,"Gestion des Clients");

    gotoxy(40,ypos_choix);




    printf("Votre Choix : ");
    scanf("%d",&choix);


    return choix + 30;

}

