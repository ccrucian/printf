#include "bonus.h"
#include <unistd.h>
#include <stdio.h>

void	ft_parser(char const *s, t_opt *opt)
{
	set_opt(opt);
	parse_flag(s, opt);
	parse_width(s, opt);
	parse_point_precision(s, opt);
	parse_specifier(s, opt);
}

void	set_opt(t_opt *opt)
{
	opt->minus = 0;
	opt->zero = 0;
	opt->width = 0;
	opt->point = 0;
	opt->prec = -1;
	opt->spec = 0;
}

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
	return (c >= 1 && c <= 9);
}
