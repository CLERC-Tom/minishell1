/*
** EPITECH PROJECT, 2023
** cpt_nbr
** File description:
** len of an int
*/
#include "my.h"

int check_file_and_path(char *file, char *full_path, struct1 *param)
{
    if (file == NULL || full_path == NULL) {
        param->last_command_status = 1;
        return 1;
    }
    return 0;
}

int execute_command(char *full_path, char *argv[], char **environ)
{
    int tempo = 0;
    char error_message[1024] = "";

    if ((tempo = execve(full_path, argv, environ)) == -1) {
        my_strcat(error_message, full_path);
        my_strcat(error_message, ": ");
        my_strcat(error_message, strerror(errno));
        my_strcat(error_message, ".\n");
        write(2, error_message, str_len(error_message));
        tempo = 1;
    }
    return tempo;
}

int handle_status(int status)
{
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

int check_command(char *file, struct1 *param)
{
    if (my_build_command(param->tokens[0]) == 0) {
        write(2, param->tokens[0], str_len(param->tokens[0]));
        write(2, ": Command not found.", 21);
        write(2, "\n", 1);
        return 1;
    }
    return 0;
}

int fork_and_execute(char *full_path, char *argv[], char **environ)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        execute_command(full_path, argv, environ);
    } else {
        if (wait(&status) == -1) {
            perror("waitpid");
            return 1;
        }
        status = handle_status(status);
    }
    return status;
}
