#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

char *arg_dupl(const char *arg);
void *free_arg(char **arg);
int execve_arg(char **arg, char **av);
int comp_arg(char *arg1, char *arg2);
char **arg_tok(char *arg);

#endif