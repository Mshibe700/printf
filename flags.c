#include "main.h"

/**
 * flags_p - Active flags to calculate
 *
 * @format: Prints the arguments of the Formatted string
 * @i: parameter.
 * Return: The active Flags
 */
int flags_p(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, val_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (val_i = *i + 1; format[val_i] != '\0'; val_i++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[val_i] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = val_i - 1;

	return (flags);
}
