#include "main.h"
#include <limits.h>
#include <stdio.h>

/**
 * main - Program Entry point
 * by Philasande
 *
 * Return: Always 0
 */
int main(void)
{
	int size;
	int size2;
	unsigned int val;
	void *addr;

	size = _printf("Project done by Philasande.\n");
	size2 = printf("Its all about how much you can adapt.\n");
	val = (unsigned int)INT_MAX + 1024;
	addr = (void *)0x7ffe637541f0;
	_printf("Length:[%d, %i]\n", size, size);
	printf("Length:[%d, %i]\n", size2, size2);
	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);
	_printf("Unsigned:[%u]\n", val);
	printf("Unsigned:[%u]\n", val);
	_printf("Unsigned octal:[%o]\n", val);
	printf("Unsigned octal:[%o]\n", val);
	_printf("Unsigned hexadecimal:[%x, %X]\n", val, val);
	printf("Unsigned hexadecimal:[%x, %X]\n", val, val);
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	_printf("Address:[%p]\n", addr);
	printf("Address:[%p]\n", addr);
	size = _printf("Percent:[%%]\n");
	size2 = printf("Percent:[%%]\n");
	_printf("Len:[%d]\n", size);
	printf("Len:[%d]\n", size2);
	return (0);
}
