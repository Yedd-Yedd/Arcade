#include <stdio.h>
#include "math.h"

int main() {
    int R= 0;
    int height= 0;

    printf("TP4: Complements sur les variables\nQuelle est le rayon du cercle?");
    scanf("%d", &R);
    printf("Ce cercle a pour diametre %d\n", R * 2);
    printf("Ce cercle a pour circonference %f\n" , 2 * M_PI * (float)R);
    printf("Ce cercle a pour air %f\n\n" , M_PI * (float) R);


    printf("Quelle est la hauteur du volume?");
    scanf("%d", &height);

    // un cast d'un en float  OU en double est possible pour la fonction "pow()" (renvoi un double)
    // qui retourne un nombre(y) multiplié par lui même N fois(x)
    // NOTE: le "%.Xf définit le nombre de chiffre après virgule d'afficher.

    printf("\nCe cylindre a pour volume %f\n", M_PI * pow((double)R, 2) * height);
    printf("Ce cone a pour volume %.4f\n", M_PI * pow((float)R, 2) * height / 3);

    return 0;
}
