#include "shell.h"

/**
 * My_GetEnv - function to print environment variables
 * @name: environment variable name
 * Return: if successful, environment variable, NULL otherwise
 */
char *My_GetEnv(const char *name)
{
	char **Env_Name;
	size_t Len = My_Strlen(name);

	for (Env_Name = environ; *Env_Name != NULL; Env_Name++)
	{
		if (My_Strcmp_Len(*Env_Name, name, Len) == 0
				&& (*Env_Name)[Len] == '=')
		{
			return (&(*Env_Name)[Len + 1]);
		}
	}
	return (NULL);
}
