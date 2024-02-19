/*
** EPITECH PROJECT, 2023
** cpt_nbr
** File description:
** len of an int
*/
#include "my.h"

int my_build_command(char *command)
{
    if (my_strcmp(command, "ls") == 0) {
        return 1;
    }
    if (my_strcmp(command, "pwd") == 0) {
        return 1;
    }
    if (my_strcmp(command, "cat") == 0) {
        return 1;
    }
    if (my_strcmp(command, "touch") == 0) {
        return 1;
    }
    if (my_strcmp(command, "rm") == 0) {
        return 1;
    }
    return 0;
}

static int verif_builtin(struct1 *param)
{
    if (param->tokens[0] == NULL) {
        return 0;
    }
    if (my_build_command(param->tokens[0])) {
        make_all(param->tokens[0], param->tokens);
        return 1;
    }
    return 0;
}

void dif_commande(struct1 *param)
{
    if (my_strcmp(param->tokens[0], "exit") == 0) {
        exit_shell(param);
    }
    if (my_strcmp(param->tokens[0], "env") == 0) {
        my_env();
    }
    if (my_strcmp(param->tokens[0], "setenv") == 0) {
        my_setenv(param);
    }
    if (verif_builtin(param) == 0) {
        perror(param->tokens[0]);
    }
}

int verif_specifier(struct1 *param, char current_dir[BUF_SIZE])
{
    if (param->tokens[0] == NULL) {
        if (isatty(STDIN_FILENO)) {
            my_printf("cobra>%s ", current_dir);
        }
        return 0;
    }
    dif_commande(param);
    if (isatty(STDIN_FILENO)) {
        my_printf("cobra>%s ", current_dir);
    }
    return 0;
}
