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

The repository also includes a bonus implementation, compiled through the `bonus` rule of the Makefile:

```bash
make bonus
```

The bonus part extends the mandatory `ft_printf` by adding support for a more advanced parsing of the format string.

In the mandatory part, the parser only needs to recognize a conversion specifier such as `%d`, `%s`, or `%x`.

In the bonus part, the parser must also detect formatting options placed between the `%` character and the conversion specifier.

For this reason, the bonus implementation uses a dedicated structure:

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

This structure stores all the information extracted from the format string before calling the correct printing function.

The bonus parser follows this order:

1. Initialize all options to their default values.
2. Parse the flags, such as `-` and `0`.
3. Parse the minimum field width.
4. Parse the precision introduced by `.`.
5. Parse the final conversion specifier.

This makes the code more modular because the parsing step is separated from the printing step.

### Supported Bonus Options

The implemented bonus options are:

| Option       | Meaning                                                        |
| ------------ | -------------------------------------------------------------- |
| `-`          | Left-aligns the output inside the given width                  |
| `0`          | Pads the output with zeroes instead of spaces when allowed     |
| `width`      | Defines the minimum number of characters to print              |
| `.precision` | Defines the precision, whose meaning depends on the conversion |

### The `-` Flag

The `-` flag left-aligns the printed value inside the field width.

Without `-`, padding is added before the value:

```c
ft_printf("%10d", 42);
```

Output:

```text
        42
```

With `-`, the value is printed first and the padding is added after it:

```c
ft_printf("%-10d", 42);
```

Output:

```text
42        
```

This flag mainly affects conversions where a minimum width is provided.

It applies to:

| Conversion  | Effect of `-`                                    |
| ----------- | ------------------------------------------------ |
| `%c`        | Prints the character first, then spaces          |
| `%s`        | Prints the string first, then spaces             |
| `%d` / `%i` | Prints the number first, then spaces             |
| `%u`        | Prints the unsigned number first, then spaces    |
| `%x` / `%X` | Prints the hexadecimal number first, then spaces |
| `%p`        | Prints the pointer first, then spaces            |

The `-` flag has priority over the `0` flag.

For example:

```c
ft_printf("%-05d", 42);
```

In this case, the output must be left-aligned, so the `0` flag is ignored and spaces are used for padding.

### The `0` Flag

The `0` flag pads the value with zeroes instead of spaces.

Example:

```c
ft_printf("%05d", 42);
```

Output:

```text
00042
```

This flag is useful mainly for numeric conversions.

It applies to:

| Conversion  | Effect of `0`                             |
| ----------- | ----------------------------------------- |
| `%d` / `%i` | Adds zeroes before the number             |
| `%u`        | Adds zeroes before the unsigned number    |
| `%x` / `%X` | Adds zeroes before the hexadecimal number |

The `0` flag does not have priority when `-` is present.

Example:

```c
ft_printf("%-05d", 42);
```

The `-` flag wins, so the result is left-aligned and padded with spaces:

```text
42   
```

The `0` flag is also ignored when precision is used with numeric conversions.

Example:

```c
ft_printf("%08.5d", 42);
```

In this case, precision controls the number of digits, while width controls the final field size.

The expected logic is:

1. Precision adds leading zeroes to the number itself.
2. Width adds spaces to reach the minimum field size.
3. The `0` flag is ignored because precision is present.

So the output is:

```text
   00042
```

### Width

The width defines the minimum number of characters that must be printed.

Example:

```c
ft_printf("%8s", "Hi");
```

Output:

```text
      Hi
```

The string has length 2, but the width is 8, so 6 spaces are added before it.

Width does not cut the output. It only adds padding if the printed value is shorter than the requested width.

Example:

```c
ft_printf("%3s", "Hello");
```

Output:

```text
Hello
```

Since the string is already longer than the width, no padding is added.

Width applies to:

| Conversion  | Effect of width                    |
| ----------- | ---------------------------------- |
| `%c`        | Pads around one character          |
| `%s`        | Pads around the string             |
| `%d` / `%i` | Pads around the signed integer     |
| `%u`        | Pads around the unsigned integer   |
| `%x` / `%X` | Pads around the hexadecimal number |
| `%p`        | Pads around the pointer address    |

### Precision

Precision is introduced by a dot:

```c
%.5d
%.3s
```

Its meaning depends on the conversion.

For strings, precision defines the maximum number of characters to print.

Example:

```c
ft_printf("%.3s", "Hello");
```

Output:

```text
Hel
```

For numbers, precision defines the minimum number of digits to print. If the number has fewer digits, zeroes are added before it.

Example:

```c
ft_printf("%.5d", 42);
```

Output:

```text
00042
```

Precision applies to:

| Conversion  | Effect of precision                  |
| ----------- | ------------------------------------ |
| `%s`        | Maximum number of characters printed |
| `%d` / `%i` | Minimum number of digits             |
| `%u`        | Minimum number of digits             |
| `%x` / `%X` | Minimum number of hexadecimal digits |

Precision does not affect `%c` in this implementation.

For `%p`, the implementation handles width and alignment, but pointer formatting keeps the standard `0x` prefix and hexadecimal address representation.

### Interaction Between Flags, Width, and Precision

The formatting options interact in a specific order.

The general rule is:

1. Precision modifies the value itself.
2. Width defines the total minimum size of the final output.
3. Padding is added if the output is shorter than the width.
4. `-` decides whether padding goes before or after the value.
5. `0` is used only when allowed, mainly for numeric values without precision and without `-`.

Example with width and precision:

```c
ft_printf("%8.5d", 42);
```

The number `42` becomes `00042` because of precision.

Then width `8` requires a total length of 8 characters.

Output:

```text
   00042
```

Example with left alignment:

```c
ft_printf("%-8.5d", 42);
```

The number still becomes `00042`, but the padding is added after the value.

Output:

```text
00042   
```

Example with zero padding:

```c
ft_printf("%08d", 42);
```

There is no precision and no `-`, so the `0` flag is active.

Output:

```text
00000042
```

Example with zero padding and precision:

```c
ft_printf("%08.5d", 42);
```

Precision has priority over `0`.

Output:

```text
   00042
```

### Conversion-Specific Behavior

#### `%c`

The `%c` conversion prints a single character.

Supported bonus options:

| Option       | Supported           |
| ------------ | ------------------- |
| `-`          | Yes                 |
| `width`      | Yes                 |
| `0`          | No practical effect |
| `.precision` | No                  |

Example:

```c
ft_printf("%5c", 'A');
```

Output:

```text
    A
```

Example:

```c
ft_printf("%-5c", 'A');
```

Output:

```text
A    
```

#### `%s`

The `%s` conversion prints a string.

Supported bonus options:

| Option       | Supported           |
| ------------ | ------------------- |
| `-`          | Yes                 |
| `width`      | Yes                 |
| `.precision` | Yes                 |
| `0`          | No practical effect |

Example:

```c
ft_printf("%10s", "Hello");
```

Output:

```text
     Hello
```

Example:

```c
ft_printf("%.3s", "Hello");
```

Output:

```text
Hel
```

Example:

```c
ft_printf("%8.3s", "Hello");
```

Output:

```text
     Hel
```

Example:

```c
ft_printf("%-8.3s", "Hello");
```

Output:

```text
Hel     
```

#### `%d` and `%i`

The `%d` and `%i` conversions print signed decimal integers.

Supported bonus options:

| Option       | Supported |
| ------------ | --------- |
| `-`          | Yes       |
| `0`          | Yes       |
| `width`      | Yes       |
| `.precision` | Yes       |

Example:

```c
ft_printf("%6d", 42);
```

Output:

```text
    42
```

Example:

```c
ft_printf("%06d", 42);
```

Output:

```text
000042
```

Example:

```c
ft_printf("%.5d", 42);
```

Output:

```text
00042
```

Example:

```c
ft_printf("%8.5d", 42);
```

Output:

```text
   00042
```

For negative numbers, the sign is part of the printed value.

Example:

```c
ft_printf("%06d", -42);
```

Output:

```text
-00042
```

#### `%u`

The `%u` conversion prints an unsigned decimal integer.

Supported bonus options:

| Option       | Supported |
| ------------ | --------- |
| `-`          | Yes       |
| `0`          | Yes       |
| `width`      | Yes       |
| `.precision` | Yes       |

Example:

```c
ft_printf("%6u", 42);
```

Output:

```text
    42
```

Example:

```c
ft_printf("%06u", 42);
```

Output:

```text
000042
```

Example:

```c
ft_printf("%.5u", 42);
```

Output:

```text
00042
```

#### `%x` and `%X`

The `%x` and `%X` conversions print an unsigned integer in hexadecimal format.

`%x` uses lowercase letters:

```text
abcdef
```

`%X` uses uppercase letters:

```text
ABCDEF
```

Supported bonus options:

| Option       | Supported |
| ------------ | --------- |
| `-`          | Yes       |
| `0`          | Yes       |
| `width`      | Yes       |
| `.precision` | Yes       |

Example:

```c
ft_printf("%x", 255);
```

Output:

```text
ff
```

Example:

```c
ft_printf("%X", 255);
```

Output:

```text
FF
```

Example:

```c
ft_printf("%6x", 255);
```

Output:

```text
    ff
```

Example:

```c
ft_printf("%06x", 255);
```

Output:

```text
0000ff
```

Example:

```c
ft_printf("%.5x", 255);
```

Output:

```text
000ff
```

#### `%p`

The `%p` conversion prints a pointer address.

Supported bonus options:

| Option       | Supported           |
| ------------ | ------------------- |
| `-`          | Yes                 |
| `width`      | Yes                 |
| `0`          | No practical effect |
| `.precision` | No                  |

A non-null pointer is printed with the `0x` prefix followed by the address in lowercase hexadecimal.

Example:

```c
ft_printf("%p", ptr);
```

Output format:

```text
0x...
```

Width can be used to align pointer output.

Example:

```c
ft_printf("%20p", ptr);
```

The pointer is right-aligned inside a field of 20 characters.

Example:

```c
ft_printf("%-20p", ptr);
```

The pointer is left-aligned inside a field of 20 characters.

A null pointer is handled separately and printed as:

```text
(nil)
```

#### `%%`

The `%%` conversion prints a literal percent sign.

Example:

```c
ft_printf("%%");
```

Output:

```text
%
```

In this implementation, `%%` is printed directly as a percent character.

### Summary of Supported Interactions

| Conversion | `-` |                 `0` | Width | Precision |
| ---------- | --: | ------------------: | ----: | --------: |
| `%c`       | Yes | No practical effect |   Yes |        No |
| `%s`       | Yes | No practical effect |   Yes |       Yes |
| `%d`       | Yes |                 Yes |   Yes |       Yes |
| `%i`       | Yes |                 Yes |   Yes |       Yes |
| `%u`       | Yes |                 Yes |   Yes |       Yes |
| `%x`       | Yes |                 Yes |   Yes |       Yes |
| `%X`       | Yes |                 Yes |   Yes |       Yes |
| `%p`       | Yes | No practical effect |   Yes |        No |
| `%%`       |  No |                  No |    No |        No |

The most important interaction rules are:

* `-` overrides `0`;
* precision overrides `0` for numeric conversions;
* width adds padding only if the printed result is shorter than the requested width;
* precision has different meanings for strings and numbers;
* for strings, precision limits the maximum number of characters;
* for numbers, precision sets the minimum number of digits;
* for hexadecimal conversions, `%x` and `%X` behave the same except for the alphabetic case.

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
