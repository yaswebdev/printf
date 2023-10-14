#include "main.h"
#include <stdio.h>

/**
 * print_char_plain - prints a char, with no formatting
 * @c: char to print
 * @count: pointer to printed chars count
 */
void print_char_plain(char c, int *count)
{
	if (DEBUG)
	{
		printf("print_char_plain: ");
		fflush(stdout);
	}

	_putchar(c);
	(*count)++;

	if (DEBUG)
		printf(" [count: %d]\n", *count);
}

/**
 * print_char - prints a char
 * @ap: _printf's variadic argument pointer holding char to print
 * @count: pointer to printed chars count
 */
void print_char(va_list ap, int *count)
{
	if (DEBUG)
	{
		printf("print_char: ");
		fflush(stdout);
	}

	_putchar(va_arg(ap, int));
	(*count)++;

	if (DEBUG)
		printf(" [count: %d]\n", *count);
}

/**
 * print_str - prints a string
 * @ap: _printf's variadic argument pointer holding string to print
 * @count: pointer to printed chars count
 */
void print_str(va_list ap, int *count)
{
	char *str = va_arg(ap, char *);
	int i;

	if (DEBUG)
	{
		printf("print_str: ");
		fflush(stdout);
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
		(*count)++;
	}


	if (DEBUG)
		printf(" [count: %d]\n", *count);
}
