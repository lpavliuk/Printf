/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 15:37:14 by opavliuk          #+#    #+#             */
/*   Updated: 2018/04/27 19:33:17 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void			check_type(va_list ap, t_str *pf)
{
	if (pf->type == 'c' || pf->type == 'C')
		write_type_c(ap, pf);
	// else if (pf->type == 'd' || pf->type == 'D')
	// 	write_type_d(format, pf);
	// else if (pf->type == 'i')
	// 	write_type_i(format, pf);
	// else if (pf->type == 'o' || pf->type == 'O')
	// 	write_type_o(format, pf);
	// else if (pf->type == 'x' || pf->type == 'X')
	// 	write_type_x(format, pf);
	// else if (pf->type == 'u' || pf->type == 'U')
	// 	write_type_u(format, pf);
	// else if (pf->type == 'p')
	// 	write_type_p(format, pf);
}

static void		clean_pf(t_str *pf)
{
	WIDTH = 0;
	PREC = 0;
	TYPE = 0;
	ft_bzero(MODF, 3);
	ft_bzero(FLAGS, 4);
}

int				ft_printf(const char *format, ...)
{
	t_str	*pf;
	int		i;
	va_list	ap;

	i = 0;
	pf = malloc(sizeof(t_str));
	va_start(ap, format);	
	while (format && *format != '\0')
	{
		clean_pf(pf);
		if (*format == '%' && *(format + 1) != '%')
		{
			if ((i = check_percent(format, pf)) == 0)
				format++;
			else
				format += i;
			check_type(ap, pf);
			continue ;
		}
		else if (*format == '%' && *(format + 1) == '%')
			format++;
		ft_putchar(*format);
		format++;
	}
	va_end (ap);
	if (i != 0)
	{
		printf("flags: %s\n", FLAGS);
		printf("width: %d\n", WIDTH);
		printf("precision: %d\n", PREC);
		printf("modifier: %s\n", MODF);
		printf("type: %c\n", TYPE);
		printf("Well done!\n");
	}
	else
		printf("Not valid percent or absent!\n");
	return (0);
}