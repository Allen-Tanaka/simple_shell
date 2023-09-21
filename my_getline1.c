#include "shell_header.h"

/**
 * my_getline - Reads an entire line from the standard input stream
 * @line: Pointer to the buffer
 * @n: Pointer to the number of characters
 *
 * Return: Number of characters read, or -1 (on failure)
 */
ssize_t my_getline1(char **line, size_t *n)
{
	static char buffer[1024];
	int total_read = 0, bytes_read;
	char *temp = NULL;

	if (!line || !n)
		return (-1);
	bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);

	if (bytes_read <= 0)
		return (-1);

	buffer[bytes_read] = '\0';
	*line = strdup(buffer);

	if (!*line)
		return (-1);

	total_read += bytes_read;
	*n = bytes_read;

	return (total_read ? (ssize_t) total_read : (ssize_t) -1);
}
