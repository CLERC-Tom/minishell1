/*
** EPITECH PROJECT, 2023
** cpt_nbr
** File description:
** len of an int
*/
#include "my.h"

int my_strcmp(const char *s1, const char *s2)
{
    while (*s1 != '\0' && *s1 == *s2) {
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}
