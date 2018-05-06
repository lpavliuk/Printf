/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 15:37:14 by opavliuk          #+#    #+#             */
/*   Updated: 2018/05/06 19:29:22 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		check_type(va_list ap, t_str *pf)
{
	int i;

	i = 0;
	if (TYPE == 's' || TYPE == 'S')
	    i = write_type_s(ap, pf);
	else if (TYPE == 'd' || TYPE == 'D' || TYPE == 'i'
		|| pf->type == 'u' || pf->type == 'U'
		|| pf->type == 'o' || pf->type == 'O')
	 	i = write_type_digital(ap, pf);
	// else if (pf->type == 'x' || pf->type == 'X')
	// 	i = write_type_x(ap, pf);
	// else if (pf->type == 'p')
	// 	i = write_type_p(ap, pf);
	else
	{
		DOT = 0;
		i = write_type_c(ap, pf);
	}
	if (i == 1)
		return (1);
	return (0);
}

void			check_buffer(t_str *pf, int turn_off, int clean_pf)
{
	if (turn_off || N > 1023)
	{
		ft_putstr(BUFFER);
		pf->symbols += ft_strlen(BUFFER);
		ft_bzero(BUFFER, 1024);
		N = 0;
	}
	if (clean_pf)
	{
		WIDTH = 0;
		PREC = 0;
		TYPE = 0;
		SPACE = 0;
		HASH = 0;
		MINUS = 0;
		ZERO = 0;
		DOT = 0;
		N_UNI = 0;
		ft_bzero(MODF, 3);
	}
}

int				ft_printf(const char *format, ...)
{
	t_str	*pf;
	int		i;
	int		n;
	va_list	ap;

	i = 0;
	n = 0;
	pf = malloc(sizeof(t_str));
	va_start(ap, format);
	ft_bzero(BUFFER, 1024);
	N = 0;
	pf->symbols = 0;
	while (format && *format != '\0')
	{
		check_buffer(pf, 0, 1);
		if (*format == '%' && *(format + 1) != '%')
		{
			if ((i = check_percent(ap, format, pf)))
				format += i;
			if (check_type(ap, pf))
			{
				ft_bzero(BUFFER, 1024);
				return (-1);
			}
			check_buffer(pf, 1, 1);
			if (i == 0)
				format++;
			continue ;
		}
		else if (*format == '%' && *(format + 1) == '%')
			format++;
		BUFFER[N] = *format;
		format++;
		N++;
	}
	check_buffer(pf, 1, 0);
	va_end (ap);
	if (i != 0)
	{
		printf("width: %d\n", WIDTH);
		printf("dot: %d\n", DOT);
		printf("precision: %d\n", PREC);
		printf("modifier: %s\n", MODF);
		printf("type: %c\n", TYPE);
		printf("Well done!\n");
	}
	else
		printf("Not valid percent or absent!\n");
	return (pf->symbols);
}