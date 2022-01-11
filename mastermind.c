#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "mastermind.h"

int *check_nb_char() {

}

int my_occurence_finder(char const *p1,const char *p2)
{
   int i = 0;
   int count = 0;
   int checker[5];

   // debug entrée de fonction (attention a la triche)
   printf(" reponse random = %s\n reponse player = %s\n",p1, p2);

   //check = check_nb_char();
   while (p1[i] != '\0'){
       if (p1[i] == p2[i])
           count++;
       i++;
   }

   // debug retour de fonction
   // printf("count = %d\n", count);
   return count;
}

int mastermind(){
    int play_again=1;
    while(play_again==1)
    {
        const int tentativ_max = 3;
        int current_tentative = 1;
        int occurence = 0;
        int i = 0;

        //char colors[] = {'R', 'V', 'B', 'J', 'O'};
        char player_answer[5];
        printf("TP7:Les Tableaux\n");

        // /*
        // GENERATION ALEATOIRE DE CODE ORDINATEU;
        srand(time(NULL));
        int l = 0;
        char code[5];
        memset(code, '\0', sizeof(code));
        while (l < 4){
            code[l] = "RVBJO"[rand() % 5];
            l++;
        }
        // */

        printf("Donnez un code de 4 couleurs differentes et sans espaces parmis : {'R', 'V', 'B', 'J', 'O'}\n");
        // 1ere boucle condition victoire, encore des tentatives
        while (current_tentative <= tentativ_max){
           // reset et vider la réponse du player
           memset(player_answer, '\0', sizeof(player_answer));
           printf(">");

           // clean la sortit standard
           fflush(stdin);

           //récupération de réponse du joueur
           while (i < 4){
               scanf("%c", &player_answer[i]);
               i++;
           }
           // mystère, le code en dur n'a pas de pointeur NULL si il est décaler ailleurs que cette ligne
           //const char code[5] = {'R', 'V', 'B', 'J', '\0'};
           // CODE EN VERSION HARDCODE

           printf("Tentative %d/%d\n", current_tentative, tentativ_max);
           // COMPTE ET RENVOIE LE NOMBRE DE CHARACTERE A LA BONNE PLACE (de meme pour les doublons);

           occurence = my_occurence_finder(code, player_answer);
           // debug occurence
           // printf("occ %d\n", occurence);

           if (strcmp(code, player_answer) == 0){
               printf("player win\n");
               break;
           }
           else
            printf("Couleurs mals placees: %d\nCouleurs bien placees: %d\n", 4 - occurence, occurence);
           i = 0;
           current_tentative++;
       }
        //parti terminé (et perdu)
        if (current_tentative > tentativ_max){
            printf("you lose\n");
        }
        printf("Voulez vous rejouez une partie ? 1-Oui 2-Non\n");
        scanf("%d",&play_again);
    }
    printf("Retour aux choix de jeu");
    return 0;
}

/*int main() {
    mastermind();
    return 0;
}*/
