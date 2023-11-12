#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/**
* handle_S - Handles the 'S' specifier.
* @args: The va_list of arguments.
* @count: The count of printed characters.
*/
void handle_S(va_list args, int *count)
{
char *s = va_arg(args, char *);
int j;
char hex[5];
if (s == NULL)
{
s = "(null)";
}
for (j = 0; s[j]; j++)
{
if ((s[j] > 0 && s[j] < 32) || s[j] >= 127)
{
write(1, "\\x", 2);
sprintf(hex, "%02X", s[j]);
write(1, hex, 2);
(*count) += 4;
}
else
{
write(1, &s[j], 1);
(*count)++;
}
}
}
