#include "shell.h"

/**
 * main - Entry point of the program
 *
 * Return: Returns the exit status of the last executed command.
 */
int main(void)
{
	char *store_str = NULL;
	size_t char_num, i = 0;
	int execute_status = -1;
	char *token, **argv = NULL;
	int counter = 0;
	char *comment;
	char *newline = NULL;

	for (;;)
	{
		if (isatty(fileno(stdin)))
		{
			write(1, "$ ", 2); }
		char_num = getline(&store_str, &i, stdin);
		if ((long int)char_num == -1)
		{
			break;
		}
		else
		{
			comment = strchr(store_str, '#');
			if (comment != NULL)
			{
				*comment = ('\0');
			}
			while ((newline = strchr(store_str, '\n')) != NULL)
			{
				*newline = ('\0');
				token = strtok(store_str, " ");
				while (token != NULL)
				{
					argv = realloc(argv, (counter + 1) * sizeof(char *));
					argv[counter] = token;
					counter++;
					token = strtok(NULL, " ");
				}
			if (counter > 0)
			{
				argv = realloc(argv, (counter + 1) * sizeof(char *));
				argv[counter] = NULL;
				execute_status = _execvp(argv[0], argv);
				free(argv);
				argv = NULL;
				counter = (0);
			}
			}
		}
	}
	free(store_str);
	return (execute_status);
}
