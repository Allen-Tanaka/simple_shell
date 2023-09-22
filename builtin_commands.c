#include "shell_header.h"

/**
 * is_exit_command - Checks if the command is 'exit'
 * @cmd: The command to check
 *
 * Return: 1(exit), 0 (otherwise)
 */
int is_exit_command(const char *cmd)
{
	const char *exit_cmd = "exit";

	while (*cmd && *exit_cmd)
	{
		if (*cmd != *exit_cmd)
			return (0);
		cmd++;
		exit_cmd++;
	}
	return (!(*cmd) && !(*exit_cmd));
}
