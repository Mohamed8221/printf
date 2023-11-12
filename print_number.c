#include "main.h"
#include <unistd.h>

/**
* print_number - Prints an integer.
* @n: The integer to be printed.
*/
void print_number(int n)
{
char c;
if (n < 0)
{
write(1, "-", 1);
n = -n;
}
if (n / 10)
print_number(n / 10);
c = n % 10 + '0';
write(1, &c, 1);
}
