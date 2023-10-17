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
int *decimal_to_basex(unsigned int num, int base)
{
	static int bin[33];
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


