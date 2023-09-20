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

	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			write(STDOUT_FILENO, "#cisfun$ ", 9);
			read = getline(&line, &len, stdin);

			if (read == -1)
			{
				free(line);
				if (feof(stdin))
				{
					write(STDOUT_FILENO, "\n", 1);
					exit(EXIT_SUCCESS);
				}
				else
				{
					perror("shell");
					exit(EXIT_FAILURE);
				}
			}
			if (read > 1)
			{
				line[read - 1] = '\0';
				exec_command(line);
			}
		}
	}
	else
	{
		read = getline(&line, &len, stdin);

		if (read > 1)
		{
			line[read - 1] = '\0';
			exec_command(line);
		}
		free(line);
		write(STDOUT_FILENO, "#cisfun$ ", 9);
	}
	return (0);
}
