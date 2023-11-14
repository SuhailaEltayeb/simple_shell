#include "shell.h"
/**
 * _Strcspn -  fucntion to return the len of segment of string
 * of chars not in 2nd string
 * @_Str1: first input string
 * @_Str2: second input string
 * Return: # of bytes that are not included in second string
 */
size_t _Strcspn(const char *_Str1, const char *_Str2)
{
	const char *_Ptr1, *_Ptr2;

	for (_Ptr1 = _Str1; *_Ptr1 != '\0'; _Ptr1++)
	{
		for (_Ptr2 = _Str2; *_Ptr2 != '\0'; _Ptr2++)
		{
			if (*_Ptr1 == *_Ptr2)
			{
				return (_Ptr1 - _Str1);
			}
		}
	}
	return (_Ptr1 - _Str1);
}

/**
 * _Strdup - function to duplicate an input string
 * @Str: string to be duplicated
 * Return: pointer to duplicated string
 */
char *_Strdup(char *Str)
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
	for (j = 0; j <= i; j++)
	{
		output[j] = Str[j];
	}
	return (output);
}
/**
 * _Strcmp - function to compare 2 input strings
 * @Str1: first input string
 * @Str2: second input string
 * Return: differences between the 2 input strings
 */
int _Strcmp(char *Str1, char *Str2)
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
