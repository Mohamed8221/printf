#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
* handle_string - Handles the 's' specifier.
* @args: The va_list of arguments.
* @count: The count of printed characters.
*/
void handle_string(va_list args, int *count)
{
char *s = va_arg(args, char *);
if (s == NULL)
s = "(null)";
while (*s)
{
write(1, s++, 1);
(*count)++;
}
}
