#include "main.h"
#include <stdio.h>

/**
 * process_tag_on - processes a char, while a tag is started
 * @c: char to process
 * @tag: pointer to tag information holding struct
 * @ap: argument pointer to _printf's variadic arguments
 * @count: pointer to printed chars count
 */
void process_tag_on(char c, tag_t *tag, va_list ap, int *count)
{
	switch (c)
	{
		case 'c':
		{
			tag->spec = 'c';
			print_char(ap, count);
			tag->on = 0;
			break;
		}

		case 's':
		{
			tag->spec = 's';
			print_str(ap, count);
			tag->on = 0;
			break;
		}

		case '%':
		{
			tag->spec = 'c';
			print_char_plain('%', count);
			tag->on = 0;
			break;
		}

		default:
		{
			if (DEBUG)
			{
				printf("[line %d]: Unhandled ", __LINE__);
				printf("(tag.on=1, fmt[i]=%c(%d))\n", c, c);
			}
			exit(1);
			break;
		}
	}
}

/**
 * process_tag_off - processes a char, while a tag is not started
 * @c: char to process
 * @tag: pointer to tag information holding struct
 * @count: pointer to printed chars count
 */
void process_tag_off(char c, tag_t *tag, int *count)
{
	switch (c)
	{
		case '%':
		{
			if (DEBUG)
				printf("%%: \n");

			tag->on = 1;
			break;
		}

		default:
		{
			if (DEBUG)
			{
				printf("default: ");
				fflush(stdout);
			}

			_putchar(c);
			(*count)++;

			if  (DEBUG)
				printf(" [count: %d]\n", *count);

			break;
		}
	}
}

/**
 * _printf - produces output according to a format
 * @format: string holding what to print and format tags for any provided
 * variadic arguments
 *
 * Return: printed chars count, excluding '\0'
 */
int _printf(const char *format, ...)
{
	int count = 0;
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
			process_tag_on(format[i], &tag, ap, &count);
		}
		else
		{
			process_tag_off(format[i], &tag, &count);
		}

		i++;
	}

	return (count);
}
