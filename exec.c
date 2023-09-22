#include "shell_header.h"

/**
 * exec_command - Execute the given command
 * @cmd: command string
 * Return: 0 (if successful), -1 (if fails)
 */

int exec_command(char *cmd)
{
	pid_t pid = fork();
	int status, i = 0, error_msg_len = 0;
	char *argv[100], *error_msg, *token = strtok(cmd, " ");

	while (token != NULL)
	{
		argv[i++] = token;
		token = strtok(NULL, " ");
	}
	argv[i] = NULL;

	if (argv[0][0] != '/')
	{
		error_msg = "./shell: command not found\n";

		while (error_msg[error_msg_len])
			error_msg_len++;
		write(STDERR_FILENO, error_msg, error_msg_len);
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
	return (0);
}
