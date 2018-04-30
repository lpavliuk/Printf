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

static int		check_type(va_list ap, t_str *pf)
{
	int i;

	i = 0;
	if (TYPE == 'c' || TYPE == 'C')
		i = write_type_c(ap, pf);
	// else if (TYPE == 's' || TYPE == 'S')
	// 	i = write_type_s(format, pf);
	// else if (pf->type == 'd' || pf->type == 'D')
	// 	i = write_type_d(format, pf);
	// else if (pf->type == 'i')
	// 	i = write_type_i(format, pf);
	// else if (pf->type == 'o' || pf->type == 'O')
	// 	i = write_type_o(format, pf);
	// else if (pf->type == 'x' || pf->type == 'X')
	// 	i = write_type_x(format, pf);
	// else if (pf->type == 'u' || pf->type == 'U')
	// 	i = write_type_u(format, pf);
	// else if (pf->type == 'p')
	// 	i = write_type_p(format, pf);
	if (i == 1)
		return (1);
	return (0);
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
	int		n;
	va_list	ap;

	i = 0;
	pf = malloc(sizeof(t_str));
	va_start(ap, format);	
	while (format && *format != '\0')
	{
		if (*format == '%' && *(format + 1) != '%')
		{
			clean_pf(pf);
			if ((i = check_percent(format, pf)) == 0)
				format++;
			else
				format += i;
			if (check_type(ap, pf))
				return (-1);
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