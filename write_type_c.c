/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_type_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 18:12:06 by opavliuk          #+#    #+#             */
/*   Updated: 2018/04/27 18:38:27 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	write_symbol(char c, int minus, int zero, t_str *pf)
{
	if (minus)
	{
		ft_putchar(c);
		while (WIDTH > 1)
		{
			ft_putchar(' ');
			WIDTH--;
		}
	}
	else
	{
		while (WIDTH > 1)
		{
			if (zero && !minus)
				ft_putchar('0');
			else
				ft_putchar(' ');
			WIDTH--;
		}
		ft_putchar(c);
	}
}

void			write_type_c(va_list ap, t_str *pf)
{
	int		i;
	char	c;
	int		minus;
	int		zero;

	i = 0;
	minus = 0;
	zero = 0;
	c = va_arg (ap, int);
	if (WIDTH != 0)
	{
		while (FLAGS[i] != '\0')
		{
			if (FLAGS[i] == '-')
				minus++;
			else if (FLAGS[i] == '0')
				zero++;
			i++;
		}
		write_symbol(c, minus, zero, pf);
	}
	else
	{
		ft_putchar(c);
	}
}