*This project has been created as part of the 42 curriculum by msotnych.*

# Libft

## Description

Libft is my first own C library, written for the 42 curriculum. The goal is to
understand how the standard C functions work by re-implementing them from
scratch, and to build a set of helper functions (strings, memory, output and
linked lists) that can be reused in future 42 projects.

The library is compiled into a static archive, `libft.a`, using the `ar`
command. It follows the 42 Norm, uses no global variables, and every function
is built with `-Wall -Wextra -Werror`.

## Instructions

### Compilation

Run these commands at the root of the repository:

```sh
make          # builds libft.a
make clean    # removes object files
make fclean   # removes object files and libft.a
make re       # fclean + all
```

### Usage

Include the header in your code and link against the library:

```c
#include "libft.h"

int main(void)
{
	ft_putendl_fd("Hello from libft!", 1);
	return (0);
}
```

```sh
cc -Wall -Wextra -Werror main.c -L. -lft -o my_program
```

## Library functions

A few basics used in the descriptions below:

- Every character is stored as a number (its **ASCII code**). For example `'A'` is 65, `'a'` is 97, `'0'` is 48 and a space is 32. Many functions simply compare these numbers.
- A C string is a row of characters that ends with a special character `'\0'` (code 0). Functions find the end of a string by looking for it.
- "Allocates" means the function reserves new memory with `malloc`. The caller must `free` it later.

### Part 1 - Libc functions

These work like the originals from the man pages; only the `ft_` prefix is different.

#### Character checks

They return `1` if the character belongs to the group and `0` if not. They are useful when you read user input and need to know what kind of character you are looking at.

- **`ft_isalpha`**: checks if the character is a letter. A letter is either an uppercase letter (codes 65-90, `A-Z`) or a lowercase letter (codes 97-122, `a-z`).
- **`ft_isdigit`**: checks if the character is a digit. Digits have codes 48-57 (`'0'` to `'9'`).
- **`ft_isalnum`**: checks if the character is a letter or a digit. It is the same as `ft_isalpha` or `ft_isdigit`.
- **`ft_isascii`**: checks if the value is a valid ASCII character, which means a code from 0 to 127. Anything bigger (for example, special symbols from other alphabets) is not ASCII.
- **`ft_isprint`**: checks if the character can be shown on the screen. Printable characters are codes 32 (space) to 126 (`~`). Codes below 32 are "control" characters such as newline or tab, and 127 is the delete key, so they are not printable.

#### Character conversion

- **`ft_toupper`**: turns a lowercase letter into an uppercase one. In the ASCII table every lowercase letter is exactly 32 higher than its uppercase version, so the function subtracts 32 when the character is between `a` and `z`. Anything else is returned unchanged.
- **`ft_tolower`**: the opposite. Adds 32 when the character is between `A` and `Z`.

#### Strings

- **`ft_strlen`**: counts how many characters are in a string before the ending `'\0'`. The `'\0'` itself is not counted.
- **`ft_strlcpy`**: copies a string `src` into the buffer `dst`, but never writes more than `size` bytes, so it cannot overflow the buffer. It copies at most `size - 1` characters and always puts a `'\0'` at the end (when `size` is not 0). It returns the full length of `src`, so you can tell if the text was cut: if the result is `>= size`, it did not fit.
- **`ft_strlcat`**: adds `src` to the end of the string already in `dst`, again without going over `size` bytes in total. It first finds the end of `dst`, then copies as many characters as still fit, leaving room for the final `'\0'`. It returns the length the result would have if there was enough room (length of `dst` + length of `src`), so you can detect cutting.
- **`ft_strchr`**: looks for a character in a string from left to right and returns a pointer to the first place where it is found, or `NULL` if it is not there. Searching for `'\0'` returns a pointer to the end of the string.
- **`ft_strrchr`**: the same as `ft_strchr`, but returns the **last** match instead of the first.
- **`ft_strncmp`**: compares two strings character by character, looking at no more than `n` characters. It stops at the first difference or at the end of a string. It returns `0` if they are equal, otherwise the difference between the first two different characters (negative if the first string is "smaller", positive if it is "bigger").
- **`ft_strnstr`**: looks for the string `little` inside the string `big`, checking only the first `len` characters of `big`. It returns a pointer to where `little` starts, or `NULL`. If `little` is empty, it returns `big`.
- **`ft_strdup`**: makes a copy of a string. It measures the string, allocates enough memory for it plus the `'\0'`, and copies everything.
- **`ft_atoi`**: turns text into a number, for example `"  -42abc"` becomes `-42`. It skips spaces and tab/newline-like characters at the start, accepts one `+` or `-` sign, then reads digits one by one (`result = result * 10 + digit`) until it meets something that is not a digit.

#### Memory

Memory functions work with raw bytes, not with strings, so they do not stop at `'\0'` and always need the number of bytes `n`.

- **`ft_memset`**: fills the first `n` bytes of a memory area with the same byte value. Useful to set a buffer to a known value.
- **`ft_bzero`**: fills the first `n` bytes with zeros (like `ft_memset` with value 0).
- **`ft_memcpy`**: copies `n` bytes from a source area to a destination area, one byte at a time. The two areas must not overlap.
- **`ft_memmove`**: also copies `n` bytes, but is safe when the two areas overlap. If the destination is before the source, it copies from the start. Otherwise it copies from the end backwards, so no byte is overwritten before it is copied.
- **`ft_memchr`**: looks for one byte inside the first `n` bytes of a memory area. Returns a pointer to it, or `NULL`. It is like `ft_strchr`, but does not care about `'\0'`.
- **`ft_memcmp`**: compares the first `n` bytes of two memory areas. Returns `0` if they are the same, otherwise the difference between the first two different bytes. It is like `ft_strncmp`, but does not stop at `'\0'`.
- **`ft_calloc`**: allocates memory for `nmemb` elements of `size` bytes each (so `nmemb * size` bytes) and fills it with zeros, so you never get random leftover data.

### Part 2 - Additional functions

These functions are not in the standard libc, or are slightly different from it. All of them that return a string or an array allocate new memory.

- **`ft_substr`**: cuts a piece out of a string. It starts at index `start` and takes up to `len` characters (fewer if the string ends earlier). If `start` is beyond the end of the string, it returns an empty string. Example: `ft_substr("hello", 1, 3)` gives `"ell"`.
- **`ft_strjoin`**: glues two strings together into a new one. Example: `ft_strjoin("foo", "bar")` gives `"foobar"`. The original strings are not changed.
- **`ft_strtrim`**: removes unwanted characters from the beginning and the end of a string. `set` lists all characters to remove. It moves forward from the start while the character is in `set`, then backwards from the end, and copies what remains in the middle. Example: `ft_strtrim("xxhixx", "x")` gives `"hi"`.
- **`ft_split`**: cuts a string into words using one separator character. Example: `ft_split("a,b,,c", ',')` gives `"a"`, `"b"`, `"c"` (repeated separators do not produce empty words). It first counts the words, allocates an array for them, and copies each word as its own new string. The array ends with `NULL` so you know where it stops. If any allocation fails, everything already allocated is freed and `NULL` is returned.
- **`ft_itoa`**: turns a number into text, the opposite of `ft_atoi`. It counts how many characters are needed (including `-` for negatives), then fills the string from the end, taking the last digit with `% 10` and removing it with `/ 10`. It uses a bigger type (`long`) internally so the smallest `int` (`-2147483648`) also works.
- **`ft_strmapi`**: builds a new string by applying a function to every character. The function receives the index and the character and returns the new character. Example: a function that makes letters uppercase turns `"abc"` into `"ABC"` in a new string.
- **`ft_striteri`**: like `ft_strmapi`, but changes the original string directly. The function receives the index and the **address** of the character, so it can modify it in place. Nothing is returned.
- **`ft_putchar_fd`**: writes one character to a file descriptor (`1` is the screen, `2` is the error output, or any opened file) using `write`.
- **`ft_putstr_fd`**: writes a whole string to a file descriptor.
- **`ft_putendl_fd`**: writes a string and then a newline (`'\n'`), so the next output starts on a new line.
- **`ft_putnbr_fd`**: writes a number as text to a file descriptor. It prints `-` first for negative numbers, then prints the digits using recursion: the front part of the number (`n / 10`) is printed first, then the last digit (`n % 10`). It uses a `long` internally so `-2147483648` works too.

### Part 3 - Linked lists

A linked list is a chain of nodes. Each node stores some data and a pointer to the next node, and the last node points to `NULL`. Unlike an array, it can grow easily, because you only need to add a new node. A node is described by this structure in `libft.h`:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
```

`content` is a `void *`, so a node can hold any type of data.

- **`ft_lstnew`**: creates a new node. It allocates 	memory for it, stores `content` inside, and sets `next` to `NULL`.
- **`ft_lstadd_front`**: puts a node at the beginning of the list. The new node points to the old first node, and then becomes the new first node.
- **`ft_lstadd_back`**: puts a node at the end of the list. If the list is empty, the new node becomes the first one. Otherwise it is linked after the current last node.
- **`ft_lstsize`**: counts the nodes by walking through the list from the first node to the end.
- **`ft_lstlast`**: returns the last node by walking forward until a node has `next == NULL`.
- **`ft_lstdelone`**: deletes one node. It uses the function `del` to free the content (the library does not know what type of data is stored, so you give it the right way to free it), and then frees the node itself. It does not touch the next node.
- **`ft_lstclear`**: deletes a node and all the nodes after it. For each node it remembers the next one first, deletes the current node, and moves on. At the end the list pointer is set to `NULL`.
- **`ft_lstiter`**: walks through the list and calls the function `f` on the content of every node (for example, to print all the data).
- **`ft_lstmap`**: creates a **new** list. For each node of the original list it calls `f` on the content and puts the result in a new node. The original list is not changed. If something fails, the new list built so far is deleted (using `del`) and `NULL` is returned, so nothing leaks.

## Logic and techniques used

This section explains the main ideas used in the code and where they appear.

### Recursion

A recursive function calls itself on a smaller version of the problem until it reaches a simple case that it can solve directly. I learned recursion during the 42 piscine and used it here in:

- **`ft_putnbr_fd`**: to print a number digit by digit in the correct order. If the number has more than one digit, the function first calls itself with `n / 10` (the number without its last digit), which prints the front digits. After that returns, it prints the last digit (`n % 10`). The simple case is a number from 0 to 9, which is printed directly.

All the other functions, including the list functions that walk through every node (`ft_lstclear`, `ft_lstiter`, `ft_lstmap`), use ordinary loops instead of recursion. A loop does not use extra stack memory for each node, so it is safe even for very long lists.

### Working with the integer limits (`long`)

The smallest `int` is `-2147483648`, but the largest is only `2147483647`, so `-n` does not fit in an `int` for that value. In **`ft_itoa`** and **`ft_putnbr_fd`** the number is first copied into a `long`, which is big enough to make it positive safely.


### Static helper functions

When a function is too long for the Norm or has a repeated task, the work is split into helpers declared `static`, so they are only visible inside their own file. For example `counter`, `fill` and `freeall` in `ft_split.c`, and `counter` in `ft_itoa.c`.

### Reusing my own functions

Some functions are built from others in the library, so the same logic is not written twice:

- `ft_split` uses `ft_substr` to cut out each word.
- `ft_strtrim` uses `ft_strchr` to check whether a character is in the set.
- `ft_substr` uses `ft_strlen` and `ft_strdup`, `ft_strdup` uses `ft_strlen`.
- `ft_calloc` uses `ft_bzero`.
- `ft_putstr_fd` and `ft_putendl_fd` use `ft_putchar_fd`; `ft_putnbr_fd` calls itself and `ft_putchar_fd`.
- `ft_lstclear` uses `ft_lstdelone`; `ft_lstadd_back` uses `ft_lstlast`; `ft_lstmap` uses `ft_lstnew`, `ft_lstadd_back` and `ft_lstclear`.


## Resources

- [Linux man pages for each re-implemented function (`man 3 strlen`, `man 3 memmove`, `man 3 strlcpy`, etc.)](https://linux.die.net/man/)
- [The Libft subject](https://cdn.intra.42.fr/pdf/pdf/216354/en.subject.pdf)
- [Google](https://www.google.com/) search engine such sites as: [Stack Overflow](https://stackoverflow.com/questions), [GeeksforGeeks](https://www.geeksforgeeks.org/), [cppreference.com](https://cppreference.com/), [GitHub](https://github.com)
- [Peer discussions with other 42 students](https://www.42network.org/)

### Use of AI

AI ([Claude](https://claude.com/)) was used:

- **Explanations:** to clarify concepts when needed.
- **README:** a draft of this file, including the function descriptions, was generated with AI and then reviewed and edited by me.