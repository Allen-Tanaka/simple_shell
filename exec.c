#include "shell_header.h"

/**
 * exec_command - Execute the given command
 * @cmd: command string
 * Return: 0 (if successful), -1 (if fails)
 */

int exec_command(char *cmd)
{
	pid_t pid = fork();
	int status;
	char *argv[100], *path_cmd;

	parse_arguments(cmd, argv);
	path_cmd = find_command_in_path(argv[0]);

	if (path_cmd == NULL)
	{
		perror("./shell");
		return (-1);
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
