/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_type_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 12:46:02 by opavliuk          #+#    #+#             */
/*   Updated: 2018/05/02 18:15:22 by opavliuk         ###   ########.fr       */
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

static void	work_with_width(t_str *pf, unsigned char *str, int n)
{
	int i;
	int dot;

	i = -1;
	dot = 0;
	while (FLAGS[++i] != '\0')
	{
		if (FLAGS[i] == '-')
			MINUS++;
		else if (FLAGS[i] == '0')
			ZERO++;
	}
	if (TYPE == 's')
		write_symbol_s(pf, str, n);
}

int			write_type_s(va_list ap, t_str *pf)
{
	int				n;
	unsigned char	*str;

	if (TYPE == 's')
		str = va_arg(ap, unsigned char *);
	n = ft_strlen((const char *)str);
	if (TYPE == 's')
		work_with_width(pf, str, n);
	return (0);
}
