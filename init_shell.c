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

char **separe_diff_line(char *line)
{
    char *token;
    char **tokens = malloc(64 * sizeof(char *));
    int position = 0;

    token = strtok(line, " \t\n");
    while (token != NULL) {
        tokens[position] = my_strdup(token);
        position++;
        token = strtok(NULL, " \t\n");
    }
    tokens[position] = NULL;
    return tokens;
}

static void process_token(struct1 *param, char *token)
{
    if (str_len(token) > 0) {
        token[str_len(token) - 1] = '\0';
    }
}

static void handle_tokens(struct1 *param, char *current_dir)
{
    int num_token = 0;

    if (param->tokens != NULL) {
        for (num_token = 0; param->tokens[num_token] != NULL; num_token++) {
            process_token(param, param->tokens[num_token]);
        }
    }
    free(param->tokens);
    param->tokens = NULL;
}

void static loop_shell2(struct1 *param, char *current_dir, size_t len)
{
    int shell_running = 1;

    while (shell_running && getline(&param->line, &len, stdin) != -1) {
        param->line[my_strcspn(param->line, "\n")] = 0;
        param->tokens = separe_diff_line(param->line);
        getcwd(current_dir, sizeof(current_dir));
        verif_specifier(param, current_dir);
        handle_tokens(param, current_dir);
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
}
