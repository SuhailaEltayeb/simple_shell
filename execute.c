#include "shell.h"

/**
 * _execvp - Executes a file with the given arguments
 * @file: The path to the file to be executed
 * @argv: An array of arguments including the file to be executed
 *
 * Return: On success, returns the exit status of the executed file.
 *         On failure, returns -1.
 */

int _execvp(const char *file, char *const argv[])
{
	pid_t pid;
	int status;
	char command_path[MAX_PATH_LENGTH];
	char *path;
	char *path_copy;
	char *dir;

	pid = fork();
	if (pid == -1)
		{
			perror("fork");
			return (-1);
		}
	else if (pid == 0)
		{
			if (strchr(file, '/') != NULL)
				{
				int execute_status = execv(file, argv);

				if (execute_status == -1)
				{
		perror("execv");
		_exit(1);
				}
	}
	else
	{
		path = getenv("PATH");
		path_copy = _Strdup(path);
		dir = strtok(path_copy, ":");

		while (dir != NULL)
		{
		snprintf(command_path, sizeof(command_path), "%s/%s", dir, file);

		execv(command_path, argv);
		dir = strtok(NULL, ":");
		}

		fprintf(stderr, "%s: Command not found\n", file);
		free(path_copy);
		_exit(1);
	}
		}
	else
	{
		waitpid(pid, &status, 0);
		return (status);
	}

	return (-1);
}
