#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

char *My_Strcat(char *Dest, char *Src);
int My_Strcmp(char *Str1, char *Str2);
char *My_Strcpy(char *Src, char *Dest);
char *My_Strdup(char *Str);
int My_Strlen(char *str);

#endif
