#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#define MAX_PATH_LENGTH 1024

int _execvp(const char *file, char *const argv[]);
int main();

/* Defining Global variable environ */

extern char **environ;
#define BUFFER_SIZE  1024
/* String Manipulation functions */

ssize_t My_Getline(char **_lineptr, size_t *size, int str);
char *My_Strtok(char *_String, const char *_Delemiter);
size_t _Strcspn(const char *_Str1, const char *_Str2);
char *_Strchr(const char *_Str, int _Char);
char *_Strdup(char *Str);
int _Strcmp(char *Str1, char *Str2);

#endif
