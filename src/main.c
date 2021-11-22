/*
** EPITECH PROJECT, 2021
** Pendu
** File description:
** main
*/

#include "pendu.h"

int main(int ac, char **av)
{
    if (ac != 2 || is_there_wrong_character(av[1]) == 84)
        help();
    pendu(av[1]);
    return 0;
}