#ifndef MAIN_H
#define MAIN_H

/* Library: */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*  */
#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 64

/* Function Prototype: */
void shell_interpreter(void);
void no_shell_interpreter(void);

#endif
