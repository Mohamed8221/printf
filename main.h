#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
void print_number(int n);
void print_binary(unsigned int n);
void handle_char(va_list args, int *count);
void handle_string(va_list args, int *count);
void handle_percent(int *count);
void handle_int(va_list args, int *count);
void handle_binary(va_list args, int *count);

#endif /* MAIN_H */
