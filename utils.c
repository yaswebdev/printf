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


	if (i != 32)
		bin[i] = -1;

	bin[0] = i - 1;

	return (bin);
}


/**
 * print_number - prints an integer
 * @n: integer to print
 * @b_written: pointer to variable holding recursively printed bytes
 */
void print_number(int n, int *b_written)
{
	unsigned int x;

	if (n < 0)
	{
		_putchar('-');
		(*b_written)++;
		n *= -1;
	}

	x = n;

	if (x / 10)
		print_number(x / 10, b_written);

	_putchar(x % 10 + '0');
	(*b_written)++;
}


