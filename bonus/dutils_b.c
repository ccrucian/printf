#include <unistd.h>
#include "bonus.h"
#include <stdio.h>

int	count_digits(int n)
{
	int	count;

	count = 1;
	if (n < 0)
		count++;
	while (n / 10 != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	sign_(int n)
{
	return (n < 0);
}

void	check_put_sign_set_positive(int *n, int *cont)
{
	if (*n < 0)
	{
		put_char('-', cont);
		(*n) *= -1;
	}
}

void	put_nbr(int n, int *cont, int zero)
{
	char	c;
	long	nb;

	nb = n;
	if (nb < 0)
	{
		put_char('-', cont);
		nb *= -1;
	}
	if (zero > 0)
		put_pad_zero(zero, cont);
	if (nb == 2147483648)
	{
		write(1, "2147483648", 10);
		(*cont) += 10;
		return ;
	}
	if (nb >= 10)
		put_nbr(nb / 10, cont, 0);
	(*cont)++;
	c = (nb % 10) + '0';
	write(1, &c, 1);
}

void	put_pad_zero(int i_pad, int *cont)
{
	while (i_pad > 0)
	{
		write(1, "0", 1);
		(*cont)++;
		i_pad--;
	}
}

/*int	main(void)
{
	ft_printf("+|%10.5d|\n", 23);
	printf("-|%10.5d|\n", 23);
	
	ft_printf("+|%-10.5d|\n", 23);
	printf("-|%-10.5d|\n", 23);
		
	ft_printf("+|%.5d|\n", 23);
	printf("-|%.5d|\n", 23);
	
	ft_printf("+|%3.5d|\n", -23);
	printf("-|%3.5d|\n", -23);
	
	ft_printf("+|%3.4d|\n", 0);
	printf("-|%3.4d|\n", 0);

	ft_printf("+|%010d|\n", -23);
	printf("-|%010d|\n", -23);

	ft_printf("+|%05d|\n", -23);
	printf("-|%05d|\n", -23);


	return (0);
}*/
