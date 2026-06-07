/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_x_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrucian <ccrucian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 15:00:50 by ccrucian          #+#    #+#             */
/*   Updated: 2026/05/29 15:00:57 by ccrucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	set_base(char spec, const char **base)
{
	if (spec == 'x')
		*base = "0123456789abcdef";
	if (spec == 'X')
		*base = "0123456789ABCDEF";
}

static void	put_x_padding(t_opt *opt, int len, int *cont)
{
	if (opt->zero == 1 && opt->point == 0)
		put_pad_zero(opt->width - len, cont);
	else
		put_pad(opt->width - len, cont);
}

static void	set_x_precision(t_opt *opt, int *len, int *zero)
{
	*zero = 0;
	if (opt->prec > *len)
	{
		*zero = opt->prec - *len;
		*len = *len + *zero;
	}
}

void	handle_xx(unsigned int n, t_opt *opt, int *cont)
{
	int			len;
	int			zero;
	const char	*base;
	
	if (n == 0 && opt->prec == 0 && opt->width == 0)
		return ;
	set_base(opt->spec, &base);
	len = count_hex((unsigned long)n);
	set_x_precision(opt, &len, &zero);
	if (len >= opt->width)
		put_hex_xx(n, cont, zero, base);
	else if (opt->minus == 1)
	{
		put_hex_xx(n, cont, zero, base);
		put_pad((opt->width - len), cont);
	}
	else
	{
		put_x_padding(opt, len, cont);
		put_hex_xx(n, cont, zero, base);
	}
}
