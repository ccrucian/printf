# ifndef BONUS_H
#define BONUS_H

#include <stdarg.h>
#include <stdio.h>

typedef struct	struct_opt
{
	int	minus;
	int	zero;
	int	width;
	int	point;
	int	prec;
	char	spec;
}	t_opt;

int	ft_print(char const *s, ...);
int	is_specifier(char c);
int	is_digit(char c);
void	read_spec(va_list list, t_opt *opt, int *cont);
void	handle_c(va_list list, t_opt *opt, int *cont);
void	handle_s(va_list list, t_opt *opt, int *cont);
void	parse_specifier(const char *s, t_opt *opt);
void	ft_parser(char const *s, t_opt *opt);
void	parse_point_precision(const char *s, t_opt *opt);
void	parse_width(const char *s, t_opt *opt);
void	parse_flag(const char *s, t_opt *opt);
void	set_opt(t_opt *opt);
void	iter_opt(const char *s, int *i);
void 	put_char(const char c, int *cont);
//	Funzioni in utils_b.c
void	put_str_prec(char const *s, int *cont, int prec); 
void	padding(int width, int *cont, int len, int prec);
void	put_pad(int i_pad, int *cont);
int	ft_strlen(char const *s);

# endif
