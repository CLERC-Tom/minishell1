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

int my_unsetenv(struct1 *params)
{
    extern char **environ;
    char **env = environ;

    if (params->tokens[1] == NULL) {
        my_printf("unsetenv: Too few arguments.\n");
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
