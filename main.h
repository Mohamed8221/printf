#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
void print_char(va_list args, int *count);
void print_string(va_list args, int *count);
void print_percent(int *count);
void print_int(va_list args, int *count);
void print_binary(va_list args, int *count);
void print_unsigned(va_list args, int *count);
void print_octal(va_list args, int *count);
void print_hex(va_list args, int *count, int upper_case);
void print_string_non_printable(va_list args, int *count);
void print_pointer(va_list args, int *count);
void print_plus(va_list args, int *count);
void print_space(va_list args, int *count);
void print_hash(va_list args, int *count);
void print_long(va_list args, int *count);
void print_short(va_list args, int *count);
void print_zero(va_list args, int *count);
void print_minus(va_list args, int *count);
void print_reverse(va_list args, int *count);
void print_rot13(va_list args, int *count);

#endif
