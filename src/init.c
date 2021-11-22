/*
** EPITECH PROJECT, 2021
** Pendu
** File description:
** init
*/

#include "pendu.h"

static char *word_hidden(char *word)
{
    char *temp = malloc(sizeof(char) * strlen(word) + 1);

    temp = strcpy(temp, word);
    for (size_t i = 0; temp[i]; i++) {
        if (temp[i] != ' ')
            temp[i] = '*';
    }
    return temp;
}

static int count_letter(char *word)
{
    int nb = 0;

    for (size_t i = 0; word[i]; i++) {
        if (word[i] == ' ')
            continue;
        else
            nb++;
    }
    return nb;
}

pendu_t *init_struct(char *word, pendu_t *pendu, int nb)
{
    pendu->length = count_letter(word);
    pendu->word = word;
    pendu->tries = 0;
    pendu->hidden = word_hidden(word);
    pendu->max_try = nb;
    return pendu;
}