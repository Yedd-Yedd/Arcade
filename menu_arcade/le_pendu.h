#ifndef LE_PENDU_H_INCLUDED
#define LE_PENDU_H_INCLUDED

void answer_state_fill(char *answer_state, size_t size);
int char_is_present(const char *current_char, char *hidden_word);
void generate_random_word(char *word, int value);
char *word_hidder(const char *current_letter_choice, const char *hidden_word, char *answer_state);
int Hangman(int value);
int pendu;
#endif // LE_PENDU_H_INCLUDED
