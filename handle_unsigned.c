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
char str[10];
int i = 0;
if (n / 10)
print_unsigned_number(n / 10);
str[i++] = (n % 10) + '0';
str[i] = '\0';
write(1, str, i);
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
