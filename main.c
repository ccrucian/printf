#include "ft_printf.h"

int	main(void)
{
	int	a = 15;
	int	b = 1;
	int	c = 16;
	int i = 0;
	/*printf("\%%c, '0':\n");
	n = ft_printf("%c", '0');
	printf("\n");
	printf("%d\n", n);
	printf("\%%c, c:\n");
	n = ft_printf("%c", c);
	printf("\n");
	printf("%d\n", n);
*/	
	/*printf(" \%%c , '0':\n");
	n = ft_printf(" %c ", '0');
	printf("\n");
	printf("%d\n", n);
	printf(" \%%c , c:\n");
	n = ft_printf(" %c ", c);
	printf("\n");
	printf("%d\n", n);*/
	
	i = printf("ve: %-2p |", &b);
	printf("\n");
	printf("%d", i);
	printf("\n");
	i = ft_printf("my: %-2p |", &b);
	printf("\n");
	printf("%d", i);
	printf("\n");
	
	i = printf("ve: %-2p |", &a);
	printf("\n");
	printf("%d", i);
	printf("\n");
	i = ft_printf("my: %-2p |", &a);
	printf("\n");
	printf("%d", i);
	printf("\n");
	i = printf("ve: %-3p |", &c);
	printf("\n");
	printf("%d", i);
	printf("\n");
	i = ft_printf("my: %-3p |", &c);
	printf("\n");
	printf("%d", i);
	printf("\n");
}
