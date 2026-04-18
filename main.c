#include "printf.h"
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int	c = 8734684;
	unsigned int	n = -1;
	char	s[] = "stai";
	int	cont;

	cont = ft_printf("ptr: %x, str: %s, percent: %%, unsigned int%u?\n", c, s, n);
	printf("cont : %d\n", cont);
	cont = printf("ptr: %x, str: %s, percent: %%, unsigned int%u?\n", c, s, n);
	printf("cont : %d\n", cont);
	return (0);
}
