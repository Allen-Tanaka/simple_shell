#include "shell_header.h"

/**
 * parse_arguments - Parse the command-line arguments
 * @cmd: input command string
 * @argv: array populating with passsed arguements
 */
void parse_arguments(char *cmd, char **argv)
{
	int i = 0;
	char *token = strtok(cmd, " ");

	while (token != NULL)
	{
		argv[i++] = token;
		token = strtok(NULL, " ");
	}
	argv[i] = NULL;
}

