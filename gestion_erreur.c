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

int exit_shell(struct1 *param)
{
    free_all(param);
    exit(0);
}

int full_exit(struct1 *param)
{
    free_all(param);
    exit(1);
}

void gestion_error(int i)
{
    write(STDOUT_FILENO, "\ncobra> ", 10);
}
