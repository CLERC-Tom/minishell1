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

int free_all(struct1 *param)
{
    if (param->copenv != NULL) {
        for (int i = 0; param->copenv[i] != NULL; i++) {
            free(param->copenv[i]);
        }
        free(param->copenv);
    }
    return 0;
}

char **separe_diff_line(char *line)
{
    char *token;
    char **tokens = malloc(64 * sizeof(char *));
    int position = 0;

    token = strtok(line, "\t\r\n\a");
    while (token != NULL) {
        tokens[position] = token;
        position++;
        token = strtok(NULL, "\t\r\n\a");
    }
    tokens[position] = NULL;
    return tokens;
}

void loop_shell(struct1 *param)
{
    char *line = NULL;
    size_t len = 0;
    int shell_running = 1;

    write(STDOUT_FILENO, "cobra> ", 7);
    while (shell_running && getline(&line, &len, stdin) != -1) {
        param->tokens = separe_diff_line(line);
        verif_specifier(param);
        free(param->tokens);
        param->tokens = NULL;
    }
    free(line);
}

char **copy_env()
{
    char **copenv = NULL;
    extern char **environ;
    int env_size = 0;

    while (environ[env_size] != NULL) {
        env_size++;
    }
    copenv = (char **)malloc((env_size + 1) * sizeof(char *));
    if (copenv == NULL) {
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < env_size; i++) {
        copenv[i] = my_strdup(environ[i]);
        if (copenv[i] == NULL) {
            exit(EXIT_FAILURE);
        }
    }
    copenv[env_size] = NULL;
    return copenv;
}

void init_shell(struct1 *param)
{
    param = malloc(sizeof(struct1));
    param->copenv = copy_env();
    signal(SIGINT, gestion_error);
    loop_shell(param);
    exit_shell(param);
}
