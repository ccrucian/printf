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

void	put_ptr(va_list list, int *cont)
{
	unsigned long	ptr;

	ptr = va_arg(list, unsigned long);
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		(*cont) += 5;
		return ;
	}
	write(1, "0x", 2);
	(*cont) += 2;
	put_hex(ptr, cont);
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

void	put_string(va_list list, int *cont)
{
	char	*s;
	int		i;

	i = 0;
	s = va_arg(list, char *);
	if (s == NULL)
	{
		write(1, "(null)", 6);
		(*cont) += 6;
		return ;
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		(*cont)++;
		i++;
	}
}
