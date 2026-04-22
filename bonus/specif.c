#include "bonus.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	read_spec(va_list list, t_opt *opt, int *cont)
{
	if (opt->spec == '%')
		put_char('%', cont);
	if (opt->spec == 'c')
		handle_c(va_arg(list, int), opt, cont);
	if (opt->spec == 's')
		handle_s(va_arg(list, char const *), opt, cont);
	if (opt->spec == 'd' || opt->spec == 'i')
		handle_d_i(va_arg(list, int), opt, cont);
}

void	handle_c(int c, t_opt *opt, int *cont)
{
	int	width;

	width = opt->width - 1;
	while (width > 0 && opt->minus == 0)
	{
		write(1, " ", 1);
		width--;
		(*cont)++;
	}
	write(1, &c, 1);
	(*cont)++;
	while (width > 0 && opt->minus == 1)
	{
		write(1, " ", 1);
		width--;
		(*cont)++;
	}
}

void	handle_s(char const *s, t_opt *opt, int *cont)
{
	int	len;

	len = ft_strlen(s);
	if (opt->prec > 0 && len > opt->prec)
		len = opt->prec;
	if (len >= opt->width)
		put_str_prec(s, cont, opt->prec);
	else if (opt->width > len)
	{
		if (opt->minus == 1)
		{
			put_str_prec(s, cont, opt->prec);
			padding(opt->width, cont, len, opt->prec);
		}
		else if (opt->minus == 0)
		{
			padding(opt->width, cont, len, opt->prec);
			put_str_prec(s, cont, opt->prec);
		}
	}
}

void	handle_d_i(int	n, t_opt *opt, int *cont)
{
	int	len;
	int	zero;

	len = count_digits(n);
	zero = 0;
	if (opt->prec > len)
	{
		zero = opt->prec - len;
		len = len + zero;
	}
	if (len >= opt->width)
		put_nbr(n, cont, zero);
	else if (opt->width > len)
	{
		if (opt->minus == 1)
		{
			put_nbr(n, cont, zero);
			put_pad((opt->width - len), cont);
		}
		else
		{
			if (opt->zero == 1 && opt->point == 0)
				put_pad_zero((opt->width - len), cont);
			else
				put_pad((opt->width - len), cont);
			put_nbr(n, cont, zero);
		}
	}
}
