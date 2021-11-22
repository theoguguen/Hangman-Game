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
    printf("Veuillez préciser un mot, ");
    printf("ou mettre le groupe de mots entre guillemets.\n");
    exit(0);
}

void help(void)
{
    printf("\t--- Bienvenue sur le jeu du pendu ---\n\n");
    printf("\tDESCRIPTION\n");
    printf("Le Pendu est un jeu consistant à trouver un mot en devinant quelles sont les lettres qui le composent.\n\n");
    printf("\tUTILISATION\n");
    printf("./pendu MOT -t ESSAIS_MAX (Par défaut 10)\n");
    exit(0);
}