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

int my_ls(char **tokens)
{
    char *ls_path = "/bin/ls";
    pid_t pid = fork();

    if (pid < 0) {
        return 84;
    }
    if (pid == 0) {
        if (execve(ls_path, tokens, NULL) == -1) {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    } else {
        waitpid(pid, NULL, 0);
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

int my_pwd(void)
{
    char cwd[1024];

    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        my_printf("%s\n", cwd);
        return 0;
    } else {
        perror("getcwd() error");
        return 1;
    }
}

int my_setenv(char **tokens)
{
    return 0;
}

int verif_specifier(struct1 *param)
{
    if (param->tokens[0] != NULL && my_strcmp(param->tokens[0], "exit") == 0) {
        exit_shell(param);
    }
    if (param->tokens[0] != NULL && my_strcmp(param->tokens[0], "ls") == 0) {
        my_ls(param->tokens);
    }
    if (param->tokens[0] != NULL && my_strcmp(param->tokens[0], "env") == 0) {
        my_env();
    }
    if (param->tokens[0] != NULL && my_strcmp(param->tokens[0], "pwd") == 0) {
        my_pwd();
    }
    if (param->tokens[0] != NULL
    && my_strcmp(param->tokens[0], "setenv") == 0) {
        my_setenv(param->tokens2);
    } else {
        write(STDOUT_FILENO, "cobra> ", 7);
    }
    return 0;
}
