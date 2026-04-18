#include "printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	put_ptr(va_list list, int *cont)
{
	long	ptr;

	ptr = va_arg(list, long);
	write(1, "0x", 2);
	(*cont) += 2;
	put_hex(ptr, cont);
}

int	put_hex(long n, int *i)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
		put_hex(n / 16, i);
	(*i)++;
	write(1, &base[n % 16], 1);
	return (*i);
}

int	put_hex_up(long n, int *i)

{
	char	*base;

	base = "0123456789ABCDEF";
	if (n >= 16)
		put_hex_up(n / 16, i);
	(*i)++;
	write(1, &base[n % 16], 1);
	return (*i);
}

void	put_string(va_list list, int *cont)
{
	char	*s;
	int		i;

	i = 0;
	s = va_arg(list, char *);
	while (s[i])
	{
		write(1, &s[i], 1);
		(*cont)++;
		i++;
	}
}
