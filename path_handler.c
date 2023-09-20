#include "shell_header.h"

/**
 * find_command_in_path - Searches for a command
 * @cmd: The name of the command to search for
 *
 * Return: A pointer to a string containing the full path
 */
char *find_command_in_path(char *cmd)
{
	char *path_env = getenv("PATH");
	char *path = malloc(PATH_MAX);
	char *token = strtok(path_env, ":");
	int status;

	if (path_env == NULL || path == NULL)
		return (NULL);

	while (token != NULL)
	{
		snprintf(path, PATH_MAX, "%s/%s", token, cmd);
		status = access(path, F_OK | X_OK);

		if (status == 0)
			return (path);
		token = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}
