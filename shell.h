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
#include <sys/prctl.h>
#include <signal.h>
#include <sys/syscall.h>
#include <err.h>

/**
 * Function prototypes
 */

void disprompt(void);
void printer(const char *msg);

#endif
