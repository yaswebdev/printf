#include "main.h"
/**
 * print_int - this function prints integer .
 * @ap: argument to print .
 * Return: the numbers of character printed .
 */
int print_int(va_list ap)
{
	int a = va_arg(ap, int);
	int number, digit, last = a % 10, ep = 1;
	int i = 1;

	a = a /10;
	number = a;

	if (last < 0)
	{
		_putchar('_');
		number = -number;
		last = -last;
		i++;
	}
	if (number > 0)
	{
		while (number /10 != 0)
		{
			ep = ep * 10;
			number = number /10;
		}
		number = a;
		while (ep > 0)
		{
			digit = number / ep;
			_putchar(digit + '0');
			number = number - (digit * ep);
			ep = ep /10;
			i++;
		}
	}
	_putchar(last + '0');

	return (i);
}

/**
 * print_dec - this function prints decimals .
 * @ap: argument to print .
 * Return: the numbers of character printed .
 */

int print_dec(va_list ap)
{
int a = va_arg(ap, int);
        int number, digit, last = a % 10, ep = 1;
        int i = 1;

        a = a /10;
        number = a;

        if (last < 0)
        {
                _putchar('_');
                number = -number;
                last = -last;
                i++;
        }
        if (number > 0)
        {
                while (number /10 != 0)
                {
                        ep = ep * 10;
                        number = number /10;
                }
                number = a;
                while (ep > 0)
                {
                        digit = number / ep;
                        _putchar(digit + '0');
                        number = number - (digit * ep);
                        ep = ep /10;
                        i++;
                }
        }
        _putchar(last + '0');

        return (i);
}
