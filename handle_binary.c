#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
* handle_binary - Handles the 'b' specifier.
* @args: The va_list of arguments.
* @count: The count of printed characters.
*/
void handle_binary(va_list args, int *count)
{
unsigned int n = va_arg(args, unsigned int);
print_binary(n);
(*count)++;
}
