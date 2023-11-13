#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/**
* print_unsigned_number - prints an unsigned int
* @n: number to print
*
* Description: This function prints an unsigned int.
*/

void print_unsigned_number(unsigned int n)
{
char c;
if (n / 10)
print_unsigned_number(n / 10);
c = n % 10 + '0';
write(1, &c, 1);
}

/**
* handle_unsigned_ - handle unsigned integers
* @args: list of arguments
* @count: pointer to count of digits
*
* Description: This function handles unsigned integers.
* It increments the count for each digit in the number.
*/
void handle_unsigned_(va_list args, int *count)
{
unsigned int n = va_arg(args, unsigned int);
unsigned int temp = n;

do {
(*count)++;
temp /= 10;
} while (temp);

print_unsigned_number(n);
}

/**
* handle_long_unsigned_ - Handles the 'u' specifier for long unsigned int
* @args: The va_list of arguments
* @count: Pointer to count of characters
*
* Description: This function handles the 'u' format
* specifier for long unsigned int.
*/

void handle_long_unsigned_(va_list args, int *count)
{
unsigned long int n = va_arg(args, unsigned long int);
print_unsigned_number(n);
*count += count_digits(n);
}

/**
* handle_short_unsigned_ - Handles the 'u' specifier for short unsigned int
* @args: The va_list of arguments
* @count: Pointer to count of characters
*
* Description: This function handles the 'u' format
* specifier for short unsigned int.
*/

void handle_short_unsigned_(va_list args, int *count)
{
unsigned int n = (unsigned short int)va_arg(args, unsigned int);
print_unsigned_number(n);
*count += count_digits(n);
}
