#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
/**
* handle_int - Handles the 'd' and 'i' specifiers.
* @args: The va_list of arguments.
* @count: The count of printed characters.
* @plus_flag: add flag.
* @space_flag: for flag.
*/
void handle_int(va_list args, int *count)
{
int n = va_arg(args, int);
print_number(n);
(*count)++;
}

/**
* handle_long_int - Handles the 'd' and 'i' specifiers for long int
* @args: The va_list of arguments
* @count: Pointer to count of characters
* @plus_flag: plus
* @space_flag: space
*
* Description: This function handles the 'd' and 'i'
* format specifiers for long int.
*/
void handle_long_int(va_list args, int *count,
int plus_flag, int space_flag)
{
long int n = va_arg(args, long int);
if (plus_flag && n >= 0)
{
print_octal('+');
(*count)++;
}
else if (space_flag && n >= 0)
{
print_octal(' ');
(*count)++;
}
print_number(n);
*count += count_digits(n);
}

/**
* handle_short_int - Handles the 'd' and 'i' specifiers for short int
* @args: The va_list of arguments
* @count: Pointer to count of characters
* @plus_flag: plus
* @space_flag: space
*
* Description: This function handles the 'd' and 'i'
* format specifiers for short int.
*/
void handle_short_int(va_list args, int *count,
int plus_flag, int space_flag)
{
int n = (short int)va_arg(args, int);
if (plus_flag && n >= 0)
{
print_octal('+');
(*count)++;
}
else if (space_flag && n >= 0)
{
print_octal(' ');
(*count)++;
}
print_number(n);
*count += count_digits(n);
}
