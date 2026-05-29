/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrucian <ccrucian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 14:48:21 by ccrucian          #+#    #+#             */
/*   Updated: 2026/05/29 14:48:47 by ccrucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_opt
{
	int	minus;
	int	zero;
	int	width;
	int	point;
	int	prec;
	char	spec;
}	t_opt;

int		ft_printf(const char *s, ...);
int		put_nbr(int n, int *i);
int		put_unsigned(unsigned int n, int *i);
int		put_hex(unsigned long n, int *i);
int		put_hex_up(unsigned long n, int *i);
void	ft_parser(char const *s, t_opt *opt);
void	leggi_specificatore(char const *s, int *i, va_list list, int *cont);
void	read_spec(va_list list, t_opt *opt, int *cont);
void	put_string(va_list list, t_opt *opt, int *cont);
void	open_arg(va_list list, int *cont, int flag, t_opt *opt);
void	char_put(va_list list, int *cont, t_opt *opt);
void	put_ptr(va_list list, int *cont, t_opt *opt);
void	put_pad(int i_pad, int *cont);
void	iter_opt(const char *s, int *i);
void	put_char(const char c, int *cont);
int		is_specifier(char c);
int		is_digit(char c);
void	set_opt(t_opt *opt);
void	parse_flag(char const *s, t_opt *opt);
void	parse_width(char const *s, t_opt *opt);
void	parse_point_precision(const char *s, t_opt *opt);
void	parse_specifier(const char *s, t_opt *opt);

#endif
