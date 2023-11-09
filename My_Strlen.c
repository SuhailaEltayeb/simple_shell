#include "shell.h"

/**
 * My_Strlen - function to return lenghth of string
 * @str: input string to which lenghth is returned
 * Return: lenghth of input string
 */
int My_Strlen(char *str)
{
	int Len = 0; /* Length of string */

	while (*str != '\0')
	{
		Len++;
		str++;
	}
	return (Len);
}
