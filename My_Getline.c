#include "shell.h"

/**
 * My_Getline - function to read sting input
 * @_lineptr: buffer pointer where to store u=input stirng
 * @size: size of buffer used to store input string
 * @str: input stream
 * Return: if successful, # of chars read, otherwise -1
 */
ssize_t My_Getline(char **_lineptr, size_t *size, int str)
{
	static char _BUFF[BUFFER_SIZE];
	int x = 0;
	int y = 0;
	int _Chars_Read = 0;

	if (*size == 0 || !(*_lineptr))
	{
		*size = BUFFER_SIZE;
		*_lineptr = malloc(sizeof(char) * (*size));
		if (!(*_lineptr))
			return (-1); }
	while (1)
	{
		if (y >= Chars_Read)
		{
			Chars_Read = read(str, _BUFF, BUFFER_SIZE);
			y = 0;
		}
		if (Chars_Read == 0 || Chars_Read == -1)
			return (-1);
		if ((size_t)x > *size)
		{
			*size = *size + BUFFER_SIZE;
			*_lineptr = realloc(*_lineptr, *size);
			if (!(*_lineptr))
				return (-1);
		}
		if (_BUFF[y] == '\n')
		{
			_BUFF[y] = '\0';
			x++;
			y++;
			break;
		}
		(*_lienptr)[x] = _BUFF[y];
		x++;
		y++; }
	if (x == 0 || Chars_Read == 0)
		return (-1);
	return (x);
}
