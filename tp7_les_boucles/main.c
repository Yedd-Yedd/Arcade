#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int still_play = 1;

int recommencer(){
    printf("Voulez-vous faire une nouvelle partie(1-oui, 2-non)\n");
    if ( (scanf("%d", &still_play) == 1)) {
        switch (still_play) {
            case 1:
                still_play = 1;
                return (0);
            case 2:
                printf("A bientot !\n");
                still_play = 2;
                return (0);
            default:
                break;
        }
        return (0);
    }
    else {
        printf("ending process\n");
        exit(84);
    }
}

int playthegame(){
    int nombre_mystere = 0;
    int nombre_utilisateur = 0;
    const int VALEUR_MIN = 1, VALEUR_MAX = 100;
    int try = 1;
    int max_try = 10;

    srand(time(NULL));
    nombre_mystere = (rand() % (VALEUR_MAX - VALEUR_MIN + 1)) + VALEUR_MIN;
    printf("Devinez quel est mon nombre mystere. Indice: c'est un nombre entre %d et %d \n", VALEUR_MIN, VALEUR_MAX);

    while (nombre_utilisateur != nombre_mystere && try < 11)
    {
        if (try == 1)
            printf("let's start the game\n");
        if ( (scanf("%d", &nombre_utilisateur) != 1))
            exit(84);
        printf("tentative %d/%d > ", try, max_try);
        if (nombre_utilisateur > nombre_mystere)
            printf("c'est moins !\n");
        else if (nombre_utilisateur < nombre_mystere)
            printf("cest plus !\n");
        else {
            printf("Bravo! le nombre mystere est bien %d\n", nombre_mystere);
            break;
        }
        try++;
    }
    recommencer();
    return (0);
}

int main() {
    printf("TP6: Les Boucles\n");
    while (still_play == 1)
        playthegame();
    return (0);
}
