/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrucian <ccrucian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 15:14:40 by ccrucian          #+#    #+#             */
/*   Updated: 2026/06/07 15:14:41 by ccrucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	call_print_functions(va_list list, t_opt *opt, int *cont)
{
	if (opt->spec == '%')
		put_char('%', cont);
	if (opt->spec == 'c')
		handle_c(va_arg(list, int), opt, cont);
	if (opt->spec == 's')
		handle_s(va_arg(list, char const *), opt, cont);
	if (opt->spec == 'd' || opt->spec == 'i')
		handle_d_i(va_arg(list, int), opt, cont);
	if (opt->spec == 'p')
		handle_p(va_arg(list, unsigned long), opt, cont);
	if (opt->spec == 'x' || opt->spec == 'X')
		handle_xx(va_arg(list, unsigned int), opt, cont);
	if (opt->spec == 'u')
		handle_u(va_arg(list, unsigned int), opt, cont);
}
