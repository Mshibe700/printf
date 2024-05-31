#include "main.h"

/**
 * print_width - Calculates the width for printing
 *
 * @format: Formatted string in which to print the arguments.
 *
 * @l: Arguments list to be printed.
 *
 * @arg: arguments list
 *
 * Return: width.
 */
int print_width(const char *format, int *l, va_list arg)
{
	int value_l;
	int width = 0;

	for (value_l = *l + 1; format[value_l] != '\0'; value_l++)
	{
		if (digit_verify(format[value_l]))
		{
			width *= 10;
			width += format[value_l] - '0';
		}
		else if (format[value_l] == '*')
		{
			value_l++;
			width = va_arg(arg, int);
			break;
		}
		else
			break;
	}

	*l = value_l - 1;

	return (width);
}
