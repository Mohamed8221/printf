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
int long_flag = 0;
int short_flag = 0;

set_flags(format, &i, &plus_flag, &space_flag, &long_flag, &short_flag);
handle_specifier(format, i, args, count, plus_flag, space_flag,
long_flag, short_flag);
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
