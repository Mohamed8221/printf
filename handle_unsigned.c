#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/**
* print_number - prints an unsigned int
* @n: number to print
*
* Description: This function prints an unsigned int.
*/
void print_number(int n)
{
if (n / 10)
print_number(n / 10);
putchar((n % 10) + '0');
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

print_number(n);
}
