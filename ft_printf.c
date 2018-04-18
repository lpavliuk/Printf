/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 15:37:14 by opavliuk          #+#    #+#             */
/*   Updated: 2018/04/18 22:32:04 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		separator(char c)
{
	if (c != 's' && c != 'S' && c != 'p' && c != 'd'
		&& c != 'D' && c != 'i' && c != 'o' &&
		c != 'O' && c != 'u' && c != 'U' &&
		c != 'x' && c != 'X' && c != 'c' && c != 'C')
		return (1);
	else
		return (0);
}

int		check_flags(const char *format, int i, t_str *pf)
{
	int		k;

	k = 0;
	pf->flags[k] = format[i];
	k++;
	i++;
	if ((format[i] == 'l' && format[i - 1] == 'l')
		|| (format[i] == 'h' && format[i - 1] == 'h'))
	{
		pf->flags[k] = format[i];
		k++;
		i++;
	}
	if (!separator(format[i]))
		return (i);
	else
	{
		ft_strclr(pf->flags);
		return (0);
	}
}

int		check_percent(const char *format, t_str *pf)
{
	int	i;

	i = 1;
	pf->width = ft_atoi(format + i);
	while (separator(format[i]) && format)
	{
		if (format[i] == '.')
			pf->prec = ft_atoi(format + (++i));
		else if (format[i] == 'h' || format[i] == 'l'
		 	|| format[i] == 'j' || format[i] == 'z')
		{
			if ((i = check_flags(format, i, pf)) != 0)
				break ;
			else
				return (0);
		}
		else if (!ft_isdigit(format[i]))
			return (0);
		i++;
	}
	if (!separator(format[i]))
		pf->type = format[i];
	return (i);
}

int		ft_printf(const char *format, ...)
{
	t_str	*pf;
	int		i;
	va_list	ap;

	i = 0;
	pf = malloc(sizeof(t_str));
	pf->str = NULL;
	pf->width = 0;
	pf->prec = 0;
	ft_bzero(pf->flags, 3);
	va_start(ap, format);
	while (format && *format != '\0')
	{
		if (*format == '%' && *(format + 1) != '%')
		{
			i = check_percent(format, pf);
			if (i == 0)
			{
				format++;
				continue ;
			}
			format += i + 1;
		}
		if (*format == '%' && *(format + 1) == '%')
			format++;
		ft_putchar(*format);
		// else
		// 	ft_putchar(*format);
		format++;
	}
	ft_putchar('\n');
	if (i != 0)
	{
		printf("width: %d\n", pf->width);
		printf("precision: %d\n", pf->prec);
		printf("flag: %s\n", pf->flags);
		printf("type: %c\n", pf->type);
		printf("Well done!\n");
	}
	else
		printf("Not valid percent or absent!\n");
	va_end (ap);
	return (0);
}
