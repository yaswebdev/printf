#ifndef MAIN_H

#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int _putchar(char c);
int _printf(const char *format, ...);
void start_capture(void);
char *end_capture(void);

int ptag_char(va_list ap);
int ptag_str(va_list ap);

/**
 * struct Tag - Information about the format tag
 * @on: whether or not currently processing a format tag
 * @spec: format tag's specifier
 */
struct Tag
{
	int on;
	char spec;
};

typedef struct Tag tag_t;

#define RED_TEXT   "\x1B[31m"
#define RESET_TEXT "\x1B[0m"

#endif /* MAIN_H */
