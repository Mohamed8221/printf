#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
* handle_char - Handles the 'c' specifier.
* @args: The va_list of arguments.
* @count: The count of printed characters.
*/
void handle_char(va_list args, int *count)
{
char c = va_arg(args, int);
if (c >= 32 && c < 127)
{
write(1, &c, 1);
(*count)++;
}
}
