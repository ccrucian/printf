/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrucian <ccrucian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 15:15:18 by ccrucian          #+#    #+#             */
/*   Updated: 2026/06/07 15:15:18 by ccrucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	put_pad_zero(int i_pad, int *cont)
{
	while (i_pad > 0)
	{
		write(1, "0", 1);
		(*cont)++;
		i_pad--;
	}
}

void	padding(int width, int *cont, int len, int prec)
{
	int	i_pad;

	if (prec == 0)
	{
		i_pad = width;
		put_pad(i_pad, cont);
	}
	else
	{
		i_pad = width - len;
		put_pad(i_pad, cont);
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
