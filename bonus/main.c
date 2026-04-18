#include "bonus.h"
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	int	n = 3;
	char	*h = "ciao";
	printf("%05d\n", n);
//	printf("05   : %05s\n", h);
	printf("5.2  : %5.2s\n", h);
	printf("-5   : %-5s\n", h);
	printf("-    : %-s\n", h);
	printf("10   : %10s\n", h);
	printf("-5.2 : %-5.2s\n", h);
	printf("-.1  : %-.1s\n", h);
}
