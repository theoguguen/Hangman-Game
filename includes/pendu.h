/*
** EPITECH PROJECT, 2021
** Pendu
** File description:
** pendu
*/

#ifndef PENDU_H_
#define PENDU_H_

#include "my.h"

typedef struct pendu_s {
    int length;
    char *hidden;
    char *word;
    int tries;
    char *alphabet;
    int max_try;
}pendu_t;

int winning_condition(pendu_t *pendu);

void result(pendu_t *pendu);

pendu_t *init_struct(char *word, pendu_t *pendu, int nb);

int is_there_wrong_character(char *word);

void print_game(pendu_t *pendu, char *used_letter);

#endif