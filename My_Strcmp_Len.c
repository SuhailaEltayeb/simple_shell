#include "shell.h"

/**
 * My_Strcmp_Len - function to compare 2 strings until specific lenghth
 * @Str1: 1st input string to compare
 * @Str2: 2nd input string to compare
 * @Len: Max lengh of strings to compare
 * Return: 0, if successful
 */
int My_Strcmp_Len(const char *Str1, Const char *Str2, Size_t Len)
{
	unsigned char Char1;
	unsigned char Char2;

	for (; Len > 0; Len--)
	{
		Char1 = (unsigned char)(*Str1);
		Str1++;
		Char2 = (unsigned int)(*Str2);
		Str2++;

		if (Char1 != Char2)
			return (Char1 - Char2);
		if (Char1 == '\0')
			break;
	}
	return (0);
}

