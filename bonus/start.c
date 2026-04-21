#include <unistd.h>
#include <stdio.h>
#include "bonus.h"
#include <stdarg.h>

int	ft_print(const char *s, ...)
{
	int	i;
	int	cont;
	va_list	list;
	t_opt	opt;

	i = 0;
	cont = 0;
	va_start(list, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			ft_parser(&s[++i], &opt);
			read_spec(list, &opt, &cont);
			iter_opt(&s[i], &i);
		}
		put_char(s[i], &cont);
		i++;
	}
	va_end(list);
	return (cont);
}

void	iter_opt(const char *s, int *i)
{
	int	n;

	n = 0;
	while (!is_specifier(s[n]))
	{
		n++;
	}
	n++;
	*i += n;
}

void	put_char(const char c, int *cont)
{
	write(1, &c, 1);
	(*cont)++;
}

int	main(void)
{
	ft_print("|%5-c|\n", 'c');
	ft_print("|%-5c| \n", 'c');
	printf("|%-5c| \n", 'c');
	return (0);
}
