#include "ft_printf_bonus.h"

void	handle_c(int c, t_opt *opt, int *cont)
{
	int		width;
	char	ch;

	width = opt->width - 1;
	while (width > 0 && opt->minus == 0)
	{
		write(1, " ", 1);
		width--;
		(*cont)++;
	}
	ch = c;
	write(1, &ch, 1);
	(*cont)++;
	while (width > 0 && opt->minus == 1)
	{
		write(1, " ", 1);
		width--;
		(*cont)++;
	}
}

static int	null_str(char const **s)
{
	if (!(*s))
	{
		(*s) = "(null)";
		return (1);
	}
	return (0);
}

void	handle_s(char const *s, t_opt *opt, int *cont)
{
	int	len;

	null_str(&s);
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
