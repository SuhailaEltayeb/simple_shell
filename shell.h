#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#define MAX_PATH_LENGTH 1024

int main(void);
int _execvp(const char *file, char *const argv[]);
void execute_shell();
void execute_command(const char *command);
void tokenize_arguments(char *command, char ***argv, int *argc);

/* Defining Global variable environ */

extern char **environ;


#endif
