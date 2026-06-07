/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_b_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrucian <ccrucian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 14:59:31 by ccrucian          #+#    #+#             */
/*   Updated: 2026/05/29 14:59:43 by ccrucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	put_str_prec(const char *s, int *cont, int prec)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (prec >= 0 && i >= prec)
	{
		write(1, s, prec);
		(*cont) += prec;
	}
	else
	{
		write(1, s, i);
		(*cont) += i;
	}
}

int	ft_strlen(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
