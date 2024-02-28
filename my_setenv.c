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

char *create_new_value(struct1 *param)
{
    char *new_value;

    if (param->tokens[2] != NULL) {
        new_value = malloc(str_len(param->tokens[1])
        + str_len(param->tokens[2]) + 2);
        my_strcpy(new_value, param->tokens[1]);
        my_strcat(new_value, "=");
        my_strcat(new_value, param->tokens[2]);
    } else {
        new_value = malloc(str_len(param->tokens[1]) + 2);
        my_strcpy(new_value, param->tokens[1]);
        my_strcat(new_value, "=");
    }
    return new_value;
}

int find_env_var(char **env, char *var)
{
    int i = 0;
    int var_len = str_len(var);

    while (env[i] != NULL) {
        if (my_strncmp(env[i], var, var_len) == 0 && env[i][var_len] == '=') {
            return i;
        }
        i++;
    }
    return -1;
}

static int my_setenv_part2(char **env, char *new_value, struct1 *param)
{
    extern char **environ;
    int index = find_env_var(env, param->tokens[1]);

    if (index != -1) {
        free(env[index]);
        env[index] = new_value;
    } else {
        env[laste(env)] = new_value;
    }
    environ = env;
    return 0;
}

int my_setenv(struct1 *param)
{
    extern char **environ;
    char **env = copy_environ();
    char *new_value;
    int check_arg_result = check_arguments(param);

    if (check_arg_result != -1) {
        return check_arg_result;
    }
    new_value = create_new_value(param);
    if (new_value == NULL) {
        return 1;
    }
    return my_setenv_part2(env, new_value, param);
}
