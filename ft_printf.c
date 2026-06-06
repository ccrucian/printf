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
			put_char(s[i], &cont);
		else
		{
			i++;
			find_specifier(s[i], list, &cont);
		}
		i++;
	}
	va_end(list);
	return (cont);
}

void	find_specifier(char c, va_list list, int *cont)
{
	if (c == '%')
		put_char('%', cont);
	else if (c == 'c')
		char_put(list, cont);
	else if (c == 's')
		put_string(list, cont);
	else if (c == 'd' || c == 'i')
		open_arg(list, cont, 1);
	else if (c == 'p')
		put_ptr(list, cont);
	else if (c == 'u')
		open_arg(list, cont, 2);
	else if (c == 'x')
		open_arg(list, cont, 3);
	else if (c == 'X')
		open_arg(list, cont, 4);
}

void	open_arg(va_list list, int *cont, int n)
{
	int	i;

	i = 0;
	if (n == 1)
	{
		n = va_arg(list, int);
		(*cont) += (put_nbr(n, &i));
	}
	if (n == 2)
	{
		n = va_arg(list, unsigned int);
		(*cont) += (put_unsigned(n, &i));
	}
	if (n == 3)
	{
		n = va_arg(list, int);
		(*cont) += (put_hex((unsigned long)(unsigned int)n, &i));
	}
	if (n == 4)
	{
		n = va_arg(list, int);
		(*cont) += (put_hex_up((unsigned long)(unsigned int)n, &i));
	}
}

void	put_char(const char c, int *cont)
{
	write(1, &c, 1);
	(*cont)++;
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
