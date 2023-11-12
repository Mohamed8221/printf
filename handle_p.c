#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
* handle_p - Handles the 'p' specifier.
* @args: The va_list of arguments.
* @count: The count of printed characters.
*/
void handle_p(va_list args, int *count)
{
void *ptr = va_arg(args, void *);
unsigned long ptr_val = (unsigned long)ptr;

write(1, "0x", 2);
print_hex(ptr_val, 0);
(*count) += 2;
}
