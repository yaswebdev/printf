#include "main.h"

/**
 * process_percent - prints a percentage sign
 * @tag: pointer to struct holding tag's options
 *
 * Return: number of bytes printed
 */
int process_percent(tag_t *tag)
{
	int b_written;

	b_written = _putchar('%');
	reset_tag(tag);

	return (b_written);
}

/**
 * process_c - prints a char from the next variable function argument
 * @tag: pointer to struct holding tag's options
 * @ap: variable argument pointer
 *
 * Return: number of bytes printed
 */
int process_c(tag_t *tag, va_list ap)
{
	int b_written;
	int arg = va_arg(ap, int);

	/*
	 * if (arg < 32 || arg > 126)
	 *	return (0);
	 */


	/*printf("\narg: %d\n", arg);*/

	b_written = _putchar(arg);
	reset_tag(tag);

	return (b_written);
}

/**
 * process_s - prints a string from the next variable function argument
 * @tag: pointer to struct holding tag's options
 * @ap: variable argument pointer
 *
 * Return: number of bytes printed
 */
int process_s(tag_t *tag, va_list ap)
{
	int b_written = 0;
	char *arg = va_arg(ap, char *);
	int i;

	if (arg == NULL)
	{
		arg = "(null)";
	}

	/*printf("%p\n", arg);*/
	/*printf("arg[0]: %s\n", arg[0]);*/

	for (i = 0; arg[i] != '\0'; i++)
	{
		/*printf("str char: |");*/
		b_written += _putchar(arg[i]);
		/*printf("|\n");*/
	}

	reset_tag(tag);

	return (b_written);
}


/**
 * process_d - prints an int from the next variable function argument
 * @tag: pointer to struct holding tag's options
 * @ap: variable argument pointer
 *
 * Return: number of bytes printed
 */
int process_d(tag_t *tag, va_list ap)
{
	int b_written = 0;
	int arg = va_arg(ap, int);

	print_number(arg, &b_written);
	reset_tag(tag);

	return (b_written);
}

/**
 * process_b - prints an unsigned int from the next variable function argument
 * as binary
 * @tag: pointer to struct holding tag's options
 * @ap: variable argument pointer
 *
 * Return: number of bytes printed
 */
int process_b(tag_t *tag, va_list ap)
{
	int b_written = 0, i;
	unsigned int arg = va_arg(ap, unsigned int);
	int *bin;

	bin = decimal_to_binary(arg);

	for (i = 1 + bin[0] - 1; i >= 1; i--)
	{
		b_written += _putchar('0' + bin[i]);
	}

	reset_tag(tag);

	return (b_written);
}


