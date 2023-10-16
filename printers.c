#include "main.h"

/**
 * ptag_char - prints a char from the next variable function argument
 * @ap: variable argument pointer
 *
 * Return: number of bytes printed
 */
int ptag_char(va_list ap)
{
	int arg = va_arg(ap, int);


	/*
	* if (arg < 32 || arg > 126)
	*	return (0);
	*/


	/*printf("\narg: %d\n", arg);*/
	return (_putchar(arg));
}



/**
 * ptag_str - prints a string from the next variable function argument
 * @ap: variable argument pointer
 *
 * Return: number of bytes printed
 */
int ptag_str(va_list ap)
{
	char *arg = va_arg(ap, char *);
	int i;
	int count = 0;

	if (arg == NULL)
	{
		arg = "(null)";
	}

	/*printf("%p\n", arg);*/
	/*printf("arg[0]: %s\n", arg[0]);*/

	for (i = 0; arg[i] != '\0'; i++)
	{
		printf("str char: |");
		count += _putchar(arg[i]);
		printf("|\n");
	}

	return (count);
}
