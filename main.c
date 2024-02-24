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
    int status;

    if (param == NULL) {
        return 1;
    }
    init_shell(param);
    status = param->last_command_status;
    free_all(param);
    free(param);
    return status;
}
