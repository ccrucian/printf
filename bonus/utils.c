#include "pf_bonus.h"
#include <unistd.h>
#include <stdlib.h>

typedef struct	struct_flags
{
	int	width;
}	type_flags;

void	set_width(type_flags *flags, const char *s, int i)
{
	flags->width = ft_atoi(s, i);
}
