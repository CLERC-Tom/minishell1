/*
** EPITECH PROJECT, 2023
** epitech_pool_day09
** File description:
** file that contains all prototypes
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <ctype.h>

#ifndef MY_H
    #define MY_H
    #define BUF_SIZE 1024

typedef struct {
    int j;
    int i;
    int count;
    char **copenv;
    char **environ;
    char **tokens;
    char **env;
    char **tokens2;
    int last_command_status;
    char *line;
    char **execute;
    char *input;
    char *current_dir;
} struct1;

void my_putchar(char c);
int my_strncmp(const char *str1, const char *str2, int n);
int my_strcspn(const char *str, const char *reject);
char **str_to_wordarray(char *phrase, struct1 *param);
int count_lines2(char *str);
int count_char(char *str);
int my_strcmp(const char *s1, const char *s2);
int my_put_nbr(int n);
int my_isalpha(int c);
char *my_strcpy(char *dest, char const *src);
int my_putstr(char const *str);
int str_len(const char *str);
int my_printf(const char *format, ...);
char *my_strdup(char const *src);
static int count_verif(const char *p, const char *r);
char *my_strcat(char *dest, char *src);

void gestion_error(int i);
char **separe_diff_line(char *line);
void init_shell(struct1 *param);
char **copy_env(void);
void init_shell(struct1 *param);
int verif_specifier(struct1 *param, char current_dir[BUF_SIZE]);
int exit_shell(struct1 *param);
void gestion_error(int i);
int full_exit(struct1 *param);
int free_all(struct1 *param);

char *my_getenv(const char *name);
char *find_command(char *command);
int my_build_command(char *command);

int make_all(char *file, char *argv[], struct1 *param);
int execute2(char **argv, char **env, struct1 *s);
int appel(struct1 *param, char *new_value);
int check_file_and_path(char *file, char *full_path, struct1 *param);
int execute_command(char *full_path, char *argv[], char **environ);
int handle_status(int status);
int check_command(char *file, struct1 *param);
int fork_and_execute(char *full_path, char *argv[], char **environ);
int laste(char **env);
char **copy_environ(void);

int my_setenv(struct1 *param);
void my_env(void);
int free_all(struct1 *param);
void segfault_sigaction(int signal, siginfo_t *si, void *arg);
int my_unsetenv(struct1 *param);

#endif /* MY_H */
