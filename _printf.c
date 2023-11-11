#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
* print_number - Prints an integer.
* @n: The integer to be printed.
*/
void print_number(int n)
{
char c;
if (n < 0)
{
write(1, "-", 1);
n = -n;
}
if (n / 10)
print_number(n / 10);
c = n % 10 + '0';
write(1, &c, 1);
}

/**
* print_binary - Prints the binary representation of a number.
* @n: The number to be printed in binary.
*/
void print_binary(unsigned int n)
{
char c;
if (n / 2)
print_binary(n / 2);
c = n % 2 + '0';
write(1, &c, 1);
}

/**
* _printf - Produces output according to a format.
* @format: The format string that specifies how subsequent arguments are converted for output.
*
* Return: The number of characters printed.
*/
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
int i;
int j;
int n;
int temp;
char c;
char *s;

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
{
c = va_arg(args, int);
write(1, &c, 1);
count++;
break;
}
case 's':
{
s = va_arg(args, char *);
for (j = 0; s[j]; j++, count++)
write(1, &s[j], 1);
break;
}
case '%':
write(1, &format[i], 1);
count++;
break;
case 'd':
case 'i':
{
n = va_arg(args, int);
if (n < 0)
count++;
temp = n;
do
{
count++;
temp /= 10;
} while (temp);
print_number(n);
break;
}
case 'b':
{
unsigned int n = va_arg(args, unsigned int);
temp = n;
do
{
count++;
temp /= 2;
} while (temp);
print_binary(n);
break;
}
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
