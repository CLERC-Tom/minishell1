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

int my_unsetenv(struct1 *params) {
    if (params->tokens[1] == NULL) {
        write(2, "unsetenv: Too few arguments.\n", 30);
        exit(1);
    }
    for (int i = 1; params->tokens[i] != NULL; i++) {
        if (unsetenv(params->tokens[i]) != 0) {
            perror("unsetenv");
            exit(EXIT_FAILURE);
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
