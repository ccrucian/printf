#include <stdio.h>
#include "bonus.h"
#include <stdarg.h>

/*int	ft_print(const char *s, ...)
{
	va_list	list;
	int	i;
	int	cont;

	i = 0;
	cont = 0;
	list = va_start(list, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			ft_parser(&s[i]);
		}
		put_char(s[i], &cont);
		i++;
	}
	va_end(list);
	return (cont);
}*/

int	ft_print(const char *s)
{
	int	i;
	int	cont;
	t_opt	opt;

	i = 0;
	cont = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			ft_parser(&s[i], &opt);
		}
		put_char(s[i], &cont);
		i++;
	}
	return (cont);
}
