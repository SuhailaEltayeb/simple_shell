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
			store_str[_Strcspn(store_str, "\n")] = '\0';
			if (_Strcmp(store_str, "exit") == 0)
			{
				free(store_str);
				return (execute_status);
		       	}
			
			comment = strchr(store_str, '#');
            
            if (comment != NULL)
            {
                *comment = '\0';
            }
            
            if (strlen(store_str) == 0)
            {
                continue;
            }

			token = strtok(store_str, " ");
			while (token != NULL)
			{
				argv = realloc(argv, (counter + 1) * sizeof(char *));
				argv[counter] = token;
				counter++;
				token = strtok(NULL, " "); }
			if (counter > 0)
			{
				argv = realloc(argv, (counter + 1) * sizeof(char *));
				argv[counter] = NULL;
				execute_status = _execvp(argv[0], argv);
				free(argv);
				argv = NULL;
				counter = 0;
			}
		}
	}


	free(store_str);
	return (execute_status);
}
