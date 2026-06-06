/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrucian <ccrucian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 15:00:29 by ccrucian          #+#    #+#             */
/*   Updated: 2026/05/29 15:00:35 by ccrucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	parse_specifier(char const *s, t_opt *opt)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (is_specifier(s[i]))
		{
			opt->spec = s[i];
			break;
		}
		i++;
	}
}

void	parse_point_precision(const char *s, t_opt *opt)
{
	int	i;

	i = 0;
	while (s[i] && !is_specifier(s[i]))
	{
		if (s[i] == '.')
		{
			opt->point = 1;
			opt->prec = 0;
			i++;
			while (s[i] >= '0' && s[i] <= '9')
			{
			      opt->prec = (opt->prec * 10) + (s[i] - '0');
			      i++;
			}
			break;
		}
		i++;
	}
}

void	parse_width(char const *s,t_opt *opt)
{
	int	i;

	i = 0;
	while (s[i] == '-' || s[i] == '0')
		i++;
	while (s[i] >= '0' && s[i] <= '9' && s[i] != '.')
	{
		opt->width = (opt->width * 10) + (s[i] - '0');
		i++;
	}
}

void	parse_flag(char const *s, t_opt *opt)
{
	int	i;

	i = 0;
	while (s[i] == '-' || s[i] == '0')
	{
		if (s[i] == '-')
			opt->minus = 1;
		if (s[i] == '0')
			opt->zero = 1;
		i++;
	}
	if (opt->minus == 1)
		opt->zero = 0;
}

/*int	main(void)
{
	char	t = 'c';

	ft_printf("%c\n", t);
	printf("%c\n", t);
	return (0);
*/
