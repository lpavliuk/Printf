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

static void	write_symbol_c_uni(wchar_t c_uni, int minus, int zero, t_str *pf)
{
	int i;

	i = 2;
	if (c_uni > 2047 && c_uni <= 65535)
		i = 3;
	else if (c_uni > 65535 && c_uni <= 1114111)
		i = 4;
	if (minus)
	{
		ft_putchar(c_uni);
		while (WIDTH-- > i)
			ft_putchar(' ');
	}
	else
	{
		while (WIDTH-- > i)
		{
			if (zero && !minus)
				ft_putchar('0');
			else
				ft_putchar(' ');
		}
		ft_putchar(c_uni);
	}
}

static void	write_symbol_c(char c, int minus, int zero, t_str *pf)
{
	if (minus)
	{
		ft_putchar(c);
		while (WIDTH-- > 1)
			ft_putchar(' ');
	}
	else
	{
		while (WIDTH-- > 1)
		{
			if (zero && !minus)
				ft_putchar('0');
			else
				ft_putchar(' ');
		}
		ft_putchar(c);
	}
}

static int	work_with_width(wchar_t c_uni, char c, t_str *pf)
{
	int	minus;
	int	zero;
	int i;

	i = 0;
	minus = 0;
	zero = 0;
	while (FLAGS[i] != '\0')
	{
		if (FLAGS[i] == '-')
			minus++;
		else if (FLAGS[i] == '0')
			zero++;
		i++;
	}
	if (TYPE == 'c')
		write_symbol_c(c, minus, zero, pf);
	else if (TYPE == 'C' && MB_CUR_MAX == 4 && c_uni > 255)
		write_symbol_c_uni(c_uni, minus, zero, pf);
	else if (TYPE == 'C' && c_uni > 0 && c_uni <= 255)
		write_symbol_c((int)c_uni, minus, zero, pf);
	else
		return (1);
	return (0);
}

int			write_type_c(va_list ap, t_str *pf)
{
	char	c;
	wchar_t	c_uni;

	if (TYPE == 'C')
		c_uni = va_arg(ap, wchar_t);
	else
		c = va_arg(ap, int);
	if (TYPE == 'C' && ((c_uni > 255 && MB_CUR_MAX == 1) || c_uni < 0))
		return (1);
	if (WIDTH != 0)
		work_with_width(c_uni, c, pf);
	else
	{
		if (TYPE == 'C' && MB_CUR_MAX == 4)
			ft_putchar(c_uni);
		else if (TYPE == 'C' && c_uni > 0 && c_uni <= 255)
			ft_putchar(c_uni);
		else if (TYPE == 'c')
			ft_putchar(c);
		else
			return (1);
	}
	return (0);
}
