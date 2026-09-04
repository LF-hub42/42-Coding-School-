*This project has been created as part of the 42 curriculum by ekypraio.*

# 🧩 Libft

## 📌 Description

Libft is one of the first projects of the 42 curriculum.

The goal of the project is to create my own C library containing functions that
are commonly used when working with strings, characters, memory, and numbers.

Instead of relying on the standard library for these functions, I implemented
my own versions with the `ft_` prefix.

The project helped me understand how basic C functions work internally and gave
me a better understanding of pointers, memory management, strings, and dynamic
allocation.

## Instructions

### Compilation

```bash
make
```

### Clean

```bash
make clean
```

### Full Clean

```bash
make fclean
```

### Recompile

```bash
make re
```

## Functions

The library contains implementations of functions for different purposes.

### Character Checks

- `ft_isalpha` — Checks whether a character is an alphabetic letter
- `ft_isdigit` — Checks whether a character is a digit
- `ft_isalnum` — Checks whether a character is alphanumeric
- `ft_isascii` — Checks whether a character belongs to the ASCII range
- `ft_isprint` — Checks whether a character is printable

### Memory Functions

- `ft_bzero` — Sets a memory area to zero
- `ft_memchr` — Searches for a character in a memory area
- `ft_calloc` — Allocates and initializes memory

### String and Conversion Functions

- `ft_atoi` — Converts a string into an integer
- `ft_itoa` — Converts an integer into a string

The functions were implemented using basic C concepts such as loops, pointers,
type conversions, dynamic memory allocation, and string manipulation.

## 🧠 What I Learned

Working on Libft helped me understand some of the C concepts that are used
throughout the later 42 projects.

In particular:

- Pointers and pointer arithmetic
- Working with `void *`
- Memory allocation with `malloc`
- Memory initialization
- Strings and character arrays
- `size_t` and memory sizes
- Type casting
- Handling negative numbers
- Checking for allocation failures
- Working with ASCII values

For example, `ft_bzero` works directly on the memory address provided to the
function and sets each byte to `0`.

`ft_calloc` builds on this idea by allocating memory and then using `ft_bzero`
to initialize the allocated memory.

## 🔧 Implementation Examples

### ft_isalpha

`ft_isalpha` checks whether the given value represents an uppercase or lowercase
letter.

```c
int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
```

### ft_bzero

`ft_bzero` uses an `unsigned char` pointer to access the memory byte by byte and
sets the requested number of bytes to zero.

```c
void	ft_bzero(void *memory_block, size_t number_of_bytes)
{
	size_t			index;
	unsigned char	*byte_pointer;

	byte_pointer = (unsigned char *)memory_block;
	index = 0;
	while (index < number_of_bytes)
	{
		byte_pointer[index] = 0;
		index++;
	}
}
```

### ft_calloc

`ft_calloc` allocates memory for multiple elements, checks for an integer
overflow, and initializes the allocated memory to zero.

```c
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pointer;
	size_t	total;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	total = nmemb * size;
	pointer = malloc(total);
	if (pointer == NULL)
		return (NULL);
	ft_bzero(pointer, total);
	return (pointer);
}
```

### ft_itoa

`ft_itoa` converts an integer into a dynamically allocated string. Negative
numbers are handled separately and the resulting string is terminated with
`'\0'`.

### ft_memchr

`ft_memchr` searches through a memory block for a specific byte and returns a
pointer to the first matching position.

## 🛠️ Development

The project was developed in C following the coding standards of the 42
curriculum.

I used VS Code during development and tested individual functions while
implementing them.

The source files follow the 42 header format and use the required `ft_` naming
convention.

Some functions also include small commented test programs that were used during
development to check their behaviour.

## 📚 Resources

- 42 Libft Subject
- C standard library documentation
- `man` pages
- C programming documentation
- Personal tests and experimentation

## 🤖 AI Usage

AI was used during the project to help clarify some C concepts and understand
how certain standard functions work.

The implementation was written and understood by me.
