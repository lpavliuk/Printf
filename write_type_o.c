/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_type_o.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 12:25:37 by opavliuk          #+#    #+#             */
/*   Updated: 2018/05/08 20:05:41 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	check_modifier_un_int(va_list ap, t_str *pf)
{
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
	else if (MODF[0] == 'j' && MODF[1] == '\0')
		un_i = va_arg(ap, uintmax_t);
	else
		un_i = va_arg(ap, unsigned int);
	return (un_i);
}

static void	write_to(uintmax_t un_i, t_str *pf, char width, short int *n)
{
	if (!width)
	{
		if (HASH || PREC > (*n))
		{
			BUFFER[N++] = '0';
			(*n)++;
		}
		if (DOT && PREC == 0 && un_i == 0 && !HASH)
			return ;
		else
			ft_unputnbr_base(un_i, 8, 0, pf);
	}
	else
	{
		if (PREC < (*n) && !ZERO && HASH)
			BUFFER[N++] = '0';
		if (DOT && PREC == 0 && un_i == 0)
			return ;
		else
			ft_unputnbr_base(un_i, 8, 0, pf);
	}
}

static void	write_to_buffer_un_digital(uintmax_t un_i, short int n, t_str *pf)
{
	if (WIDTH && !HASH && DOT && PREC == 0 && un_i == 0)
		n = 0;
	if (WIDTH < 0)
	{
		write_to(un_i, pf, 0, &n);
		ft_putendl(ft_itoa(n));
		ft_putendl(ft_itoa(WIDTH));
		while (WIDTH++ < (n * (-1)))
			write_to_buffer(pf, ' ');
	}
	else
	{
		if (((PREC >= n && WIDTH <= PREC) || ZERO) && HASH && un_i > 0)
			BUFFER[N++] = '0';
		while (WIDTH-- > n)
		{
			if ((WIDTH == PREC) && (PREC > n) && HASH && un_i > 0)
				BUFFER[N++] = '0';
			else if (WIDTH < PREC || (ZERO && !MINUS))
				write_to_buffer(pf, '0');
			else
				write_to_buffer(pf, ' ');
		}
		write_to(un_i, pf, 1, &n);
	}
}

int			write_type_o(va_list ap, t_str *pf)
{
	short int	n;
	uintmax_t	un_i;

	un_i = check_modifier_un_int(ap, pf);
	n = ft_count(un_i, 8);
	if (DOT || PREC)
		ZERO = 0;
	if (PREC && PREC > WIDTH && ++ZERO && WIDTH > 0)
	{
		n -= 2;
		WIDTH = PREC;
	}
	if (PREC && (PREC > n) && WIDTH > 0)
		WIDTH--;
	if (HASH && PREC < n)
		n++;
	if (PREC && WIDTH < PREC && WIDTH > 0)
		n++;
	write_to_buffer_un_digital(un_i, n, pf);
	return (0);
}