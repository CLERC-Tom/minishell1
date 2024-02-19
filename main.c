/*
** EPITECH PROJECT, 2023
** cpt_nbr
** File description:
** len of an int
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include "my.h"

int main(void)
{
    struct1 *param = malloc(sizeof(struct1));

    if (param == NULL) {
        return 84;
    }
    init_shell(param);
    free_all(param);
    free(param);
    return 0;
}
