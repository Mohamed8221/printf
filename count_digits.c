/**
* count_digits - Counts the number of digits in a number
* @n: The number to count the digits of
*
* Return: The number of digits in n
*/
int count_digits(long int n)
{
int count = 0;

/* Handle 0 explicitly, otherwise it will not count a digit */
if (n == 0)
return (1);

/* Count digits for both positive and negative numbers */
n = (n < 0) ? -n : n;
while (n != 0)
{
n /= 10;
++count;
}

return (count);
}
