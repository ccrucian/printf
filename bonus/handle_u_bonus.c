/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrucian <ccrucian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 15:01:04 by ccrucian          #+#    #+#             */
/*   Updated: 2026/05/29 15:01:10 by ccrucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	print_u_padded(unsigned int n, t_opt *opt, int *cont, int zero)
{
	if (opt->zero == 1 && opt->point == 0)
		put_pad_zero(opt->width - count_digits_u(n) - zero, cont);
	else
		put_pad(opt->width - count_digits_u(n) - zero, cont);
	put_un(n, cont, zero);
}

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
	if (len >= opt->width)
		put_un(n, cont, zero);
	else if (opt->width > len)
	{
		if (opt->minus == 1)
		{
			put_un(n, cont, zero);
			put_pad((opt->width - len), cont);
		}
		else
			print_u_padded(n, opt, cont, zero);
	}
}

void	put_un(unsigned int n, int *cont, int zero)
{
	unsigned long		nb;
	char				c;

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
