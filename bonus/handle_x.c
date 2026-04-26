#include "bonus.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

static void	set_base(char spec, const char **base)
{
	if (spec == 'x')
		*base = "0123456789abcdef";
	if (spec == 'X')
		*base = "0123456789ABCDEF";
}

void	handle_xX(unsigned int n, t_opt *opt, int *cont)
{
	int	len;
	int	zero;
	const char	*base;
	
	if ( n == 0 && opt->prec == 0 && opt->width == 0)
		return ;
	set_base(opt->spec, &base);
	len = count_hex((unsigned long)n);
	zero = 0;
	if (opt->prec > len)
	{
		zero = opt->prec - len;
		len = len + zero;
	}
	if (len >= opt-> width)
		put_hex_xX(n, cont, zero, base);
	else if (opt->width > len)
	{
		if (opt->minus == 1)
		{
			put_hex_xX(n, cont, zero, base);
			put_pad((opt->width - len), cont);
		}
		else
		{
			if (opt->width == 1 && opt->point == 0)
				put_pad_zero((opt->width - len), cont);
				
			else
				put_pad((opt->width - len), cont);
			put_hex_xX(n, cont, zero, base);
		}
	}
}

void	put_hex_xX(unsigned int n, int *cont, int zero, const char *base)
{ 
	if (zero > 0)
		put_pad_zero(zero, cont);
	if (n >= 16)
		put_hex_xX(n / 16, cont, 0, base);
	(*cont)++;
	write(1, &base[n % 16], 1);
}
