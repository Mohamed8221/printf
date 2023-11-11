#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
* _printf - a function that produces output according to a format
* @format: character string (to be parsed)
* Return: the number of characters printed (excluding the null byte)
*/
int _printf(const char *format, ...)
{
va_list args;
int count = 0;

va_start(args, format);
for (int i = 0; format[i] != '\0'; i++)
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
{
char c = va_arg(args, int);

write(1, &c, 1);
count++;
break;
}
case 's':
{
char *s = va_arg(args, char *);

for (int j = 0; s[j] != '\0'; j++)
{
write(1, &s[j], 1);
count++;
}
break;
}
case '%':
{
write(1, &format[i], 1);
count++;
break;
}
case 'd':
case 'i':
{
int num = va_arg(args, int);
char str[12]; /* Buffer big enough for an int. */
sprintf(str, "%d", num); /* Convert the int to a string. */

for (int j = 0; str[j] != '\0'; j++)
{
write(1, &str[j], 1);
count++;
}
break;
}
default:
break;
}
}
}
va_end(args);
return (count);
}
