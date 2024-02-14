/*
** EPITECH PROJECT, 2023
** setting up
** File description:
** algo de base
*/
#include "my.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

char *my_strcpy(char *dest, const char *src)
{
    int index = 0;

    while (src[index] != '\0') {
        dest[index] = src[index];
        index++;
    }
    dest[index] = '\0';
    return dest;
}
