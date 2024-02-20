/*
** EPITECH PROJECT, 2023
** cpt_nbr
** File description:
** len of an int
*/
#include "my.h"

char *my_getenv(const char *name)
{
    int i = 0;
    int len = str_len(name);
    extern char **environ;

    if (name == NULL) {
        return NULL;
    }
    while (environ[i]) {
        if (my_strncmp(environ[i], name, len) == 0 && environ[i][len] == '=') {
            return &environ[i][len + 1];
        }
        i++;
    }
    return NULL;
}

char *execute_in(char *command)
{
    char *full_path = NULL;
    char *result = NULL;

    if (command == NULL) {
        return NULL;
    }
    if (command[0] == '.' && command[1] == '/') {
        full_path = malloc(str_len(command) + 1);
        if (full_path == NULL) {
            return NULL;
        }
        my_strcpy(full_path, &command[2]);
        if (access(full_path, X_OK) == 0) {
            result = my_strdup(full_path);
            free(full_path);
            return result;
        }
        free(full_path);
    }
    return NULL;
}

static char *create_full_path(char *command, char *path_part)
{
    char *full_path = malloc(str_len(path_part) + str_len(command) + 2);

    if (full_path == NULL) {
        return NULL;
    }
    my_strcpy(full_path, path_part);
    my_strcat(full_path, "/");
    my_strcat(full_path, command);
    return full_path;
}

static char *check_command_access(char *command, char *path_part)
{
    char *result;
    char *full_path = create_full_path(command, path_part);

    if (full_path == NULL){
        return NULL;
    }
    if (access(full_path, X_OK) == 0) {
        result = my_strdup(full_path);
        free(full_path);
        return result;
    }
    free(full_path);
    return NULL;
}

char *parcours_path(char *command, char *path_part)
{
    char *result;

    if (command == NULL || path_part == NULL){
        return NULL;
    }
    result = NULL;
    while (path_part != NULL && result == NULL){
        result = check_command_access(command, path_part);
        path_part = strtok(NULL, ":");
    }
    return result;
}

char *find_command(char *command)
{
    char *path = NULL;
    char *result = execute_in(command);
    char *path_part;

    if (command == NULL) {
        return NULL;
    }
    if (result == NULL) {
        path = my_getenv("PATH");
        if (path == NULL) {
            return NULL;
        }
        path_part = strtok(my_strdup(path), ":");
        result = parcours_path(command, path_part);
        free(my_strdup(path));
    }
    return result;
}

static void erreur1(char *full_path, char *argv[], char **environ)
{
    if (full_path == NULL || argv == NULL || environ == NULL) {
        exit(EXIT_FAILURE);
    }
    execve(full_path, argv, environ);
    perror("execve");
    exit(EXIT_FAILURE);
}

static int verif_error(pid_t pid)
{
    if (pid < 0) {
        return 84;
    }
    if (waitpid(pid, NULL, 0) < 0) {
        perror("waitpid");
        return 84;
    }
    return 0;
}

int make_all(char *file, char *argv[])
{
    extern char **environ;
    char *full_path = find_command(file);
    pid_t pid;

    if (file == NULL || argv == NULL) {
        return 84;
    }
    if (full_path == NULL) {
        return 84;
    }
    pid = fork();
    if (pid == 0) {
        erreur1(full_path, argv, environ);
    } else {
        if (verif_error(pid) != 0) {
            return 84;
        }
    }
    free(full_path);
    return 0;
}
