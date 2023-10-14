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
			tag->on = 0;
			tag->spec = '\0';
			break;
		}

		case 's':
		{
			tag->spec = 's';
			count = print_str(ap, count);
			tag->on = 0;
			tag->spec = '\0';
			break;
		}

		case '%':
		{
			tag->spec = 'c';
			count = print_char_plain('%', count);
			tag->on = 0;
			tag->spec = '\0';
			break;
		}

		default:
		{
			if (DEBUG)
			{
				printf("[line %d]: Unhandled ", __LINE__);
				printf("(tag.on=1, fmt[i]=%c(%d))\n", c, c);
			}

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
			if (DEBUG)
				printf("%%: \n");

			tag->on = 1;
			tag->spec = '\0';
			break;
		}

		default:
		{
			if (DEBUG)
			{
				printf("default: ");
				fflush(stdout);
			}

			count = _putchar(c);
		
			if  (DEBUG)
				printf(" [count: %d]\n", *count);
			
			tag->spec = '\0';

			break;
		}
	}

	return (count);
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
		exit(1);
	}

	i = 0;
	while (format[i] != '\0')
	{
		if (DEBUG)
		{
			printf("Processing: %c...\n\t", format[i]);
		}

		if (tag.on)
		{
			i_count = process_tag_on(format[i], &tag, ap, &count);
		}
		else
		{
			i_count = process_tag_off(format[i], &tag, &count);
		}

		if (i_count == -1)
			return (-1);
		else
			count += i_count;

		i++;
	}

	return (count);
}
