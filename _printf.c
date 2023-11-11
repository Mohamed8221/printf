#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>
#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
* handle_percent_format - Handles the format after encountering '%'
* @format: The format string
* @i: Pointer to the current index in the format string
* @list: va_list
* @buffer: Array to store characters
*
* Return: Number of characters printed
*/
static int handle_percent_format(const char *format, int *i,
va_list list, char buffer[])
{
int flags, width, precision, size;
int printed;

flags = get_flags(format, i);
width = get_width(format, i, list);
precision = get_precision(format, i, list);
size = get_size(format, i);
++(*i);

printed = handle_print(format, i, list, buffer, flags, width, precision, size);
if (printed == -1)
return (-1);

return (printed);
}

/**
* _printf - Printf function
* @format: format.
* Return: Printed chars.
*/
int _printf(const char *format, ...)
{
int i, printed_chars = 0;
int buff_ind = 0;
va_list list;
char buffer[BUFF_SIZE];

if (format == NULL)
return (-1);

va_start(list, format);

for (i = 0; format && format[i] != '\0'; i++)
{
if (format[i] != '%')
{
buffer[buff_ind++] = format[i];
if (buff_ind == BUFF_SIZE)
print_buffer(buffer, &buff_ind);
printed_chars++;
}
else
{
print_buffer(buffer, &buff_ind);
printed_chars += handle_percent_format(format, &i, list, buffer);
}
}

print_buffer(buffer, &buff_ind);

va_end(list);

return (printed_chars);
}

/**
* print_buffer - Prints the contents of the buffer if it exists.
* @buffer: Array of chars
* @buff_ind: Index at which to add the next char, represents the length.
*/
void print_buffer(char buffer[], int *buff_ind)
{
if (*buff_ind > 0)
write(1, &buffer[0], *buff_ind);

*buff_ind = 0;
}
