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

int verif_lol(struct1 *params)
{
    if (params->tokens[1] == NULL) {
        write(1, "unsetenv: Too few arguments.\n", 30);
        return 1;
    }
    return 0;
}

int unset_env_var(char **tmp, char *token)
{
    int j = 0;
    int k;

    while (tmp[j] != NULL) {
        if (my_strncmp(tmp[j], token, str_len(token)) == 0
        && tmp[j][str_len(token)] == '=') {
            k = j;
            while (tmp[k] != NULL) {
                tmp[k] = tmp[k + 1];
                k++;
            }
            break;
        }
        j++;
    }
    return 0;
}

int my_unsetenv(struct1 *params)
{
    extern char **environ;
    char **tmp = environ;

    verif_lol(params);
    for (int i = 1; params->tokens[i] != NULL; i++) {
        unset_env_var(tmp, params->tokens[i]);
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
