#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
* print_char - Prints a character
* @args: List of arguments
* @count: Pointer to the count of characters
*/
void print_char(va_list args, int *count)
{
char c = va_arg(args, int);

write(1, &c, 1);
(*count)++;
}

/**
* print_string - Prints a string
* @args: List of arguments
* @count: Pointer to the count of characters
*/
void print_string(va_list args, int *count)
{
char *s = va_arg(args, char *);

for (int j = 0; s[j] != '\0'; j++)
{
write(1, &s[j], 1);
(*count)++;
}
}

/**
* print_percent - Prints a percent symbol
* @count: Pointer to the count of characters
*/
void print_percent(int *count)
{
write(1, "%", 1);
(*count)++;
}

/**
* print_int - Prints an integer
* @args: List of arguments
* @count: Pointer to the count of characters
*/
void print_int(va_list args, int *count)
{
int num = va_arg(args, int);
char str[12]; /* Buffer big enough for an int. */

sprintf(str, "%d", num); /* Convert the int to a string. */

for (int j = 0; str[j] != '\0'; j++)
{
write(1, &str[j], 1);
(*count)++;
}
}

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
print_char(args, &count);
break;
case 's':
print_string(args, &count);
break;
case '%':
print_percent(&count);
break;
case 'd':
case 'i':
print_int(args, &count);
break;
default:
break;
}
}
}
va_end(args);
return (count);
}
