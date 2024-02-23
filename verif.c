/*
** EPITECH PROJECT, 2023
** cpt_nbr
** File description:
** len of an int
*/
#include "my.h"

int my_build_command(char *command)
{
    char *full_path = find_command(command);

    if (full_path != NULL) {
        free(full_path);
        return 1;
    }
    return 0;
}

int verif_builtin(struct1 *param)
{
    if (param->tokens[0] == NULL) {
        return 0;
    }
    if (my_strcmp(param->tokens[0], "exit") == 0 ||
        my_strcmp(param->tokens[0], "env") == 0 ||
        my_strcmp(param->tokens[0], "setenv") == 0 ||
        my_strcmp(param->tokens[0], "unsetenv") == 0) {
        param->last_command_status = 0;
        return 0;
    }
    if (my_build_command(param->tokens[0])) {
        param->last_command_status =
        make_all(param->tokens[0], param->tokens, param);
        return 0;
    }
    return 1;
}

int verif_exist(struct1 *param)
{
    if (verif_builtin(param) == 0) {
        return 0;
    }
    if (my_build_command(param->tokens[0]) == 0) {
        write(2, param->tokens[0], str_len(param->tokens[0]));
        write(2, ": Command not found.\n", 20);
        exit(1);
    }
    return 0;
}

void dif_commande(struct1 *param)
{
    if (my_strcmp(param->tokens[0], "exit") == 0) {
        full_exit(param);
    }
    if (my_strcmp(param->tokens[0], "env") == 0) {
        my_env();
    }
    if (my_strcmp(param->tokens[0], "setenv") == 0) {
        my_setenv(param);
    }
    if (my_strcmp(param->tokens[0], "unsetenv") == 0) {
        my_unsetenv(param);
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
    if (verif_exist(param) == 0) {
        dif_commande(param);
    }
    if (isatty(STDIN_FILENO)) {
        my_printf("cobra>%s ", current_dir);
    }
    return 0;
}
