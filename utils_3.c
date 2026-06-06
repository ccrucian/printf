#include "ft_printf.h"

void	put_hex_digits(unsigned long ptr, int *cont)
{
	char	*base;

	base = "0123456789abcdef";
	if (ptr >= 16)
		put_hex_digits(ptr / 16, cont);
	write(1, &base[ptr % 16], 1);
	(*cont)++;
}

void	put_hex_p(unsigned long ptr, int *cont)
{
	put_char('0', cont);
	put_char('x', cont);
	put_hex_digits(ptr, cont);
}

void	put_ptr(va_list list, int *cont)
{
	unsigned long	p;

	p = va_arg(list, unsigned long);
	if (p == 0)
	{
		write(1, "(nil)", 5);
		(*cont) += 5;
		return ;
	}
	put_hex_p(p, cont);
}