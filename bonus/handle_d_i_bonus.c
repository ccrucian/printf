#include "ft_printf_bonus.h"

void	set_len_di_zerosprec(int *len, int *zero, int n, t_opt *opt)
{
	int	digits;

	*len = count_digits(n);
	*zero = 0;
	digits = *len - sign_(n);
	if (opt->prec > digits)
	{
		*zero = opt->prec - digits;
		*len = *len + *zero;
	}
}

/*helper per norminettare */
static void	put_d_i_zero_pads(int *n, int *cont, int i_pad)
{
	check_put_sign_set_positive(n, cont);
	put_pad_zero(i_pad, cont);
}

void	handle_d_i(int n, t_opt *opt, int *cont)
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
				put_d_i_zero_pads(&n, cont, (opt->width - len));
			else
				put_pad((opt->width - len), cont);
			put_nbr(n, cont, zero);
		}
	}
}
