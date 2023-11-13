#include "shell.h"

/**
 * My_Strtok - function to pares input string into tokens
 * @_String: input strint to be tokenized
 * @_Delemiter: delemiter used to tokenize the input string
 * Return: ptr to 1st token of tokenized string
 */
char *My_Strtok(char *_String, const char *_Delemiter)
{
	static char _BUFF;
	int i, j, Copy, Match;
	char *Start, *End, *Token;

	if (_String != NULL)
		_BUFF = _String;
	if (!_BUFF || *_BUFF == '\0')
		return (NULL);
	Token = _BUFF;
	for (; *_BUFF != '\0'; _BUFF++)
	{
		j = 0;
		if (*_BUFF == _Delemiter[j++])
		{
			Match = Copy = 0;
			End = _BUFF++;
			Start = _BUFF;
			for (; _Delemiter[j] != '\0'; j++)
			{
				if (*Start++ != _Delemiter[j])
				{
					Match = (-1);
					break;
				}
				Copy++;
			}
			if (Match == 0)
			{
				_BUFF = Start;
				*End = '\0';
				if (*Token != '\0')
				{
					return (Token);
				}
				else
					return (My_Strtok(NULL, _Delemiter)); } } }
	_BUFF = NULL;
	return (Token);
}
