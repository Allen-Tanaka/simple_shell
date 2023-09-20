#include "shell_header.h"

/**
 * main - Entry point for the shell
 * Return: 0 on success, 1 on failure
 */

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);

		read = getline(&line, &len, stdin);

		if (read == -1)
		{
			if (feof(stdin))
			{
				free(line);
				exit(EXIT_SUCCESS);
			}
			else
			{
				perror("getline");
				free(line);
				exit(EXIT_FAILURE);
			}
		}

		if (read > 1)
		{
			line[read - 1] = '\0';
			exec_command(line);
		}
	}
	return (0);
}
