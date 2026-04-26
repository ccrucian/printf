#include <stdio.h>

int	main(void)
{
	int	i = 0;

	printf("normale\n");
	printf("|%p|\n", &i);
	printf("con width = 5\n");
	printf("|%5p|\n", &i);
	printf("con width = 20\n");
	printf("|%20p|\n", &i);
	printf("con width = 20 e -\n");
	printf("|%-20p|\n", &i);
	/*NON FUNZIONANO PREC e 0 con ptr
	 *
	printf("con width = 20 e 0\n");
	printf("|%0020p|\n", &i);
	printf("con precisione 20\n");
	printf("|%.20p|\n", &i);*/

	return (0);
}
