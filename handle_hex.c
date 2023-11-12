#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
/**
* print_hex - prints an unsigned int in hexadecimal
* @n: number to print
* @uppercase: flag for uppercase letters
*
* Description: This function prints an unsigned int in hexadecimal.
*/
void print_hex(unsigned long n, int uppercase)
{
char str[10];
int i = 0;
char *hex = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

if (n / 16)
print_hex(n / 16, uppercase);

str[i++] = hex[n % 16];
str[i] = '\0';

write(1, str, i);
}

/**
* handle_hex - handle hexadecimal numbers
* @args: list of arguments
* @count: pointer to count of digits
* @uppercase: flag for uppercase letters
*
* Description: This function handles hexadecimal numbers.
* It increments the count for each digit in the number.
*/
void handle_hex(va_list args, int *count, int uppercase)
{
unsigned int n = va_arg(args, unsigned int);
unsigned int temp = n;

do {
(*count)++;
temp /= 16;
} while (temp);

print_hex(n, uppercase);
}

/**
* handle_long_hex - Handles the 'x' and 'X' specifiers for long unsigned int
* @args: The va_list of arguments
* @count: Pointer to count of characters
* @uppercase: Flag to determine if the hex digits should be uppercase
*
* Description: This function handles the 'x' and 'X'
* format specifiers for long unsigned int.
*/
void handle_long_hex(va_list args, int *count, int uppercase)
{
unsigned long int n = va_arg(args, unsigned long int);
print_hex(n, uppercase);
*count += count_digits(n);
}

/**
* handle_short_hex - Handles the 'x' and 'X' specifiers for short unsigned int
* @args: The va_list of arguments
* @count: Pointer to count of characters
* @uppercase: Flag to determine if the hex digits should be uppercase
*
* Description: This function handles the 'x' and 'X'
* format specifiers for short unsigned int.
*/
void handle_short_hex(va_list args, int *count, int uppercase)
{
unsigned int n = (unsigned short int)va_arg(args, unsigned int);
print_hex(n, uppercase);
*count += count_digits(n);
}
