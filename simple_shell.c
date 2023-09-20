#include "shell_header.h"

/**
 * main - Entry point for the shell
 * Return: 0 on success, 1 on failure
 */

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read = getline(&line, &len, stdin);
	int interactive = isatty(STDIN_FILENO);

	while (1)
	{
		if (interactive)
			write(STDOUT_FILENO, "$ ", 2);

		if (read == -1)
		{
			if (feof(stdin))
			{
				if (interactive)
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

		if (!interactive)
			break;
	}
	free(line);
	return (0);
}
