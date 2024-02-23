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
        my_strcpy(full_path, command);
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
    printf("1");
    perror("execve");
    exit(1);
}

static int verif_error(pid_t pid)
{
    if (pid < 0) {
        return 1;
    }
    if (waitpid(pid, NULL, 0) < 0) {
        printf("2");
        perror("waitpid");
        return 1;
    }
    return 0;
}

int make_all(char *file, char *argv[], struct1 *param)
{
    extern char **environ;
    char *full_path = find_command(file);
    pid_t pid;
    int tempo = 0;
    int status;
    pid = fork();

    if (file == NULL || argv == NULL) {
        param->last_command_status = 1;
       return 1; 
    }
    if (full_path == NULL) {
        param->last_command_status = 1;
       return 1;
    }
    if (my_build_command(param->tokens[0]) == 0) {
        write(2, param->tokens[0], str_len(param->tokens[0]));
        write(2, ": Command not found.\n", 20);
        exit(1);
    }
    if (pid == 0) {
        if ((tempo = execve(full_path, argv, environ)) == -1) {
            perror(full_path);
        }
    } else {
        if (wait(&status) == -1) {
            perror("waitpid");
            return 1; 
        }
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        }
        if (WIFSIGNALED(status)) {
            if (WTERMSIG(status) == SIGSEGV) {
                my_printf("Segmentation fault\n");
            }
            return 0;
        }
        return status;
    }
    return status;
}
