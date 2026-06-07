/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrucian <ccrucian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 15:15:14 by ccrucian          #+#    #+#             */
/*   Updated: 2026/06/07 15:15:15 by ccrucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	put_nbr(int n, int *cont, int zero)
{
	char	c;
	long	nb;

	nb = n;
	if (nb < 0)
	{
		put_char('-', cont);
		nb *= -1;
	}
	if (zero > 0)
		put_pad_zero(zero, cont);
	if (nb == 2147483648)
	{
		write(1, "2147483648", 10);
		(*cont) += 10;
		return ;
	}
	if (nb >= 10)
		put_nbr(nb / 10, cont, 0);
	(*cont)++;
	c = (nb % 10) + '0';
	write(1, &c, 1);
}

int	count_digits(int n)
{
	int	count;

	count = 1;
	if (n < 0)
		count++;
	while (n / 10 != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	sign_(int n)
{
	return (n < 0);
}

void	check_put_sign_set_positive(int *n, int *cont)
{
	if (*n < 0)
	{
		put_char('-', cont);
		(*n) *= -1;
	}
}
