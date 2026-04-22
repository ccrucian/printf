#include "bonus.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	read_spec(va_list list, t_opt *opt, int *cont)
{
	if (opt->spec == 'c')
		handle_c(list, opt, cont);
	if (opt->spec == 's')
		handle_s(list, opt, cont);
}

void	handle_c(va_list list, t_opt *opt, int *cont)
{
	int	c;
	int	width;

	width = opt->width - 1;
	c = va_arg(list, int);
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

void	handle_s(va_list list, t_opt *opt, int *cont)
{
	char	*s;
	int	len;

	s = va_arg(list, char *);
	len = ft_strlen(s);
	//if (opt->prec > 0 && len > opt->prec)
	//	len -= prec;
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
