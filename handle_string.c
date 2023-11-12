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
int j;
if (s == NULL)
{
s = "(null)";
}
for (j = 0; s[j]; j++, (*count)++)
write(1, &s[j], 1);
}
