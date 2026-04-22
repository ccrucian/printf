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
	int	cont1;
	int	cont2;

	printf("len maggiore di width ( width < len:\n");
	cont1 = ft_print(">|%2s|\n", "ciao");
	cont2 = printf("-|%2s|\n", "ciao");
	printf("%d\n", cont1);
	printf("%d\n\n", cont2);
	
	printf("Width=6:\n");
	cont1 = ft_print(">|%6s|\n", "ciao");
	cont2 = printf("-|%6s|\n", "ciao");
	printf("%d\n", cont1);
	printf("%d\n\n", cont2);

	printf("Width=-6:\n");
	cont1 = ft_print(">|%-6s|\n", "ciao");
	cont2 = printf("-|%-6s|\n", "ciao");
	printf("%d\n", cont1);
	printf("%d\n\n", cont2);

	printf("Solo point.:\n");
	cont1 = ft_print("+|%.s|\n", "ciao");
	cont2 = printf("-|%.s|\n", "ciao");
	printf("%d\n", cont1);
	printf("%d\n\n", cont2);

	printf("Prec: .2:\n");
	cont1 = ft_print(">|%.2s|\n", "ciao");
	cont2 = printf("-|%.2s|\n", "ciao");
	printf("%d\n", cont1);
	printf("%d\n\n", cont2);

	printf("Width+prec: 5.2:\n");
	cont1 = ft_print("+|%5.2s|\n", "ciao");
	cont2 = printf("-|%5.2s|\n", "ciao");
	printf("%d\n", cont1);
	printf("%d\n\n", cont2);

	printf("Width+pointsolo con -: -5.:\n");
	cont1 = ft_print("+|%-5.s|\n", "ciao");
	cont2 = printf("-|%-5.s|\n", "ciao");
	printf("%d\n", cont1);
	printf("%d\n\n", cont2);

	printf("Width minore len+prec: 3.2:\n");
	cont1 = ft_print("+|%3.2s|\n", "ciao");
	cont2 = printf("-|%3.2s|\n", "ciao");
	printf("%d\n", cont1);
	printf("%d\n\n", cont2);

	printf("Width minore len+prec e prec > len: -3.6:\n");
	cont1 = ft_print("+|%-3.6s|\n", "ciao");
	cont2 = printf("-|%-3.6s|\n", "ciao");
	printf("%d\n", cont1);
	printf("%d\n\n", cont2);

	printf("Width maggiore len+prec e prec > len: -6.5\n");
	cont1 = ft_print("+|%-6.5s|\n", "ciao");
	cont2 = printf("-|%-6.5s|\n", "ciao");
	printf("%d\n", cont1);
	printf("%d\n\n", cont2);

	return (0);
}
