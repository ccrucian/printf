/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrucian <ccrucian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 15:00:38 by ccrucian          #+#    #+#             */
/*   Updated: 2026/05/29 15:00:47 by ccrucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_parser(char const *s, t_opt *opt)
{
	initialize_options(opt);
	parse_flag(s, opt);
	parse_width(s, opt);
	parse_point_precision(s, opt);
	parse_specifier(s, opt);
}

void	initialize_options(t_opt *opt)
{
	opt->minus = 0;
	opt->zero = 0;
	opt->width = 0;
	opt->point = 0;
	opt->prec = -1;
	opt->spec = 0;
}

int	is_specifier(char c)
{
	if (c == 'c' || c == 'p' || c == 's' || c == 'd' || c == 'u'
			|| c == 'i' || c == 'x' || c == 'X' || c == '%')
		return (1);
	else
		return (0);
}

int	is_digit(char c)
{
	return (c >= '1' && c <= '9');
}
