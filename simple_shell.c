#include "shell_header.h"

/**
 * main - Entry point for the shell
 * Return: 0 on success, 1 on failure
 */

int main(void)
{
	char *line = NULL, *argv[];
	int argc;
	size_t len = 0;
	ssize_t read;
	
	if (argc == 1)
	{
		while (1)
		{
			write(STDOUT_FILENO, "#cisfun$ ", 9);

			read = getline(&line, &len, stdin);

			if (read == -1)
			{
				free(line);
				if (feof(stdin))
					exit(EXIT_SUCCESS);
				else
				{
					perror("getline");
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
		exec_command(argv[1]);
	free(line);
	return (0);
}
