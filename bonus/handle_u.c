#include "bonus.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

void	handle_u(unsigned int n, t_opt *opt, int *cont)
{
	int	len;
	int	zero;

	if (n == 0 && opt->prec == 0 && opt->width == 0)
		return ;
	len = count_digits_u(n);
	zero = 0;
	if (opt->prec > len)
	{
		zero = opt->prec - len;
		len = len + zero;
	}
	if (len >= opt-> width)
		put_un(n, cont, zero);
	else if (opt->width > len)
	{
		if (opt->minus == 1)
		{
			put_un(n, cont, zero);
			put_pad((opt->width - len), cont);
		}
		else
		{
			if (opt->zero == 1 && opt->point == 0)
				put_pad_zero((opt->width - len), cont);
			else
				put_pad((opt->width - len), cont);
			put_un(n, cont, zero);
		}
	}
}

void	put_un(unsigned int n, int *cont, int zero)
{
	unsigned long	nb;
	char	c;

	nb = n;
	if (zero > 0)
		put_pad_zero(zero, cont);
	if (nb >= 10)
		put_un(nb / 10, cont, 0);
	(*cont)++;
	c = (nb % 10) + '0';
	write(1, &c, 1);
}

int	count_digits_u(unsigned int n)
{
	int	count;

	count = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}


