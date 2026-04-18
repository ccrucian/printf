#include "bonus.h"
#include <unistd.h>
#include <stdio.h>

void	put_char(const char c, int *cont)
{
	write(1, &c, 1);
	(*cont)++;
}

void	set_opt(t_opt *opt)
{
	opt->minus = 0;
//	printf("%d\n", opt->minus);
	opt->zero = 0;
//	printf("%d\n", opt->zero);
	opt->width = 0;
//	printf("%d\n", opt->width);
	opt->point = 0;
//	printf("%d\n", opt->point);
	opt->prec = 0;
//	printf("%d\n", opt->precision);
	opt->specifier = 0;
//	printf("%d\n", opt->specifier);
}
