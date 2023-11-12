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
char str[10];
int i = 0;

if (n / 8)
print_octal(n / 8);

str[i++] = (n % 8) + '0';
str[i] = '\0';

write(1, str, i);
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
unsigned int temp = n;

do {
(*count)++;
temp /= 8;
} while (temp);

print_octal(n);
}