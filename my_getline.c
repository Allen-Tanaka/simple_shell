#include "shell_header.h"

#define BUFFER_SIZE 4096

/**
 * refill_buffer - Refills the buffer from standard input
 * @buffer: buffer to fill
 * @characters_left: pointer to variable holding characters left
 * @buffer_ptr: pointer to the current buffer position
 *
 * Return: number of characters read, or -1 on EOF or error
 */


static ssize_t refill_buffer(char *buffer, size_t *characters_left,
		char **buffer_ptr)
{
	ssize_t characters_read;

	characters_read = read(STDIN_FILENO, buffer, 4096);

	if (characters_read > 0)
	{
		*characters_left = characters_read;
		*buffer_ptr = buffer;
	}
	return (characters_read);
}


/**
 * my_getline - custom getline implementation to read lines from STDIN
 * @line: double pointer to the buffer to fill with the read line
 * @n: pointer to the length of the buffer
 *
 * Return: number of characters read, or -1 on failure or EOF
 */
ssize_t my_getline(char **line, size_t *n)
{
	static char buffer[4096], *buffer_ptr;
	static size_t characters_left;
	size_t total_read = 0;
	char *line_ptr;

	if (!line || !n)
		return (-1);
	if (!*line)
	{
		*line = malloc(4096);
		if (!*line)
			return (-1);
		*n = 4096;
	}
	line_ptr = *line;

	while (1)
	{
		if (characters_left == 0 && refill_buffer(buffer, &characters_left,
					&buffer_ptr) <= 0)
			return (total_read ? (ssize_t) total_read : (ssize_t) -1);

		if (total_read >= *n - 1)
		{
			*n += 4096;
			*line = realloc(*line, *n);
			if (!*line)
				return (-1);
			line_ptr = *line + total_read;
		}
		*line_ptr++ = *buffer_ptr++;
		total_read++;
		characters_left--;

		if (line_ptr[-1] == '\n')
		{
			*line_ptr = '\0';
			return (total_read);
		}
	}
}
