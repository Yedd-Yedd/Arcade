#include <stdio.h>
#include <string.h>

int main() {

    char date_naissance[100]; // = "";
    char nom[100]; // = "";
    char prenom[100];// = "";
    char couleur_yeux[100];// = "";

    // DEBUT PROGRAMME + DATE NAISSANCE
    fflush(stdin);
    printf("Donnez les informations suivantes:\n");
    printf("Date de naissance: ");
    fgets(date_naissance, 99,stdin);
    printf("%s", date_naissance);

    // NOM
    fflush(stdin);
    printf("Nom: ");
    fgets(nom,99,stdin);
    // scanf("%s", &nom);
    printf("%s", nom);

    // PRENOM
    fflush(stdin);
    printf("Prenom: ");
    // scanf("%s", prenom);
    fgets(prenom,99,stdin);
    printf("%s", prenom);

    // COULEURS YEUX
    fflush(stdin);
    printf("Couleurs des yeux: ");
    fgets(couleur_yeux,99,stdin);
    // scanf("%s", &couleur_yeux);
    printf("%s", couleur_yeux);

    // MANIPULATION DU '\n' DE FGETS()
    prenom[strcspn(prenom, "\n")] = 0;
    nom[strcspn(nom, "\n")] = 0;
    date_naissance[strcspn(date_naissance, "\n")] = 0;
    couleur_yeux[strcspn(couleur_yeux, "\n")] = 0;

    printf("Vous vous appelez %s %s, vous etes nee le %s et vos yeux sont %s.\n", prenom, nom, date_naissance, couleur_yeux);

    return 0;
}
