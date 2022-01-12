#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "le_pendu.h"
#include "pierre_feuille_ciseau.h"
#include "mastermind.h"

// LA STRUCTURE SAUVEGARDE LE PROFIL ET SCORE DUN JOUEUR
typedef struct SCORE
{
    char nom[3];
    int win_pendu;
    int lose_pendu;
    int win_pierre_papier_ciseau;
    int lose_pierre_papier_ciseau;
    int win_mastermind;
    int lose_mastermind;
}score;

// CHANGE LE SCORE (VICTOIRE = 0) DU JOUEUR EN FONCTION DU JEU
// DANS LE SWITCH CASE: 1 = PENDU 2 = PFC 3 = MASTERMIND
void updateprofile(score* liste_score,char *player_name,int win, int jeu, int nb_joueur){
    switch(jeu){
    case 1:
        for(int i=0;i<nb_joueur;i++){
            if(win==1 && strcmp(player_name,liste_score[i].nom)==0){
                liste_score[i].win_pendu+=1;
            }
            if(win==0 && strcmp(player_name,liste_score[i].nom)==0){
                liste_score[i].lose_pendu+=1;
            }
        }
        break;
    case 2:
        for(int i=0;i<nb_joueur;i++){
            if(win==1 && strcmp(player_name,liste_score[i].nom)==0){
                liste_score[i].win_pierre_papier_ciseau+=1;
            }
            if(win==0 && strcmp(player_name,liste_score[i].nom)==0){
                liste_score[i].lose_pierre_papier_ciseau+=1;
            }
        }
        break;
    case 3:
        for(int i=0;i<nb_joueur;i++){
            if(win==1 && strcmp(player_name,liste_score[i].nom)==0){
                liste_score[i].win_mastermind+=1;
            }
            if(win==0 && strcmp(player_name,liste_score[i].nom)==0){
                liste_score[i].lose_mastermind+=1;
            }
        }
        break;
    }

}

// REECRIT PAR DESSUS LES ANCIENNES DONNEES DU FICHIER
void rewrite_file(score* liste_score,int nb_joueur){
    FILE* pt_fichier = fopen("Scoring.txt","w");
    rewind(pt_fichier);
    for(int i=0;i<nb_joueur;i++){
        fprintf(pt_fichier,"%s %d %d %d %d %d %d\n",liste_score[i].nom, liste_score[i].win_pendu, liste_score[i].lose_pendu, liste_score[i].win_pierre_papier_ciseau,liste_score[i].lose_pierre_papier_ciseau,
                liste_score[i].win_mastermind,liste_score[i].lose_mastermind);
    }
    fclose(pt_fichier);
}

// check si unb player du meme nom est déjà présent
int check_existing_player(char *word){

    int wordExist=0;
    int bufferLength = 255;
    char line[bufferLength];

    // read le fichier
    FILE* pt_fichier = fopen("Scoring.txt","r");

    while(fgets(line, bufferLength, pt_fichier))
    {
        // si le mot est présent dans le fichier
        char *cmp = strstr(line, word);
        if (cmp != NULL)
        {
            wordExist=1;
            break;
        }
    }
    fclose(pt_fichier);
    if (wordExist==1)
        return (1);
    else
        return (0);
}

// setup un profil de joueur
int player_setup(char *player_name){

    int size = 0;
    // créer des un fichier si inexistant
    FILE* pt_fichier = fopen("Scoring.txt","a+");
    player_name[strcspn(player_name, "\n")] = 0;

    // si le fichier est non ouvert/créer
    if (pt_fichier != NULL) {
        fseek (pt_fichier, 0, SEEK_END);
        size = ftell(pt_fichier);

        // si le fichier est vide
        if (size == 0) {
            //fputs("PLAYER_NAME:\n", pt_fichier);
            fputs(player_name, pt_fichier);
            fputs(" 0 0 0 0 0 0\n", pt_fichier);
        }
        // si le fichier est déja remplis
        else if (size > 0) {
            if (check_existing_player(player_name) == 0) {
                //fputs("\nPLAYER_NAME:\n", pt_fichier);
                fputs(player_name, pt_fichier);
                fputs(" 0 0 0 0 0 0\n", pt_fichier);
            }
        }
        fclose(pt_fichier);
    }
    else
        printf("profile failed to load\n");
    return (0);
}

// LIT ET GET LES SCORES DUN FICHIERS POUR CHAQUES JOUEURS (lit juste les structures)
int read_file(FILE *pt_fichier,score *liste_score,int nb_joueur){
    for(int i=0;i<nb_joueur;i++){
        fscanf(pt_fichier,"%s %d %d %d %d %d %d",liste_score[i].nom, &(liste_score[i].win_pendu),&(liste_score[i].lose_pendu),&(liste_score[i].win_pierre_papier_ciseau),
               &(liste_score[i].lose_pierre_papier_ciseau),&(liste_score[i].win_mastermind),&(liste_score[i].lose_mastermind));
    }
}

// COMPTE LE NOMBRE DE JOUEUR DIFFERENT DANS LE FICHIER DES SCORES
int nombre_ligne(FILE *pt_fichier){
    int nb_ligne=0;
    int c;
    while((c=fgetc(pt_fichier))!= EOF){
        if(c=='\n'){
            nb_ligne++;
        }
    }
    return nb_ligne;
}

int main() {
    char player_name[5];
    int choix_entier=0;
    int nb_joueur=10;
    score liste_score[nb_joueur];

    // créer un fichier si inexistant et l'ouvre
    FILE *pt_fichier = fopen("Scoring.txt", "a+");

    // SELECTION NOM JOUEUR
    printf("please, choose a player name\nenter 3 letters  between A-Z\n");
    fgets(player_name, 5, stdin);

    // le joueur ne souhaite aps sauvegardé son profil
    if (player_name[0] != '\n')
        player_setup(player_name);

    //NETTOIE LA SORTIE STANDARD
    fflush(stdin);
    nb_joueur=nombre_ligne(pt_fichier);

    // PLACE LE POINTEUR AU DEBUT DE FICHIER
    rewind(pt_fichier);

    //LIT LE FICHIER
    read_file(pt_fichier,liste_score,nb_joueur);
    int i=0;
    while (strcmp(player_name, liste_score[i].nom) != 0){
        i++;
    }

    //AFFICHAGE MENU CHOIX DU JEU
    do
    {
        printf("Choisir une option dans le menu suivant : \
               \n\t Le jeu du pendu \t<1> %d/%d\
               \n\t Pierre Feuille Ciseau\t<2> %d/%d\
               \n\t MasterMind \t\t<3> %d/%d \
               \n\t Quitter\t\t<0> ", liste_score[i].win_pendu, liste_score[i].lose_pendu, liste_score[i].win_pierre_papier_ciseau, liste_score[i].lose_pierre_papier_ciseau, liste_score[i].win_mastermind, liste_score[i].lose_mastermind);
        printf("\n\t Indiquez votre choix : ") ;

        //NETTOIE LA SORTIE STANDARD
        fflush(stdin);

        // RECUPERATION DU JEU CHOISIS
        scanf("%d",&choix_entier);

        // SERS A MAINTENIR LE BINAIRE EN EXECUTION SI LE JOEUR VEUT CONTINUER A JOUER
        int play_again=1;

        // SI UN JJEU EST CHOISIS, TRAITE AU CAS PAR CAS
        switch (choix_entier)
        {
            // JEU PENDU CHOISIS
            case 1 :
                printf("Pendu\n");
                while(play_again==1) {

                    // PROFILE DU JOUEUR CHANGE EN CAS DE VICTOIRE
                    if (pendu() == 0){
                        updateprofile(liste_score,player_name,1,choix_entier,nb_joueur);
                    }

                    // PROFILE DU JOUEUR CHANGE EN CAS DE DEFAITE
                    else
                        updateprofile(liste_score,player_name,0,choix_entier,nb_joueur);

                    // REECRIT PAR DESSUS LE FICHIER DES SCORES ET AFFICHE LE SCORE ACTUEL
                    rewrite_file(liste_score,nb_joueur);
                    printf("Voulez vous rejouez une partie ? 1-Oui 2-Non\nVictoires %d/%d Defaites\n", liste_score[i].win_pendu, liste_score[i].lose_pendu);
                    fflush(stdin);

                    //PROPOSITION POUR RECOMMENCER UNE PARTIE
                    scanf("%d", &play_again);
                }

                // LE JOUEUR SOUHAITE RETOURNER AU MENU
                printf("Retour aux choix de jeux\n");
                break ;

            // JEU PIERRE FEUILLE CISEAUX CHOISIS
            case 2 :
                printf("Piere,Feuille, Ciseau\n");
                while (play_again==1) {

                    // PROFILE DU JOUEUR CHANGE EN CAS DE VICTOIRE
                    if (pierre_papier_ciseaux() == 0){
                        updateprofile(liste_score,player_name,1,choix_entier,nb_joueur);
                    }

                    // PROFILE DU JOUEUR CHANGE EN CAS DE DEFAITE
                    else{
                        updateprofile(liste_score,player_name,0,choix_entier,nb_joueur);
                    }

                    // REECRIT PAR DESSUS LE FICHIER DES SCORES ET AFFICHE LE SCORE ACTUEL
                    rewrite_file(liste_score,nb_joueur);
                    printf("Voulez vous rejouez une partie ? 1-Oui 2-Non\nVictoires %d/%d Defaites\n", liste_score[i].win_pierre_papier_ciseau, liste_score[i].lose_pierre_papier_ciseau);
                    fflush(stdin);

                    //PROPOSITION POUR RECOMMENCER UNE PARTIE
                    scanf("%d",&play_again);
                }

                // LE JOUEUR SOUHAITE RETOURNER AU MENU
                printf("Retour aux choix de jeu\n");
                break ;

            // JEU MASTERMIND CHOISIS
            case 3 :
                printf("MasterMind\n");
                while(play_again==1) {

                    // PROFILE DU JOUEUR CHANGE EN CAS DE VICTOIRE
                    if (mastermind() == 0){
                        updateprofile(liste_score,player_name,1,choix_entier,nb_joueur);
                    }
                    // PROFILE DU JOUEUR CHANGE EN CAS DE DEFAITE
                    else{
                        updateprofile(liste_score,player_name,0,choix_entier,nb_joueur);
                    }

                    // REECRIT PAR DESSUS LE FICHIER DES SCORES ET AFFICHE LE SCORE ACTUEL
                    rewrite_file(liste_score,nb_joueur);
                    printf("Voulez vous rejouez une partie ? 1-Oui 2-Non\nVictoires %d/%d Defaites\n", liste_score[i].win_mastermind, liste_score[i].lose_mastermind);
                    fflush(stdin);

                    //PROPOSITION POUR RECOMMENCER UNE PARTIE
                    scanf("%d",&play_again);
                }

                // LE JOUEUR SOUHAITE RETOURNER AU MENU
                printf("Retour aux choix de jeu\n");
                break ;
        }
    }
    while (  choix_entier !=0 ) ;
    return 0;

}
