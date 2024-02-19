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

char *my_getenv(const char *name)
{
    int i = 0;
    int len = str_len(name);
    extern char **environ;

    while (environ[i]) {
        if (my_strncmp(environ[i], name, len) == 0 && environ[i][len] == '=') {
            return &environ[i][len + 1];
        }
        i++;
    }
    return NULL;
}

char *find_command(char *command)
{
    char *path = my_getenv("PATH");
    char *path_part = strtok(my_strdup(path), ":");
    char *full_path = NULL;
    char *result = NULL;

    while (path_part != NULL){
        full_path = malloc(str_len(path_part) + str_len(command) + 2);
        my_strcpy(full_path, path_part);
        my_strcat(full_path, "/");
        my_strcat(full_path, command);
        if (access(full_path, X_OK) == 0) {
            result = my_strdup(full_path);
            free(full_path);
            break;
        }
        free(full_path);
        path_part = strtok(NULL, ":");
    }
    free(my_strdup(path));
    return result;
}

int make_all(char *file, char *argv[])
{
    extern char **environ;
    char *full_path = find_command(file);
    pid_t pid = fork();

    if (full_path == NULL) {
        return 84;
    }
    if (pid < 0) {
        perror("fork");
        return 84;
    }
    if (pid == 0) {
        execve(full_path, argv, environ);
        perror("execve");
        exit(EXIT_FAILURE);
    } else {
        waitpid(pid, NULL, 0);
    }
    free(full_path);
    return 0;
}
