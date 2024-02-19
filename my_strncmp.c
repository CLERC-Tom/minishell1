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

int my_strncmp(const char *str1, const char *str2, size_t n)
{
    while (n--) {
        if (*str1 != *str2) {
            return *str1 - *str2;
        }
        if (*str1 == '\0') {
            return 0;
        }
        str1++;
        str2++;
    }
    return 0;
}
