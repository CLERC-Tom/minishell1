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


int my_setenv(struct1 *param)
{
    extern char **environ;
    char **env = environ;
    int n = 0;
    char *new_value = malloc(str_len(param->tokens[1])
    + str_len(param->tokens[2]) + 2);

    if (new_value == NULL) {
        return 1;
    }
    my_strcpy(new_value, param->tokens[1]);
    my_strcat(new_value, "=");
    my_strcat(new_value, param->tokens[2]);
    for (int i = 0; env[i] != NULL; i ++) {
        n = i;
    }
    env[n] = new_value;
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

int verif_specifier(struct1 *param, char current_dir[BUF_SIZE])
{
    if (param->tokens[0] != NULL && my_strcmp(param->tokens[0], "exit") == 0)
        exit_shell(param);
    if (param->tokens[0] != NULL && my_strcmp(param->tokens[0], "ls") == 0)
        make_all(param->tokens[0], param->tokens);
    if (param->tokens[0] != NULL && my_strcmp(param->tokens[0], "env") == 0)
        my_env();
    if (param->tokens[0] != NULL && my_strcmp(param->tokens[0], "pwd") == 0) {
        make_all(param->tokens[0], param->tokens);
    }
    if (param->tokens[0] != NULL
    && my_strcmp(param->tokens[0], "setenv") == 0) {
        my_setenv(param);
    }
    if (isatty(STDIN_FILENO))
        my_printf("cobra>%s ", current_dir);
    return 0;
}
