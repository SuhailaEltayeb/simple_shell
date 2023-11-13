#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* Defining Global variable environ */

extern char **environ;
#define BUFFER_SIZE = 1024
/* String Manipulation functions */

ssize_t My_Getline(char **_lineptr, size_t *size, int str);
char *My_Strtok(char *_String, const char *_Delemiter);
int My_Strcmp_Len(const char *Str1, Const char *Str2, Size_t Len);
char *My_Strcat(char *Dest, char *Src);
int My_Strcmp(char *Str1, char *Str2);
char *My_Strcpy(char *Src, char *Dest);
char *My_Strdup(char *Str);
int My_Strlen(char *str);
char *My_GetEnv(const char *name);

#endif
