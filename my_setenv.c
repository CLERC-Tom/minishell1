/*
** EPITECH PROJECT, 2023
** cpt_nbr
** File description:
** len of an int
*/
#include "my.h"

int my_isalpha(int c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int check_arguments(struct1 *param)
{
    for (int i = 0; param->tokens[1][i] != '\0'; i++) {
            if (!my_isalpha(param->tokens[1][i])) {
                my_printf("setenv: Variable name must begin with a letter.\n");
                return 1;
            }
    }
    if (param->tokens[1] == NULL) {
        my_env();
        return 0;
    }
    if (param->tokens[2] == NULL) {
        return 0;
    } else if (param->tokens[2] == NULL || param->tokens[3] != NULL) {
        my_printf("setenv: Too many arguments.\n");
        return 1;
    }
    return -1;
}

char *create_new_value(struct1 *param)
{
    char *new_value = malloc(str_len(param->tokens[1])
    + str_len(param->tokens[2]) + 2);

    if (new_value == NULL) {
        return NULL;
    }
    appel(param, new_value);
    return new_value;
}

int laste(char **env)
{
    int n = 0;

    for (int i = 0; env[i] != NULL; i ++) {
        n = i;
    }
    return n;
}

int my_setenv(struct1 *param)
{
    extern char **environ;
    char **env = environ;
    char *new_value;
    int check_arg_result = check_arguments(param);

    if (check_arg_result != -1) {
        return check_arg_result;
    }
    new_value = create_new_value(param);
    if (new_value == NULL) {
        return 1;
    }
    env[laste(env)] = new_value;
    return 0;
}
