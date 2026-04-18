#include "bonus.h"
#include <stdarg.h>
#include <stdio.h>

int	is_specifier(char c)
{
	if (c == 'c' || c == 'p' || c == 's' || c == 'd' || c == 'u'
			|| c == 'i' || c == 'x' || c == 'X')
		return (1);
	else
		return (0);
}

int	is_digit(char c)
{
	if (c >= 1 && c <= 9)
		return (1);
	else
		return (0);
}

void	ft_parser(char const *s, t_opt *opt)
{
	set_opt(opt);
	parse_flag(s, opt);
	parse_width(s, opt);
	parse_point_precision(s, opt);
	parse_specifier(s, opt);
	printf("%d\n", opt->zero);
}

void	parse_specifier(char const *s, t_opt *opt)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (is_specifier(s[i]))
		{
			opt->specifier = s[i];
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
			i++;
			while (s[i] >= '0' && s[i] <= '9')
			{
			      opt->prec = (opt->prec * 10) + (s[i] - '0');
			      i++;
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

int	main(void)
{
	char	*s;
	char	*t = "%05d\n";

	s = "0001d\n";
	ft_print(s);
	printf("----------------\n");
	ft_print(t);
	return (0);
}
