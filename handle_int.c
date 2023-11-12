#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
* handle_int - Handles the 'd' and 'i' specifiers.
* @args: The va_list of arguments.
* @count: The count of printed characters.
*/
void handle_int(va_list args, int *count)
{
int n = va_arg(args, int);
int temp;
if (n < 0)
(*count)++;
temp = n;
do {
(*count)++;
temp /= 10;
} while (temp);
print_number(n);
}
