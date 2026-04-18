#include <stdio.h>

int	main(void)
{
	char	*s;
	int	n;

	n = 123456789;
	s = "ciao";
	printf("%-8s\n%8s\n", s, s);
	printf("%-5d\n%5d\n", n, n);
	return (0);
}	
