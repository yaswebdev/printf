#ifndef MAIN_H

#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/**
 * struct Tag - Information about the format tag
 * @on: whether or not currently processing a format tag
 * @spec: format tag's specifier
 * @is_signed: whether int is signed, if spec is one of ints
 */
struct Tag
{
	int on;
	char spec;
	int is_signed;
	int base;
	int is_capital;
	int is_print_np;
};
typedef struct Tag tag_t;

int _putchar(char c);
void putchar_buf(char c, char *buffer, int *buffer_len, int *bwritten);
int writebuffer(char *buffer, int buffer_len);
int _printf(const char *format, ...);
void start_capture(void);
char *end_capture(void);


/* UTILS */
void p_as_hex(char *buffer, int *buffer_len, int *bwritten, unsigned int d, int min_len, int is_capital);

void reset_tag(tag_t *tag);
void print_number(int n, int *b_written, int is_signed);
int *decimal_to_binary(unsigned int num);
unsigned long *decimal_to_basex(unsigned long num, int base);

int process_percent(tag_t *tag, char *buffer, int *buffer_len, int *bwritten);
int process_c(tag_t *tag, va_list ap, char *buffer, int *buffer_len, int *bwritten);
int process_s(tag_t *tag, va_list ap, char *buffer, int *buffer_len, int *bwritten);
int process_int(tag_t *tag, va_list ap, char *buffer, int *buffer_len, int *bwritten);
int process_b(tag_t *tag, va_list ap, char *buffer, int *buffer_len, int *bwritten);
int process_p(tag_t *tag, va_list ap, char *buffer, int *buffer_len, int *bwritten);

#define RED_TEXT   "\x1B[31m"
#define RESET_TEXT "\x1B[0m"

#endif /* MAIN_H */
