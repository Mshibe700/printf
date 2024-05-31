#include "main.h"

/**
 * exact_p - Calculates the precision for printing
 *
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int exact_p(const char *format, int *i, va_list list)
{
	int val_i = *i + 1;
	int precision = -1;

	if (format[val_i] != '.')
		return (precision);

	precision = 0;

	for (val_i += 1; format[val_i] != '\0'; val_i++)
	{
		if (digit_verify(format[val_i]))
		{
			precision *= 10;
			precision += format[val_i] - '0';
		}
		else if (format[val_i] == '*')
		{
			val_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = val_i - 1;

	return (precision);
}
