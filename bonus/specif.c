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

void	set_len_di_zerosprec(int *len, int *zero, int n, t_opt *opt)
{
	(*len) = count_digits(n);
	*zero = 0;
	if (opt->prec > *len)
	{
		*zero = opt->prec - (*len - sign_(n));
		*len = *len + *zero;
	}	
}

/*helper per norminettare */
static void	ft(int *n, int *cont, int i_pad)
{
	check_put_sign_set_positive(n, cont);
	put_pad_zero(i_pad, cont);
}

void	handle_d_i(int	n, t_opt *opt, int *cont)
{
	int	len;
	int	zero;

	if (n == 0 && opt->prec == 0 && opt->width == 0)
		return ;
	set_len_di_zerosprec(&len, &zero, n, opt);
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
				ft(&n, cont, (opt->width - len));
			else
				put_pad((opt->width - len), cont);
			put_nbr(n, cont, zero);
		}
	}
}
