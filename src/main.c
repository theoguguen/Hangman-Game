/*
** EPITECH PROJECT, 2021
** Pendu
** File description:
** main
*/

#include "pendu.h"

static int  is_num(char *str)
{
    for (size_t i = 0; str[i]; i++) {
        if (str[i] < 48 || str[i] > 57)
            return 1;
    }
    return 0;
}

int main(int ac, char **av)
{
    int sec = 5;
    if (ac == 2 && strcmp(av[1], "-h") == 0)
        help();
    if (ac == 4 && strcmp(av[2], "-t") == 0 && is_num(av[3]) == 0)
        pendu(av[1], atoi(av[3]));
    if (ac != 2 || is_there_wrong_character(av[1]) == 84)
        wrong();
    pendu(av[1], 10);
    while (sec > 0) {
        printf("%d\n", sec);
        sec--;
        sleep(1);
    }
    return 0;
}