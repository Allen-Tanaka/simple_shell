#include "shell_header.h"

/**
 * is_exit_command - Checks if the command is 'exit'
 * @cmd: The command to check
 *
 * Return: 1(exit), 0 (otherwise)
 */
int is_exit_command(const char *cmd)
{
	return (strcmp(cmd, "exit") == 0);
}
