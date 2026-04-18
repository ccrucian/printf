#include "printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

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
			leggi_specificatore(s, i++, list, &cont);
			i++;
		}
		write(1, &s[i], 1);
		cont++;
		i++;
	}
	va_end(list);
	return (cont);
}

void	leggi_specificatore(char const *s, int i, va_list list, int *cont)
{
	i++;
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
	int	c = 8734684;
	unsigned int	n = -1;
	char	s[] = "stai";
	int	cont;

	cont = ft_printf("ciao %X come %s oppure %%, %u?", c, s, n);
	write(1, "\n", 1);
	printf("cont : %d\n", cont);
	cont = printf("ciao %x come %s oppure %%, %u?\n", c, s, n);
	printf("cont : %d\n", cont);
	return (0);
}*/
