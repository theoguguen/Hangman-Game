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
        printf("\t--- Le jeu du pendu ! ---\n\n");
        printf("Vous avez gagné ! Le mot à deviner était bien : %s\n", pendu->word);
        printf("Vous avez deviné ce mot avec seulement %d erreur(s) !\n", pendu->tries);
    }
    else {
        printf("\t--- Le jeu du pendu ! ---\n\n");
        printf("Vous avez perdu :( Le mot à deviner était : %s\n", pendu->word);
    }
}