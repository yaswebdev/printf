#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>

int _putchar(char c);

int _printf(const char *format, ...);

/**
 * struct Tag - Information about the format tag
 * @on: whether or not currently processing a format tag
 * @spec: format tag's specifier
 */
struct Tag
{
	unsigned int on;
	char spec;
};

typedef struct Tag tag_t;

void print_char_plain(char c, unsigned int *count);
void print_char(va_list ap, unsigned int *count);
void print_str(va_list ap, unsigned int *count);

#endif /* MAIN_H */
