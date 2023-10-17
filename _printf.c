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
	tag->base = 10;
	tag->is_capital = 0;
}

/**
 * process_tag_on - processes the next format char, while a tag is started
 * @c: char to process
 * @tag: pointer to tag information holding struct
 * @ap: argument pointer to _printf's variadic arguments
 *
 * Return: number of characters printed
 */
int process_tag_on(char c, tag_t *tag, va_list ap, char *buffer, int *buffer_len, int *bwritten)
{
	switch (c)
	{
		case '%':
			return (process_percent(tag, buffer, buffer_len, bwritten));
			break;
		case 'c':
		case 'C':
			return (process_c(tag, ap, buffer, buffer_len, bwritten));
			break;
		case 's':
			return (process_s(tag, ap, buffer, buffer_len, bwritten));
			break;
		case 'i':
		case 'd':
			tag->is_signed = 1;
			tag->base = 10;
			return (process_int(tag, ap, buffer, buffer_len, bwritten));
			break;
		case 'o':
			tag->is_signed = 0;
			tag->base = 8;
			return (process_int(tag, ap, buffer, buffer_len, bwritten));
			break;
		case 'x':
			tag->is_capital = 0;
			tag->is_signed = 0;
			tag->base = 16;
			return (process_int(tag, ap, buffer, buffer_len, bwritten));
			break;
		case 'X':
			tag->is_capital = 1;
			tag->is_signed = 0;
			tag->base = 16;
			return (process_int(tag, ap, buffer, buffer_len, bwritten));
			break;
		case 'u':
			tag->is_signed = 0;
			tag->base = 10;
			return (process_int(tag, ap, buffer, buffer_len, bwritten));
			break;
		case 'b':
			return (process_b(tag, ap, buffer, buffer_len, bwritten));
			break;
		case ' ':
			reset_tag(tag);
			return (-1);
			break;
		default:
			putchar_buf('%', buffer, buffer_len, bwritten);
			putchar_buf(c, buffer, buffer_len, bwritten);
			va_arg(ap, int);
			reset_tag(tag);
			return (0);
			break;
	}

	return (0);
}

/**
 * process_tag_off - processes a char, while a tag is not started
 * @c: char to process
 * @tag: pointer to tag information holding struct
 *
 * Return: -1 on error, 0 otherwise
 */
int process_tag_off(char c, tag_t *tag, char *buffer, int *buffer_len, int *bwritten)
{
	switch (c)
	{
		case '%':
			{
				tag->on = 1;
				tag->spec = '\0';
				tag->is_signed = 1;
				return (0);
				break;
			}

		default:
			{
				putchar_buf(c, buffer, buffer_len, bwritten);
				reset_tag(tag);
				return (0);
				break;
			}
	}

	return (0);
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
	int i;
	va_list ap;
	char buffer[1024];
	int buffer_len = 0;
	int bwritten = 0;

	tag_t tag = {
		0,
		'\0',
		1,
		10,
		0
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
		{
			if (process_tag_on(format[i], &tag, ap, buffer, &buffer_len, &bwritten) == -1)
			{
				va_end(ap);
				return (-1);
			}
		}
		else
		{
			if (process_tag_off(format[i], &tag, buffer, &buffer_len, &bwritten) == -1)
			{
				va_end(ap);
				return (-1);
			}
		}
	}

	va_end(ap);

	if (tag.on)
		return (-1);

	bwritten += (writebuffer(buffer, buffer_len));
	return (bwritten);
}
