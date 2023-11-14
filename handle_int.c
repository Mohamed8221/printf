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
void handle_int(va_list args, int *count, int plus_flag, int space_flag)
{
int n = va_arg(args, int);
int temp;
if (n < 0)
{
(*count)++;
}
else if (n >= 0 && plus_flag)
{
write(1, "+", 1);
(*count)++;
}
else if (n >= 0 && space_flag)
{
write(1, " ", 1);
(*count)++;
}

temp = n;
do {
(*count)++;
temp /= 10;
} while (temp);

print_number(n);
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

/**
* print_int - Prints an integer
* @args: The va_list of arguments
*
* Description: This function prints an integer to the standard output.
*/
void print_int(va_list args)
{
int n = va_arg(args, int);
char buffer[1024];
int i = 1023;
int negative = n < 0;

if (negative)
n = -n;

do {
buffer[i--] = n % 10 + '0';
n /= 10;
} while (n > 0);

if (negative)
buffer[i--] = '-';

write(1, buffer + i + 1, 1023 - i);
}

/**
* print_pointer - Prints a pointer address
* @args: The va_list of arguments
*
* Description: This function prints a pointer address to the standard output.
*/
void print_pointer(va_list args)
{
void *ptr = va_arg(args, void *);
char buffer[1024];
unsigned long n = (unsigned long)ptr;
int i = 1023;

do {
int digit = n % 16;
buffer[i--] = digit < 10 ? digit + '0' : digit - 10 + 'a';
n /= 16;
} while (n > 0);

buffer[i--] = 'x';
buffer[i--] = '0';

write(1, buffer + i + 1, 1023 - i);
}
