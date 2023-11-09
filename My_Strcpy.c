#include "shell.h"

/**
 * My_Strcpy - function to copy string
 * @Src: string to copy from
 * @Dest: string to copy to
 * Return: pointer to destination string
 */
char *My_Strcpy(char *Src, char *Dest)
{
	int Len = 0;
	int idx = 0;

	while (*(Src + Len) != '\0')
	{
		Len++;
	}
	for ( ; idx < Len; idx++)
	{
		Dest[idx] = Src[idx];
	}
	Dest[Len] = '\0';
	return (Dest);
}
