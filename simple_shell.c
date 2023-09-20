#include "shell_header.h"

/**
 * main - Entry point for the shell
 * Return: 0 on success, 1 on failure
 */
i
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read = getline(&line, &len, stdin);

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);

		if (read == -1)
		{
			if (feof(stdin))
			{
				write(STDOUT_FILENO, "\n", 1);
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
	free(line);
	return (0);
}
