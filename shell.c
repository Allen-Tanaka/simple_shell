#include "shell_header.h"

/**
 * main - Entry point for the shell
 * Return: 0 on success, 1 on failure
 */
int main(void)
{
	if (isatty(STDIN_FILENO))
		interactive_mode();
	else
		non_interactive_mode();
	return (0);
}

/**
 * interactive_mode - handles shell in interactive mode.
 */
void interactive_mode(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);
		read = getline(&line, &len, stdin);

		if (read == -1)
			break;
		if (read > 1)
		{
			line[read - 1] = '\0';
			process_input(line);
		}
	}
	free(line);
}

/**
 * non_interactive_mode - shell in non_interactive_mode
 */
void non_interactive_mode(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	read = getline(&line, &len, stdin);
	if (read > 1)
	{
		line[read - 1] = '\0';
		process_input(line);
	}
	free(line);
}

/**
 * process_input - Processes the user's input string for execution
 * @line: The command to be processed.
 */
void process_input(char *line)
{
	if (is_exit_command(line))
	{
		exit(EXIT_SUCCESS);
	}
	exec_command(line);
}
