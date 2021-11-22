/*
** EPITECH PROJECT, 2021
** Pendu
** File description:
** help
*/

#include "my.h"

int is_there_wrong_character(char *word)
{
    for (size_t i = 0; word[i]; i++) {
        if (word[i] == ' ')
            continue;
        if (isalpha(word[i]) == 0)
            return 84;
    }
    return 0;
}

void wrong(void)
{
    printf("Please, input a word or put ");
    printf("a word group into quotes.\n");
    printf("No special characters are admitted\n");
    printf("Type ./hangman -h for more informations\n");
    exit(0);
}

void help(void)
{
    printf("\t--- Welcome to the Hangman Game ! ---\n\n");
    printf("    DESCRIPTION\n");
    printf("  The Hangman Game is a game of finding a word by \nguessing which are the letters that compose it.\n\n");
    printf("    USAGE\n");
    printf("  ./pendu WORD -t MAX_TRIES (Default: 10).\n");
    exit(0);
}