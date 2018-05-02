/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_type_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 12:46:02 by opavliuk          #+#    #+#             */
/*   Updated: 2018/05/02 14:21:06 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void check_precision(t_str pf, unsigned char str, n)
{
	if (DOT)
	{
		
	}
}

static void	write_symbol_s(t_str *pf, unsigned char *str, int n)
{
	if (MINUS)
	{
		ft_cpy_to_buffer(pf, str);
		while (WIDTH-- > n)
			write_to_buffer(pf, ' ');
	}
	else
	{
		while (WIDTH-- > n)
		{
			if (ZERO && !MINUS)
				write_to_buffer(pf, '0');
			else
				write_to_buffer(pf, ' ');
		}
		ft_cpy_to_buffer(pf, str);
	}
}

static void	work_with_width(t_str *pf, unsigned char *str)
{
	int n;
	int i;
	int dot;

	i = -1;
	dot = 0;
	n = ft_strlen((const char *)str);
	while (FLAGS[++i] != '\0')
	{
		if (FLAGS[i] == '-')
			MINUS++;
		else if (FLAGS[i] == '0')
			ZERO++;
	}
	check_precision(pf, str, n);
	if (TYPE == 's')
		write_symbol_s(pf, str, n);
}

int			write_type_s(va_list ap, t_str *pf)
{
	unsigned char *str;

	if (TYPE == 's')
		str = va_arg(ap, unsigned char *);
	if (WIDTH != 0)
		work_with_width(pf, str);
	else
	{
		check_precision(pf, str, n);
		if (TYPE == 's')
		ft_cpy_to_buffer(pf, str);
	}
	return (0);
}
