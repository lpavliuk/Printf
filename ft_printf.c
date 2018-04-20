/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 15:37:14 by opavliuk          #+#    #+#             */
/*   Updated: 2018/04/20 15:55:36 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	write_type_c(const char *format, t_str pf)
{
	
}

void	check_type(const char *format, t_str pf)
{
	if (pf->type == 'c' || pf->type == 'C')
		write_type_c(format, pf);
	else if (pf->type == 'd' || pf->type == 'D')
		write_type_d(format, pf);
	else if (pf->type == 'i')
		write_type_i(format, pf);
	else if (pf->type == 'o' || pf->type == 'O')
		write_type_o(format, pf);
	else if (pf->type == 'x' || pf->type == 'X')
		write_type_x(format, pf);
	else if (pf->type == 'u' || pf->type == 'U')
		write_type_u(format, pf);
	else if (pf->type == 'p')
		write_type_p(format, pf);
}

int		ft_printf(const char *format, ...)
{
	t_str	*pf;
	int		i;
	va_list	ap;

	i = 0;
	pf = malloc(sizeof(t_str));
	pf->width = 0;
	pf->precision = 0;
	ft_bzero(pf->modifier, 3);
	ft_bzero(pf->flags, 4);
	va_start(ap, format);
	while (format && *format != '\0')
	{
		if (*format == '%' && *(format + 1) != '%')
		{
			if ((i = check_percent(format, pf)) == 0)
				format++;
			else
				format += i;
			check_type(format, pf);
		}
		else if (*format == '%' && *(format + 1) == '%')
			format++;
		ft_putchar(*format);
		format++;
	}
	va_end (ap);
	if (i != 0)
	{
		printf("flags: %s\n", pf->flags);
		printf("width: %d\n", pf->width);
		printf("precision: %d\n", pf->precision);
		printf("modifier: %s\n", pf->modifier);
		printf("type: %c\n", pf->type);
		printf("Well done!\n");
	}
	else
		printf("Not valid percent or absent!\n");
	return (0);
}