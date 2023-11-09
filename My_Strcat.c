#include "shell.h"

/**
 * My_Strcat - function to concatinate 2 input strings
 * @Src: input string
 * @Dest: output sting
 * Return: pointer to destination string
 */
char *My_Strcat(char *Dest, char *Src)
{
	int i;
	int j;

	i = 0;
	while (Dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (Src[j] != '\0')
	{
		Dest[i] = Src[j];
		i++;
		j++;
	}
	Dest[i] = '\0';
	return (Dest);
}
