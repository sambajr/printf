#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 *  * _printf - Custom printf function
 *   * @format: Format string containing directives
 *    *
 *     * Return: Number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count;
	char c;
	char *str;

	va_start(args, format);
	count = 0;
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
						count += write(1, &c, 1);
						break;
					}
				case 's':
					{
						str = va_arg(args, char *);
						while (*str != '\0')
						{
							count += write(1, str, 1);
							str++;
						}
						break;
					}
				case '%':
					count += write(1, "%", 1);
					break;
				default:
					write(1, "%", 1);
					write(1, format, 1);
					count += 2;
					break;
			}
		}
		else
		{
			count += write(1, format, 1);
		}
			format++;
	}
	va_end(args);
	return (count);
}
