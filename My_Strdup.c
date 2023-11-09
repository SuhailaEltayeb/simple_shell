#include "shell.h"

/**
 * My_Strdup - function to duplicate an input string
 * @Str: string to be duplicated
 * Return: pointer to duplicated string
 */
char *My_Strdup(char *Str)
{
	size_t i, j;
	char *output;

	if (Str == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (Str[i] != '\0')
	{
		i++;
	}
	output = malloc(sizeof(char) * (i + 1));
	if (output == NULL)
	{
		return (NULL);
	}
	for (j = 0, j <= i; j++)
	{
		output[j] = Str[j];
	}
	return (output);
}
