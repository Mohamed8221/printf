#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/**
* handle_pointer - handle pointers
* @args: list of arguments
* @count: pointer to count of digits
*
* Description: This function handles pointers.
* It increments the count for each digit in the number.
*/
void handle_pointer(va_list args, int *count)
{
void *p = va_arg(args, void *);
write(1, "0x", 2);
(*count) += 2;
print_hex((unsigned long)p, 0);
}
