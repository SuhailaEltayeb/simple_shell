#include "shell.h"


ssize_t My_Getline(char **_lineptr, size_t *size, int str)
{
        static char _BUFF[BUFFER_SIZE];
        int Chars_Read = 0;
        int j = 0;
	int i = 0;

        if (*size == 0 || !(*_lineptr))
        {
                *size = BUFFER_SIZE;
                *_lineptr = malloc(sizeof(char) * (*size));
                if (!(*_lineptr))
                        return (-1);
        }
        while (1)
        {
                if (j >= Chars_Read)
                {
                        Chars_Read = read(str, _BUFF, BUFFER_SIZE);
                        j = 0;
                }
                if (Chars_Read == 0 || Chars_Read == -1)
                        return (-1);
                if ((size_t)i > *size)
                {
                        *size = *size + BUFFER_SIZE;
                        *_lineptr = realloc(*_lineptr, *size);
                        if (!(*_lineptr))
                                return (-1);
                }
                if (_BUFF[j] == '\n') 
		{
                        _BUFF[j] = '\0';
                        i++;
                        j++;
                        break;
                }
                (*_lineptr)[i] = _BUFF[j];
                i++;
                j++; }
        if (i == 0 || Chars_Read == 0)
                return (-1);
        return (i);
}
