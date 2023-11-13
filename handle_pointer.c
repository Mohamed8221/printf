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
void *ptr = va_arg(args, void *);
unsigned long ptr_val = (unsigned long)ptr;

write(1, "0x", 2);
print_hex(ptr_val, 0);
(*count) += 2;
}
