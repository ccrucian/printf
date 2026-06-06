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

void	put_ptr(va_list list, int *cont)
{
	unsigned long	p;

	p = va_arg(list, unsigned long);
	if (p == 0)
	{
		write(1, "(nil)", 5);
		(*cont) += 5;
		return ;
	}
	put_hex_p(p, cont);
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
