#include "main.h"
#include <stdarg.h>
#include <unistd.h>

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
int temp = n;

do {
(*count)++;
temp /= 10;
} while (temp);

print_number(n);
}
