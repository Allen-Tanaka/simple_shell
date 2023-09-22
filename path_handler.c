#include "shell_header.h"

/**
 * get_command_path - searches the PATH
 * @cmd: command to search for
 *
 * Return: full path of the command or NULL if not found
 */
char *get_command_path(char *cmd)
{
	char *PATH = getenv("PATH");
	char *dir, *save_ptr, *full_path;
	size_t dir_len, cmd_len;
	char *temp = full_path;

	if (PATH == NULL)
		return (NULL);

	PATH = strdup(PATH);
	cmd_len = custom_strlen(cmd);

	for (dir = strtok_r(PATH, ":", &save_ptr); dir; dir = strtok_r
			(NULL, ":", &save_ptr))
	{
		dir_len = custom_strlen(dir);
		full_path = malloc(dir_len + cmd_len + 2);

		while (*dir)
			*temp++ = *dir++;
		*temp++ = '/';
		while (*cmd)
			*temp++ = *cmd++;
		*temp = '\0';

		if (access(full_path, X_OK) == 0)
		{
			free(PATH);
			return (full_path);
		}
		free(full_path);
	}
	free(PATH);
	return (NULL);
}
