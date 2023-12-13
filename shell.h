#ifndef SHELL_H
#define SHELL_H

/**
 * Header guards for shell
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/syscall.h>

/**
 * Function prototypes
 */
char *tok(const char *input_buf);
void disprompt(void);
void printer(const char *msg);
int execcmd(char **token);

#endif
