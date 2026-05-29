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
		if (s[i] == '%')
		{
			i++;
			leggi_specificatore(s, i, list, &cont);
			i++;
		}
		else
		{
			write(1, &s[i], 1);
			cont++;
			i++;
		}
	}
	va_end(list);
	return (cont);
}

void	leggi_specificatore(char const *s, int i, va_list list, int *cont)
{
	if (s[i] == 'c')
		char_put(list, cont);
	if (s[i] == 's')
		put_string(list, cont);
	if (s[i] == 'p')
		put_ptr(list, cont);
	if (s[i] == 'd' || s[i] == 'i')
		open_arg(list, cont, 1);
	if (s[i] == 'u')
		open_arg(list, cont, 2);
	if (s[i] == 'x')
		open_arg(list, cont, 3);
	if (s[i] == 'X')
		open_arg(list, cont, 4);
	if (s[i] == '%')
	{
		write(1, &s[i], 1);
		(*cont)++;
	}
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
