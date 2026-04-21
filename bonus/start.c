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
	printf("len maggiore di width ( width < len:\n");
	ft_print(">|%2s|\n", "ciao");
	printf("-|%2s|\n", "ciao");

	printf("Width=6:\n");
	ft_print(">|%6s|\n", "ciao");
	printf("-|%6s|\n", "ciao");

	printf("Width=-6:\n");
	ft_print(">|%-6s|\n", "ciao");
	printf("-|%-6s|\n", "ciao");

	printf("Solo point.:\n");
	ft_print("+|%.s|\n", "ciao");
	printf("-|%.s|\n", "ciao");

	printf("Prec: .2:\n");
	ft_print(">|%.2s|\n", "ciao");
	printf("-|%.2s|\n", "ciao");

	printf("Width+prec: 5.2:\n");
	ft_print("+|%5.2s|\n", "ciao");
	printf("-|%5.2s|\n", "ciao");

	printf("Width+pointsolo: 5.:\n");
	ft_print("+|%5.s|\n", "ciao");
	printf("-|%5.s|\n", "ciao");

	printf("Width minore len+prec: 3.2:\n");
	ft_print("+|%3.2s|\n", "ciao");
	printf("-|%3.2s|\n", "ciao");



	return (0);
}
