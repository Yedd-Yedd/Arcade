#include <stdio.h>
#include <stdlib.h>
#include "le_pendu.h"
#include "pierre_feuille_ciseau.h"
#include "mastermind.h"

int main()
{
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


        /*permet de passer du caractère ’i’ (code ASCII) à l’entier i */
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

    return 0;
}

