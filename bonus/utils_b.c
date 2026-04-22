#include <stdio.h>
#include <unistd.h>
#include "bonus.h"
#include <stdarg.h>

void	put_str_prec(const char *s, int *cont, int prec)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (prec >= 0 && i >= prec)
	{
		write(1, s, prec);
		(*cont) += prec;
	}
	else
	{
		write(1, s, i);
		(*cont) += i;
	}
}

void	padding(int width, int *cont, int len, int prec)
{
	int	i_pad;

	if (prec == 0)
	{
		i_pad = width;
		put_pad(i_pad, cont);
	}
	else
	{
		i_pad = width - len;
		put_pad(i_pad, cont);
	}
}

void	put_pad(int i_pad, int *cont)
{
	while (i_pad > 0)
	{
		write(1, " ", 1);
		(*cont)++;
		i_pad--;
	}
}

int	ft_strlen(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
