#include <stdarg.h>
#include <stdio.h>
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
	int i, count, num, len;
	char c;
	char *str;
	char nuffer[32];
	unsigned int bum;
	char buffer[20];

	va_start(args, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'd':
				case 'i':
					{
						num = va_arg(args, int);
						len = sprintf(buffer, "%d", num);
						count += write(1, buffer, len);
						break;
					}
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
				case 'b': {
						  bum = va_arg(args, unsigned int);
						  i = 0;
						  while (num > 0)
						  {
							  nuffer[i++] = (bum % 2) + '0';
							  bum /= 2;
						  }
						  if (i == 0)
						  {
							  nuffer[i++] = '0';
						  }
						  i--;
						  while (i >= 0)
						  {
							  count += write(1, &nuffer[i--], 1);
						  }
						  break;
					  }
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
