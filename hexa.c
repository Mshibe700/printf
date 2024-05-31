#include "main.h"

/*
 * unsig_p - Prints an unsigned number
 *
 * @types: List type of arguments
 * @buffer: Handles printing the Buffer array
 * @flags:  active flags to be calculated
 * @width: get width option
 * @precision: Precision format specification
 * @size: Size option specifier
 * Return: Number of characters printed.
 */
int unsig_p(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = unsig_convert(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (num_unsig(0, i, buffer, flags, width, precision, size));
}


/**
 * octal_p - Prints an unsigned number in octal notation
 * @types: List type of arguments
 * @buffer: Handle printing of Buffer array
 * @flags:  active flags to be calculated
 * @width: get width option
 * @precision: Precision format specification
 * @size: Size specification
 * Return: Number of characters printed
 */
int octal_p(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = unsig_convert(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (num_unsig(0, i, buffer, flags, width, precision, size));
}


/**
 * hexadec_p - Prints an unsigned number in hexadecimal notation
 * @types: List type of arguments
 * @buffer: Handle printing Buffer array
 * @flags:  active flags to be calculated
 * @width: get width option
 * @precision: Precision format specification
 * @size: Size specification
 * Return: Number of characters printed
 */
int hexadec_p(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: List type of arguments
 * @buffer: Handle printing Buffer array
 * @flags:  Active flags to be calculated
 * @width: get width option
 * @precision: Precision format specification
 * @size: Size specification
 * Return: Number of characters printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}


/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: Lit type of arguments
 * @map_to: Map leading to the number  and value of arrays
 * @buffer: Handle printing of Buffer array
 * @flags:  Active flags to be calculated
 * @flag_ch: Active flags to be calculated
 * @width: get width option
 * @precision: Precision format specification
 * @size: Size specification
 * @size: Size specification
 * Return: Number of characters printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = unsig_convert(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (num_unsig(0, i, buffer, flags, width, precision, size));
}
