# ifndef BONUS_H
#define BONUS_H

typedef struct	struct_opt
{
	int	minus;
	int	zero;
	int	width;
	int	point;
	int	precision;
	char	specifier;
}	t_opt;

void	set_opt(t_opt *opt);
void 	put_char(const char c, int *cont);

# endif
