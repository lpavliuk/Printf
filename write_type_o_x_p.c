/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_type_o_x_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 12:42:10 by opavliuk          #+#    #+#             */
/*   Updated: 2018/05/07 14:28:41 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_hash(t_str *pf)
{
	if ((TYPE == 'o' || TYPE == 'O') && HASH)
		BUFFER[N++] = '0';
	else if (TYPE == 'p' || ((TYPE == 'x' || TYPE == 'X') && HASH))
	{
		BUFFER[N++] = '0';
		if (TYPE == 'x' || TYPE == 'p')
			BUFFER[N++] = 'x';
		else
			BUFFER[N++] = 'X';
	}
}

static void	to_buffer(uintmax_t un_i, t_str *pf)
{
	if (TYPE == 'o' || TYPE == 'O')
		ft_unputnbr_base(un_i, 8, 0, pf);
	else if (TYPE == 'x' || TYPE == 'p')
		ft_unputnbr_base(un_i, 16, 0, pf);
	else
		ft_unputnbr_base(un_i, 16, 1, pf);
}

static void	write_to_buffer_un_digital(uintmax_t un_i, short int n, t_str *pf)
{
	if (WIDTH < 0)
	{
		check_hash(pf);
		to_buffer(un_i, pf);
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
		check_hash(pf);
		to_buffer(un_i, pf);
	}
}

int			write_type_o_x_p(va_list ap, t_str *pf)
{
	short int	n;
	uintmax_t	un_i;

	un_i = check_modifier_un_int(ap, pf);
	if (TYPE == 'o' || TYPE == 'O')
		n = ft_count(un_i, 8);
	else
		n = ft_count(un_i, 16);
	if ((TYPE == 'o' || TYPE == 'O') && HASH)
		n++;
	else if (TYPE == 'p' || ((TYPE == 'x' || TYPE == 'X') && HASH))
		n += 2;
	if (DOT || PREC)
		ZERO = 0;
	if (PREC > WIDTH)
		WIDTH = PREC;
	write_to_buffer_un_digital(un_i, n, pf);
	return (0);
}
