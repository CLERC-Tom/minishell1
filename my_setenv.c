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
    if (param->tokens[1] == NULL) {
        my_env();
        return 0;
    }
    for (int i = 0; param->tokens[1][i] != '\0'; i++) {
        if (!my_isalpha(param->tokens[1][i])) {
            write(2, "setenv: Variable name", 22);
            write(2, " must begin with a letter.\n", 27);
            return 1;
        }
    }
    if (param->tokens[2] == NULL) {
        return 0;
    } else if (param->tokens[3] != NULL) {
        write(2, "setenv: Too many arguments.\n", 29);
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

int laste(char **env) {
    int n = 0;
    for (int i = 0; env[i] != NULL; i++) {
        n = i;
    }
    return n;
}

int find_env_var(char **env, char *var) {
    int i = 0;
    int var_len = str_len(var);

    while (env[i] != NULL) {
        if (strncmp(env[i], var, var_len) == 0 && env[i][var_len] == '=') {
            return i;
        }
        i++;
    }
    return -1;
}

char **copy_environ()
{
    extern char **environ;
    int i = 0;
    while (environ[i] != NULL) {
        i++;
    }
    char **copy = malloc((i + 1) * sizeof(char *));
    if (copy == NULL) {
        return NULL;
    }
    for (int j = 0; j < i; j++) {
        copy[j] = strdup(environ[j]);
        if (copy[j] == NULL) {
            return NULL;
        }
    }
    copy[i] = NULL;
    return copy;
}

int my_setenv(struct1 *param)
{
    extern char **environ;
    char **env = copy_environ();
    char *new_value;
    int check_arg_result = check_arguments(param);
    int index;

    if (check_arg_result != -1) {
        return check_arg_result;
    }
    new_value = create_new_value(param);
    if (new_value == NULL) {
        return 1;
    }
    index = find_env_var(env, param->tokens[1]);
    if (index != -1) {
        free(env[index]);
        env[index] = new_value;
    } else {
        env[laste(env)] = new_value;
    }
    environ = env;
    return 0;
}


