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
    full_path = malloc(str_len(command) + 1);
    if (full_path == NULL) {
        return NULL;
    }
    my_strcpy(full_path, command);
    if (access(full_path, X_OK) == 0) {
        result = my_strdup(full_path);
        free(full_path);
        return result;
    }
    free(full_path);
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
    char *temp_path;

    if (command == NULL) {
        return NULL;
    }
    if (result == NULL) {
        path = my_getenv("PATH");
        if (path == NULL) {
            return NULL;
        }
        temp_path = my_strdup(path);
        path_part = strtok(temp_path, ":");
        result = parcours_path(command, path_part);
        free(temp_path);
    }
    return result;
}

static void erreur1(char *full_path, char *argv[], char **environ)
{
    if (full_path == NULL || argv == NULL || environ == NULL) {
        exit(1);
    }
    execve(full_path, argv, environ);
    perror("execve");
    exit(1);
}

static int verif_error(pid_t pid)
{
    if (pid < 0) {
        return 1;
    }
    if (waitpid(pid, NULL, 0) < 0) {
        perror("waitpid");
        return 1;
    }
    return 0;
}

int make_all(char *file, char *argv[], struct1 *param)
{
    extern char **environ;
    char *full_path = find_command(file);

    if (full_path == NULL) {
        full_path = my_strdup(file);
    }
    if (check_file_and_path(file, full_path, param)) {
        return 1;
    }
    check_command(file, param);
    return fork_and_execute(full_path, argv, environ);
}
