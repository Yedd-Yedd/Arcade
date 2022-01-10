#include <stdio.h>

int main() {
    int square_size = 0;
    int width = 0;
    int height = 0;


    // calcule carré
    /*
    printf("TP3: operations sur variables\nQuelle est la taille d'un cote du carre ?");
    scanf(" %d", &square_size);
    printf("Ce carre a pour perimetre %d\n" , (square_size * 4));
    printf("Ce carre a pour surface %d\n" , (square_size * square_size));
    */

    // calcule rectangle

    printf("TP3: operations sur variables\nQuelle est la hauteur et largeur du rectangle ?");
    scanf( "%d %d", &width, &height);
    printf("Ce rectangle a pour perimetre %d\n" , ((width * 2) + (height * 2)));
    printf("Ce rectangle a pour surface %d\n" , (width * height));

    return 0;
}
