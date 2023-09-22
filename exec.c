#include "shell_header.h"

/**
 * custom_strlen -  custo, length function
 * @str: the string to compute length for
 *
 * Return: length of the string
 */
size_t custom_strlen(const char *str)
{
	size_t len = 0;

	while (*str++)
		len++;
	return (len);
}

/**
 * exec_command - Execute the given command
 * @cmd: command string
 * Return: 0 (if successful), -1 (if fails)
 */

int exec_command(char *cmd)
{
	pid_t pid = fork();
	int status, i = 0;
	char *argv[100], *token = strtok(cmd, " ");

	while (token != NULL)
	{
		argv[i++] = token;
		token = strtok(NULL, " ");
	}
	argv[i] = NULL;
	if (argv[0][0] != '/' && argv[0][0] != '.')
	{
		path_cmd = get_command_path(argv[0]);
		if (!path_cmd)
		{
			write(STDERR_FILENO, "./shell: ", 9);
			write(STDERR_FILENO, cmd, custom_strlen(cmd));
			write(STDERR_FILENO, ": command not found\n", 20);
			return (-1);
		}
		argv[0] = path_cmd;
	}
	if (pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
		perror("./shell");
	else
	{
		do
			waitpid(pid, &status, WUNTRACED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	free(path_cmd);
	return (0);
}
