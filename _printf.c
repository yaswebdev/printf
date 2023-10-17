#include "main.h"

/**
 * reset_tag - Resets the tag struct
 * @tag: pointer to tag struct
 */
void reset_tag(tag_t *tag)
{
	tag->on = 0;
	tag->spec = '\0';
	tag->is_signed = 1;
}

/**
 * process_tag_on - processes the next format char, while a tag is started
 * @c: char to process
 * @tag: pointer to tag information holding struct
 * @ap: argument pointer to _printf's variadic arguments
 *
 * Return: number of characters printed
 */
int process_tag_on(char c, tag_t *tag, va_list ap)
{
	int b_written;

	switch (c)
	{
		case '%':
			b_written = process_percent(tag);
			break;
		case 'c':
		case 'C':
			b_written = process_c(tag, ap);
			break;
		case 's':
			b_written = process_s(tag, ap);
			break;
		case 'i':
		case 'd':
			tag->is_signed = 1;
			b_written = process_int(tag, ap);
			break;
		case 'u':
			tag->is_signed = 0;
			b_written = process_int(tag, ap);
			break;
		case 'b':
			b_written = process_b(tag, ap);
			break;
		case ' ':
			b_written = -1;
			reset_tag(tag);
			break;
		default:
			_putchar('%');
			_putchar(c);
			b_written = 2;
			va_arg(ap, int);
			reset_tag(tag);
			break;
	}

	return (b_written);
}

/**
 * process_tag_off - processes a char, while a tag is not started
 * @c: char to process
 * @tag: pointer to tag information holding struct
 *
 * Return: number of characters printed
 */
int process_tag_off(char c, tag_t *tag)
{
	int b_written;

	switch (c)
	{
		case '%':
		{
			b_written = 0;
			tag->on = 1;
			tag->spec = '\0';
			tag->is_signed = 1;
			break;
		}

		default:
		{
			b_written = _putchar(c);
			reset_tag(tag);
			break;
		}
	}

	return (b_written);
}

/**
 * _printf - produces output according to a format
 * @format: string holding what to print and format tags for any provided
 * variadic arguments
 *
 * Return: printed chars count (excluding '\0')
 */
int _printf(const char *format, ...)
{
	int b_written = 0;
	int b_written_curr;
	int i;
	va_list ap;

	tag_t tag = {
		0,
		'\0',
		1
	};

	va_start(ap, format);

	if (format == NULL)
	{
		va_end(ap);
		return (-1);
	}

	for (i = 0; format[i] != '\0'; i++)
	{
		if (tag.on)
			b_written_curr = process_tag_on(format[i], &tag, ap);
		else
			b_written_curr = process_tag_off(format[i], &tag);

		if (b_written_curr == -1)
		{
			va_end(ap);
			return (-1);
		}
		b_written += b_written_curr;
	}

	if (tag.on)
		b_written = -1;


	va_end(ap);
	return (b_written);
}
