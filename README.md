# printf

A reimplementation of the C standard library's `printf`, written from scratch for the ALX Software Engineering program. Output goes through `write(2)` directly, with no use of the standard `printf` family for formatting.

Team project by **Muhammad Ussama** and **Mohamed Awad**.

## Usage

```c
#include "main.h"

int main(void)
{
    int len = _printf("Hello %s, you are %d years old\n", "Sara", 21);

    _printf("Printed %d characters\n", len);
    return (0);
}
```

Compile your program together with the library sources (every `.c` file here except `main.c`, which is the test program):

```bash
gcc -Wall -Wextra -std=gnu89 your_program.c $(ls *.c | grep -v '^main.c$') -o your_program
```

To build and run the bundled comparison test, which prints each case with `_printf` and then with the real `printf`:

```bash
gcc -Wall -Wextra -std=gnu89 -Wno-format *.c -o test_printf && ./test_printf
```

`_printf` returns the number of characters written.

## Supported conversions

| Specifier | Output |
|---|---|
| `%c` | Single character |
| `%s` | String (`(null)` for a NULL pointer) |
| `%%` | Literal percent sign |
| `%d`, `%i` | Signed decimal integer |
| `%u` | Unsigned decimal integer |
| `%o` | Unsigned octal |
| `%x`, `%X` | Unsigned hexadecimal, lower and upper case |
| `%p` | Pointer address |
| `%b` | Unsigned integer in binary (custom) |
| `%S` | String with non-printable characters shown as `\xHH` (custom) |

```c
_printf("%b\n", 98);              /* 1100010 */
_printf("%S\n", "Best\nSchool");  /* Best\x0ASchool */
```

## Known limitations

- The `+` and space flags and the `l` / `h` length modifiers are parsed in `set_flags.c` but do not produce correct output yet.
- Field width and precision are not supported.

## How it's organized

- `_printf.c`: walks the format string and dispatches on `%`
- `set_flags.c`, `handle_specifier.c`: flag parsing and specifier dispatch
- `handle_*.c`: one handler per conversion
- `print_number.c`, `print_binary.c`, `count_digits.c`: number output helpers
- `main.h`: prototypes
