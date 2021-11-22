/*
** EPITECH PROJECT, 2021
** Pendu
** File description:
** end_game
*/

#include "pendu.h"

int winning_condition(pendu_t *pendu)
{
    if (pendu->tries == pendu->max_try)
        return 1;
    for (size_t i = 0; pendu->hidden[i]; i++)
        if (pendu->hidden[i] == '*')
            return 0;
    return 1;
}

void result(pendu_t *pendu)
{
    system("clear");
    if (pendu->tries != pendu->max_try) {
        printf("\t--- The Hangman Game ---\n\n");
        printf("You won ! The word to guess was : %s\n", pendu->word);
        printf("You guessed the word making only %d error(s) !\n", pendu->tries);
    }
    else {
        printf("\t--- The Hangman Game---\n\n");
        printf("You lost :( The word to guess was : %s\n", pendu->word);
    }
}