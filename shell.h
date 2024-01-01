#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

char *cpy_str(char *dest, const char *src);
char *str_tok(char *str, const char *delim);
char *str_pbrk(const char *str, const char *delim);
char *read_input(void);
char *read_input_handler(void);
void display_prompt(void);
void remove_newline(char *str);
void display_environment(void);
void execute_external_command(char *input);
void execute_command(char *input);
int exec_cmd(const char *command, char *const args[], char *const env[]);
int str_cmp(const char *s1, const char *s2);
str_format(full_path, sizeof(full_path), "%s/%s", (void *)token, (void *)input);

#endif

