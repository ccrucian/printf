#include <stdio.h>
#include "bonus.h"
#include <stdarg.h>

int	ft_print(const char *s, ...)
{
	va_list	list;
	int	j;
	int	cont;

	j = 0;
	cont = 0;
	list = va_start(list, s);
	while (s[j])
	{
		if (s[j] == '%')
		{
			j++;
			j += ft_parser(&s[j], &cont, list);
		}
		put_char(s[j], &cont);
		i++;
	}
	va_end(list);
	return (cont);
}

int	ft_parser(const char *s, int *cont, va_list list)
{
	int	i;

	i = 0;
	parse_flag();
}

void	parse_flag(int *i)
{
	while (s[*i] == 0 && !(is_digit(s[++(*i)])))
	{
		data.flag = 0;
		(*i)++;
	}
	if (s[*i] == '-')
	{
		data.flag = '-';
		(*i)++;
	}
	if (s[*i] == '0' && s[(*i)++] == '-')
		data.flag = '-';	
}



