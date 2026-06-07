/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrucian <ccrucian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 15:15:09 by ccrucian          #+#    #+#             */
/*   Updated: 2026/06/07 15:15:09 by ccrucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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

void	put_hex_xx(unsigned int n, int *cont, int zero, const char *base)
{
	if (zero > 0)
		put_pad_zero(zero, cont);
	if (n >= 16)
		put_hex_xx(n / 16, cont, 0, base);
	(*cont)++;
	write(1, &base[n % 16], 1);
}

void	put_hex_digits(unsigned long ptr, int *cont)
{
	char	*base;

	base = "0123456789abcdef";
	if (ptr >= 16)
		put_hex_digits(ptr / 16, cont);
	write(1, &base[ptr % 16], 1);
	(*cont)++;
}

void	put_hex_p(unsigned long ptr, int *cont)
{
	put_char('0', cont);
	put_char('x', cont);
	put_hex_digits(ptr, cont);
}
