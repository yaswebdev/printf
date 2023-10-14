#include <unistd.h>
#include <stdio.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	/*return (write(1, &c, 1));*/

	ssize_t result;

	result = (write(1, &c, 1));

	if (result == -1)
		exit(1);

	fflush(stdout);

	/*printf("\nprinted: %c (%d)\n", c, c);*/

	return (result);
}
