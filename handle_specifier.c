#include <unistd.h>
#include "main.h"

/**
* handle_specifier_helper - Helper function to handle format specifiers
* @format_char: Current character in format string
* @args: List of arguments
* @count: Pointer to count of characters
* @plus_flag: Plus flag
* @space_flag: Space flag
* @long_flag: Long flag
* @short_flag: Short flag
*
* This function checks the current character in the format string and calls
* the corresponding function to handle the format specifier. It also passes
* any flags that have been set to the handling function.
*/
void handle_specifier_helper(char format_char, va_list args, int *count,
int plus_flag, int space_flag, int long_flag, int short_flag)
{
switch (format_char)
{
case 'c':
handle_char(args, count);
break;
case 's':
handle_string(args, count);
break;
case '%':
handle_percent(count);
break;
case 'r':
write(1, "%", 1);
write(1, "r", 1);
(*count) += 2;
break;
case 'd':
case 'i':
handle_int_specifier(args, count, plus_flag,
space_flag, long_flag, short_flag);
break;
case 'b':
handle_binary(args, count);
break;
case 'o': case 'u':
case 'X': case 'x':
handle_unsigned_specifier(format_char, args, count,
long_flag, short_flag);
break;
case 'p':
handle_pointer(args, count);
break;
case 'S':
handle_S(args, count);
break;
default:
write(1, &format_char, 1);
*count += 1;
break;
}
}

/**
* handle_int_specifier - Helper function to handle 'd' and 'i' specifiers
* @args: List of arguments
* @count: Pointer to count of characters
* @plus_flag: Plus flag
* @space_flag: Space flag
* @long_flag: Long flag
* @short_flag: Short flag
*
* This function checks the flags and calls the corresponding function to
* handle the 'd' or 'i' format specifier.
*/
void handle_int_specifier(va_list args, int *count,
int plus_flag, int space_flag, int long_flag, int short_flag)
{
if (long_flag)
handle_long_int(args, count, plus_flag, space_flag);
else if (short_flag)
handle_short_int(args, count, plus_flag, space_flag);
else
handle_int(args, count, plus_flag, space_flag);
}

/**
* handle_unsigned_specifier - Helper function to handle
* 'u', 'o', 'x', 'X' specifiers
* @format_char: Current character in format string
* @args: List of arguments
* @count: Pointer to count of characters
* @long_flag: Long flag
* @short_flag: Short flag
*
* This function checks the current character in the format string and calls
* the corresponding function to handle the
* 'u', 'o', 'x', or 'X' format specifier.
*/

void handle_unsigned_specifier(char format_char, va_list args,
int *count, int long_flag, int short_flag)
{
switch (format_char)
{
case 'u':
if (long_flag)
handle_long_unsigned_(args, count);
else if (short_flag)
handle_short_unsigned_(args, count);
else
handle_unsigned_(args, count);
break;
case 'o':
if (long_flag)
handle_long_octal(args, count);
else if (short_flag)
handle_short_octal(args, count);
else
handle_octal(args, count);
break;
case 'x':
case 'X':
if (long_flag)
handle_long_hex(args, count, format_char == 'X');
else if (short_flag)
handle_short_hex(args, count, format_char == 'X');
else
handle_hex(args, count, format_char == 'X');
break;
}
}

/**
* handle_specifier - handle format specifiers
* @format: format string
* @i: current index in format string
* @args: list of arguments
* @count: pointer to count of characters
* @plus_flag: plus flag
* @space_flag: space flag
* @long_flag: long flag
* @short_flag: short flag
*
* Description: This function handles format specifiers.
*/
void handle_specifier(const char *format, int i, va_list args,
int *count, int plus_flag, int space_flag,
int long_flag, int short_flag)
{
handle_specifier_helper(format[i], args, count, plus_flag,
space_flag, long_flag, short_flag);
}
