#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/**
* print_octal - prints an unsigned int in octal
* @n: number to print
*
* Description: This function prints an unsigned int in octal.
*/
void print_octal(unsigned int n)
{
if (n / 8)
print_octal(n / 8);
putchar((n % 8) + '0');
}

/**
* handle_octal - handle octal numbers
* @args: list of arguments
* @count: pointer to count of digits
*
* Description: This function handles octal numbers.
* It increments the count for each digit in the number.
*/
void handle_octal(va_list args, int *count)
{
unsigned int n = va_arg(args, unsigned int);
int temp = n;

do {
(*count)++;
temp /= 8;
} while (temp);

print_octal(n);
}
