/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 15:37:14 by opavliuk          #+#    #+#             */
/*   Updated: 2018/05/09 16:04:32 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		check_type(va_list ap, t_str *pf)
{
	int i;

	i = 0;
	if (TYPE == 's' || TYPE == 'S')
		i = write_type_s(ap, pf);
	else if (TYPE == 'd' || TYPE == 'D' || TYPE == 'i')
		i = write_type_d_i(ap, pf);
	else if (TYPE == 'u' || TYPE == 'U')
		i = write_type_u(ap, pf);
	else if (TYPE == 'x' || TYPE == 'X' || TYPE == 'p')
		i = write_type_x_p(ap, pf);
	else if (TYPE == 'o' || TYPE == 'O')
		i = write_type_o(ap, pf);
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
	if (turn_off || N > 100)
	{
		write(1, BUFFER, N);
		pf->symbols += N;
		ft_bzero(BUFFER, 101);
		N = 0;
	}
	if (clean_pf)
	{
		WIDTH = 0;
		PREC = 0;
		TYPE = 0;
		SPACE = 0;
		HASH = 0;
		PLUS = 0;
		MINUS = 0;
		ZERO = 0;
		DOT = 0;
		N_UNI = 0;
		ft_bzero(MODF, 3);
	}
}

void			write_struct(t_str *pf)
{
	printf("TYPE: %c\n", TYPE);
	printf("MODF: %s\n", MODF);
	printf("PREC: %d\n", PREC);
	printf("WIDTH: %d\n", WIDTH);
	printf("PLUS: %d\n", PLUS);
	printf("MINUS: %d\n", MINUS);
	printf("HASH: %d\n", HASH);
	printf("ZERO: %d\n", ZERO);
	printf("DOT: %d\n", DOT);
	printf("SPACE: %d\n", SPACE);
}

static int		work_while(const char *format, t_str *pf, va_list ap)
{
	int i;

	i = 0;
	while (format && *format != '\0')
	{
		check_buffer(pf, 0, 1);
		if (*format == '%' && *(format + 1) != '\0')
		{
			if ((i = check_percent(ap, format, pf)))
				format += i;
			write_struct(pf);
			if (check_type(ap, pf))
				return (-1);
			check_buffer(pf, 1, 1);
			if (i == 0)
				format++;
			continue ;
		}
		if (*format != '%')
		{
			BUFFER[N] = *format;
			N++;
		}
		format++;
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
	ft_bzero(BUFFER, 101);
	N = 0;
	pf->symbols = 0;
	if ((i = work_while(format, pf, ap)) == -1)
	{
		free(pf);
		return (-1);
	}
	check_buffer(pf, 1, 0);
	free(pf);
	va_end(ap);
	return (pf->symbols);
}
