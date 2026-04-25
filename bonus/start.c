#include <unistd.h>
#include <stdio.h>
#include "bonus.h"
#include <stdarg.h>

int	ft_printf(const char *s, ...)
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
		if (s[i] != '%')
		{
			put_char(s[i], &cont);
			i++;
		}
		else
		{
			ft_parser(&s[++i], &opt);
			read_spec(list, &opt, &cont);
			iter_opt(&s[i], &i);
		}
	}
	va_end(list);
	return (cont);
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

void	put_char(const char c, int *cont)
{
	write(1, &c, 1);
	(*cont)++;
}

/*int	main(void)
{
	int	cont1;
	int	cont2;

	cont1 = ft_printf("%7.3s\n", "ciao");
	cont2 = printf("%7.3s\n", "ciao");
	printf("%d\n", cont1);
	printf("%d\n", cont2);
	
	return (0);
}*/
