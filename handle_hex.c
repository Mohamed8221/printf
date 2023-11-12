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