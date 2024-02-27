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

int my_strncmp(const char *str1, const char *str2, int n)
{
    for (int i = 0; i < n; i++) {
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

int check_char(const char *s, const char *reject)
{
    const char *r;

    for (r = reject; *r; r++) {
        if (*s == *r) {
            return 1;
        }
    }
    return 0;
}

int my_strcspn(const char *str, const char *reject)
{
    const char *s;

    for (s = str; *s; s++) {
        if (check_char(s, reject)) {
            return s - str;
        }
    }
    return s - str;
}

int laste(char **env)
{
    int n = 0;

    for (int i = 0; env[i] != NULL; i++) {
        n = i;
    }
    return n;
}
