/*
** EPITECH PROJECT, 2021
** Pendu
** File description:
** pendu
*/

#include "pendu.h"

static void exec_loop(pendu_t *pendu, char *buff, int state)
{
    int found = 0;
    size_t i = 0;

    if (buff[0] == '\n')
        return;
    if (strlen(buff) > 2) {
        while (buff[i]){
            if (buff[i] == pendu->word[i] || buff[i] == '\n')
                i++;
            else {
                pendu->tries += 1;
                return;
            }
        }
    }
    if (i == strlen(buff)) {
        pendu->hidden = pendu->word;
        return;
    }
    else {
        for (int i = 0; pendu->hidden[i]; i++) {
            if (pendu->word[i] == buff[0] && strlen(buff) == 2) {
                pendu->hidden[i] = buff[0];
                found = 1;
            }
        }
    }
    if (state == 0 && found == 0)
        pendu->tries += 1;
}

char *check_already_used(char *used_letter, char *buff, int *new_letter_pos, int *state)
{
    for (size_t i = 0; used_letter[i]; i++) {
        if (used_letter[i] == buff[0]) {
            printf("Vous avez déjà utilisé cette lettre ! Essayez-en une autre.\n");
            *state = 1;
            return used_letter;
        }
    }
    used_letter[*new_letter_pos] = buff[0];
    *new_letter_pos += 1;
    return used_letter;
}

static void game(pendu_t *pendu)
{
    char *buff = NULL;
    size_t s = 0;
    int state = 0;
    int new_letter_pos = 0;
    char *used_letter = malloc(sizeof(char) * 26);

    system("clear");
    printf("\t--- Le jeu du pendu ---\n\n");
    while (winning_condition(pendu) == 0) {
        state = 0;
        printf("Mot à deviner : \t%s (%d lettres)\n", pendu->hidden, pendu->length);
        printf("Nombre d'essais restant ; \t%d essais\n\n", (pendu->max_try - pendu->tries));
        printf("Proposez une lettre ou un mot : ");
        if (getline(&buff, &s, stdin) == -1)
            break;
        if (strlen(buff) == 2)
            used_letter = check_already_used(used_letter, buff, &new_letter_pos, &state);
        exec_loop(pendu, buff, state);
    }
    result(pendu);
    free(buff);
}

void pendu(char *word, int nb)
{
    pendu_t *pendu = malloc(sizeof(pendu_t));

    if (nb <= 0) {
        free(pendu);
        wrong();
    }
    pendu = init_struct(word, pendu, nb);
    game(pendu);
    free(pendu);
    exit(0);
}