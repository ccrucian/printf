*This project has been created as part of the 42 curriculum by ccrucian.*

# ft_printf

## Description

`ft_printf` is a 42 School project whose goal is to recreate a simplified version of the standard C `printf()` function.

The project focuses on variadic functions, formatted output, argument parsing, type conversion, and clean modular C programming. The final result is a static library named `libftprintf.a`, which exposes the function:

```c
int ft_printf(const char *format, ...);
```

The function writes formatted output to the standard output and returns the number of characters printed, similarly to the original `printf()` function.

The mandatory implementation supports the following conversions:

| Conversion | Description                                        |
| ---------- | -------------------------------------------------- |
| `%c`       | Prints a single character                          |
| `%s`       | Prints a string                                    |
| `%p`       | Prints a pointer address in hexadecimal format     |
| `%d`       | Prints a signed decimal integer                    |
| `%i`       | Prints a signed decimal integer                    |
| `%u`       | Prints an unsigned decimal integer                 |
| `%x`       | Prints an unsigned number in lowercase hexadecimal |
| `%X`       | Prints an unsigned number in uppercase hexadecimal |
| `%%`       | Prints a percent sign                              |

## Instructions

### Compilation

To compile the mandatory part:

```bash
make
```

This creates the static library:

```bash
libftprintf.a
```

To compile the bonus part:

```bash
make bonus
```

To remove object files:

```bash
make clean
```

To remove object files and the compiled library:

```bash
make fclean
```

To fully rebuild the project:

```bash
make re
```

### Usage

After compiling the library, include the header in your C file:

```c
#include "ft_printf.h"
```

Example:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s!\n", "world");
    ft_printf("Number: %d\n", 42);
    ft_printf("Hex: %x\n", 255);
    return (0);
}
```

Compile your test file with the library:

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o test
./test
```

## Project Structure

```text
.
├── Makefile
├── README.md
├── ft_printf.c
├── ft_printf.h
├── utils.c
├── utils_2.c
├── utils_3.c
└── bonus/
    ├── ft_printf_bonus.h
    ├── start_bonus.c
    ├── parser_bonus.c
    ├── parsing_bonus.c
    ├── dispatch_bonus.c
    ├── padding_bonus.c
    ├── handle_c_s_bonus.c
    ├── handle_d_i_bonus.c
    ├── handle_p_bonus.c
    ├── handle_u_bonus.c
    ├── handle_x_bonus.c
    ├── hex_utils_bonus.c
    ├── number_utils_bonus.c
    └── string_utils_bonus.c
```

## Technical Choices

### General Algorithm

The mandatory implementation follows a simple linear parsing algorithm.

The format string is scanned character by character:

1. If the current character is not `%`, it is printed directly with `write()`.
2. If the current character is `%`, the next character is interpreted as a conversion specifier.
3. According to the specifier, the correct helper function is called.
4. The corresponding argument is retrieved from the `va_list`.
5. The value is converted and printed.
6. A counter keeps track of the total number of characters written.

This approach is appropriate for the mandatory project because the required format grammar is limited to direct conversions without full buffer management.

The complexity is linear in relation to the size of the format string plus the number of characters produced by each conversion.

### Variadic Arguments

The function uses the standard variadic argument mechanism:

```c
va_start
va_arg
va_end
```

This allows `ft_printf` to accept a variable number of arguments, just like the original `printf()`.

Each conversion retrieves the expected type from the argument list. For example:

* `%c`, `%d`, and `%i` retrieve an `int`
* `%u`, `%x`, and `%X` retrieve an unsigned integer value
* `%s` retrieves a `char *`
* `%p` retrieves a pointer value represented as an unsigned long

### Number Conversion

Numbers are printed recursively.

For decimal numbers, the function divides the number by 10 until the most significant digit is reached, then prints each digit while the recursive calls return.

For hexadecimal numbers, the same logic is used with base 16 and a hexadecimal base string:

```c
"0123456789abcdef"
"0123456789ABCDEF"
```

This avoids dynamic memory allocation and keeps the implementation simple and compatible with the project constraints.

### Data Structures

The mandatory part does not require complex data structures.

It mainly uses:

* `int` counters to track printed characters
* indexes to scan the format string
* `va_list` to handle variadic arguments
* helper functions to separate the handling of each conversion

This choice keeps the code direct and easy to follow.

The bonus part uses a structure named `t_opt` to store parsed formatting options:

```c
typedef struct s_opt
{
    int     minus;
    int     zero;
    int     width;
    int     point;
    int     prec;
    char    spec;
}   t_opt;
```

This structure makes the bonus parser more organized because all relevant formatting information is stored in one place before dispatching the printing function.

## Bonus

The repository includes a bonus implementation with a dedicated `bonus` rule in the Makefile.

The bonus parser is designed to handle additional formatting options such as:

* left alignment with `-`
* zero padding with `0`
* minimum field width
* precision with `.`

The use of the `t_opt` structure allows the parser to separate format analysis from actual printing, which makes the code easier to extend and maintain.

## Resources

The following references are useful to understand the concepts used in this project:

* `man 3 printf`
* `man 3 stdarg`
* `man 2 write`
* `man 1 ar`
* C documentation about variadic functions
* 42 Norm documentation
* The C Programming Language, Brian W. Kernighan and Dennis M. Ritchie

### AI Usage

AI was used to help write and structure this `README.md` file according to the subject requirements.

In particular, AI was used for:

* organizing the documentation sections;
* improving the clarity of the project description;
* explaining the general algorithm;
* explaining the data structure choices;
* describing the role of the bonus parser and the `t_opt` structure;
* writing this README and formatting the file in Markdown.

AI was not used in this README step to generate, modify, or replace the source code. The implementation remains the responsibility of the student and must be fully understood, tested, and explained during peer evaluation.
