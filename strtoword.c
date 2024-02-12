/*
** EPITECH PROJECT, 2023
** cpt_nbr
** File description:
** len of an int
*/
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "my.h"

int count_lines2(char *str)
{
    int count = 0;

    for (int i = 0; str != NULL && str[i] != '\0'; i++) {
        if (str[i] == '\n')
            count++;
    }
    return count + 1;
}

char **str_to_wordarray(char *str, struct1 *param)
{
    int lines = count_lines2(str);
    int count_c = str_len(str);
    char **array = malloc(sizeof(char *) * (lines + 1));

    while (str[param->count] != '\0') {
        array[param->j] = malloc(sizeof(char) * (count_c + 1));
        while (str[param->count] != '\0' && str[param->count] != '\n') {
            array[param->j][param->i] = str[param->count];
            param->i++;
            param->count++;
        }
        array[param->j][param->i] = '\0';
        param->j++;
        param->count++;
        param->i = 0;
    }
    array[lines] = NULL;
    return array;
}
