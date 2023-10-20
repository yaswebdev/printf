#include "main.h"

/**
 * decimal_to_binary - converts decimal number to binary
 * @num: number in decimal form to convert
 *
 * Return: binary number as array
 */
int *decimal_to_binary(unsigned int num)
{
	static int bin[33];
	int i = 1;

	if (num == 0)
		bin[i++] = 0;

	for (; num > 0; )
	{
		bin[i++] = num % 2;
		num /= 2;
	}


	bin[0] = i - 1;

	return (bin);
}

/**
 * decimal_to_basex - converts decimal number to a base number
 * @num: number in decimal form to convert
 * @base: goal number base
 *
 * Return: binary number as array
 */
unsigned long *decimal_to_basex(unsigned long num, int base)
{
	static unsigned long bin[33];
	int i = 1;

	if (num == 0)
		bin[i++] = 0;

	for (; num > 0; )
	{
		bin[i++] = num % base;
		num /= base;
	}


	bin[0] = i - 1;

	return (bin);
}

void p_as_hex(char *buffer, int *buffer_len, int *bwritten, unsigned int d, int min_len, int is_capital)
{
	unsigned long *x_arr = decimal_to_basex(d, 16);
	int i;

	for (i = min_len - x_arr[0]; i > 0; i--)
	{
		putchar_buf('0', buffer, buffer_len, bwritten);
	}

	for (i = 1 + x_arr[0] - 1; i >= 1; i--)
	{
		if (x_arr[i] >= 10)
		{
			putchar_buf((is_capital ? 'A' : 'a') + x_arr[i] - 10, buffer, buffer_len, bwritten);
		}
		else
		{
			putchar_buf('0' + x_arr[i], buffer, buffer_len, bwritten);
		}
	}
}

/**
 * print_number - prints an integer
 * @n: integer to print
 * @b_written: pointer to variable holding recursively printed bytes
 * @is_signed: whether int is signed
 */
void print_number(int n, int *b_written, int is_signed)
{
	unsigned int x;

	if (is_signed && n < 0)
	{
		_putchar('-');
		(*b_written)++;
		n *= -1;
	}

	x = n;

	if (x / 10)
		print_number(x / 10, b_written, 0);

	_putchar(x % 10 + '0');
	(*b_written)++;
}


