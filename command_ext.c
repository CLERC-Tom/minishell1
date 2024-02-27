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
    char **tmp = environ;
    if (params->tokens[1] == NULL) {
        write(2, "unsetenv: Too few arguments.\n", 30);
        return 1;
    }
    for (int i = 1; params->tokens[i] != NULL; i++) {
        int j = 0;
        while (tmp[j] != NULL) {
            if (strncmp(tmp[j], params->tokens[i], strlen(params->tokens[i])) == 0 && tmp[j][strlen(params->tokens[i])] == '=') {
                int k = j;
                while (environ[k] != NULL) {
                    environ[k] = environ[k + 1];
                    k++;
                }
                break;
            }
            j++;
        }
    }
    return 0;
}



int laste(char **env)
{
    int n = 0;

    for (int i = 0; env[i] != NULL; i++) {
        n = i;
    }
    return n;
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
