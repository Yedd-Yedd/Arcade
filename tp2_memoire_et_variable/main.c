#include <stdio.h>

int main() {
    int i = 0;
    long int li = 100;
    short sh = 2;
    double du = 2.5;
    char c = 'c';

    /* print de chacune des variables et leurs valeurs attribuées
     * Vive CLION
     * */
    printf("TP2: Memoire et Variables\n mes variables sont:\n i = %d\n ld = %ld\n sh = %d\n du = %f\n c = \'%c\'\n", i, li, sh, du, c);


    // print de la taille des variables
    printf("mes tailles de variables sont:\n int = %d\n long int = %d\n short = %d\n double = %d\n c = %d", sizeof(i), sizeof(li), sizeof(sh), sizeof(du), sizeof(c));

    return 0;
}
