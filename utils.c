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

void	char_put(va_list list, int *cont)
{
	int	n;
	char	c;

	n = va_arg(list, int);
	c = (char)n;
	write(1, &c, 1);
	(*cont)++;
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

void	put_string(va_list list, int *cont)
{
	char	*s;
	int		i;

	i = 0;
	s = va_arg(list, char *);
	if (s == NULL)
		s = "(null)";
	while (s[i])
		i++;
	write(1, s, i);
	(*cont) += i;
}
