# ifndef BONUS_H
#define BONUS_H

typedef struct	struct_opt
{
	int	minus;
	int	zero;
	int	width;
	int	point;
	int	prec;
	char	specifier;
}	t_opt;

int	ft_print(char const *s);
int	is_specifier(char c);
void	parse_specifier(const char *s, t_opt *opt);
void	ft_parser(char const *s, t_opt *opt);
void	parse_point_precision(const char *s, t_opt *opt);
void	parse_width(const char *s, t_opt *opt);
void	parse_flag(const char *s, t_opt *opt);
void	set_opt(t_opt *opt);
void 	put_char(const char c, int *cont);

# endif
