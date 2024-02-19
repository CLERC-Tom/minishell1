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

    token = strtok(line, " ");
    while (token != NULL) {
        tokens[position] = token;
        position++;
        token = strtok(NULL, " ");
    }
    tokens[position] = NULL;
    return tokens;
}

void static loop_shell2(struct1 *param, char *current_dir, size_t len)
{
    int shell_running = 1;
    int num_token = 0;

    while (shell_running && getline(&param->line, &len, stdin) != -1) {
        param->line[strcspn(param->line, "\n")] = 0;
        param->tokens = separe_diff_line(param->line);
        getcwd(current_dir, sizeof(current_dir));
        verif_specifier(param, current_dir);
        if (param->tokens != NULL) {
            for (num_token = 0; param->tokens[num_token]
            != NULL; num_token++) {
                param->tokens[num_token][str_len(param->tokens[num_token]) - 1]
                = '\0';
            }
        }
        free(param->tokens);
        param->tokens = NULL;
    }
}

void loop_shell(struct1 *param)
{
    char current_dir[BUF_SIZE];
    size_t len = 0;

    getcwd(current_dir, sizeof(current_dir));
    if (isatty(STDIN_FILENO)) {
        my_printf("cobra>%s ", current_dir);
    }
    loop_shell2(param, current_dir, len);
    free(param->line);
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
    param->copenv = copy_env();
    signal(SIGINT, gestion_error);
    loop_shell(param);
    exit_shell(param);
}
