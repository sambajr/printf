#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 *  * _printf - Custom printf function
 *   * @format: Format string containing directives
 *    *
 *     * Return: Number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	char c;
	int count;
	char *str;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
				{
					c = va_arg(args, int);
					_putchar(c);
					count++;
					break;
				}
				case 's':
				{
					str = va_arg(args, char *);
					while (*str != '\0')
					{
						_putchar(*str);
						str++;
						count++;
					}
					break;
				}
				case '%':
				_putchar('%');
				count++;
				break;
				default:
				break;
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}								
