#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
* _printf - Produces output according to a format.
* @format: The format string that specifies how subsequent arguments
* are converted for output.
* Return: The number of characters printed.
*/
int _printf(const char *format, ...)
{va_list args;
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
switch (format[i])
{
case 'c':
handle_char(args, &count);
break;
case 's':
handle_string(args, &count);
break;
case '%':
handle_percent(&count);
break;
case 'd':
case 'i':
handle_int(args, &count);
break;
case 'b':
handle_binary(args, &count);
break;
default:
write(1, &format[i - 1], 2);
count += 2;
break;
}
}
}
va_end(args);
return (count);
}
