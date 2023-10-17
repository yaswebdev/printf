#include <unistd.h>

#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	int bwritten = (write(1, &c, 1));

	/*
	*if (bwritten == -1)
	*{
	*	printf(RED_TEXT "!!! ERROR ||| Unhandled (bwritten == -1)");
	*	exit(1);
	*}
	*/

	fflush(stdout);

	return (bwritten);
}

void putchar_buf(char c, char *buffer, int *buffer_len, int *bwritten)
{
	if (*buffer_len == 1024)
	{
		(*bwritten) += writebuffer(buffer, *buffer_len);
		*buffer_len = 0;
	}

	buffer[*buffer_len] = c;
	(*buffer_len)++;
}
