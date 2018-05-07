/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 15:37:14 by opavliuk          #+#    #+#             */
/*   Updated: 2018/05/07 19:28:57 by opavliuk         ###   ########.fr       */
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
		|| TYPE == 'u' || TYPE == 'U')
		i = write_type_digital(ap, pf);
	else if (pf->type == 'x' || pf->type == 'X'
		|| TYPE == 'o' || TYPE == 'O' || TYPE == 'p')
		i = write_type_o_x_p(ap, pf);
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

static int		work_while(const char *format, t_str *pf, va_list ap)
{
	int i;

	i = 0;
	while (format && *format != '\0')
	{
		check_buffer(pf, 0, 1);
		if (*format == '%')
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
		BUFFER[N] = *format;
		format++;
		N++;
	}
	return (0);
}

int				ft_printf(const char *format, ...)
{
	t_str	*pf;
	int		i;
	va_list	ap;

	i = 0;
	pf = malloc(sizeof(t_str));
	va_start(ap, format);
	ft_bzero(BUFFER, 1024);
	N = 0;
	pf->symbols = 0;
	if ((i = work_while(format, pf, ap)) == -1)
		return (-1);
	check_buffer(pf, 1, 0);
	va_end(ap);
	return (pf->symbols);
}
