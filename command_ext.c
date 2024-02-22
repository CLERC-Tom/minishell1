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

void verif_nbarg(struct1 *param, char **env, int i, int j)
{
    if (my_strncmp(env[i], param->tokens[j],
    str_len(param->tokens[j])) == 0) {
        env[i] = NULL;
    }
}

int my_unsetenv(struct1 *params)
{
    extern char **environ;
    char **env = environ;

    if (params->tokens[1] == NULL) {
        write(2, "unsetenv: Too few arguments.\n", 30);
        exit(1);
    }
    for (int j = 1; params->tokens[j] != NULL; j++) {
        for (int i = 0; env[i] != NULL; i++) {
            verif_nbarg(params, env, i, j);
        }
    }
    return 0;
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
