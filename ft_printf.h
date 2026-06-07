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
# include <unistd.h>

int		ft_printf(const char *s, ...);
int		put_nbr(int n, int *i);
int		put_unsigned(unsigned int n, int *i);
int		put_hex(unsigned long n, int *i);
int		put_hex_up(unsigned long n, int *i);
void	find_specifier(char c, va_list list, int *cont);
void	put_string(va_list list, int *cont);
void	open_arg(va_list list, int *cont, int flag);
void	char_put(va_list list, int *cont);
void	put_ptr(va_list list, int *cont);
void	put_char(const char c, int *cont);
void	put_hex_digits(unsigned long ptr, int *cont);
void	put_hex_p(unsigned long ptr, int *cont);

#endif
