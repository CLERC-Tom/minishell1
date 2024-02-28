/*
** EPITECH PROJECT, 2023
** cpt_nbr
** File description:
** len of an int
*/
#include "my.h"

int check_e(struct1 *param)
{
    if (param->tokens[1] == NULL) {
        my_env();
        return 0;
    }
    return -1;
}

int check_egale(struct1 *param)
{
    for (int i = 0; param->tokens[1][i] != '\0'; i++) {
        if (param->tokens[1][i] == '=') {
            write(1, "setenv: Variable name", 22);
            write(1, " must contain alphanumeric character.\n", 39);
            return 1;
        }
    }
    return -1;
}

int check_first(struct1 *param)
{
    for (int i = 0; param->tokens[1][i] != '\0'; i++) {
        if (!my_isalpha(param->tokens[1][i])) {
            write(1, "setenv: Variable name", 22);
            write(1, " must begin with a letter.\n", 27);
            return 1;
        }
    }
    return -1;
}

int check_arguments(struct1 *param)
{
    int result;

    result = check_e(param);
    if (result != -1) {
        return result;
    }
    result = check_egale(param);
    if (result != -1) {
        return result;
    }
    result = check_first(param);
    if (result != -1) {
        return result;
    }
    if (param->tokens[3] != NULL) {
        write(1, "setenv: Too many arguments.\n", 29);
        return 1;
    }
    return -1;
}
