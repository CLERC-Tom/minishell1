/*
** EPITECH PROJECT, 2023
** cpt_nbr
** File description:
** len of an int
*/
#include "my.h"

char **copy_environ()
{
    extern char **environ;
    int i = 0;

    while (environ[i] != NULL) {
        i++;
    }
    char **copy = malloc((i + 1) * sizeof(char *));
    if (copy == NULL) {
        return NULL;
    }
    for (int j = 0; j < i; j++) {
        copy[j] = strdup(environ[j]);
        if (copy[j] == NULL) {
            return NULL;
        }
    }
    copy[i] = NULL;
    return copy;
}
