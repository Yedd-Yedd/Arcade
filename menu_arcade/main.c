#include <stdio.h>
#include <stdlib.h>
#include "le_pendu.h"
#include "pierre_feuille_ciseau.h"

int main()
{
     char choix, choix_entier ;
    do
    {
        printf("Choisir une option dans le menu suivant : \
               \n\t Le jeu du pendu <1><return> \
               \n\t Pierre Feuille Ciseau <2><return> \
               \n\t MasterMind <3><return> \
               \n\t Quitter <q><return> ") ;
        printf("\n\t\t Indiquez votre choix : ") ;
        rewind(stdin) ;
        choix = getch() ;


        /*permet de passer du caractère ’i’ (code ASCII) à l’entier i */
        switch (choix_entier)
        {
        case 1 :
            printf("Pendu");

            break ;
        case 2 :
             printf("Piere,Feuille, Ciseau");
            break ;
        case 3 :
            printf("MasterMind") ;
            break ;
        }
    }
    while ( choix!='q' ) ;

    return 0;
}

