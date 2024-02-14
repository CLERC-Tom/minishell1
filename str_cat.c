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

void my_strcat(char *chaine1, char *chaine2)
{
    while (*chaine1) {
        chaine1++;
    }
    while (*chaine2) {
        *chaine1 = *chaine2;
        chaine1++;
        chaine2++;
    }
    *chaine1 = '\0';
}
