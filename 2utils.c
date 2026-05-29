/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2utils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrucian <ccrucian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 14:48:44 by ccrucian          #+#    #+#             */
/*   Updated: 2026/05/29 14:48:47 by ccrucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static void	put_null_ptr(t_opt *opt, int *cont)
{
	char	*s;

	s = "(nil)";
	if (opt->width > 5)
	{
		if (opt->minus == 0)
		{
			put_pad((opt->width - 5), cont);
			write(1, s, 5);
			(*cont) += 5;
		}
		else if (opt->minus == 1)
		{
			write(1, s, 5);
			(*cont) += 5;
			put_pad((opt->width - 5), cont);
		}
	}
	else
	{
		write(1, s, 5);
		(*cont) += 5;
	}
}

void	put_ptr(va_list list, int *cont, t_opt *opt)
{
	unsigned long	p;
	int				n;

	p = va_arg(list, unsigned long);
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

int	put_hex(unsigned long n, int *i)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
		put_hex(n / 16, i);
	(*i)++;
	write(1, &base[n % 16], 1);
	return (*i);
}

int	put_hex_up(unsigned long n, int *i)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (n >= 16)
		put_hex_up(n / 16, i);
	(*i)++;
	write(1, &base[n % 16], 1);
	return (*i);
}
