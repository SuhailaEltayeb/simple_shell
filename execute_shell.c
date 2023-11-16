#include "shell.h"
/**
 * execute_shell - function to execute shell program
 *
 * Return: void
 */
void execute_shell(void)
{
	char *store_str = NULL;
	size_t i = 0;
	ssize_t char_num;
	int execute_status = -1;
	char *token;
	char **argv = NULL;
	int counter = 0;
	int j;
	char *comment_pos;

	for (;;)
	{
		if (isatty(fileno(stdin)))
		{
			write(1, "$ ", 2); }
		char_num = getline(&store_str, &i, stdin);
		if (char_num == -1)
		{
			break;
		}
		else
		{
			store_str[strcspn(store_str, "\n")] = '\0';
			if (strcmp(store_str, "exit") == 0)
			{
				break; }
			comment_pos = strchr(store_str, '#');
			if (comment_pos != NULL)
			{
				*comment_pos = '\0'; }
			if (strlen(store_str) == 0)
			{
				continue; }
			token = strtok(store_str, " ");
			while (token != NULL)
			{
				if (strcmp(token, "$?") == 0)
				{
					char exit_status[4];

					snprintf(exit_status, sizeof(exit_status), "%d", execute_status);
					argv = realloc(argv, (counter + 1) * sizeof(char *));
					argv[counter] = strdup(exit_status); }
				else if (strcmp(token, "$$") == 0)
				{
					char pid[10];

					snprintf(pid, sizeof(pid), "%d", getpid());
					argv = realloc(argv, (counter + 1) * sizeof(char *));
					argv[counter] = strdup(pid); }
				else
				{
					argv = realloc(argv, (counter + 1) * sizeof(char *));
					argv[counter] = strdup(token); }
				counter++;
				token = strtok(NULL, " "); }
			if (counter > 0)
			{
				argv = realloc(argv, (counter + 1) * sizeof(char *));
				argv[counter] = NULL;
				execute_status = _execvp(argv[0], argv);
				for (j = 0; j <= counter; j++)
				{
					free(argv[j]); }
				free(argv);
				argv = NULL;
				counter = 0; } } }
	free(store_str); }
