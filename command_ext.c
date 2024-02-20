/*
** EPITECH PROJECT, 2023
** cpt_nbr
** File description:
** len of an int
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include "my.h"

int appel(struct1 *param, char *new_value)
{
    my_strcpy(new_value, param->tokens[1]);
    my_strcat(new_value, "=");
    my_strcat(new_value, param->tokens[2]);
    return 0;
}

int my_setenv(struct1 *param)
{
    extern char **environ;
    char **env = environ;
    char *new_value;
    int n = 0;

    if (param->tokens[1] == NULL ||
    param->tokens[2] == NULL) {
        return 1;
    }
    new_value = malloc(str_len(param->tokens[1])
    + str_len(param->tokens[2]) + 2);
    if (new_value == NULL) {
        return 1;
    }
    appel(param, new_value);
    for (int i = 0; env[i] != NULL; i ++) {
        n = i;
    }
    env[n] = new_value;
    return 0;
}

int my_unsetenv(struct1 *params)
{
    extern char **environ;
    char **env = environ;

    if (params->tokens[1] == NULL) {
        return 1;
    }
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], params->tokens[1],
        str_len(params->tokens[1])) == 0) {
            env[i] = NULL;
            return 0;
        }
    }
    return 1;
}

void my_env(void)
{
    extern char **environ;
    char **env = environ;

    while (*env) {
        my_printf("%s\n", *env);
        env++;
    }
}
