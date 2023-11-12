#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
 * struct print - struct for conversion specifiers
 * @c: specifier
 * @f: function for specifier
 */
typedef struct print
{
    char *c;
    void (*f)(va_list, int *);
} print_t;

int _printf(const char *format, ...);
void print_number(int n);
void print_unsigned_number(unsigned int n);
void print_binary(unsigned int n);
void handle_char(va_list args, int *count);
void handle_string(va_list args, int *count);
void handle_percent(int *count);
void handle_int(va_list args, int *count);
void handle_binary(va_list args, int *count);
void handle_unsigned_(va_list args, int *count);
void handle_octal(va_list args, int *count);
void handle_hex(va_list args, int *count, int uppercase);
void handle_pointer(va_list args, int *count);
void handle_format(const char *format, int i, va_list args, int *count);
void print_hex(unsigned long n, int uppercase);
void print_octal(unsigned int n);

#endif /* MAIN_H */
