#include "main.h"

/**
* set_flags - set flags for format specifiers
* @format: format string
* @i: pointer to current index in format string
* @plus_flag: pointer to plus flag
* @space_flag: pointer to space flag
* @long_flag: pointer to long flag
* @short_flag: pointer to short flag
*
* Description: This function sets flags for format specifiers.
*/
void set_flags(const char *format, int *i, int *plus_flag,
int *space_flag, int *long_flag, int *short_flag)
{
if (format[*i] == '+')
{
*plus_flag = 1;
(*i)++;
}
else if (format[*i] == ' ')
{
*space_flag = 1;
(*i)++;
}
else if (format[*i] == 'l')
{
*long_flag = 1;
(*i)++;
}
else if (format[*i] == 'h')
{
*short_flag = 1;
(*i)++;
}
}
