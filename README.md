*This project has been created as part of the 42 curriculum by ommorali.*

# ft_printf

## Description

ft_printf is a project at 42 that asks students to recode the standard C library function `printf()`. 

The primary goal of this project is to understand variadic functions in C (`stdarg.h`), formatted output processing, and standard I/O byte accounting. The function handles conversion specifiers `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%%` without using `printf`'s standard output buffering.

### Algorithm Explanation & Justification

Selected Approach: Single-Pass Parsing with Variadic Argument Extraction

To handle varying parameters dynamically, this implementation iterates through the format string character by character:
- **Format Parsing:** Plain characters are immediately written to standard output (`write(1, ...)`), incrementing the return counter.
- **Specifier Dispatching:** Upon encountering a `%` character, the function inspects the following conversion specifier and dispatches processing to dedicated type-handler helpers (`ft_putchar`, `ft_putstr`, `ft_putnbr`, `ft_print_ptr`).
- **Base Conversion & Precision:** Numerical output (decimal and hexadecimal) uses recursive modulo decomposition, allowing unified handling for base-10 and base-16 signed and unsigned values without requiring intermediate buffer allocations.

## Instructions

### Compilation

The project builds a static library `libftprintf.a` at the root of the repository using the provided Makefile:

```bash
make
```

Available Makefile rules:
- `make` or `make all`: Compiles the source files and builds `libftprintf.a`.
- `make clean`: Removes all compiled object files (`.o`).
- `make fclean`: Removes object files and the static library `libftprintf.a`.
- `make re`: Rebuilds the entire library from scratch.

### Execution Example

Here is how you can use `ft_printf` inside a C program:

```c
#include "ft_printf.h"
int main()
{
    char a = 0;
    char *c = &a;
    ft_printf("%c %s %p %d %i %u %x %X %%\n", a, "hi", c, -42, 42, 42, 255, 255);
    return (0);
}
```

To compile your code with the library:

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o test_printf
./test_printf
```

## Resources & AI Usage

### References & Documentation

- **C Man Pages:** `man 3 stdarg`, `man 3 write`, `man 3 printf`
- **42 Norm v4 Documentation:** Official guidelines for code formatting and structure.
- **Standards:** C99 Standard regarding variadic macro processing and type conversions.

### AI Assistance Disclosure

Artificial Intelligence (AI) was utilized during the development of this project under the following specific scopes:
- **Debugging & Edge-Case Analysis:** Analyzing edge cases such as `INT_MIN` overflow handling and NULL pointer string formats.
- **Norminette Structuring:** Ensuring line count limits and function count per file adhere to 42 Norm guidelines.