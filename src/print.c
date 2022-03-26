/*
** EPITECH PROJECT, 2021
** Hangman-Game
** File description:
** print
*/

#include "pendu.h"

static void print_used_letters(char *used_letters)
{
    printf("Used letters: [%c", used_letters[0]);
    for (size_t i = 1; used_letters[i]; i++)
        printf(", %c", used_letters[i]);
    printf("]\n");
}

void print_game(pendu_t *pendu, char *used_letter)
{
    printf("\t--- The Hangman Game ---\n\n");
    printf("Word to guess: \t%s (%d letters)\n", pendu->hidden, pendu->length);
    printf("Fails left: \t%d fails\n", (pendu->max_try - pendu->tries));
    print_used_letters(used_letter);
    printf("\nSuggest a letter or a word : ");
}
