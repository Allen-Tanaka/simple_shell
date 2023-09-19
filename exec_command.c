#include "shell_header.h"

/**
 * exec_command - Execute the given command
 * @cmd: command string
 * Return: 0 (if successful), -1 (if fails)
 */

int exec_command(char *cmd)
{
	pid_t pid = fork(), wpid;
	int status;

	if (pid == 0)
	{
		if (execve(cmd, NULL, NULL) == -1)
			perror("simple_shell");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("simple_shell");
	else
	{
		do
			wpid = waitpid(pid, &status, WUNTRACED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (0);
}
