#include "main.h"

/**
 * process_percent - prints a percentage sign
 * @tag: pointer to struct holding tag's options
 *
 * Return: -1 on error, 0 otherwise
 */
int process_percent(tag_t *tag, char *buffer, int *buffer_len, int *bwritten)
{
	putchar_buf('%', buffer, buffer_len, bwritten);
	reset_tag(tag);

	return (0);
}

/**
 * process_c - prints a char from the next variable function argument
 * @tag: pointer to struct holding tag's options
 * @ap: variable argument pointer
 *
 * Return: -1 on error, 0 otherwise
 */
int process_c(tag_t *tag, va_list ap, char *buffer, int *buffer_len, int *bwritten)
{
	int arg = va_arg(ap, int);

	/*
	 * if (arg < 32 || arg > 126)
	 *	return (0);
	 */


	/*printf("\narg: %d\n", arg);*/

	putchar_buf(arg, buffer, buffer_len, bwritten);
	reset_tag(tag);

	return (0);
}

/**
 * process_s - prints a string from the next variable function argument
 * @tag: pointer to struct holding tag's options
 * @ap: variable argument pointer
 *
 * Return: -1 on error, 0 otherwise
 */
int process_s(tag_t *tag, va_list ap, char *buffer, int *buffer_len, int *bwritten)
{
	char *arg = va_arg(ap, char *);
	int i;
	int *hex_arr;

	if (arg == NULL)
	{
		arg = "(null)";
	}

	/*printf("%p\n", arg);*/
	/*printf("arg[0]: %s\n", arg[0]);*/

	for (i = 0; arg[i] != '\0'; i++)
	{
		/*printf("str char: |");*/
		if (!tag->is_print_np)
			putchar_buf(arg[i], buffer, buffer_len, bwritten);
		else
		{
			if (arg[i] >= 32 && arg[i] <= 126)
				putchar_buf(arg[i], buffer, buffer_len, bwritten);
			else
			{
				putchar_buf('\\', buffer, buffer_len, bwritten);
				putchar_buf('x', buffer, buffer_len, bwritten);
				p_as_hex(buffer, buffer_len, bwritten, arg[i], 2, 1);
			}
		}
		/*printf("|\n");*/
	}

	reset_tag(tag);

	return (0);
}


/**
 * process_int - prints an int from the next variable function argument
 * @tag: pointer to struct holding tag's options
 * @ap: variable argument pointer
 *
 * Return: -1 on error, 0 otherwise
 */
int process_int(tag_t *tag, va_list ap, char *buffer, int *buffer_len, int *bwritten)
{
	int i;
	int arg = va_arg(ap, int);
	unsigned int arg_unsigned;
	int *num_arr;

	if (tag->is_signed && arg < 0)
	{
		putchar_buf('-', buffer, buffer_len, bwritten);
		arg *= -1;
	}
	arg_unsigned = arg;

	num_arr = decimal_to_basex(arg_unsigned, tag->base);

	for (i = 1 + num_arr[0] - 1; i >= 1; i--)
	{
		if (tag->base > 10)
		{
			if (num_arr[i] >= 10)
				putchar_buf((tag->is_capital ? 'A' : 'a') + num_arr[i] - 10, buffer, buffer_len, bwritten);
			else
				putchar_buf('0' + num_arr[i], buffer, buffer_len, bwritten);
		}
		else
			putchar_buf('0' + num_arr[i], buffer, buffer_len, bwritten);
	}

	/*print_number(arg, &b_written, tag->is_signed);*/
	reset_tag(tag);

	return (0);
}

/**
 * process_b - prints an unsigned int from the next variable function argument
 * as binary
 * @tag: pointer to struct holding tag's options
 * @ap: variable argument pointer
 *
 * Return: -1 on error, 0 otherwise
 */
int process_b(tag_t *tag, va_list ap, char *buffer, int *buffer_len, int *bwritten)
{
	int i;
	unsigned int arg = va_arg(ap, unsigned int);
	int *bin;

	bin = decimal_to_binary(arg);

	for (i = 1 + bin[0] - 1; i >= 1; i--)
	{
		putchar_buf('0' + bin[i], buffer, buffer_len, bwritten);
	}

	reset_tag(tag);

	return (0);
}


