#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "pierre_feuille_ciseau.h"

int pierre_papier_ciseaux() {

        int player_won_rounds = 0;
        int computer_won_rounds = 0;
        int computer_sign = 0;
        int player_sign = 0;
        const int VALEUR_MIN = 1, VALEUR_MAX = 3;

        while (player_won_rounds != 3 && computer_won_rounds != 3) {

            printf("Score actuel: PLAYER %d-%d COMPUTER\n", player_won_rounds, computer_won_rounds);
            printf("que voulez vous jouer (1-Pierre, 2-Papier, 3-Ciseaux)\n");

            // check du retour de scanf pour éviter un warning (hors CLION windows)
            if ((scanf("%d", &player_sign, &player_sign)) != 1){
               exit(84);
           }

            computer_sign = (rand() % VALEUR_MAX) + VALEUR_MIN;
            printf("ordinateur a joue : %d\n", computer_sign);
            // switch selon le choix du player avec
            // un autre switch imbriqué pour faire du cas par cas selon le choix de l'ordinateur
            switch (player_sign) {
                case 1:
                    switch (computer_sign) {
                        case 1:
                            printf("egalite\n");
                            break;
                        case 2:
                            computer_won_rounds++;
                            printf("player lost\n");
                            break;
                        default:
                            printf("player gagne\n");
                            player_won_rounds++;
                            break;
                    }
                    break;
                case 2:
                    switch (computer_sign) {
                        case 1:
                            printf("player gagne\n");
                            player_won_rounds++;
                            break;
                        case 2:
                            printf("egalite\n");
                            break;
                        default:
                            computer_won_rounds++;
                            printf("player perdu\n");
                            break;
                    }
                    break;
                default:
                    switch (computer_sign) {
                        case 1:
                            printf("player perdu\n");
                            computer_won_rounds++;
                            break;
                        case 2:
                            printf("player gagne\n");
                            player_won_rounds++;
                            break;
                        default:
                            printf("egalite\n");
                            break;
                    }
                    if (player_sign < 0 || player_sign > 3) {
                        printf("le puit n'existe pas");
                    }
            }
        }
        if (player_won_rounds == 3)
            printf("player won the game\nscore: %d-%d\n", player_won_rounds, computer_won_rounds);
        if (computer_won_rounds == 3) {
            printf("computer won the game\nscore: %d-%d\n", player_won_rounds, computer_won_rounds);
            return (-1);
        }
        return 0;
}

/*int main(){
    pierre_papier_ciseaux();
    return 0;
}*/
