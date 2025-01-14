#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);



int print_char(va_list data, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list data, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list data, char buffer[],
	int flags, int width, int precision, int size);


int print_int(va_list data, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list data, char buffer[],
	int flags, int width, int precision, int size);
int unsig_p(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int octal_p(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int hexadec_p(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);


int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);


int var_point(va_list types, char buffer[],
	int flags, int width, int precision, int size);


int flags_p(const char *format, int *i);
int print_width(const char *format, int *l, va_list arg);
int exact_p(const char *format, int *i, va_list list);
int size_p(const char *format, int *i);


int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);


int rotstr13_p(va_list types, char buffer[],
	int flags, int width, int precision, int size);


int char_handle(char c, char buffer[],
	int flags, int width, int precision, int size);
int digit_write(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int buff_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int num_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int num_unsig(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);


int to_print(char);
int hexa_append(char, char[], int);
int digit_verify(char);

long int num_convert(long int num, int size);
long int unsig_convert(unsigned long int num, int size);

#endif
