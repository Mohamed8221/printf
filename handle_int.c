#include "main.h"
#include <stdarg.h>
#include <unistd.h>

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
