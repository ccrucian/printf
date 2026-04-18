#include <stdio.h>

int	main(void)
{
	float	f = 3.45673;

	printf("prova con - %-010.3f ok\n", f);
	printf("prova sen - %0-10.3f ok\n", f);
	return (0);
}
