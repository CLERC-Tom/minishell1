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

void my_ls(char **tokens)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        if (execvp(tokens[0], tokens) == -1) {
            perror("execvp");
        }
        exit(EXIT_FAILURE);
    }
    if (pid < 0) {
        perror("fork");
    } else {
        while (waitpid(pid, &status, 0) == 0);
    }
}

int verif_specifier(struct1 *param)
{
    if (param->tokens[0] != NULL && my_strcmp(param->tokens[0], "exit") == 0) {
        exit_shell(param);
    }
    if (param->tokens[0] != NULL && my_strcmp(param->tokens[0], "ls") == 0) {
        my_ls(param->tokens);
        write(STDOUT_FILENO, "cobra> ", 7);
    } else {
        write(STDOUT_FILENO, "cobra> ", 7);
    }
    return 0;
}
