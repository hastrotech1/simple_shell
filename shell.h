#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>

#include <stdarg.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

extern char **environ;

/*extern char path_name[];*/

#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 1024

/*Custom Function prototypes*/
void call_and_execute(char *args[]);
char *cstm_getline(void);
char *cstm_strtok(char *str, const char *delim);
char *cstm_non_interactive_getline(void);
char *cstm_getenv(char *env_name);

void change_dir(char *cmd_args[], char *currt_wrk_dir);
void cmd_seperator(char *get_line_val, char *currt_wrk_dir, char *user_prompt);

/*Helper function for printing to stdout*/
int _printf(const char *format, ...);
int _putchar(char c);
int _strlen(char *str);

#endif
