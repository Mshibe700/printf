#include "main.h"
/**
 * handle_print - Prints an format specifier argument based on its type
 *
 * @fmt: Prints the argument of the Formatted string
 * @list: Prints the List of arguments
 * @ind: The index
 * @buffer: Handle the print of the Buffer array.
 * @flags: active flags to calculated
 * @width: get width option.
 * @precision: Precision format specification
 * @size: Size format specifier
 * Return: 1 or 2;
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', unsig_p}, {'o', octal_p}, {'x', hexadec_p},
		{'X', print_hexa_upper}, {'p', var_point}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', rotstr13_p}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &fmt[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
