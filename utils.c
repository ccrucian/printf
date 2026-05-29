/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrucian <ccrucian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 14:47:53 by ccrucian          #+#    #+#             */
/*   Updated: 2026/05/29 17:16:16 by ccrucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	char_put(va_list list, int *cont, t_opt *opt)
{
	int	n;
	char	c;
	int	width;

	width = opt->width - 1;
	n = va_arg(list, int);
	c = (char)n;
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

void	open_arg(va_list list, int *cont, int n, t_opt *opt)
{
	int	i;

	i = 0;
	if (n == 1)
	{
		n = va_arg(list, int);
		(*cont) += (put_nbr(n, &i));
	}
	if (n == 2)
	{
		n = va_arg(list, unsigned int);
		(*cont) += (put_unsigned(n, &i));
	}
	if (n == 3)
	{
		n = va_arg(list, int);
		(*cont) += (put_hex((unsigned long)(unsigned int)n, &i));
	}
	if (n == 4)
	{
		n = va_arg(list, int);
		(*cont) += (put_hex_up((unsigned long)(unsigned int)n, &i));
	}
}

int	put_unsigned(unsigned int n, int *i)
{
	char	c;

	if (n >= 10)
		put_unsigned(n / 10, i);
	(*i)++;
	c = (n % 10) + '0';
	write(1, &c, 1);
	return (*i);
}

int	put_nbr(int n, int *i)
{
	long	nb;
	char	c;

	nb = n;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*i) += 11;
		return (*i);
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		(*i) += 1;
		nb *= -1;
	}
	if (nb >= 10)
		put_nbr(nb / 10, i);
	(*i)++;
	c = (nb % 10) + '0';
	write(1, &c, 1);
	return (*i);
}

void	put_string(va_list list, t_opt *opt, int *cont)
{
	char	*s;
	int		i;
	int		len;

	i = 0;
	s = va_arg(list, char *);
	if (s == NULL)
		s = "(null)";
	while (s[i])
		i++;
	len = i;
	if (opt->prec > 0 && len > opt->prec)
		len = opt->prec;
	if (len >= opt->width)
	{
		if (opt->prec > 0)
		{
			write(1, s, opt->prec);
			(*cont) += opt->prec;
		}
		else
		{
			write(1, s, i);
			(*cont) += i;
		}
	}
	else if (opt->width > len)
	{
		if (opt->minus == 1)
		{
			if (opt->prec > 0)
			{
				write(1, s, opt->prec);
				(*cont) += opt->prec;
			}
			else
			{
				write(1, s, i);
				(*cont) += i;
			}
			put_pad(opt->width - len, cont);
		}
		else if (opt->minus == 0)
		{
			put_pad(opt->width - len, cont);
			if (opt->prec > 0)
			{
				write(1, s, opt->prec);
				(*cont) += opt->prec;
			}
			else
			{
				write(1, s, i);
				(*cont) += i;
			}
		}
	}
}

void	put_pad(int i_pad, int *cont)
{
	while (i_pad > 0)
	{
		write(1, " ", 1);
		(*cont)++;
		i_pad--;
	}
}
