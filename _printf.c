#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
* handle_format - handle format specifiers
* @format: format string
* @i: current index in format string
* @args: list of arguments
* @count: pointer to count of characters
*
* Description: This function handles format specifiers.
*/
void handle_format(const char *format, int i, va_list args, int *count)
{
int plus_flag = 0;
int space_flag = 0;
if (format[i] == '+')
{
plus_flag = 1;
i++;
}
else if (format[i] == ' ')
{
space_flag = 1;
i++;
}

switch (format[i])
{
case 'c':
handle_char(args, count);
break;
case 's':
handle_string(args, count);
break;
case '%':
handle_percent(count);
break;
case 'd':
case 'i':
handle_int(args, count, plus_flag, space_flag);
break;
case 'b':
handle_binary(args, count);
break;
case 'u':
handle_unsigned_(args, count);
break;
case 'o':
handle_octal(args, count);
break;
case 'x':
handle_hex(args, count, 0);
break;
case 'X':
handle_hex(args, count, 1);
break;
case 'p':
handle_pointer(args, count);
break;
default:
write(1, &format[i - 1], 2);
*count += 2;
break;
}
}

/**
* _printf - formatted output conversion and print
* @format: character string composed of zero or more directives
*
* Description: This function writes output to stdout,
* the standard output stream.
* It returns the number of characters written,
* or negative value if an error occurs.
*
* Return: the number of characters written
*/
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
int i;

va_start(args, format);

for (i = 0; format[i]; i++)
{
if (format[i] != '%')
{
write(1, &format[i], 1);
count++;
}
else
{
i++;
handle_format(format, i, args, &count);
}
}

va_end(args);
return (count);
}
