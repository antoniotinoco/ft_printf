_This project has been created as part of the 42 curriculum by atinoco-._

# ft_printf

A re-implementation of the C standard library `printf()` function, built from scratch as part of the 42 School curriculum. The project's main challenge is learning how to handle a variable number of arguments using variadic functions.

---

## Supported Conversions

| Specifier | Description |
|---|---|
| `%c` | Single character |
| `%s` | String |
| `%p` | Pointer address in hexadecimal |
| `%d` | Decimal (base 10) integer |
| `%i` | Integer in base 10 |
| `%u` | Unsigned decimal integer |
| `%x` | Hexadecimal (base 16) lowercase |
| `%X` | Hexadecimal (base 16) uppercase |
| `%%` | Literal percent sign |

---

## Usage

Compile the library:
```bash
make
```

**To try it out** using the provided `main.c` with example calls:
```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o test
./test
```

**To use it in your own project**, link the library and include the header:
```bash
cc -Wall -Wextra -Werror your_file.c -L. -lftprintf -o your_program
```
```c
#include "ftprintf.h"

ft_printf("Hello, %s! You are %d years old.\n", "world", 42);
```

---

## Files

| File | Description |
|---|---|
| `ft_printf.c` | Core logic and format string parsing |
| `spf_helper1.c and spf_helper2.c` | Files with helper functions |
| `ft_printf.h` | Header file |
| `main.c` | Usage examples |
| `Makefile` | Builds `libftprintf.a` with `all`, `clean`, `fclean`, `re` |

---

## Key Concepts Learned

**Variadic functions** | Using `va_start`, `va_arg`, `va_copy`, and `va_end` from `<stdarg.h>` to handle an unknown number of arguments at runtime.

**Format string parsing** | Iterating through a string character by character, detecting `%` specifiers, and dispatching to the correct handler.

**Base conversion** | Manually converting integers to different bases (decimal, hex) for `%x`, `%X`, `%p`, and `%u`.

**Static libraries** | Compiling object files and archiving them into a `.a` library using `ar`, then linking against it.