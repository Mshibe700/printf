#include "main.h"

/**
 * size_p - Calculates the size to cast the argument
 *
 * @format: Prints the arguments of the Formatted string
 * @i: Prints the arguments list
 *
 * Return: Precision specification.
 */
int size_p(const char *format, int *i)
{
	int val_i = *i + 1;
	int size = 0;

	if (format[val_i] == 'l')
		size = S_LONG;
	else if (format[val_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = val_i - 1;
	else
		*i = val_i;

	return (size);
}
