#ifndef MAIN_H
#define MAIN_H

/* Library: */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * MAX_INPUT_SIZE - maximum input size
 * MAX_ARGS - maximum arguments size
 */
#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 64

extern char **environ;

/* Function Prototype: */
void shell_interactive(void);
void no_shell_interactive(void);
int execute_command(char *command);
void execute_command(char *input);

#endif
