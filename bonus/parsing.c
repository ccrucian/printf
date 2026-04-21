#include "bonus.h"
#include <stdarg.h>
#include <stdio.h>

void	parse_specifier(char const *s, t_opt *opt)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (is_specifier(s[i]))
		{
			opt->spec = s[i];
			break;
		}
		i++;
	}
}

void	parse_point_precision(const char *s, t_opt *opt)
{
	int	i;

	i = 0;
	while (s[i] && !is_specifier(s[i]))
	{
		if (s[i] == '.')
		{
			opt->point = 1;
			opt->prec = 0;
			while (s[i] >= '0' && s[i] <= '9')
			{
			      i++;
			      opt->prec = (opt->prec * 10) + (s[i] - '0');
			}
			break;
		}
		i++;
	}
}

void	parse_width(char const *s,t_opt *opt)
{
	int	i;

	i = 0;
	while (s[i] && !is_specifier(s[i]) && s[i] != '.')
	{
		while (s[i] >= '0' && s[i] <= '9')
		{
			opt->width = (opt->width * 10) + (s[i] - '0');
			i++;
		}
		i++;
	}
}

void	parse_flag(char const *s, t_opt *opt)
{
	int	i;

	i = 0;
	while (s[i] && !is_specifier(s[i]))
	{
		if (s[i] == '-')
			opt->minus = 1;
		if (s[i] == '0' && !is_digit(s[i + 1]) && s[i - 1] != '.')
			opt->zero = 1;
		i++;
	}
}

/*int	main(void)
{
	char	t = 'c';

	ft_print("%c\n", t);
	printf("%c\n", t);
	return (0);
}*/
