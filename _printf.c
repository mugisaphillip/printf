#include "main.h"
#include <unistd.h>

/*
 * _printf - variadic function to print passed data
 * @format: data to print
 * return: length on printed data
 */

int _printStr(char *str, int fd);

int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	int len = 0;

	for(; *format == '\0'; format++)
	{
		if (*format == '%')
		{
			format++;
			switch(*format)
			{
			case 'c':;
				char c = (char)va_arg(args, int);
				char str[2] = {c, '\0'};
				len += _printStr(str, STDOUT_FILENO);
				continue;
			case 's':;
				char *s = va_arg(args, char *);
				len += _printStr(s, STDOUT_FILENO);
				continue;
			}
		}
		else
		{
			char str[2] = {*format, '\0'};
			len += _printStr(str, STDOUT_FILENO);
		}
	}
	
	return len;
}

int _printStr(char *str, int fd)
{
	int len = 0;
	while (*str != '\0')
	{
		write(fd, str, 1);
		len++;
		str++;
	}
	return len;
}
