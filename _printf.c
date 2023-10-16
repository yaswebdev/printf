#include "main.h"
#include <stdio.h>

/**
 * process_tag_on - processes a char, while a tag is started
 * @c: char to process
 * @tag: pointer to tag information holding struct
 * @ap: argument pointer to _printf's variadic arguments
 *
 * Return: number of characters printed, or -1 on error
 */
int process_tag_on(char c, tag_t *tag, va_list ap)
{
	int count = 0;

	switch (c)
	{
		case 'c':
		{
			tag->spec = 'c';
			count = print_char(ap);
			tag->on = 0, tag->spec = '\0';
			break;
		}
		case 's':
		{
			tag->spec = 's';
			count = print_str(ap);
			tag->on = 0, tag->spec = '\0';
			break;
		}
		case '%':
		{
			tag->spec = 'c';
			count = print_char_plain('%');
			tag->on = 0, tag->spec = '\0';
			break;
		}
		default:
		{
			/*
			*if (DEBUG)
			*{
			*	printf("[line %d]: Unhandled ", __LINE__);
			*	printf("(tag.on=1, fmt[i]=%c(%d))\n", c, c);
			*}
			*/
			count = -1;
			break;
		}
	}

	return (count);
}

/**
 * process_tag_off - processes a char, while a tag is not started
 * @c: char to process
 * @tag: pointer to tag information holding struct
 *
 * Return: number of characters printed, or -1 on error
 */
int process_tag_off(char c, tag_t *tag)
{
	int count = 0;

	switch (c)
	{
		case '%':
		{
			/*
			*if (DEBUG)
			*	printf("%%: \n");
			*/

			tag->on = 1;
			tag->spec = '\0';
			break;
		}

		default:
		{
			/*
			*if (DEBUG)
			*{
			*	printf("default: ");
			*	fflush(stdout);
			*}
			*/

			count = _putchar(c);

			/*
			*if  (DEBUG)
			*	printf(" [count: %d]\n", count);
			*/

			tag->spec = '\0';

			break;
		}
	}

	return (count);
}

/**
 * pchar - prints a char or its ascii name if not printable
 * @c: char to print
 */
void pchar(char c)
{
	const char *ascii_names[] = {
		"NUL", "SOH", "STX", "ETX", "EOT", "ENQ", "ACK", "BEL",
		"BS",  "TAB", "LF",  "VT",  "FF",  "CR",  "SO",  "SI",
		"DLE", "DC1", "DC2", "DC3", "DC4", "NAK", "SYN", "ETB",
		"CAN", "EM",  "SUB", "ESC", "FS",  "GS",  "RS",  "US",
		"SPACE"
	};

	if (c >= 0 && c <= 32)
	{
		printf("%s", ascii_names[(int)c]);
	}
	else
	{
		printf("%c", c);
	}
}

/**
 * _printf - produces output according to a format
 * @format: string holding what to print and format tags for any provided
 * variadic arguments
 *
 * Return: printed chars count (excluding '\0') or -1 on error
 */
int _printf(const char *format, ...)
{
	int count = 0, i_count;
	va_list ap;
	int i;
	tag_t tag = {
		0,
		'\0'
	};

	va_start(ap, format);

	if (format == NULL)
	{
		printf("format == NULL");
		return (-1);
	}

	i = 0;
	while (format[i] != '\0')
	{
		if (DEBUG)
		{
			printf("\n(len: %d) Processing: ", count);
			pchar(format[i]);
			printf("(%d)...\n", format[i]);
		}

		if (tag.on)
			i_count = process_tag_on(format[i], &tag, ap);
		else
			i_count = process_tag_off(format[i], &tag);

		if (i_count == -1)
			return (-1);
		count += i_count;
		i++;
	}

	return (count);
}
