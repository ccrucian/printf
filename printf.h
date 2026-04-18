#ifndef PRINTF_H

# define PRINTF_H

# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *s, ...);
int		put_nbr(int n, int *i);
int		put_unsigned(unsigned int n, int *i);
int		put_hex(long n, int *i);
int		put_hex_up(long n, int *i);
void	leggi_specificatore(char const *s, int i, va_list list, int *cont);
void	put_string(va_list list, int *cont);
void	open_arg(va_list list, int *cont, int flag);
void	char_put(va_list list, int *cont);
void	put_ptr(va_list list, int *cont);

#endif
