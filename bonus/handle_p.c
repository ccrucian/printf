#include "bonus.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

static void	put_null_ptr(t_opt *opt, int *cont)
{
	char	*s;
	
	s = "(nil)";
	if (opt->width > 5)
	{
		if (opt->minus == 0)
		{
			put_pad((opt->width - 5), cont);
			put_str_prec(s, cont, -1);
		}
		else if (opt->minus == 1)
		{
			put_str_prec(s, cont, -1);
			put_pad((opt->width - 5), cont);
		}
	}
	else
		put_str_prec(s, cont, -1);
}

int	count_hex(unsigned long n)
{
	int	i;

	i = 1;
	while (n / 16 != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

void	 handle_p(unsigned long p, t_opt *opt, int *cont)
{
	int	n;

	if (p == 0)
	{
		put_null_ptr(opt, cont);
		return ;
	}	 
	n = count_hex(p);
	if (opt->width > n + 2)
	{
		if (opt->minus == 0)
		{
			put_pad((opt->width - (n + 2)), cont);
			put_hex_p(p, cont, n);
		}
		else if (opt->minus == 1)
		{
			put_hex_p(p, cont, n);
			put_pad((opt->width - (n + 2)), cont);
		}
	}
	else
		put_hex_p(p, cont, n);
}

void	put_hex_p(unsigned long ptr, int *cont, int n)
{
	char	*base;

	base = "0123456789abcdef";
	n--;
	if (n == 1)
		put_char('0', cont);
	if (n == 0)
		put_char('x', cont);
	if (ptr >= 16)
		put_hex_p(ptr / 16, cont, n);
	(*cont)++;
	write(1, &base[ptr % 16], 1);
}

/*int	main(void)
{
	int	i;

	i = 1;
	ft_printf("%p\n", &i);
	printf("%p\n", &i);
	ft_printf("%16p\n", &i);
	printf("%16p\n", &i);
	ft_printf("%-20p\n", &i);
	printf("%-20p\n", &i);

	return (0);
}*/
