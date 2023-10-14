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

int print_char_plain(char c);
int print_char(va_list ap);
int print_str(va_list ap);
int print_int(va_list ap);
int print_dec(va_list ap);


#ifndef DEBUG
#define DEBUG 0
#endif /* DEBUG */


#endif /* MAIN_H */
