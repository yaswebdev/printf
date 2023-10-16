#include "main.h"
#include <stdio.h>

/**
 * print_char_plain - prints a char, with no formatting
 * @c: char to print
 *
 * Return: number of characters printed, or -1 on error
 */
int print_char_plain(char c)
{
	int result;

	/*
	*if (DEBUG)
	*{
	*	printf("print_char_plain: ");
	*	fflush(stdout);
	}
	*/

	result = _putchar(c);

	/*
	*if (DEBUG)
	*	printf(" [count: %d]\n", result);
	*/
	return (result);
}

/**
 * print_char - prints a char
 * @ap: _printf's variadic argument pointer holding char to print
 *
 * Return: number of characters printed, or -1 on error
 */
int print_char(va_list ap)
{
	int result;
	int arg;

	/*
	*if (DEBUG)
	*{
	*	printf("print_char: ");
	*	fflush(stdout);
	}
	*/

	arg = va_arg(ap, int);

	if (sizeof(arg) != 4)
	{
		if (DEBUG)
		{
			printf("sizeof(arg) = %lu != 4", sizeof(arg));
			return (-1);
		}
	}
	if (arg < 0 || arg > 255)
	{
		if (DEBUG)
		{
			printf("arg(%d): < 0 || > 255", arg);
			return (-1);
		}
	}

	result = _putchar(va_arg(ap, int));

	/*
	*if (DEBUG)
	*	printf(" [count: %d]\n", result);
	*/

	return (result);
}

/**
 * print_str - prints a string
 * @ap: _printf's variadic argument pointer holding string to print
 *
 * Return: number of characters printed, or -1 on error
 */
int print_str(va_list ap)
{
	char *str = va_arg(ap, char *);
	int i;
	int i_result, result = 0;

	/*
	*if (DEBUG)
	*{
	*	printf("print_str: ");
	*	fflush(stdout);
	*}
	*/

	for (i = 0; str[i] != '\0'; i++)
	{
		i_result = _putchar(str[i]);
		if (DEBUG)
		{
			printf("\nprint_str: i_result(%d), result(%d)\n", i_result, result);
		}
		if (i_result == -1)
			return (-1);

		result += i_result;
	}

	/*
	*if (DEBUG)
	*	printf(" [count: %d]\n", result);
	*/

	return (result);
}
