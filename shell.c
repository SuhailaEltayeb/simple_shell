#include "shell.h"


/**
 * main - Entry point of the program
 *
 * Return: Returns the exit status of the last executed command.
 */
int main(void)
{
	char *store_str = NULL;
	size_t i = 0;
	ssize_t char_num;
	int execute_status = -1;
	char *token;
	char **argv = NULL;
	int counter = 0;

	for (;;)
	{
		if (isatty(fileno(stdin)))
		{
			write(1, "$ ", 2);
		}
		char_num = getline(&store_str, &i, stdin);
		if (char_num == -1)
		{
			break;
		}
		else
		{
			store_str[_Strcspn(store_str, "\n")] = '\0';

			if (_Strcmp(store_str, "exit") == 0)
			{
				break;
			}

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
			}
		}
	}

	free(store_str);
	return (execute_status);
}
