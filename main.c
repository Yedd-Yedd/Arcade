#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "le_pendu.h"
#include "pierre_feuille_ciseau.h"
#include "mastermind.h"

int check_existing_player(char *word){

    int wordExist=0;
    int bufferLength = 255;
    char line[bufferLength];

    FILE* pt_fichier = fopen("../scoring/Scoring.txt","r");

    while(fgets(line, bufferLength, pt_fichier))
    {
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

int main() {

    char player_name[5];
    char chose_game[3];

    int size = 0;

    printf("please, choose a player name\nenter 3 letters  between A-Z\n");
    fgets(player_name, 5, stdin);
    fflush(stdin);

    FILE* pt_fichier = fopen("../scoring/Scoring.txt","a+");
    player_name[strcspn(player_name, "\n")] = 0;

    if (pt_fichier != NULL) {
        fseek (pt_fichier, 0, SEEK_END);
        size = ftell(pt_fichier);
        if (size == 0) {
            fputs("PLAYER_NAME:\n", pt_fichier);
            fputs(player_name, pt_fichier);
            fputs("\nGAME:\npierre_feuille_ciseau:\t\twin 0/0 lose\n", pt_fichier);
            fputs("mastermind:\t\t\t\t\twin 0/0 lose\n", pt_fichier);
            fputs("pendu:\t\t\t\t\t\twin 0/0 lose\n\n", pt_fichier);
        }
        if (size > 0) {
            printf("jsuis ici\n");
            if (check_existing_player(player_name) == 0) {
                fputs("PLAYER_NAME:\n", pt_fichier);
                fputs(player_name, pt_fichier);
                fputs("\nGAME:\npierre_feuille_ciseau:\t\twin 0/0 lose\n", pt_fichier);
                fputs("mastermind:\t\t\t\t\twin 0/0 lose\n", pt_fichier);
                fputs("pendu:\t\t\t\t\t\twin 0/0 lose\n\n", pt_fichier);

            }
        }
    }
    
    int choix_entier=0;
    do
    {
        printf("Choisir une option dans le menu suivant : \
               \n\t Le jeu du pendu <1><return> \
               \n\t Pierre Feuille Ciseau <2><return> \
               \n\t MasterMind <3><return> \
               \n\t Quitter <0><return> ") ;
        printf("\n\t\t Indiquez votre choix : ") ;

        fflush(stdin);
        scanf("%d",&choix_entier);


        /*permet de passer du caract�re �i� (code ASCII) � l�entier i */
        switch (choix_entier)
        {
            case 1 :
                printf("Pendu\n");
                pendu();
                break ;
            case 2 :
                printf("Piere,Feuille, Ciseau\n");
                pierre_papier_ciseaux();
                break ;
            case 3 :
                printf("MasterMind\n") ;
                mastermind();
                break ;
        }
    }
    while (  choix_entier !=0 ) ;

    return 0;    // créer des un fichier si inexistant

    return 0;
}