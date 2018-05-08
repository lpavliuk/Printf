/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_type_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 12:23:05 by opavliuk          #+#    #+#             */
/*   Updated: 2018/05/08 18:40:48 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	write_to_buffer_un_digital(uintmax_t un_i, short int n, t_str *pf)
{
	if (PREC && PREC > WIDTH)
		WIDTH = PREC;
	if (WIDTH < 0)
	{
		ft_unputnbr_base(un_i, 10, 0, pf);
		while (WIDTH++ < (n * (-1)))
			write_to_buffer(pf, ' ');
	}
	else
	{
		while (WIDTH-- > n)
		{
			if (WIDTH < PREC || (ZERO && !MINUS))
				write_to_buffer(pf, '0');
			else
				write_to_buffer(pf, ' ');
		}
		ft_unputnbr_base(un_i, 10, 0, pf);
	}
}

int			write_type_u(va_list ap, t_str *pf)
{
	short int	n;
	uintmax_t	un_i;

	if ((MODF[0] == 'l' && MODF[1] == '\0') || TYPE == 'U' || TYPE == 'O')
		un_i = va_arg(ap, unsigned long int);
	else if (MODF[0] == 'l' && MODF[1] == 'l')
		un_i = va_arg(ap, unsigned long long int);
	else if (MODF[0] == 'h' && MODF[1] == '\0')
		un_i = (unsigned short int)va_arg(ap, unsigned int);
	else if (MODF[0] == 'h' && MODF[1] == 'h')
		un_i = (unsigned char)va_arg(ap, unsigned int);
	else if (MODF[0] == 'z' && MODF[1] == '\0')
		un_i = va_arg(ap, size_t);
	else if ((MODF[0] == 'j' && MODF[1] == '\0') || TYPE == 'p')
		un_i = va_arg(ap, uintmax_t);
	else
		un_i = va_arg(ap, unsigned int);
	n = ft_count(un_i, 10);
	if (DOT || PREC)
		ZERO = 0;
	write_to_buffer_un_digital(un_i, n, pf);
	return (0);
}
