/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_type_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 12:46:02 by opavliuk          #+#    #+#             */
/*   Updated: 2018/05/04 12:29:45 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	write_symbol_s(t_str *pf, unsigned char *str, int n)
{
	if ((!DOT && !PREC) || n <= PREC)
		PREC = n;
	if (MINUS)
	{
		if (DOT && n >= PREC)
			ft_cpy_to_buffer(pf, str, PREC);
		else
			ft_cpy_to_buffer(pf, str, n);
		while (WIDTH-- > PREC)
			write_to_buffer(pf, ' ');
	}
	else
	{
		while (WIDTH-- > PREC)
		{
			if (ZERO && !MINUS)
				write_to_buffer(pf, '0');
			else
				write_to_buffer(pf, ' ');
		}
		if (DOT && n >= PREC)
			ft_cpy_to_buffer(pf, str, PREC);
		else
			ft_cpy_to_buffer(pf, str, n);
	}
}

static int	check_unicode_massive(wchar_t *str_uni)
{
	int i;
	int n;

	n = 0;
	i = 0;
	while (str_uni[i] != '\0')
	{
		if (str_uni[i] > 127 && str_uni[i] <= 2047)
			n++;
		else if (str_uni[i] > 2047 && str_uni[i] <= 65535)
			n++;
		else if (str_uni[i] > 65535 && str_uni[i] <= 1114111)
			n++;
		i++;
	}
	return (n);
}

int			write_type_s(va_list ap, t_str *pf)
{
	int				n;
	unsigned char	*str;
	wchar_t			*str_uni;

	if (TYPE == 'S' || (TYPE == 's' && MODF[0] == 'l'))
	{
		str_uni = va_arg(ap, wchar_t *);
		n = ft_strlen((const char *)str_uni);
	}
	else if (TYPE == 's')
	{
		str = va_arg(ap, unsigned char *);
		n = ft_strlen((const char *)str);
	}
	if ((TYPE == 'S' || (TYPE == 's' && MODF[0] == 'l')) &&
		((MB_CUR_MAX == 1 && check_unicode_massive(str_uni))))
		return (1);
	if (TYPE == 'S' || (TYPE == 's' && MODF[0] == 'l'))
		write_symbol_s_uni(pf, str_uni, n);
	else if (TYPE == 's')
		write_symbol_s(pf, str, n);
	return (0);
}
