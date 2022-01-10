#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// REMPLIT LETAT DE LA REPONSE AVEC DES _
void answer_state_fill(char *answer_state, size_t size){
    size_t i = 0;

    while (i < size){
        answer_state[i] = '_';
        i++;
    }
    answer_state[i] = '\0';
    //  debug
    //  printf("filled : %s\nI = %d\n size=%d\n", answer_state, i, size);
}

// DETECTE SI LE CARACTERE DE LA CHAINE "CURRENT CHAR" EST PRESENT
int char_is_present(const char *current_char, char *hidden_word){
    int i = 0;
    int detector = 0;

    // DEBUG ENTREE FONCTION
    // printf("current_char = %s\nhidden word = %s\n", current_char, hidden_word);

    // PARCOUR LA CHAINE ET COPIE
    while(hidden_word[i] != '\0'){
        if (hidden_word[i] == current_char[0])
            detector++;
        i++;
    }
    return (detector);
}

// GENERATEUR DE MOT ALEATOIRE
void generate_random_word(char *word, int value){
    // SET UP ET INITIALIZATION DES VARIABLES
    size_t i = 0;
    memset(word, '\0', value);

    // TANT QUE IL NA PAS ATTEINT LA TAILLE MAX ATTENDU
    while (i < value) {
        //
        word[i] = "PROGRAMMATION"[i];
        // CARACTERE ALEATOIRE -> fonctionne
        // word[i] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[rand() % 26];
        i++;
    }

    word[i] = '\0';
    // DEBUGG mot bien généré
    printf("MOT GENERE  = %s\n", word);
}

// REMPLIS UNE VARIABLE TAMPON POUR PRINT LES LETTRES TROUVEES SINON DES '_'
char *word_hidder(const char *current_letter_choice, const char *hidden_word, char *answer_state){

    int i = 0;

    // debug entrée fonction
    // printf("answer state = %s\n", answer_state);
    while (hidden_word[i] != '\0') {
        if (hidden_word[i] == current_letter_choice[0]){
            answer_state[i] = current_letter_choice[0];
        }
        while (hidden_word[i] == '_')
            i++;
        i++;
    }
    answer_state[i] = '\0';

    // debug answer state
    // printf("answer state = %s\n", answer_state);
    return (answer_state);
}

int Hangman(int value){

    // INITIALIZATION DES VARIABLES
    int life = 10;
    size_t letters_found = 0;

    char hidden_word[value];
    char current_letter_choice[3];
    char *answer_state = malloc(value - 1);
    char player_answer[value - 1];

    // set les strings , évite de crash
    memset(player_answer, '\0', value + 1);
    memset(answer_state, '\0', value + 1);
    memset(current_letter_choice, '\0', value + 1);

    // debug pointeur existe
    // printf("player  est %s\n answer est %s\n", player_answer, answer_state);

    // generation du mot aléatoire
    generate_random_word(hidden_word, value);
    answer_state_fill(answer_state, strlen(hidden_word));

    // tant que les conditions de victoires/Defaites ne sont pas atteint la partie continue
    while (letters_found < strlen(hidden_word)) {
        if (life == 0) {
            return (-1);
        }
        // on vide la chaine de caractère contenant la réponse de lutilisateur en stockant le retour de gets
        memset(current_letter_choice, '\0', value + 1);
        printf("Proposer une lettre >");

        // clean la sortis standard
        fflush(stdin);

        // get letter, la lettre ne peut pas etre plus longue que le mot généré
        fgets(current_letter_choice, value + 1, stdin);

        //printf("current letter choice =%s\n", current_letter_choice);
        current_letter_choice[strcspn(current_letter_choice, "\n")] = 0;

        // CHECK SI ON ENVOIE 1 LETTRE
        if (strlen(current_letter_choice) == 1) {
            if (char_is_present(current_letter_choice, hidden_word) > 0) {
                letters_found += char_is_present(current_letter_choice, hidden_word);
                answer_state = word_hidder(current_letter_choice, hidden_word, answer_state);
                printf("Oui, la lettre '%s' est presente dans le mot \"%s\"\n", current_letter_choice, answer_state);
            } else {
                life--;
                printf("Non, la lettre '%s' n'est pas le mot \"%s\", il vous reste %d vies\n", current_letter_choice, answer_state, life);
            }
        }
            // CHECK SI ON TENTE AVEC LE MOT EN ENTIER
        else if (strcmp(current_letter_choice, hidden_word) == 0){
            letters_found = value;
            printf("vous avez trouve le mot\n");
            exit(0);
        }
            // si il n'y pas assez ou trop de caractère.
            // POSSIBILITE DE FAIRE PERDRE UNE VIE EN CAS DERREUR
        else if (strlen(current_letter_choice) > 1 && strlen(current_letter_choice) + 1 != strlen(hidden_word)){
            life--;
            printf("1 lettre a la fois ou la reponse entiere\nIl vous reste %d vies\n", life);
        }
        else {

            // life--;
            printf("Non, la reponse est fausse '%s' n'est pas dans le mot \"%s\", il vous reste %d vies\n",
                   current_letter_choice, answer_state, life);
        }
    }
    return (0);
}

int main() {

    // pour set la longueur d'un mot avant la partie,
    // mettre "int ac, char **av" dans les paramètres du main
    // mettre "atoi[av1];" dans les parametres de Hangman();

    int word_lenght = 13;
    srand(time(NULL));
    printf("TP10: Les strings\n");
    if (Hangman(word_lenght) == 0){
        printf("you win\n");
    }
    else
        printf("loooooooser\n");
    return 0;
}