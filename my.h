/*
** EPITECH PROJECT, 2023
** epitech_pool_day09
** File description:
** file that contains all prototypes
*/

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
    char *line;
}struct1;

void my_putchar(char c);
int lenght(char *buffer);
void print_map(char **array);
int weidth(char *buffer);
void free_wordarray(char **wordtab);
char **str_to_wordarray(char *phrase, struct1 *param);
int count_lines2(char *str);
int count_char(char *str);
int my_strcmp(char *s1, char *s2);
int my_put_nbr(int n);
char *my_strcpy(char *dest, char const *src);
int my_putstr(char const *str);
int str_len(const char *str);
void ls_a(void);
int my_printf(const char *format, ...);
static int count_verif(const char *p, const char *r);
void gestion_error(int i);
char **separe_diff_line(char *line);
void loop_shell(struct1 *param);
char **copy_env(void);
char *my_strdup(char const *src);
void init_shell(struct1 *param);
int verif_specifier(struct1 *param, char current_dir[BUF_SIZE]);
int exit_shell(struct1 *param);
void gestion_error(int i);
int my_ls(char **tokens);
int free_all(struct1 *param);
int my_pwd(void);
void my_strcat(char *chaine1, char *chaine2);

#endif /* MY_H */
