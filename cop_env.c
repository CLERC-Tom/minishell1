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
    char **copy;

    while (environ[i] != NULL) {
        i++;
    }
    copy = malloc((i + 1) * sizeof(char *));
    if (copy == NULL) {
        return NULL;
    }
    for (int j = 0; j < i; j++) {
        copy[j] = my_strdup(environ[j]);
        if (copy[j] == NULL) {
            return NULL;
        }
    }
    copy[i] = NULL;
    return copy;
}
