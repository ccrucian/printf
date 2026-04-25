#ifndef BONUS_H
# define BONUS_H

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

int	ft_printf(char const *s, ...);
void	read_spec(va_list list, t_opt *opt, int *cont);
void	handle_percent(t_opt *opt, int *cont);
void	handle_c(int c, t_opt *opt, int *cont);
void	handle_s(char const *s, t_opt *opt, int *cont);
void	handle_d_i(int arg, t_opt *opt, int *cont);
void	iter_opt(const char *s, int *i);
void 	put_char(const char c, int *cont);
int	sign_(int n);
void	set_len_di_zerospec(int *len, int *zero, int n, t_opt *opt);
void	check_put_sign_set_positive(int *n, int *cont);

//	parser.c
void	ft_parser(char const *s, t_opt *opt);
void	set_opt(t_opt *opt);
int	is_specifier(char c);
int	is_digit(char c);


//	parsing.c
void	parse_specifier(const char *s, t_opt *opt);
void	parse_point_precision(const char *s, t_opt *opt);
void	parse_width(const char *s, t_opt *opt);
void	parse_flag(const char *s, t_opt *opt);

//	butils_b.c
int	count_digits(int n);
void	put_nbr(int n, int *cont, int zero);
void	put_pad_zero(int i_pad, int *cont);

//	utils_b.c
void	put_str_prec(char const *s, int *cont, int prec); 
void	padding(int width, int *cont, int len, int prec);
void	put_pad(int i_pad, int *cont);
int	ft_strlen(char const *s);

#endif
