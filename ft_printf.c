/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrucian <ccrucian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 14:48:32 by ccrucian          #+#    #+#             */
/*   Updated: 2026/05/29 15:19:47 by ccrucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	list;
	int		i;
	int		cont;

	cont = 0;
	i = 0;
	va_start(list, s);
	while (s[i])
	{
		if (s[i] != '%')
		{
			put_char(s[i], &cont);
			i++;
		}
		else
			find_specifier(s, &i, list, &cont);
	}
	va_end(list);
	return (cont);
}

void	find_specifier(char const *s, int *i, va_list list, int *cont)
{
	t_opt	opt;

	ft_parser(&s[*i], &opt);
	call_print_functions(list, &opt, cont);
	iter_opt(&s[*i], i);
}

void	ft_parser(char const *s, t_opt *opt)
{
	initialize_options(opt);
	parse_flag(s, opt);
	parse_width(s, opt);
	parse_point_precision(s, opt);
	parse_specifier(s, opt);
}

void	put_char(const char c, int *cont)
{
	write(1, &c, 1);
	(*cont)++;
}

void	iter_opt(const char *s, int *i)
{
	int	n;

	n = 0;
	while (s[n] && !is_specifier(s[n]))
	{
		n++;
	}
	n++;
	*i += n;
}

/*
*Set options to default values 
*/
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

void	parse_flag(char const *s, t_opt *opt)
{
	int	i;

	i = 0;
	while (s[i] && !is_specifier(s[i]))
	{
		if (s[i] == '-')
			opt->minus = 1;
		if (s[i] == '0' && !is_digit(s[i + 1]) && s[i - 1] != '.')
			opt->zero = 1;
		i++;
	}
}

void	parse_width(char const *s, t_opt *opt)
{
	int	i;

	i = 0;
	while (s[i] && !is_specifier(s[i]) && s[i] != '.')
	{
		if (s[i] >= '0' && s[i] <= '9')
			opt->width = (opt->width * 10) + (s[i] - '0');
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

void	parse_specifier(const char *s, t_opt *opt)
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

void	call_print_functions(va_list list, t_opt *opt, int *cont)
{
	if (opt->spec == '%')
		put_char('%', cont);
	if (opt->spec == 'c')
		char_put(list, cont, opt);
	if (opt->spec == 's')
		put_string(list, opt, cont);
	if (opt->spec == 'd' || opt->spec == 'i')
		open_arg(list, cont, 1, opt);
	if (opt->spec == 'p')
		put_ptr(list, cont, opt);
	if (opt->spec == 'u')
		open_arg(list, cont, 2, opt);
	if (opt->spec == 'x')
		open_arg(list, cont, 3, opt);
	if (opt->spec == 'X')
		open_arg(list, cont, 4, opt);
}

/*int	main(void)
{
	char	c;
	int	n;
	
	c = '0';
	printf("\%%c, '0':\n");
	n = ft_printf("%c", '0');
	printf("\n");
	printf("%d\n", n);
	printf("\%%c, c:\n");
	n = ft_printf("%c", c);
	printf("\n");
	printf("%d\n", n);
	
	return (0);
}*/
