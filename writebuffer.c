#include <unistd.h>

#include "main.h"

/**
 * writebuffer - writes the buffer to stdout
 * @buffer: The buffer to print
 *
 * Return: n of bytes written, or -1 on error
 */
int writebuffer(char *buffer, int *buffer_len)
{
	int bwritten = (write(1, buffer, *buffer_len));

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
