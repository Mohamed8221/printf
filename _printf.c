#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
* _printf - Custom printf function with limited functionality
* @format: Format string
*
* Return: Number of characters printed (excluding null byte)
*/
int _printf(const char *format, ...) {
va_list args;
int count = 0;
char *str;
va_start(args, format);
while (*format) {
if (*format == '%' && *(format + 1) != '\0') {
switch (*(format + 1)) {
case 'c':
count += write(1, &(char){va_arg(args, int)}, 1);
break;
case 's':
str = va_arg(args, char *);
while (*str) {
count += write(1, str++, 1);
}
break;
case '%':
count += write(1, "%", 1);
break;
default:
count += write(1, format, 1);
break;
}
format += 2; // Move to the next character after the specifier
} else {
count += write(1, format++, 1);
}
}
va_end(args);
}
return count;
