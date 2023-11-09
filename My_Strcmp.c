#include "shell.h"

/**
 * My_Strcmp - function to compare 2 input strings
 * @Str1: first input string
 * @Str2: second input string
 * Return: differences between the 2 input strings
 */
int My_Strcmp(char *Str1, char *Str2)
{
	int i = 0;

	while (Str1[i] != '\0' && Str2[i] != '\0')
	{
		if (Str1[i] != Str2[i])
		{
			return (Str1[i] - Str2[i]);
		}
		i++;
	}
	return (0);
}
