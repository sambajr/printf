#include <stdlib.h>
#include "main.h"
#include <stdio.h>
/**
 *  * _print_str - Print a string
 *   * @str: String to be printed
 *    *
 *     * Return: Number of characters printed
 */
int _print_str(char *str)
{
	int count;

	count = 0;
	while (*str != '\0')
	{
		count += _putchar(*str);
		str++;
	}
	return (count);
}
