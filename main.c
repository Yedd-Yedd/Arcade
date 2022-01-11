#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "le_pendu.h"
#include "pierre_feuille_ciseau.h"
#include "mastermind.h"
void score_change(char *player_name, int game_id){

}

void updateprofile(int game_id, int state, char *player_name){

    FILE *pt_fichier = fopen("../Scoring/Scoring.txt", "r+" );
    int bufferLength = 255;
    char buffer[bufferLength];

    int match_player = 0;
    int match_score = 0;
    long  i = 0;

    while(fgets(buffer, bufferLength, pt_fichier)) {
        if (match_score == 1){
            switch (game_id) {
                case 1:
                    if (state == 0){
                        char test = '1';
                        char result = buffer[0];
                        result++;
                        fwrite(&test,1, sizeof(char), pt_fichier);
                        fflush(pt_fichier);
                    }
                    else {
                        fseek(pt_fichier, 2, SEEK_CUR);
                        char *result = &buffer[0];
                        *result++;
                        fwrite(&result,sizeof(char*), 1, pt_fichier);
                    }
                    break;
                case 2:
                    if (state == 0){
                        fseek(pt_fichier, 4, SEEK_CUR);
                        char *result = &buffer[0];
                        *result++;
                        fwrite(&result,sizeof(char*), 1, pt_fichier);
                    }
                    else {
                        fseek(pt_fichier, 6, SEEK_CUR);
                        char *result = &buffer[0];
                        *result++;
                        fwrite(&result,sizeof(char*), 1, pt_fichier);
                    }
                    break;
                case 3:
                    if (state == 0){
                        fseek(pt_fichier, 8, SEEK_CUR);
                        char *result = &buffer[0];
                        *result++;
                        fwrite(&result,sizeof(char*), 1, pt_fichier);
                    }
                    else {
                        fseek(pt_fichier, 10, SEEK_CUR);
                        char *result = &buffer[0];
                        *result++;
                        fwrite(&result,sizeof(char*), 1, pt_fichier);
                    }
                    break;
            }
            match_score = 0;
        }
        if (match_player == 1){
            if (strncmp(player_name, buffer, strlen(player_name)) == 0){
                match_score = 1;
            }
            match_player = 0;
        }
        if (strncmp("PLAYER_NAME:", buffer, strlen("PLAYER_NAME:")) == 0){
            match_player = 1;
        }
    }
    fclose(pt_fichier);

    char word[100];
    char replace[100];
    size_t size = 0;

    fseek (pt_fichier, 0, SEEK_END);



}

int check_existing_player(char *word){

    int wordExist=0;
    int bufferLength = 255;
    char line[bufferLength];

    FILE* pt_fichier = fopen("../Scoring/Scoring.txt","r");

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


int player_setup(char *player_name){

    int size = 0;
    // créer des un fichier si inexistant
    FILE* pt_fichier = fopen("../Scoring/Scoring.txt","a+");
    player_name[strcspn(player_name, "\n")] = 0;

    // si le fichier est non ouvert/créer
    if (pt_fichier != NULL) {
        fseek (pt_fichier, 0, SEEK_END);
        size = ftell(pt_fichier);

        // si le fichier est vide
        if (size == 0) {
            fputs("PLAYER_NAME:\n", pt_fichier);
            fputs(player_name, pt_fichier);
            fputs("\n0/0 0/0 0/0\n", pt_fichier);
        }
        // si le fichier est déja remplis
        if (size > 0) {
            if (check_existing_player(player_name) == 0) {
                fputs("PLAYER_NAME:\n", pt_fichier);
                fputs(player_name, pt_fichier);
                fputs("\n0/0 0/0 0/0\n", pt_fichier);
            }
        }
    }
    else
        printf("profile failed to load\n");
    fclose(pt_fichier);
    return (0);
}

int main() {

    char player_name[5];
    int choix_entier=0;

    printf("please, choose a player name\nenter 3 letters  between A-Z\n");
    fgets(player_name, 5, stdin);
    // le joueur ne souhaite aps sauvegardé son profil
    if (player_name[0] != '\n')
        player_setup(player_name);
    fflush(stdin);
    do
    {
        printf("Choisir une option dans le menu suivant : \
               \n\t Le jeu du pendu \t<1> \
               \n\t Pierre Feuille Ciseau\t<2>\
               \n\t MasterMind \t\t<3> \
               \n\t Quitter\t\t<0> ") ;
        printf("\n\t Indiquez votre choix : ") ;

        fflush(stdin);
        scanf("%d",&choix_entier);

        int play_again=1;
        /*permet de passer du caractere �i� (code ASCII) � lentier i */
        switch (choix_entier)
        {
            case 1 :
                printf("Pendu\n");
                while(play_again==1) {
                    if (pendu() == 0){
                        updateprofile(choix_entier, 0, player_name);
                        // check retour pour le ratio
                    }
                    else
                        updateprofile(choix_entier, 1, player_name);
                    printf("Voulez vous rejouez une partie ? 1-Oui 2-Non\n");
                    fflush(stdin);
                    scanf("%d", &play_again);
                }
                printf("Retour aux choix de jeux\n");
                break ;
            case 2 :
                printf("Piere,Feuille, Ciseau\n");
                while (play_again==1) {
                    if (pierre_papier_ciseaux() == 0){

                    }
                    printf("Voulez vous rejouez une partie ? 1-Oui 2-Non\n");
                    fflush(stdin);
                    scanf("%d",&play_again);
                }
                printf("Retour aux choix de jeu\n");
                break ;
            case 3 :
                printf("MasterMind\n");
                while(play_again==1) {
                    if (mastermind() == 0){

                    }
                    printf("Voulez vous rejouez une partie ? 1-Oui 2-Non\n");
                    fflush(stdin);
                    scanf("%d",&play_again);
                }
                printf("Retour aux choix de jeu\n");
                break ;
        }
    }
    while (  choix_entier !=0 ) ;

    return 0;

}