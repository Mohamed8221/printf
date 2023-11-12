#include "main.h"
#include <unistd.h>

/**
* print_binary - Prints the binary representation of a number.
* @n: The number to be printed in binary.
*/
void print_binary(unsigned int n)
{
char c;
if (n / 2)
print_binary(n / 2);
c = n % 2 + '0';
write(1, &c, 1);
}
