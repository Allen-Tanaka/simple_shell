#include "shell_header.h"

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
	struct stat st;

	while (token != NULL)
	{
		argv[i++] = token;
		token = strtok(NULL, " ");
	}
	argv[i] = NULL;

	if (stat(argv[0], &st) == 0 && (st.st_mode & S_IXUSR))
	{
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
	}
	else
		write(STDERR_FILENO, "./shell: No such file or directory\n", 35);
	return (0);
}
