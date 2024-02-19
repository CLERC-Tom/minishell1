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

int is_builtin_command(char *command)
{
    if (my_strcmp(command, "ls") == 0) {
        return 1;
    }
    if (my_strcmp(command, "pwd") == 0) {
        return 1;
    }
    if (my_strcmp(command, "cat") == 0) {
        return 1;
    }
    if (my_strcmp(command, "touch") == 0) {
        return 1;
    }
    if (my_strcmp(command, "rm") == 0) {
        return 1;
    }
    return 0;
}

static int verif_builtin(struct1 *param)
{
    if (param->tokens[0] == NULL) {
        return 0;
    }
    if (is_builtin_command(param->tokens[0])) {
        make_all(param->tokens[0], param->tokens);
        return 1;
    }
    return 0;
}

void handle_commands(struct1 *param)
{
    if (my_strcmp(param->tokens[0], "exit") == 0) {
        exit_shell(param);
    }
    if (my_strcmp(param->tokens[0], "env") == 0) {
        my_env();
    }
    if (my_strcmp(param->tokens[0], "setenv") == 0) {
        my_setenv(param);
    }
    if (verif_builtin(param) == 0) {
        perror(param->tokens[0]);
    }
}

int verif_specifier(struct1 *param, char current_dir[BUF_SIZE])
{
    if (param->tokens[0] == NULL) {
        if (isatty(STDIN_FILENO)) {
            my_printf("cobra>%s ", current_dir);
        }
        return 0;
    }
    handle_commands(param);
    if (isatty(STDIN_FILENO)) {
        my_printf("cobra>%s ", current_dir);
    }
    return 0;
}
